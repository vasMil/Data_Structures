#Variables of the Makefile. There are conventions for the variable names
CC=g++

#-c for compilation, -Wall for warnings
CFLAGS=-c -Wall

all: part1

part1: main.o Menu.o AverageTimes.o BinarySearch.o BIS_improved.o BIS_standard.o check.o CountingSort.o HeapSort.o HelpOnSearch.o HelpOnSorting.o inputValues.o interpolationSearch.o MergeSort.o printVec.o quicksort.o transfer.o
	$(CC) main.o Menu.o AverageTimes.o BinarySearch.o BIS_improved.o BIS_standard.o check.o CountingSort.o HeapSort.o HelpOnSearch.o HelpOnSorting.o inputValues.o interpolationSearch.o MergeSort.o printVec.o quicksort.o transfer.o -o part1.exe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Menu.o: Menu.cpp
	$(CC) $(CFLAGS) Menu.cpp

AverageTimes.o: AverageTimes.cpp
	$(CC) $(CFLAGS) AverageTimes.cpp

BinarySearch.o: BinarySearch.cpp
	$(CC) $(CFLAGS) BinarySearch.cpp

BIS_improved.o: BIS_improved.cpp
	$(CC) $(CFLAGS) BIS_improved.cpp

BIS_standard.o: BIS_standard.cpp
	$(CC) $(CFLAGS) BIS_standard.cpp

check.o: check.cpp
	$(CC) $(CFLAGS) check.cpp

CountingSort.o: CountingSort.cpp
	$(CC) $(CFLAGS) CountingSort.cpp

HeapSort.o: HeapSort.cpp
	$(CC) $(CFLAGS) HeapSort.cpp

HelpOnSearch.o: HelpOnSearch.cpp
	$(CC) $(CFLAGS) HelpOnSearch.cpp

HelpOnSorting.o: HelpOnSorting.cpp
	$(CC) $(CFLAGS) HelpOnSorting.cpp

inputValues.o: inputValues.cpp
	$(CC) $(CFLAGS) inputValues.cpp

interpolationSearch.o: interpolationSearch.cpp
	$(CC) $(CFLAGS) interpolationSearch.cpp

MergeSort.o: MergeSort.cpp
	$(CC) $(CFLAGS) MergeSort.cpp

printVec.o: printVec.cpp
	$(CC) $(CFLAGS) printVec.cpp

quicksort.o: quicksort.cpp
	$(CC) $(CFLAGS) quicksort.cpp

transfer.o: transfer.cpp
	$(CC) $(CFLAGS) transfer.cpp

clean:
	rm -rf *.o part1.exe 