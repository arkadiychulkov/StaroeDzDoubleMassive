#include<iostream>
#include <ctime>
#include "functions.h"

void initializate(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() % 21;
		}
	}
}

void show(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void show(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl<< std::endl;
}


void task1(int arr[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	double average = sum / n;

	if (average > 0) {
		for (int i = 0; i < 2 * n / 3 - 1; i++) {
			for (int j = i + 1; j < 2 * n / 3; j++) {
				if (arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	else {
		for (int i = 0; i < n / 3 - 1; i++) {
			for (int j = i + 1; j < n / 3; j++) {
				if (arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	for (int i = 2 * n / 3, j = n - 1; i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void task2(int** matrix, int rows, int cols) {
	int max = 0;
	int min = 100000;
	int sum = 0;
	int sredneArifmet;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += matrix[i][j];
			if (matrix[i][j] < min)
				min = matrix[i][j];
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}

	sredneArifmet = sum / (rows * cols);
	std::cout << "sredneArifmet: " << sredneArifmet << std::endl;
	std::cout << "sum: " << sum << std::endl;
	std::cout << "min: " << min << std::endl;
	std::cout << "max: " << max << std::endl;
}

void task3(int** matrix, int rows, int cols) {
	int* colSums = new int[cols]();
	int* rowSums = new int[rows]();
	int totalSum = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			rowSums[i] += matrix[i][j];
			colSums[j] += matrix[i][j];
			totalSum += matrix[i][j];
		}
	}

	std::cout << "\nResults:" << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "| " << rowSums[i] << std::endl;
	}
	std::cout << "--------------------------\n";
	for (int j = 0; j < cols; j++) {
		std::cout << colSums[j] << "\t";
	}
	std::cout << "| " << totalSum << std::endl;

	delete[] colSums;
	delete[] rowSums;
}

void task4() {
	const int rows = 5, cols = 10;
	int** largeMatrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		largeMatrix[i] = new int[cols];
	}

	int** smallMatrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		smallMatrix[i] = new int[rows];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			largeMatrix[i][j] = rand() % 51;
		}
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {
			smallMatrix[i][j] = largeMatrix[i][2 * j] + largeMatrix[i][2 * j + 1];
		}
	}

	std::cout << "\nLarge Matrix:" << std::endl;
	show(largeMatrix, rows, cols);

	std::cout << "\nSmall Matrix:" << std::endl;
	show(smallMatrix, rows, rows);

	for (int i = 0; i < rows; ++i) {
		delete[] largeMatrix[i];
		delete[] smallMatrix[i];
	}
	delete[] largeMatrix;
	delete[] smallMatrix;
}