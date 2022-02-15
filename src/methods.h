//
// Created by vityha on 15.02.22.
//

#ifndef CONVERTER_METHODS_H
#define CONVERTER_METHODS_H

#include <chrono>
#include <atomic>
#include <vector>
#include <string>

using std::vector;
using std::string;

inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template <class D>
long long to_us(const D &d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

vector<double> convert_using_stringstream(const std::vector<std::string> &strs);
vector<double> convert_using_stod(const std::vector<std::string> &strs);
vector<double> convert_using_sscanf(const std::vector<std::string> &strs);
vector<double> convert_using_boost(const std::vector<std::string> &strs);
vector<double> convert_using_qt(const std::vector<std::string> &strs);


#endif //CONVERTER_METHODS_H
