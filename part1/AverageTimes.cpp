#include "myHeader.h"
#include "inputValues.h"

typedef std::vector<std::vector<inputValues> > myInput;

std::vector<long long> searchRand(myInput &inp, int size) {
	int i, day, measur;
	std::vector<long long> res;

	std::default_random_engine generator((unsigned int)time(NULL));
	std::uniform_int_distribution<int> distribution4days(0, inp.size()-1);

	for (i = 0; i < size; i++) {
		day = distribution4days(generator);
		std::uniform_int_distribution<int> distribution4obj(0, inp[day].size()-1);
		measur = distribution4obj(generator);
		res.push_back(inp[day][measur].igettime());
	}

	return res;
}

void averageMergeSort(myInput inp) { //sorting algorithms will be sorting the whole 2d array
	myInput tempor1 = inp; //will be creating new vectors so I don't change the given input
	myInput tempor2 = inp;

	auto t1 = std::chrono::high_resolution_clock::now();
	MergeSort(tempor1,"sort");
	auto t2 = std::chrono::high_resolution_clock::now();
	MergeSort(tempor2, "search");
	auto t3 = std::chrono::high_resolution_clock::now();

	auto time1 = (std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()) / inp.size();
	auto time2 = (std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count()) / inp.size();

	//vectors will be destroyed when they get out of scope, dont think I need to destruct them here

	std::cout << "Mergesort on measurments (temp/hum) averaged:\t" << (float)time1/1000 << "ms" << std::endl;
	std::cout << "Mergesort on timespamps averaged:\t" << (float)time2/1000 << "ms" << std::endl;

	//I will not be returning any values since I can instantly print time intervals (I know it is mergesort (so I can specify whose time I am printing on cout), since I am not getting the function that will be used by reference!
	//Look into lamda function, could provide you with the solution you are seeking, so I can merge with averageSort function
}

float averageSort(myInput inp, void (*func)(std::vector<std::vector<inputValues> >&, int day)) { //cannot include Mergesort in this implementation since it needs 3 arguments (DAMN YOU MERGESORT)
	myInput tempor = inp;																		//will be creating new vectors so I don't change the given input
	auto t1 = std::chrono::high_resolution_clock::now();
	func(tempor,-1);																			//cannot use default arguments on pointer functions, so I need set -1 by hand
	auto t2 = std::chrono::high_resolution_clock::now();
	int time = (int)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / inp.size();
	return (float)time/1000;

	//need to return the value and use cout outside of the function since I am getting the function that will be used as an argument
}

void averageBIS(myInput inp, bool choice) { //same problems occure as in the sorting functions
	unsigned int counter = 0, j = 0;
	int index = -1;
	std::vector<int> dur;
	std::vector<long long> searchfor = searchRand(inp); //you can set the size of the vector default 100
	myInput tempor = inp;
	MergeSort(tempor, "search"); //just so I make sure the vector I am searching in is always sorted!!!
	//std::cout << "size of the vector: \t" << searchfor.size() << std::endl;

	for (counter = 0; counter < searchfor.size(); counter++) {
		j = 0; index = -1; int temp;
		while (index == -1) {
			auto t1 = std::chrono::high_resolution_clock::now();
			if (choice == 0) {
				index = BISstd(tempor[j], searchfor[counter]);
			}
			else {
				index = BISimproved(tempor[j], searchfor[counter]);
			}
			
			auto t2 = std::chrono::high_resolution_clock::now();
			temp = (int)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			j++;
		}

		dur.push_back(temp);		
	}


	int time = 0;
	for (counter = 0; counter < dur.size(); counter++) {
		time = dur[counter] + time;
	}
	time = time / dur.size();


	if (!choice) {
		std::cout << "BIS needs in average:\t" << (float)time/1000 << "ms per search" << std::endl;
	}
	else {
		std::cout << "Improved BIS needs in average:\t" << (float)time/1000 << "ms per search" << std::endl;
	}
}

float averageSearch(myInput inp, int (*func)(std::vector<inputValues>& day, int left, int right, long long element)) {
	myInput tempor = inp;
	MergeSort(tempor, "search"); //just so I make sure the vector I am searching in is always sorted!!!

	std::vector<long long> searchfor = searchRand(inp);
	unsigned int i = 0, j = 0;
	int index = -1;
	int time;
	int res = 0;
	std::chrono::steady_clock::time_point t1, t2;

	for (j = 0; j < searchfor.size(); j++) {
		index = -1; i = 0; time = 0;
		while (i < tempor.size() && index == -1) {

			auto t1 = std::chrono::high_resolution_clock::now();
			index = func(tempor[i], 0, tempor[i].size() - 1, searchfor[j]);
			auto t2 = std::chrono::high_resolution_clock::now();

			time = (int)std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
			i++;
		}
		res = res + time;
	}

	res = res / searchfor.size();
	return (float)res/1000;
}

void worstBIS(myInput inp) {
	std::vector<inputValues> temp = inp[0];
	MergeSort(temp, "search");
	const long long int element = fixMeUp("2014-02-13T00:00:01"); //auto to element den iparxei se kanena simeio tou arxeiou alla an ipirxe 8a htan sthn 1h mera, opote
																 //o algori8mos 8a paei na ps3ei sth 1h mera kai de 8a brei to stoixeio, opote 8a mou epistrepsei to xeirotero dinato xrono
	auto t1 = std::chrono::high_resolution_clock::now();
	BISstd(temp, element);
	auto t2 = std::chrono::high_resolution_clock::now();

	int timer = (int)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Standard BIS needs worst case: " << (float)timer / 1000 << "ms in the worst case, to search through " << temp.size() << " elements" << std::endl;

	t1 = std::chrono::high_resolution_clock::now();
	BISimproved(temp, element);
	t2 = std::chrono::high_resolution_clock::now();

	timer = (int)std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Improved BIS needs worst case: " << (float)timer/1000 << "ms in the worst case, to search through " << temp.size() << " elements" << std::endl;
}