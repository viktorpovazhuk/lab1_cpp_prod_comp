#ifndef OPTIONS_PARSER_CONFIG_FILE_H
#define OPTIONS_PARSER_CONFIG_FILE_H

#include <boost/program_options.hpp>
#include <string>
#include <exception>
#include <stdexcept>

class OptionsParseException : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

class command_line_options_t {
public:
    command_line_options_t();
    command_line_options_t(int ac, char **av);

    //! Explicit is better than implicit:
    command_line_options_t(const command_line_options_t&) = default;
    command_line_options_t& operator=(const command_line_options_t&) = delete;
    command_line_options_t(command_line_options_t&&) = default;
    command_line_options_t& operator=(command_line_options_t&&) = delete;
    ~command_line_options_t() = default;

    [[nodiscard]] int get_method_number() const { return method_number; };
    [[nodiscard]] std::string get_input_filename() const { return input_filename; };
    [[nodiscard]] std::string get_output_filename() const { return output_filename; };

    void parse(int ac, char **av);
private:
    int method_number = 0;
    std::string input_filename;
    std::string output_filename;

    boost::program_options::variables_map var_map{};
    boost::program_options::options_description opt_conf{};
    boost::program_options::positional_options_description opt_pos{};
};

#endif //OPTIONS_PARSER_CONFIG_FILE_H

