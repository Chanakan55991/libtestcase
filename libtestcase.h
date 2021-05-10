#pragma once
#include <string>
bool assert_equal(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>);
bool assert_equal(int, int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>);
bool assert_true(bool, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>);
void test_finish();
void fail_fast(bool);
