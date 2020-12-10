#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
using namespace std;

// Swap function - swaps values at two specified positions
void swap(int dataArrayArg[], int position1Arg, int position2Arg) {

    int temp1;
    int temp2;

    temp1 = dataArrayArg[position1Arg];
    temp2 = dataArrayArg[position2Arg];

    dataArrayArg[position1Arg] = temp2;
    dataArrayArg[position2Arg] = temp1;
}

// BubbleSort function - uses loops to compare two items and swap
// resulting in a sorted array

void bubbleSort(int dataArrayArg[], int lengthArg) {

    int numSwaps = 1;
    int i = 0;

    while (numSwaps != 0) {
        numSwaps = 0;
        for (i = 0; i <= lengthArg-2; i++) {
            if (dataArrayArg[i] > dataArrayArg[i + 1]) {
                swap(dataArrayArg, i, i+1);
                numSwaps = numSwaps + 1;
            }
        }
    }
}

int main() {

    int numberOfDataItems;
    int index;
    string dataFileName;

//    dataFileName = "../data5.txt";
//    dataFileName = "../data1000.txt";
//    dataFileName = "../data5000.txt";
//    dataFileName = "../data10000.txt";
//    dataFileName = "../data15000.txt";
    dataFileName = "../data20000.txt";

    // Open file for input here
    // First, read the number of data items and use that to size the array
    // Then read each item into the array

    ifstream inFS;
    inFS.open(dataFileName);
    inFS >> numberOfDataItems;

    int dataArray[numberOfDataItems];

    for (index = 0; index <= numberOfDataItems; index++) {
        inFS >> dataArray[index];
    }

    inFS.close();

    // print input data
    cout << "Unsorted:" << endl;
    for (index = 0; index < numberOfDataItems; index = index + 1) {
        cout << dataArray[index] << '\t';
    }
    cout << endl;

    clock_t start_bubbleSort = clock();

    // sort array using bubbleSort
    bubbleSort(dataArray, numberOfDataItems);

    clock_t end_bubbleSort = clock();

    // verify it is sorted with a unit test
    for (index = 0; index < numberOfDataItems - 1; index = index + 1) {
        assert(dataArray[index] <= dataArray[index+1]);
    }

    cout << "Sorted:" << endl;
    for (index = 0; index < numberOfDataItems; index = index + 1) {
        cout << dataArray[index] << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort into file "bubble.txt"
    ofstream outFS;
    outFS.open("Bubble.txt");
    outFS << (numberOfDataItems) << endl;

    for (index = 0; index < numberOfDataItems; index++) {
        outFS << dataArray[index] << endl;
    }

    outFS.close();

    // print elapsed time  bubbleSort
    double elapsedTime_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;
    cout << "Time for bubble sort with N = " << numberOfDataItems << ": " << elapsedTime_bubbleSort << endl;

    return 0;
}