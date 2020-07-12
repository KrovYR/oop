#include "function.h"

std::vector<double> ReadNumbers(std::istream& stream)
{
    double number;
    std::vector<double> numbers;

    while (stream >> number)
    {
        numbers.push_back(number);
    }

    return numbers;
}

double GetLowerValue(const std::vector<double>& numbers)
{
    if (numbers.empty())
        throw std::invalid_argument("Passing parameter can not be empty vector");

    return *(std::min_element(numbers.begin(), numbers.end()));
}

void MultiplyByLowerValue(std::vector<double>& numbers)
{
    double lowerValue = GetLowerValue(numbers);

    std::for_each(numbers.begin(), numbers.end(), [&](double& number) {
        number *= lowerValue;
        });
}

void SortNumbersAscending(std::vector<double>& numbers)
{
    std::sort(numbers.begin(), numbers.end(), std::less<double>());
}

void PrintNumbers(const std::vector<double>& numbers, std::ostream& outStream)
{
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(outStream, " "));

    outStream << std::endl;
}