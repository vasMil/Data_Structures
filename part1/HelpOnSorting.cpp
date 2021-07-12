#include "myHeader.h"
#include "inputValues.h"


void swapValues(inputValues* obj1, inputValues* obj2) { //will be used for quicksort
	inputValues tempor;								   //in myHeader.h under help functions
	tempor.settemp(obj1->gettemp()); //1
	tempor.settime(obj1->gettime()); //2
									//8elo ta 1 kai 2 na ginontai kanontas tempor = *obj1
	obj1->settemp(obj2->gettemp());
	obj1->settime(obj2->gettime());

	obj2->settemp(tempor.gettemp());
	obj2->settime(tempor.gettime());
}

void timeToSort(myInput &inp) {
	std::string ch1;
	unsigned int i;

	std::cout << "What to sort:\n" << std::endl;
	std::cout << "1. A specific day" << std::endl;
	std::cout << "2. All given days" << std::endl;

	std::cin.ignore();
	getline(std::cin, ch1);
	if (ch1 == "A specific day" || ch1 == "1") {
		std::cout << "What day should I sort?\t(use either the date of the first measurment or the index of the day)" << std::endl; //indexes start from 0
		getline(std::cin, ch1);

		if (ch1.length() > 2) {
			for (i = 0; i < inp.size(); i++) {
				if (inp[i][0].gettime() == ch1) {
					break; //breaks out of the for loop so I get the index of the day
				}
			}
		}
		else {
			i = stoi(ch1);
		}
		chooseSort(inp, i);
	}
	else if (ch1 == "All given days" || ch1 == "2") {
		chooseSort(inp);
	}

}

void chooseSort(myInput& inp, int day) { //haven't handled any exceptions that may occur due to the user input
	std::string alg;

	std::cout << "What algorithm should I use to sort with?" << std::endl;
	std::cout << "1. Mergesort (use if search follows)" << std::endl;
	std::cout << "2. Mergesort" << std::endl;
	std::cout << "3. Quicksort" << std::endl;
	std::cout << "4. Heapsort" << std::endl;
	std::cout << "5. Counting Sort" << std::endl;
	std::cout << "6. Go back" << std::endl;

	do {
		std::getline(std::cin, alg);

		if (alg == "Mergesort (use if search follows)" || alg == "1") {
			MergeSort(inp, "search", day);
		}
		else if (alg == "Mergesort" || alg == "2") {
			MergeSort(inp, "sort", day);
			alg = "1";
		}
		else if (alg == "Quicksort" || alg == "3") {
			quicksort(inp, day);
			alg = "1";
		}
		else if (alg == "Heapsort" || alg == "4") {
			Heapsort(inp, day);
			alg = "1";
		}
		else if (alg == "Counting Sort" || alg == "5") {
			CountingSort(inp,day);
			alg = "1";
		}
		else if (alg == "Go back" || alg == "6") {
			return;
		}
		else {
			std::cout << "That is not a valid input" << std::endl;
		}
	} while (alg != "1"); //pretty sure there is a better way to implement the while loop, but it works


}