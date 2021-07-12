#include "myHeader.h"
#include "inputValues.h"


void quicksort(std::vector<inputValues>& vec, int low, int high) {
	int pi;
	if (low < high){
		pi = partition(vec, low, high);
		quicksort(vec, low, pi - 1);
		quicksort(vec, pi + 1, high);
	}
}


void quicksort(std::vector<std::vector<inputValues> >& myvec, int day){ //kodikas gia tis meres
	int left = 0;
	unsigned int i = myvec.size();

	if (day != -1) {
		int right = myvec[day].size();
		quicksort(myvec[day], left, right);
	}
	else {
		for (i = 0; i < myvec.size(); i++){    //loupa gia tis meres tou arxeiou tempm.txt
			int right = myvec[i].size();
			quicksort(myvec[i], left, right);
		}
	}

}

//kodikas gia thermokrasies
int partition(std::vector<inputValues>& vec, int low, int high) {	//partition(vazei ola ta mikrotera apo thn timh 
																	//tou pivot prin apo auto kai ta megalutera meta
	int i=0;
	int pivot = low;
	int	left = low;
	high = vec.size() - 1;
	for( i = low + 1 ; i<=high; i++)//loopa gia tis 8ermokrasies
	{
		if (vec[i].gettemp() < vec[pivot].gettemp()) {
			swapValues(&vec[i], &vec[left + 1]);
			left = left + 1;
		}
	}
		
		swapValues(&vec[pivot], &vec[left]);

			return (left);
}

