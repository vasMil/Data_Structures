#include "myHeader.h"
#include "inputValues.h"

bool in_range(int pos, int left, int right) {
	if (left <= right) {
		if (left <= pos && pos <= right) {
			return 1;
		}
	}
	return 0;
}

int BISstd(std::vector<inputValues> day, long long element) {
	int left = 0;
	int right = day.size() - 1;
	int size = right - left;
	int pos = size * (element - day[left].igettime())/(day[right].igettime() - day[left].igettime());

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
			while (pos + i * (int)sqrt(size) < right && element > day[pos + i * (int)sqrt(size)].igettime()) {
				i++;
			}

			right = std::min(right, pos + i * (int)sqrt(size));
			left = std::max(left , pos + (i - 1) * (int)sqrt(size));
		}

		else if (element < day[pos].igettime()) {
			while (pos - i * (int)sqrt(size) >= left && element < day[pos - i * (int)sqrt(size)].igettime()) {
				i++;
			}

			right = std::min(right, pos - (i - 1) * (int)sqrt(size));
			left = std::max(left, pos - i * (int)sqrt(size));
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