// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <atomic>
#include <sstream>
#include "options_parser.h"
#include "errors.h"
#include <memory>

using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::make_unique;



inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template <class D>
inline long long to_us(const D &d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

vector<double> convert_using_stringstream(const std::vector<std::string> &strs)
{
    size_t n = strs.size();
    std::vector<double> dd(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::stringstream sstream{strs[i]};
        sstream >> dd[i];
    }
    return dd;
}

vector<double> convert_using_stod(const std::vector<std::string> &strs)
{
    size_t n = strs.size();
    std::vector<double> dd(n);
    for (size_t i = 0; i < n; ++i)
    {
        dd[i] = std::stod(strs[i]);
    }
    return dd;
}

vector<double> convert_using_sscanf(const std::vector<std::string> &strs)
{
    size_t n = strs.size();
    std::vector<double> dd(n);
    for (size_t i = 0; i < n; ++i)
    {
        sscanf(strs[i].c_str(), "%lf", &dd[i]);
    }
    return dd;
}

int main(int argc, char* argv[]) {
    unique_ptr<command_line_options_t> command_line_options;
    try {
        command_line_options = make_unique<command_line_options_t>(argc, argv);
    }
    catch (std::exception &ex) {
        cout << "Program arguments parsing error" << endl;
        return Errors::ARGS_PARSER;
    }

    if (argc != 4)
    {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return Errors::INCOR_ARGS_NUM;
    }

    std::ifstream input_file(command_line_options->get_input_filename());

    if (!input_file)
    {
        std::cerr << "Error opening input file" << std::endl;
        return Errors::OPEN_INPUT_FILE;
    }

    std::vector<std::string> strs;
    std::string str;

    while (input_file >> str)
    {
        strs.push_back(str);
    }

    if (!input_file.eof())
    {
        std::cerr << "Error reading input file" << std::endl;
        return Errors::READ_INPUT_FILE;
    }

    //#define PRINT_STEPS

    auto time_start = get_current_time_fenced();

    vector<double> dd;

    switch (command_line_options->get_method_number())
    {
        case 1:
            dd = convert_using_stringstream(strs);
            break;
        case 2:
            dd = convert_using_stod(strs);
            break;
        case 3:
            dd = convert_using_sscanf(strs);
            break;
        default:
            std::cerr << "Incorrect method number" << std::endl;
            return Errors::INCOR_METHOD_NUM;
    }

    double sum = 0;
    for (auto d : dd)
    {
        sum += d;
    }
    double av = sum / dd.size();

    auto time_finish = get_current_time_fenced();

#ifdef PRINT_STEPS
    std::cout << "time: ";
#endif

    std::cout << to_us(time_finish - time_start) << std::endl;

#ifdef PRINT_STEPS
    std::cout << "sum: " << sum << std::endl;
    std::cout << "av: " << av << std::endl;
#endif

    std::ofstream output_file(command_line_options->get_output_filename());

    if (!output_file)
    {
        std::cerr << "Error opening output file" << std::endl;
        return Errors::OPEN_OUTPUT_FILE;
    }

    output_file << sum << std::endl << av << std::endl;

    if (!output_file)
    {
        std::cerr << "Error writing in output file" << std::endl;
        return Errors::WRITE_OUTPUT_FILE;
    }

    return EXIT_SUCCESS;
}
