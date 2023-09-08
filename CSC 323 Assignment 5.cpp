#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>


#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;


int main(){

    using namespace std::chrono;
	
    srand(time(NULL));
    
    int arraySize;
    cout << "Enter an array size: ";
    cin >> arraySize;
    
    int maxValue;
    cout << "Enter max. value: ";
    cin >> maxValue;
       
    int *arrayPtr = new int[arraySize];
    
    // prints the input array as it gets filled up
    cout << "Input array: ";
    for (int index = 0; index < arraySize; index++){
    	arrayPtr[index] = 1 + ( rand() % maxValue);
    	cout << arrayPtr[index] << " ";
    }
    
    cout << endl; 
    
    
    // Begin the code for a sorting algorithm
    // Choose either Insertion sort, Bubble sort or Merge sort
    
    int numComparisonsSorting = 0;
    
    // # 1: Implement your sorting algorithm here and 
    // get the array (pointed to by arrayPtr) to be sorted
    // Also, use the numComparisonsSorting variable to keep track 
    // of the number of comparisons encountered by the sorting algorithm
    
    // Insertion Sort Implementation
    
    int v, j;
    for (int i = 1; i < arraySize; i++){
      v = arrayPtr[i];
      j = i - 1;
      while (j >= 0){
        numComparisonsSorting++;
        if (arrayPtr[j] > v){
          arrayPtr[j + 1] = arrayPtr[j];
        }
        else{
          break;
        }
        j = j - 1;
      }
      arrayPtr[j + 1] = v;
    }
    
    // End of the sorting algorithm code
    
    // printing the sorted array
    cout <<  "Sorted array: ";
    for (int i = 0; i < arraySize; i++)
    	cout << arrayPtr[i] << " ";
    cout << endl;
    
    
    // Look at the printed sorted array and enter an appropriate search key	
    cout << "Enter a search key: ";
    int searchKey;
    cin >> searchKey;
    	
    	
    int numComparisonsBinarySearch = 0;	
    // Keep track of the number of comparisons involved in the binary search 
    // through the variable numComparisonsBinarySearch
    
    
    int resultFirstOccurrence = -1; // to store the index of first occurrence
    								// determined by the binary search algorithm
    
    int resultLastOccurrence = -1;  // to store the index of last occurrence 
    								// determined by the binary search algorithm
    	
    // #2: Begin binary search code to find the index of first occurrence
    int leftIndex = 0;
    int rightIndex = arraySize - 1;
    
    while(leftIndex <= rightIndex){
        
        int middleIndex = (leftIndex + rightIndex) / 2;
        
        numComparisonsBinarySearch++;
        if (arrayPtr[middleIndex] < searchKey){
            leftIndex = middleIndex + 1;
        }
        else{
            numComparisonsBinarySearch++;
            if (arrayPtr[middleIndex] > searchKey){
                rightIndex = middleIndex - 1;
                numComparisonsBinarySearch++;
            }
            else{
                resultFirstOccurrence = middleIndex;
                rightIndex = middleIndex - 1;
            }
        }
    }
    
    
    // End binary search code to find the index of first occurrence 
    
    if (resultFirstOccurrence == -1){
    		cout << searchKey << " is not there " << endl;
    		cout << "# comparisons for sorting: " << numComparisonsSorting << endl;
    		cout << "# comparisons for binary search: " << numComparisonsBinarySearch << endl;
    		system("pause");
    	return 0;
    }
    
    
    
    // #3: Begin binary search code to find the index of last occurrence
    
    // It is necessary to reassign the values of leftIndex and rightIndex because their
    // values were changed while finding the first index of occurrence
    leftIndex = 0;
    rightIndex = arraySize - 1;
    
    while(leftIndex <= rightIndex){
        
        int middleIndex = (leftIndex + rightIndex) / 2;
        
        numComparisonsBinarySearch++;
        if (arrayPtr[middleIndex] < searchKey){
            leftIndex = middleIndex + 1;
        }
        else{
            numComparisonsBinarySearch++;
            if (arrayPtr[middleIndex] > searchKey){
                rightIndex = middleIndex - 1;
                numComparisonsBinarySearch++;
            }
            else{
                resultLastOccurrence = middleIndex;
                leftIndex = middleIndex + 1;
            }
        }
    }
    
    cout << "Index of First occurrence: " << resultFirstOccurrence << endl;
    cout << "Index of Last occurrence: " << resultLastOccurrence << endl;
    
    
    // End binary search code to find the index of last occurrence
    
    cout << "# occurrences of " << searchKey << " is: " << (resultLastOccurrence - resultFirstOccurrence + 1) << endl; 
    
    
    cout << "# comparisons for sorting: " << numComparisonsSorting << endl;
    cout << "# comparisons for binary search: " << numComparisonsBinarySearch << endl;
    
    
    system("pause");
    
    return 0;
}


