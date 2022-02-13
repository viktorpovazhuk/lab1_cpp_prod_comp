// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <filesystem>
#include <iostream>
#include "options_parser.h"

namespace po = boost::program_options;

using std::string;

command_line_options_t::command_line_options_t() {
    opt_conf.add_options()
        ("help,h",
                "Show help message")
        ("method_number",
         po::value<int>(),
                "Number of method to run")
                ("input_file",
                        po::value<string>(),
                                "File with input data")
            ("output_file",
                    po::value<string>(),
                            "File for result")
        ;

    opt_pos.add("method_number", 1)
    .add("input_file", 1)
    .add("output_file", 1);

}

command_line_options_t::command_line_options_t(int ac, char **av):
        command_line_options_t() // Delegate constructor
{
    parse(ac, av);
}

void command_line_options_t::parse(int ac, char **av) {
    try {
        po::parsed_options parsed = po::command_line_parser(ac, av)
                .options(opt_conf)
                .positional(opt_pos)
                .run();
        po::store(parsed, var_map);
        po::notify(var_map);

        if (var_map.count("help")) {
            std::cout << opt_conf << "\n";
            exit(EXIT_SUCCESS);
        }
        method_number = var_map["method_number"].as<int>();
        input_filename = var_map["input_file"].as<string>();
        output_filename = var_map["output_file"].as<string>();
    } catch (std::exception &ex) {
        throw OptionsParseException(ex.what()); // Convert to our error type
    }
}