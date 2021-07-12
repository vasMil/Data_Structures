#include "myHeader.h"
#include "inputValues.h"


void MergeSort(std::vector<std::vector<inputValues> >&date, std::string choice, int day) {
	if (day == -1) {
		unsigned int i;
		for (i = 0; i < date.size(); i++) {
			date[i] = MergeSort(date[i], choice);
		}
	}
	else {
		date[day] = MergeSort(date[day], choice);
	}
}

std::vector<inputValues> MergeSort(std::vector<inputValues> measurs, std::string choice) { //change the function so you pass measurs as a pointer
	unsigned int size = measurs.size();													   //(kinda complicated, since you are using iterators)
	std::vector<inputValues>::const_iterator  it1 = measurs.begin(), it2 = measurs.begin() + (int)floor(size / 2), it3 =  measurs.end();
	std::vector<inputValues> left(it1, it2), right(it2 , it3);

	if (left.size() > 1) {
		left = MergeSort(left, choice);
	}
	if (right.size() > 1) {
		right = MergeSort(right, choice);
	}
	return Merge(left, right, choice);
}

std::vector<inputValues> Merge(std::vector<inputValues> left, std::vector<inputValues> right, std::string choice) {
	unsigned int l = 0, r = 0;
	std::vector<inputValues> sorted;
																				//in this implemetation there is no need to use a function pointer
	if (choice == "sort") {														//IDEA 1:
		float (inputValues:: * func)();											//the pointer could be used if I could assign a variable "T" as it's
		func = &inputValues::gettemp;											//return type, where T could either be float or long long int --> Implies templates --> could probably work with some kind of type punning
		while (l < left.size() && r < right.size()) {							//IDEA 2:
			if ((left[l].*func)() < (right[r].*func)()) {						//Functors!! It will work but I am really not sure how to implement it
				sorted.push_back(left[l]);										//I think if I make it at some point then I could use any function (quicksort etc.),
				l++;															//in order to sort by a specific characteristic of class inputValues
			}
			else {
				sorted.push_back(right[r]);
				r++;
			}
		}
	}
	else if (choice == "search") {
		long long (inputValues:: * func)();
		func = &inputValues::igettime;
		while (l < left.size() && r < right.size()) {
			if ((left[l].*func)() < (right[r].*func)()) {
				sorted.push_back(left[l]);
				l++;
			}
			else {
				sorted.push_back(right[r]);
				r++;
			}
		}
	}
	else {
		throw std::invalid_argument("You need to choose between \"sort\" and \"search\" "); // using \" in order to place quotation marks in a string
	}


	if (l < left.size()) {
		while (l < left.size()) {
			sorted.push_back(left[l]);
			l++;
		}
	}
	if (r < right.size()) {
		while (r < right.size()) {
			sorted.push_back(right[r]);
			r++;
		}
	}

	return sorted;
}