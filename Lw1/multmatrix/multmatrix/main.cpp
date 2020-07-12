#include <istream>
#include <fstream>
#include <sstream>
#include <string>

void fillMatrix(std::ifstream matrixFile, double matrix[3][3])
{

}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return 1;
	}

	std::ifstream matrixFile1, matrixFile2;
	matrixFile1.open(argv[1]);
	matrixFile2.open(argv[2]);

	if (!matrixFile1 || matrixFile2)
	{
		return 1;
	}

	double matrix1[3][3], matrix2[3][3];

	return 0;
}



/*
#include <iostream>
#include <fstream>
#include <string>

const int SIZE = 3;
const int NUBER_OF_ARGUMENT = 3;

const int ARGUMENTS_ERROR = 1;
const char* ARGUMENTS_ERROR_TEXT = "Invalid argument count\nUsage: extract.exe <matrixFile1> <matrixFile2>";

const int FILE_OPRENING_ERROR = 2;
const char* FILE_OPRENING_ERROR_TEXT = "Can't open file";

const int EMPTY_FILE_ERROR = 3;
const char* EMPTY_FILE_ERROR_TEXT = "File empty";


// Функция заполнения матрицы
void fillMatrix(float matrix[SIZE][SIZE], std::ifstream& matrixFile)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			matrixFile >> matrix[i][j];
		}
	}
}


// Основная программа
int main(int argc, char* argv[])
{
	// Проверка количества аргументов
	if (argc != NUBER_OF_ARGUMENT)
	{
		std::cout << ARGUMENTS_ERROR_TEXT << std::endl;
		return ARGUMENTS_ERROR;
	}

	// Открытие фалйлов
	std::ifstream matrixFile1, matrixFile2;
	matrixFile1.open(argv[1]);
	matrixFile2.open(argv[2]);

	// Проверка открытия файлов
	if (!matrixFile1 || !matrixFile2)
	{
		std::cout << FILE_OPRENING_ERROR_TEXT << std::endl;
		return FILE_OPRENING_ERROR;
	}

	float matrix1[SIZE][SIZE], matrix2[SIZE][SIZE];

	fillMatrix(matrix1, matrixFile1);
	fillMatrix(matrix2, matrixFile2);
	
	int i, j, k;
	float matrix[SIZE][SIZE];

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			matrix[i][j] = 0;
			for (k = 0; k < SIZE; k++)
			{
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	//std::cout << std::fixed;
	//std::cout.precision(3);

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			std::cout.width(15);
			std::cout << round(matrix[i][j] * 1000) / 1000 << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
*/