#include "myHeader.h"
#include"inputValues.h"

int interpolationSearch(std::vector<inputValues>& day, int left, int right, long long element) {

	while (left <= right && day[left].igettime() != day[right].igettime()) {
		unsigned int pos = left + ((right - left) * (int)(element - day[left].igettime()) / (int)(day[right].igettime() - day[left].igettime()));
		if (pos < day.size() && pos >= 0) {

			if (day[pos].igettime() < element) {
				return interpolationSearch(day, pos + 1, right, element);
			}
			else if (day[pos].igettime() > element) {
				return interpolationSearch(day, left, pos - 1, element);
			}
			else if (day[pos].igettime() == element) {
				return pos;
			}
		}
		return -1;
	}
	return -1;
}