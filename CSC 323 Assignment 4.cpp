#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>


#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;


// Implement here the DivideByHalf algorithm

int DivideByHalf(int* arrayPtr, int leftIndex, int rightIndex){
    
    // Terminating Condition
    if (leftIndex == rightIndex){
        return leftIndex;
    }
    
    // Find middle index
    int middleIndex = (leftIndex + rightIndex) / 2;
    
    int leftMinIndex = DivideByHalf(arrayPtr, leftIndex, middleIndex); // Find the minimum left index
    int rightMinIndex = DivideByHalf(arrayPtr, middleIndex + 1, rightIndex); // Find the minimum right index
    
    if (arrayPtr[leftMinIndex] < arrayPtr[rightMinIndex]){
        return leftMinIndex;
    }
    else{
        return rightMinIndex;
    }
}

// Implement here the DecreaseByOne algorithm

int DecreaseByOne(int* arrayPtr, int size){
    
    int minIndex = 0;
    
    // Terminating Condition
    if (size == 1){
        return 0;
    }
    
    // Find the minIndexExceptLast 
    int minIndexExceptLast = DecreaseByOne(arrayPtr, size - 1);
    
    if (arrayPtr[minIndexExceptLast] < arrayPtr[size - 1]){
        minIndex = minIndexExceptLast;
    }
    else{
        minIndex = size - 1;
    }
    
    return minIndex;
}


int main(){

    using namespace std::chrono;
	
    srand(time(NULL));
   
    int arraySize;
    cout << "Enter an array size: ";
    cin >> arraySize;
   
    int maxValue;
    cout << "Enter max. value: ";
    cin >> maxValue;
   
    int option;
    cout << "Enter 1 for dividing the array size by half; 2 for decreasing the array size by one" << endl;
    cin >> option;
   
    double totalTime_nano = 0;
   
    int numTrials = 1000;
   
    for (int trials = 1; trials <= numTrials; trials++){
	   
        int *arrayPtr = new int[arraySize];
   
        for (int index = 0; index < arraySize; index++)
		    arrayPtr[index] = 1 + ( rand() % maxValue);
	
	    int minValue = -1;
	
	    if (option == 1){
	
		    high_resolution_clock::time_point t1 = high_resolution_clock::now();
		
		    int minIndex = DivideByHalf(arrayPtr, 0, arraySize-1);
	   	    minValue = arrayPtr[minIndex];

		    high_resolution_clock::time_point t2 = high_resolution_clock::now();	
		    duration<double, std::nano> time_nano = t2 - t1;		
		    totalTime_nano += time_nano.count();	
		
	    }
	    else if (option == 2){
		
		    high_resolution_clock::time_point t1 = high_resolution_clock::now();

		    int minIndex = DecreaseByOne(arrayPtr, arraySize);
            minValue = arrayPtr[minIndex];

		    high_resolution_clock::time_point t2 = high_resolution_clock::now();	
		    duration<double, std::nano> time_nano = t2 - t1;		
		    totalTime_nano += time_nano.count();	
		
	    }
	    else{
		
		    cout << "Invalid option " ;
		    return 0;
		
	    }
	

	
	    // cout << "Min. element is: " << minValue << endl;

		
	    delete[] arrayPtr;
	
	
    }// trials loop


    cout << "Option " << option << " : Average time " << (totalTime_nano/numTrials) << " nano seconds " << endl;



    system("pause");

    return 0;
}



