#include "myHeader.h"
#include "inputValues.h"

int main(int argc, const char* argv[]) {

	std::vector<std::vector<inputValues> > inp;
	basicMenu(inp);

////___________________________________________________________________________________________ USED TO DEBUG BIS
//	std::vector<long long> searchfor; //= searchRand(inp, 10000);
//
//	transfer("tempm.txt", inp);
//	MergeSort(inp, "search");
//	for (int idk = 0; idk < inp.size(); idk++) {
//		for (int idk2 = 0; idk2 < inp[idk].size(); idk2++) {
//			searchfor.push_back(inp[idk][idk2].igettime());
//		}
//	}
//
//	////int cnt;
//	////for (cnt = 0; cnt < searchfor.size(); cnt++) {
//	////	std::cout << cnt << ".\t" << searchfor[cnt] << std::endl;
//	////}
//	////std::cout << "\n\n" << std::endl;
//
//	int i = 0, j, index = -1;
//	double ok;
//
//	for (j = 0; j < searchfor.size(); j++) {
//		ok = floor((double)(inp[0][0].igettime() / pow(10, 6)));
//		i = 0; index = -1;
//
//		while (ok != floor(searchfor[j] / pow(10, 6))){
//			i++;
//			ok = floor((double)(inp[i][0].igettime() / pow(10, 6)));
//		}
//		//index = BinarySearch(inp[i], 0, inp[i].size() - 1, searchfor[j]); //can also be used to make sure the other searching algorithms are also working as expexted
//		//index = BIS(inp[i], searchfor[j], 1);
//		index = BISimproved(inp[i], searchfor[j]);
//		if (index == -1) {
//			std::cout << "fuck: \t" << searchfor[j] << std::endl;
//		}
//		//else {
//		//	std::cout << "DONE: \t" << searchfor[j] << std::endl;
//		//}
//		//std::cout << j << ".\t";
//		//inp[i][index].printMeasur();
//	}
////______________________________________________________________________________________________END OF BIS DEBUG


//_______________________________________________________________________________________________________AverageTemperatures (just to make sure part2 works as expected)
	//for (int i = 0; i < inp.size(); i++) {
	//	float sum = 0;
	//	for (int j = 0; j < inp[i].size(); j++) {
	//		sum = sum + inp[i][j].gettemp();
	//	}
	//	std::cout << "Average Temperature of day: " << i << ". " << sum / inp[i].size() << std::endl;
	//}
//______________________________________________________________________________________________________AverageTemperatures END
}