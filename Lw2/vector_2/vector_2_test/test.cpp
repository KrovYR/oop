#define CATCH_CONFIG_MAIN
#include "../../catch/catch.hpp"
#include "../vector_2/function.h"
#include <iostream>

TEST_CASE("Check_vector_with_zero")
{
	std::vector<double> numbers = { 0, 1, 2, 3, 4 };
	std::vector<double> output = { 0, 0, 0, 0, 0 };
	MultiplyByLowerValue(numbers);
	SortNumbersAscending(numbers);
	REQUIRE(output == numbers);
}

TEST_CASE("Check_vector_sort")
{
	std::vector<double> numbers = { 6, 3, 2, 1, 4, 5 };
	std::vector<double> output = { 1, 2, 3, 4, 5, 6 };
	MultiplyByLowerValue(numbers);
	SortNumbersAscending(numbers);
	REQUIRE(output == numbers);
}