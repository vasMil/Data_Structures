#include "myHeader.h"
#include "inputValues.h"

std::string timeToSearch() { //Still waiting for a valorant pass to drop lmao
	int i = 0;
	std::string str,year,month,day,hour,minute,seconds;
	do {
std::cout << "1. GiveTheHoleTimestamp in the correct format" << std::endl;
std::cout << "2. Give timestamp guided" << std::endl;
std::cin >> i;
	} while (i != 1 && i != 2);

	if (i == 1) {
		std::cout << "Enter Here:\t";
		std::cin.ignore();
		std::getline(std::cin, str);
	}
	else {
		std::cout << "Enter year:\t";
		std::cin.ignore();
		std::getline(std::cin, year);

		std::cout << "Enter month:\t";
		std::getline(std::cin, month);

		std::cout << "Enter date:\t";
		std::getline(std::cin, day);

		std::cout << "Enter hours:\t";
		std::getline(std::cin, hour);

		std::cout << "Enter minutes:\t";
		std::getline(std::cin, minute);

		std::cout << "Enter seconds:\t";
		std::getline(std::cin, seconds);

		str.append(year + "-" + month + "-" + day + "T" + hour + ":" + minute + ":" + seconds);
	}
	return str;
}

long long int fixMeUp(std::string time) {
	unsigned int i;
	char x;
	std::string temp;
	for (i = 0; i <= time.size(); i++) {							//se ka8e string stis 8eseis 11 mexri 18 brisketetai
		x = time[i];								           //h xronikh stigmh ths metrishs
		if (x != '-' && x != 'T' && x != ':') {
			temp = temp + time[i];
		}												//logo tou cast se integer den 8a exoun
	}													//ola to idio mhkos (ama enas ari8mos 3ekinaei apo 0
	return stoll(temp);									 //					  ta prota 0 trimarontai)
}



int basicSearch(std::vector<std::vector<inputValues> >& date, int day, long long findDate, std::string choice) {
	int index = -1;
	double str = floor(date[day][0].igettime() / pow(10, 6));

	if (floor(findDate / pow(10, 6)) != str) { //division combined with floor trims the 4 last digits of itimestamp, so I only keep the digits of month and day.
		return -1;
	}
	else {

		if (choice == "Binary Search" || choice == "BS" || stoi(choice) == 1) {
			index = BinarySearch(date[day], 0, date[day].size() - 1, findDate);
		}
		else if (choice == "Interpolation Search" || choice == "IS" || stoi(choice) == 2) {
			index = interpolationSearch(date[day], 0, date[day].size() - 1, findDate);
		}
		else if (choice == "Binary Interpolation Search" || choice == "BIS" || stoi(choice) == 3) {
			index = BISstd(date[day], findDate);
		}
		else if (choice == "BIS Improved" || choice == "IBIS" || stoi(choice) == 4) {
			index = BISimproved(date[day], findDate);
		}
		else if (stoi(choice) == 5) {
			return -3;
		}
		else {
			//std::cout << "That is not a valid input!" << std::endl;
			return -2;
		}

		if (index == -1) {
			return -1;
		}
		else {
			return index;
		}
	}

}

inputValues Search(std::vector<std::vector<inputValues> >& date, int day) {			//if returns -1 --> error
	inputValues res; res.settime("-1");												//using string time to determin if search failed --> time = -1;
	long long findDate = fixMeUp(timeToSearch());								    //input of a search function
	int index;																		//output of a search function
	std::string choice;

	if (day != -1 && icheck(date, day) == 0) {
		std::cout << "The measurments in the day you are trying to search are not sorted" << std::endl;
		return res;
	}
	else if (day == -1 && icheck(date) == 0) {
		std::cout << "The vector is not sorted" << std::endl;
		return res;
	}
	else {
		std::cout << "\nPick the algorithm I should use:\n" << std::endl;
		std::cout << "1. Binary Search (BS)" << std::endl;
		std::cout << "2. Interpolation Search (IS)" << std::endl;
		std::cout << "3. Binary Interpolation Search (BIS)" << std::endl;
		std::cout << "4. BIS Improved (IBIS)\n" << std::endl;
		std::cout << "5. Go back" << std::endl;
		std::getline(std::cin, choice);

		if (day == -1) {
			for (day = 0; (unsigned)day < date.size(); day++) {
				index = basicSearch(date, day, findDate, choice);
				if (index != -1 && index != -2 && index != -3) {
					std::cout << "The element was found!(indexes)\nDay:\t" << day << "\nMeasurement:\t" << index << std::endl;
					std::cout << "\nPrinting the element:\n" << std::endl;
					res = date[day][index];
					res.printMeasur();
					return res;
				}
				else if (index == -2) {
					std::cout << "That was not a valid input!" << std::endl;
					return res;
				}
				else if (index == -3) {
					//go back
					return res;
				}
			}
			std::cout << "NOT FOUND!" << std::endl;
			return res;
		}
		else if (day >= 0 && (unsigned)day < date.size()) { //the unsigned cast is really not necessary but I really dislike warnings lmao
			index = basicSearch(date, day, findDate, choice);

			if (index == -1) {
				std::cout << "The measurment you where searching for is not in the given date!" << std::endl;
				return res;
			}
			else if (index == -3) {
				//go back
				return res;
			}
			else {
				std::cout << "The element was found!(indexes)\nDay:\t" << day << "\nMeasurement:\t" << index << std::endl;
				std::cout << "\nPrinting the element:\n" << std::endl;
				date[day][index].printMeasur();
				return date[day][index];
			}
		}
		else {
			std::cout << "That is not a valid date" << std::endl;
			return res;
		}
	}
}