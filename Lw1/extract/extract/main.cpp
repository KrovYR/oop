#include <iostream>
#include <fstream>

using namespace std;

const int NUMBER_OF_ARGUMENTS = 5;

const int ARGUMENTS_ERROR = 1;
const string ARGUMENTS_ERROR_TEXT = "Invalid argument count\nUsage: extract.exe <inputFile> <outputFile> <startPosition> <fragmetSize>";

const int FILE_OPRENING_ERROR = 2;
const string FILE_OPRENING_ERROR_TEXT = "Can't open file";

const int EMPTY_FILE_ERROR = 3;
const string EMPTY_FILE_ERROR_TEXT = "File empty";

const int OUT_OF_RANGE_ERROR = 4;
const string OUT_OF_RANGE_ERROR_TEXT = "Out of range";

int main(int argc, char* argv[])
{
	if (argc != NUMBER_OF_ARGUMENTS)
	{
		cout << ARGUMENTS_ERROR_TEXT << endl;
		return ARGUMENTS_ERROR;
	}

	ifstream inputFile;
	inputFile.open(argv[1], ios::binary);

	ofstream outputFile;
	outputFile.open(argv[2], ios::binary);

	if (!inputFile || !outputFile)
	{
		cout << FILE_OPRENING_ERROR_TEXT << endl;
		return FILE_OPRENING_ERROR;
	}
	else if (inputFile.peek() == EOF)
	{
		cout << EMPTY_FILE_ERROR_TEXT << endl;
		return EMPTY_FILE_ERROR;
	}

	long long startPosition = atoi(argv[3]);

	long long fragmentSize = atoi(argv[4]);

	inputFile.seekg(0, ios::end);
	long long fileSize = inputFile.tellg();

	if (startPosition < 0)
	{
		cout << OUT_OF_RANGE_ERROR_TEXT << endl;
		return OUT_OF_RANGE_ERROR;
	}
	else if (startPosition > fileSize)
	{
		cout << OUT_OF_RANGE_ERROR_TEXT << endl;
		return OUT_OF_RANGE_ERROR;
	}
	else if (startPosition + fragmentSize > fileSize)
	{
		cout << OUT_OF_RANGE_ERROR_TEXT << endl;
		return OUT_OF_RANGE_ERROR;
	}

	inputFile.seekg(startPosition, ios_base::beg);

	char ch;

	while (inputFile.read((char*)&ch, 1) && fragmentSize > 0)
	{
		outputFile.write((char*)&ch, sizeof(ch));
		fragmentSize--;
	}

	return 0;
}