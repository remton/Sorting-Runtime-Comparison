//File provided by instructor, modified by me to write/read the data from files 

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string>
#include "number_data.h"
using namespace std;

void fill_random_numbers (int arr [], const unsigned int SIZE)
{
	// Pre:  SIZE is no more than a million, arr has been declared to be
	//       an array of at least SIZE elements.
	// Post: The first SIZE elements of the array arr have been populated with
	//       random integers between 0 and one million.

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = round(rand() / double(RAND_MAX) * 1000000);
	}
}

void fill_sorted_numbers (int asc [], int dsc [], const unsigned int SIZE)
{
	// Pre:  SIZE is no more than a million, and asc and dsc have been declared
	//       to be arrays of at least SIZE elements.
	// Post: The first SIZE elements of the array asc have been populated with
	//       integers between 0 and one million in ascending order, and dsc has
	//       the same numbers in descending order.

	int step = 1000000 / SIZE;

	for (int i = 0; i < SIZE; i++)
	{
		asc[i] = dsc [SIZE-1-i] = step*i;
	}
}

//Added By Remington
const string RANDOM_FILENAME = "Random_";
const string SORTED_FILENAME = "Sorted_";

//Added By Remington
//Fills or creates a file with size random numbers
void write_random_numbers(const unsigned int SIZE) {
	int* nums = new int[SIZE];
	fill_random_numbers(nums, SIZE);
	ofstream file = ofstream(RANDOM_FILENAME + to_string(SIZE) + ".txt");
	for (size_t i = 0; i < SIZE; i++) {
		file << nums[i] << endl;
	}
	file.close();
	delete[] nums;
}
//Added By Remington
//Fills or creates a file with SIZE sorted numbers in ascending order
void write_sorted_numbers(const unsigned int SIZE) {
	int* acs = new int[SIZE];
	int* des = new int[SIZE];
	fill_sorted_numbers(acs, des, SIZE);
	ofstream file = ofstream(SORTED_FILENAME + to_string(SIZE) + ".txt");
	for (size_t i = 0; i < SIZE; i++) {
		file << acs[i] << endl;
	}
	file.close();
	delete[] acs;
	delete[] des;
}
//Added By Remington
//Reads the random numbers file and fills up to SIZE nums in nums array.
void read_random_numbers(int nums[], const unsigned int SIZE) {
	ifstream file = ifstream(RANDOM_FILENAME + to_string(SIZE) + ".txt");
	for (size_t i = 0; i < SIZE; i++) {
		if (file.eof())
			break;
		file >> nums[i];
	}
	file.close();
}
//Added By Remington
//Reads the sorted numbers file and fills up to SIZE nums in arrays.
void read_sorted_numbers(int asc[], int des[], const unsigned int SIZE) {
	ifstream file = ifstream(SORTED_FILENAME + to_string(SIZE) + ".txt");
	for (size_t i = 0; i < SIZE; i++) {
		if (file.eof())
			break;
		file >> asc[i];
		des[SIZE - 1 - i] = asc[i];
	}
	file.close();
}