#include "myHeader.h"
#include "inputValues.h"

int stepR(int left, int right, std::vector<inputValues> day, long long element) { //de3ia bhmata mege8ous sqrt(n) kai epistrefei to de3i pointer
	int temp = left;																//apo ton opoio epeita 8a ipologiso ton left me left = right - sqrt(n)
	int size = right - left;
	int i = 0;
	while (temp <= right && day[temp].igettime() < element) {
		i++;
		temp = left + i * (int)sqrt(size);
	}

	return std::min(right, temp);
}

int stepL(int left, int right, std::vector<inputValues> day, long long element) { //aristera bhmata mege8ous sqrt(n) kai epistrefei ton aristero pointer
	int temp = right;																//apo ton opoio epeita 8a ipologiso ton right me right = left + sqrt(n)
	int size = right - left;
	int i = 0;
	while (temp >= left && day[temp].igettime() > element) {
		i++;
		temp = right - i * (int)sqrt(size);
	}

	return std::max(left, temp);
}

int BISimproved(std::vector<inputValues> day, long long element) {
	int left = 0;
	int right = day.size() - 1;
	int size = right - left;
	int pos = size * (element - day[left].igettime()) / (day[right].igettime() - day[left].igettime());
	int temp = 0;

	while (in_range(pos, left, right) && day[pos].igettime() != element) {
		int i = 0;
		size = right - left;
		if (size <= 3) {
			pos = BinarySearch(day, left, right, element);
			if (pos != -1) {
				return pos;
			}
			else {
				//std::cout << "BINARY SEARCH FAILED OMG OMG OMG!!1" << std::endl;
				return -1;
			}
		}

		if (element >= day[pos].igettime()) {
			while (pos + (2^i) * (int)sqrt(size) < right && element > day[pos + (2^i) * (int)sqrt(size)].igettime()) {
				i++;
			}

			right = std::min(right, pos + (2^i) * (int)sqrt(size));
			left = std::max(left, pos + (2^(i - 1)) * (int)sqrt(size));

			size = right - left;
			right = stepR(left, right, day, element);
			left = right - (int)sqrt(size);
		}

		else if (element < day[pos].igettime()) {
			while (pos - (2 ^ i) * (int)sqrt(size) >= left && element < day[pos - (2 ^ i) * (int)sqrt(size)].igettime()) {
				i++;
			}

			right = std::min(right, pos - (2^(i - 1)) * (int)sqrt(size));
			left = std::max(left, pos - (2^i) * (int)sqrt(size));

			size = right - left;
			left = stepL(left, right, day, element);
			right = left + (int)sqrt(size);
		}
		if (right == left) {
			break;
		}
		pos = left + ((right - left) * (int)((element - day[left].igettime()) / (day[right].igettime() - day[left].igettime())));
	}

	if (in_range(pos, left, right) && element == day[pos].igettime()) {
		return pos;
	}
	else {
		return -1;
	}
}