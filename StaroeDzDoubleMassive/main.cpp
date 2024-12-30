#include<iostream>
#include"functions.h"

int main() {
	int rows = 3;
	int cols = 3;
	int size = 15;
	int** matrix = new int* [rows];
	int array[15] = { 0,9,8,78,6,5,4,3,21,1,65,7,8,9,44 };

	initializate(matrix, rows, cols);
	show(matrix, rows, cols);

	task1(array, size);
	show(array, size);

	task2(matrix, rows, cols);

	task3(matrix, rows, cols);

	task4();
}