#include "function.h"

int main()
{
    try
    {
        std::vector<double> numbers = ReadNumbers(std::cin);

        MultiplyByLowerValue(numbers);
        SortNumbersAscending(numbers);

        PrintNumbers(numbers, std::cout);
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << std::endl;

        return 1;
    }

    return 0;
}