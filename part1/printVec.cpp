#include "myHeader.h"
#include "inputValues.h"



void printVec(std::vector<std::vector<inputValues> > &myvec) {
	unsigned int days = myvec.size() , i, j;
//	std::cout <<"days = "<< days <<std::endl;
//	int row =myvec[0].size();
//	std::cout <<"rows = " << row;
	for (i = 0; i < days; i++) {
		std::cout << "\n\n" << i <<".\t\t\t\t\t\t\t\tALLAGH\n\n"<<std::endl;
		for (j = 0; j < myvec[i].size(); j++) {
			std::cout << myvec[i][j].gettime() << ": " << myvec[i][j].gettemp() << std::endl;
		}
	} 
}

void printVec(std::vector<std::vector<inputValues> >& myvec, int day) {
	unsigned int i;
	for (i = 0; i < myvec[day].size(); i++) {
		std::cout << i <<".\t" << myvec[day][i].gettime() << ": " << myvec[day][i].gettemp() << std::endl;  //day-1 gt profanos h ari8misi 3ekinaei apo 0
		//std::cout << i << ".\t"<< myvec[day - 1][i].igettime() << std::endl;
	}
}