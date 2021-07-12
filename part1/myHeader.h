#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <time.h>
#include <algorithm>

class inputValues;
typedef std::vector<std::vector<inputValues> > myInput;



//_____________________________________________CHECK IF WORKS FUNCTIONS____________________________________________________________________________________________________________________________________

void check(std::vector<std::vector<inputValues> >& myvec); //an easy O(n^2) to check if everything is sorted correctly (gettemp())
bool icheck(std::vector<std::vector<inputValues> >& myvec); //returns 1 if sorted, 0 if not (igettime())
bool icheck(std::vector<std::vector<inputValues> >& myvec, int i); //icheck for a specific day

//you can implement this by using quicksort and counting the swaps of element. If > 0 the the array is not sorted
//be careful to get a copy of the array, so you dont make any changes to the input



//__________________________________________________SORTING FUNCTIONS_______________________________________________________________________________________________________________________________________

//menu functions
void timeToSort(myInput& inp);
void chooseSort(myInput& inp, int day = -1);

//algorithms

	//quickSort
int partition(std::vector<inputValues>& vec, int left, int right);
void quicksort(std::vector<inputValues>& vec, int low, int high);
void quicksort(std::vector<std::vector<inputValues> >& myvec, int day = -1);

	//MergeSort (choice == "sort" --> sort by value || choice == "search" --> sort by date)
void MergeSort(std::vector<std::vector<inputValues> >& date, std::string choice, int day = -1);
std::vector<inputValues> MergeSort(std::vector<inputValues> measurs, std::string choice); //overload so I can sort an exact day
std::vector<inputValues> Merge(std::vector<inputValues> left, std::vector<inputValues> right, std::string choice); //dont really need to return the vector, since I am passing the vector by reference

	//HeapSort
void Heapify(std::vector<inputValues>& vheap, int i, int sz);
void BuildMaxHeap(std::vector<inputValues>& vecth);
void Heapsort(std::vector<inputValues>& heapvec);
void Heapsort(std::vector<std::vector<inputValues> >& hvec, int day);

	//CountingSort
void CountingSort(myInput& inp, int day = -1);
void CountingSort(std::vector<inputValues>& day);



//_______________________________________________SEARCHING FUNCTIONS________________________________________________________________________________________________________________________________________

//menu functions
int basicSearch(std::vector<std::vector<inputValues> >& date, int day, long long findDate, std::string choice);
inputValues Search(std::vector<std::vector<inputValues> >& date, int day = -1);

//algorithms

		//BINARY search (elements must be sorted)
int BinarySearch(std::vector <inputValues> &measure, int l, int r, long long seek); //returns either the position of seek in the vector measure or -1 if the given timestamp is not in that vector

		//INTERPOLATION search (elements must be sorted && uniformly distributed in order to achive O(log log n) )
		//if not uniformly distributed then worst case: O(n)
		//it uses both indexes and values of of current state in order to determin the next index value. (in comparison binary search uses ONLY the indexes of current state)
int interpolationSearch(std::vector<inputValues>& day, int left, int right, long long element);

		//Binary Interpolation Search
bool in_range(int pos, int left, int right);
int BISstd(std::vector<inputValues> day, long long element);
int BISimproved(std::vector<inputValues> day, long long element);

// use this :https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
//so you can make a function that calculates times needed by each search function to return a value



//___________________________________________inputValues HELP FUNCTIONS_____________________________________________________________________________________________________________________________________

void transfer(std::string filename, std::vector<std::vector<inputValues> >& vec_m); //transfer the txt file to a 2d vector of objects
void printVec(std::vector<std::vector<inputValues> >& myvec); //printing the whole 2d vector
void printVec(std::vector<std::vector<inputValues> >& myvec, int day); //print a specific day of the vector
void swapValues(inputValues* obj1, inputValues* obj2); //swapping 2 inputValues objects --> can be replaced with an overload =
std::string timeToSearch(); //gets an input from the user and outputs the timestamp as a string
long long int fixMeUp(std::string time); //timestamp from string to int, discarding some digits


//___________________________________________TIMING_functions____________________________________________________________________________________________________________________________________

std::vector<long long> searchRand(myInput& inp, int size = 100); //will return a vector of random timestamps, so I can use search for them
void averageMergeSort(myInput inp);
float averageSort(myInput inp, void (*func)(std::vector<std::vector<inputValues> >&, int day));
void averageBIS(myInput inp, bool choice = 0); //0 --> standard bis || 1 --> bis improved
float averageSearch(myInput inp, int (*func)(std::vector<inputValues>& day, int left, int right, long long element));
void worstBIS(myInput inp);

//_______________________________________________Menu Functions_______________________________________________________________________________________________________________________________________________
void basicMenu(myInput &inp);
void transferMenu(myInput &inp);
void averageMenu(myInput &inp);


/*NOTES
In this section we will be making suggestions on how the code may be improved, shrinked and optimized

1. Creating timer struct where constructor starts the clock and the destructor ends it, because of the scope of the struct, I can measure the time needed for any of my functions to execute, just
by typing Timer timer; (creating an instace that will be automatically destructed at the end of the function (where it gets out of scope) ).

2. The AverageTimes functions can probably be bypassed using method 1, or maybe there is a way to give any of sorting/searching functions as input, just by using the address of the function, without worrying
about it's arguments and it's return values, so I can trim the functions down to 2 (maybe 1).

3. The menus may need some attention (not really important).

4. Transfer function could use arx.peek() to make the code more readable (I would like to think that the time complexity is fine, would like to know how to improve it though).

5. Impelement the idea described in MergeSort.cpp (function pointers (functors) seem to be useful).

6. Error handling is missing completly!

7. Check functions may be more useful to reduce their time complexity, using simple ideas such as calling quicksort and if a swap occurs then the array is not sorted.

8. Write some code using the matlab engine or a graphing library, in order to visualize sorting algorithms (very optimistic)
inspiration: https://www.youtube.com/watch?v=kPRA0W1kECg

9. Use typedef when needed!!!

10. Precompile the standard headers that are included in this file (lines 2-9), since we are not going to make any changes on them. It is kinda pointless at the current state of
the project but it would definitly improve the building time.

11. Probably more staff ll come up
*/
