#include "myHeader.h"
#include "inputValues.h"

void check(std::vector<std::vector<inputValues> > &myvec) {
	unsigned int i = 0, j = 1;
	float tempor;
	while (i < myvec.size()) {
		tempor = myvec[i][0].gettemp();
		j = 1;
		while (j < myvec[i].size()) {
			if (tempor > myvec[i][j].gettemp()) {
				std::cout << "LA8OS\n\n"<<"Day: "<<i+1<<"  Metrisi: "<<j<< std::endl;
				return ;
				tempor = myvec[i][j].gettemp();
				j++;
			}
			else {
				tempor = myvec[i][j].gettemp();
				j++;
			}
		}
		i++;
	}
	std::cout << "OLA OK" << std::endl;
}

bool icheck(std::vector<std::vector<inputValues> >& myvec) {
	unsigned int i = 0;
	bool j = 1;
	while (i < myvec.size() && j == 1) {
		j = icheck(myvec, i);
		i++;
	}
	return j;
}

bool icheck(std::vector<std::vector<inputValues> >& myvec , int i) {
	unsigned int j = 0;
	long long tempor;
	tempor = myvec[i][j].igettime();
	j++;
	while (j < myvec[i].size()) {
		if (tempor > myvec[i][j].igettime()) {
			//std::cout << "LA8OS\n\n" << "Day: " << i + 1 << "  Metrisi: " << j << std::endl;
			return 0;
			//tempor = myvec[i][j].igettime(); //if you want to spot the mistakes, remove return restore code in comments
			//j++;							  //dont forget to fix it when done with debbuging
		}
		else {
			tempor = myvec[i][j].igettime();
			j++;
		}
	}
	i++;
//std::cout << "OLA OK" << std::endl;
return 1;
}


