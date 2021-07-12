#include "myHeader.h"
#include "inputValues.h"

typedef std::vector<std::vector<inputValues> > myInput;


void CountingSort(std::vector<inputValues>& day) {

	std::vector<int> countArray(101);     
	std::vector <inputValues> tempor = day;
	unsigned int i;
	int j;

	for (i = 0; i < tempor.size(); i++) {
		countArray[(unsigned int)tempor[i].gettemp()]++;
	}

	for (i = 1; i < countArray.size(); i++) {
		countArray[i] = countArray[i] + countArray[i - 1];
	}
	
	for (j = tempor.size() - 1; j >= 0; j--) {											
		day[countArray[(unsigned int)tempor[j].gettemp()] - 1] = tempor[j];
		countArray[(unsigned int)tempor[j].gettemp()]--;
	}
}


void CountingSort(myInput &inp, int day) {
	//mono gia sorting akeraion --> mporo na kano elegxo se O(n^2) , me if (int)test[0][0].gettemp() == inp[0][0].gettemp();
	//gia auto 8a xrisimopoihsoume mono to arxeio me tis igrasies, dilonontai me pososta %, opote range: 0 to 100

	//myInput test = inp;

	unsigned int i;

	if (day == -1) {
		for (i = 0; i < inp.size(); i++) {
			CountingSort(inp[i]);
		}
	}
	else {
		CountingSort(inp[day]);
	}

}