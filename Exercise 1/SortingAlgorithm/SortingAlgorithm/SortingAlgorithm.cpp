// SortingAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>



int main()
{
	int size = 10000;
	fillArray(size);

    return 0;
}

void fillArray(int size) {
	std::vector<int> output;
	int randomNumber;
	for (int x = 0; x < size; x++) {
		randomNumber = rand() % 9 + 1; //Random number ranging from 1 to 9
		output.push_back(randomNumber);
	}
}

