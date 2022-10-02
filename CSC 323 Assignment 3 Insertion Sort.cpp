#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>

#include <stdlib.h>
#include <time.h>

int main() {

  using namespace std;

  int numElements;
  cout << "Enter the number of elements: ";
  cin >> numElements;

  int maxValue;
  cout << "Enter the maximum value: ";
  cin >> maxValue;

  srand(static_cast<unsigned int>(time(nullptr)));

  int numTrials = 10;
  int totalComparisons = 0;

  for (int trials = 1; trials <= numTrials; trials++) {

    int *array = new int[numElements];

    for (int index = 0; index < numElements; index++) {
      array[index] = 1 + (rand() % maxValue);
    }
    
    // start your code for the sorting algorithm
    int v, j;
    int numComparisons = 0;
    for (int i = 1; i < numElements; i++){
      v = array[i];
      j = i - 1;
      while (j >= 0){
        numComparisons++;
        if (array[j] > v){
          array[j + 1] = array[j];
        }
        else{
          break;
        }
        j = j - 1;
      }
      array[j + 1] = v;
    }
    
    /*
    for(int i = 0; i < numElements; i++){
        if (i % 10 == 0){
            cout <<endl;
        }
        cout << array[i] << " ";
    }
    */

    totalComparisons += numComparisons;
    
    // end your code for the sorting algorithm

    delete[] array;

  } // end trials loop

  // print the average number of comparisons per trial
  
  double avgComparisons = (((double) totalComparisons)/numTrials);
  cout << endl;
  cout << "Average Number of Comparisons: " << avgComparisons << endl;

  system("pause");

  return 0;
}


