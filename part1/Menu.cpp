#include "myHeader.h"
#include "inputValues.h"

typedef std::vector<std::vector<inputValues> > myInput;

void averageMenu(myInput &inp) {
	int x;
	float timer;
	
	do {
		std::cout << "Pick the algorithm to get the execution time: " << std::endl;
		std::cout << "1. Merge Sort (average time)" << std::endl;
		std::cout << "2. Quick Sort (average time)" << std::endl;
		std::cout << "3. Heap Sort (average time)" << std::endl;
		std::cout << "4. Counting Sort (average time)" << std::endl;
		std::cout << "5. Binary Search (average time)" << std::endl;
		std::cout << "6. Interpolation Search (average time)" << std::endl;
		std::cout << "7. Binary Interpolation Search (average time)" << std::endl;
		std::cout << "8. Improved Binary Interopolation Search (average time)" << std::endl;
		std::cout << "9. BIS - Improved BIS (worst time)" << std::endl;
		std::cout << "\n10. Go back" << std::endl;

		std::cin.ignore();
		std::cin >> x;

		switch (x) {
		case 1:
			std::cout << std::endl;
			averageMergeSort(inp);
			std::cout << std::endl;
			break;
		case 2:
			timer = averageSort(inp, quicksort);
			std::cout << std::endl;
			std::cout << "Quick Sort executed in " << timer << "ms" << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			timer = averageSort(inp, Heapsort);
			std::cout << std::endl;
			std::cout << "Heap Sort executed in " << timer << "ms" << std::endl;
			std::cout << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			std::cout << "Should only be used to sort integers! If the input contains floats expect an error to occure." << std::endl;
			timer = averageSort(inp, CountingSort);
			std::cout << "Counting Sort executed in " << timer << "ms" << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			timer = averageSearch(inp, BinarySearch);
			std::cout << std::endl;
			std::cout << "Binary Search executed in " << timer << "us" << std::endl;
			std::cout << std::endl;
			break;
		case 6:
			timer = averageSearch(inp, interpolationSearch);
			std::cout << std::endl;
			std::cout << "Interpolation Search executed in " << timer << "us" << std::endl;
			std::cout << std::endl;
			break;
		case 7:
			std::cout << std::endl;
			averageBIS(inp);
			std::cout << std::endl;
			break;
		case 8:
			std::cout << std::endl;
			averageBIS(inp, 1);
			std::cout << std::endl;
			break;
		case 9:
			std::cout << std::endl;
			worstBIS(inp);
			std::cout << std::endl;
			break;
		case 10:
			break;
		default:
			std::cout << "That is not an option! Try again!" << std::endl;
		}
	} while (x != 10);
}

void transferMenu(myInput &inp) {
	std::cout << "1. Load tempm.txt" << std::endl;
	std::cout << "2. Load hum.txt" << std::endl;
	std::cout << "3. Load a new file (The file needs to be included with the rest of the codes)" << std::endl;
	std::cout << "4. Go back" << std::endl;

	int x;
	std::string str;
	do {
		std::cout << "Choose what is that you want to do:" << std::endl;
		std::cin >> x;
		switch (x) {
		case 1:
			transfer("tempm.txt", inp);
			break;
		case 2:
			transfer("hum.txt", inp);
			break;
		case 3:
			std::cout << "Next you need to type the name of the file (including .txt extension). If there is no such file an error will occure" << std::endl; //needs to be handling the errors
			std::cin.ignore();
			getline(std::cin, str);
			transfer(str, inp);
			break;
		case 4:
			break;
		default:
			std::cout << "This is not an expected input try again" << std::endl;
		}
	}while (x != 1 && x != 2 && x != 3 && x != 4);

}


void basicMenu(myInput &inp) {
	bool basicQuit = 0;

	while (!basicQuit) {
		std::cout << "\n-----------------MENU---------------\n" << std::endl;
		std::cout << "1. Transfer the file you need to load" << std::endl;
		std::cout << "2. Sort your measurments" << std::endl;
		std::cout << "3. Search through the sorted measurments" << std::endl;
		std::cout << "4. Get the average times of our algorithms" << std::endl;
		std::cout << "5. Print the vector" << std::endl;
		std::cout << "6. End Me" << std::endl;

		int x, ch;
		std::string str;
		std::cout << "Choose through 1 to 6" << std::endl;
		std::cin >> x;
		switch (x) {
		case 1:
			transferMenu(inp);
			break;
		case 2:
			timeToSort(inp);
			break;
		case 3:
			std::cout << "Warning the measurments should already be sorted to continue" << std::endl;
			std::cout << "If you want to just search in a specific day, give its index, else give -1" << std::endl;
			std::cin >> ch;
			if (ch >= 0 && ch < 116) {
				Search(inp, ch);
			}
			else {
				Search(inp);
			}
			break;
		case 4:
			averageMenu(inp);
			break;
		case 5:
			std::cout << "Which day should I print? (give index)" << std::endl;
			std::cin >> ch;
			while (((unsigned)ch >= inp.size() || ch < 0) && ch != -1) {
				std::cout << "there is no day with that index in the input, try again! (or give -1 to get to the main menu)" << std::endl;
				std::cin >> ch;
			}
			if (ch == -1) {
				break;
			}
			printVec(inp, ch);
			break;

		case 6:
			basicQuit = 1;
			break;
		default:
			std::cout << "That is not a valid input, try again!\n\n" << std::endl;
		}
	}
}