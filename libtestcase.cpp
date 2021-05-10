#include "libtestcase.h"
#include <cstring>
#include <iostream>

int total_test = 0, failed_test = total_test, passed_test = total_test, skipped_test = total_test;
bool fast_fail = false, test_failed = fast_fail;

bool assert_equal(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> str1, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> str2, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> str3)
{
        if(test_failed)
        {
                total_test += 1;
                skipped_test += 1;
                return false;
        }
	if(str1.compare(str2) == 0)
	{
		std::cout << "(" << str3 << ") \033[1;32mTest Passed: \033[0m got \"" << str1 << "\" as expected." << std::endl;
		total_test += 1;
		passed_test += 1;
		return true;
	} else {
		std::cout << "(" << str3 << ")  \033[1;31mTest Failed: \033[0m got \"" << str1 << "\", expected \""  << str2 << "\"." << std::endl;
		total_test += 1;
		failed_test += 1;
                if(fast_fail)
                {
                        test_failed = true;
                }
		return false;
	}
}

bool assert_equal(int int1, int int2, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> str)
{
        if(test_failed) {
                total_test += 1;
                skipped_test += 1;
                return false;
        }
	if(int1 == int2)
	{
		std::cout << "(" << str << ")  \033[1;32mTest Passed: \033[0m got " << int1 << " as expected." << std::endl;
		total_test += 1;
		passed_test += 1;
	       return true;
	} else {
		std::cout << "(" << str << ")  \033[1;31mTest Failed: \033[0m got " << int1 << ", expected " << int2 << "." << std::endl;
		total_test += 1;
		failed_test += 1;
                if(fast_fail)
                {
                        test_failed = true;
                }
		return false;
	}
}

void fail_fast(bool toggle)
{
        fast_fail = toggle;
}

bool assert_true(bool boolean, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> test_name)
{
        if(test_failed)
        {
                total_test += 1;
                skipped_test += 1;
                return false;
        }
        if(boolean)
        {
                std::cout << "(" << test_name << ") \033[1;32mTest Passed: \033[0m boolean equal to true as expected." << std::endl;
                total_test += 1;
                passed_test += 1;
                return true;
        } else {
                std::cout << "(" << test_name << ") \033[1;31mTest Failed: \033[0m boolean is false." << std::endl;
                total_test += 1;
                failed_test += 1;
                if(fast_fail)
                        test_failed = true;
                return false;
        }
}

void test_finish()
{
	std::cout << std::endl << std::endl;
	std::cout << "Total Tests: " << total_test << " (\033[1;32mPassed: " << passed_test << "\033[0m" << ", \033[1;31mFailed: " << failed_test << "\033[0m" << ", \033[1;33mSkipped: " << skipped_test <<  "\033[0m) " << std::endl;
}
