#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

std::vector<double> ReadNumbers(std::istream& stream);

double GetLowerValue(const std::vector<double>& numbers);

void SortNumbersAscending(std::vector<double>& numbers);

void MultiplyByLowerValue(std::vector<double>& numbers);

void PrintNumbers(const std::vector<double>& numbers, std::ostream& outStream);