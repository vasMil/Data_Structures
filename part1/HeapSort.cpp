#include "myHeader.h"
#include "inputValues.h"




void Heapify(std::vector<inputValues>& vheap, int i, int sz) {

	int p = i;                   //parent
	int lc = 2 * i + 1;          //left child                                      
	int rc = 2 * i + 2;          //right child                                        

	if (lc < sz && vheap[lc].gettemp() > vheap[p].gettemp()) {
		p = lc;
	}
	if (rc < sz && vheap[rc].gettemp() > vheap[p].gettemp()) {
		p = rc;
	}
	if (p != i) {
		swapValues(&vheap[p], &vheap[i]);
		Heapify(vheap, p, sz);
	}
}



void BuildMaxHeap(std::vector<inputValues>& vecth) {

	for (int b = (vecth.size() / 2) - 1; b >= 0; b--) {
		Heapify(vecth, b, vecth.size());
	}
}

void Heapsort(std::vector<inputValues>& heapvec) {
	//int vecsize = heapvec.size();

	BuildMaxHeap(heapvec);
	int vecsize = heapvec.size();
	for (int c = heapvec.size() - 1; c > 0; c--) {

		swapValues(&heapvec[0], &heapvec[c]);
		vecsize--;
		Heapify(heapvec, 0, vecsize);
	}
}


void Heapsort(std::vector<std::vector<inputValues> >& hvec, int day) {
	if (day == -1) {
		unsigned int row;
		for (row = 0; row < hvec.size(); row++) {
			Heapsort(hvec[row]);
		}
	}
	else {
		Heapsort(hvec[day]);
	}
}

