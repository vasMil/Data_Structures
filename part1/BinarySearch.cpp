#include "myHeader.h"
#include "inputValues.h"


int BinarySearch(std::vector <inputValues> &measure, int l, int r, long long seek) {
	unsigned int mid;
	if (l < r) {
		mid = (r + l) / 2;
		if (measure[mid].igettime() == seek) {
			return mid;
		}
		else if (measure[mid].igettime() > seek) {
			return BinarySearch(measure, l, mid - 1, seek);
		}
		else if (measure[mid].igettime() < seek) {
			return BinarySearch(measure, mid + 1, r, seek);
		}
	}
	else if (measure[r].igettime() == seek) {
		return r;
	}
	return -1;
}