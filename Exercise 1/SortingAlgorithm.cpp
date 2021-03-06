// SortingAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <vector>

std::vector<int> fillArray(int size, std::vector<int> &output);
std::vector<int> sortArray(int size, std::vector<int> &output);
void printArray(int size, std::vector<int> &output);
void runAlgorithm(int size);
int main()
{
	//Set up the variables we're going to work with
	int size = 100;

	//Run the algorithm multiple times
	for (int x = 0; x < 40; x++) {
		
		std::cout << size;
		runAlgorithm(size);
		//std::cout << "Amount of numbers in total : " << size;
		std::cout << '\n';
		size = size + 10;
	}
	//std::cout << "Amount of numbers in total : " << size;
	std::cout << size;
	std::cout << "Done running";
	
	std::cin.get();
    return 0;
}

std::vector<int> fillArray(int size, std::vector<int> &output){
	int randomNumber;
	for (int x = 0; x < size; x++) {
		randomNumber = rand() % 9 + 1; //Random number ranging from 1 to 9
		output.push_back(randomNumber);
	}

	return output;
}

//Implementing bubble sorting
std::vector<int> sortArray(int size, std::vector<int> &output) {
	bool hasSwapped;
	int countChanged = 0; //Debugging - Counts the amount of changes made
	for (int x = 0; x < size-1; x++) {
		hasSwapped = false;
		for (int y = 0; y < size-x-1; y++) {
			if (output[y] > output[y+1]) {
				int temp = output[y];
				output[y] = output[y+1];
				output[y+1] = temp;
				countChanged++;
				y = 0;
			}
		}

		//If no two elements have been swapped in the last run
		if (hasSwapped == false) {
			break;
		}
	}

	//std::cout << "Amount of changes made : " << countChanged;

	return output;
}

void printArray(int size, std::vector<int> &output) {
	for (int x : output) {
		std::cout << x << '\n';
	}
}

void runAlgorithm(int size) {
	//Set up the timer
	std::clock_t start;
	double duration;
	start = std::clock();

	//Set up the output vector
	std::vector<int> output;

	//Call the functions
	fillArray(size, output);
	sortArray(size, output);
	//printArray(size, output);

	//End the timer
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	//std::cout << "\nTime taken: " << duration << '\n';
	std::cout << " " << duration;
}

