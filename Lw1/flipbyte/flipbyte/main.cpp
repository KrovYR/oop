#include <iostream>

const int MIN_INPUT = 0;
const int MAX_INPUT = 255;
const int NUMBER_OF_ARGUMENTS = 2;

const int ARGUMENTS_ERROR = 1;
const std::string ARGUMENTS_ERROR_TEXT = "Invalid argument count\nUsage: flipbyte.exe <inputNumber>";

const int INPUT_ERROR = 2;
const std::string INPUT_ERROR_TEXT = "Error expected a number in the range from 0 to 255";

bool isNumber(const std::string& str)
{
	return !str.empty() && (str.find_first_not_of("0123456789") == str.npos);
}

unsigned char reversBits(unsigned char byte)
{
	byte = (byte & 0x55) << 1 | (byte & 0xAA) >> 1;	// 76543210 -> 67452301
	byte = (byte & 0x33) << 2 | (byte & 0xCC) >> 2;	// 67452301 -> 45670123
	byte = (byte & 0x0F) << 4 | (byte & 0xF0) >> 4;	// 45670123 -> 01234567

	return byte;
}

int main(int argc, char* argv[])
{

	if (argc != NUMBER_OF_ARGUMENTS)
	{
		std::cout << ARGUMENTS_ERROR_TEXT << std::endl;
		return ARGUMENTS_ERROR;
	}

	if (!isNumber(argv[1]))
	{
		std::cout << INPUT_ERROR_TEXT << std::endl;
		return INPUT_ERROR;
	}

	int inputNumber = atoi(argv[1]);

	if (inputNumber < MIN_INPUT || inputNumber > MAX_INPUT)
	{
		std::cout << INPUT_ERROR_TEXT << std::endl;
		return INPUT_ERROR;
	}

	unsigned char byte = inputNumber;


	std::cout << static_cast <int>(reversBits(byte)) << std::endl;

	return 0;
}