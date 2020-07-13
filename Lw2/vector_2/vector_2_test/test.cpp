#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../vector_2/function.h"
#include <iostream>

TEST_CASE("Check_function_ReadNumbers")
{
	std::istringstream stringStream("10 2.4 7.9 0 11");
	std::istream stream(stringStream.rdbuf());

	std::vector<double> nonEmptyVector{ 10, 2.4, 7.9, 0, 11 };

	REQUIRE(ReadNumbers(stream) == nonEmptyVector);
}

TEST_CASE("Check_function_GetLowerValue")
{
	std::vector<double> nonEmptyVector{ 10, 2.4, 7.9, 0, 11 };

	double LowerValue = 0;

	REQUIRE(GetLowerValue(notEmptyVector) == LowerValue);
}

TEST_CASE("Check_function_SortNumbersAscending")
{
	std::vector<double> nonEmptyVector{ 10, 2.4, 7.9, 0, 11 };

	std::vector<double> sortedNonEmptyVector{ 0, 2.4, 7.9, 10, 11 };

	SortNumbersAscending(nonEmptyVector);

	REQUIRE(notEmptyVector == sortedNonEmptyVector);
}

TEST_CASE("Check_function_MultiplyByLowerValue (lowerValue = 0)")
{
	std::vector<double> nonEmptyVector{ 10, 2.4, 7.9, 0, 11 };

	std::vector<double> resultVector{ 0, 0, 0, 0, 0 };

	MultiplyByLowerValue(nonEmptyVector);

	REQUIRE(notEmptyVector == resultVector);
}

TEST_CASE("Check_function_MultiplyByLowerValue (lowerValue = 1)")
{
	std::vector<double> nonEmptyVector{ 3, 4, 1, 2, 6, 5 };

	std::vector<double> resultVector{ 1, 2, 3, 4, 5, 6 };

	MultiplyByLowerValue(nonEmptyVector);

	REQUIRE(notEmptyVector == resultVector);
}