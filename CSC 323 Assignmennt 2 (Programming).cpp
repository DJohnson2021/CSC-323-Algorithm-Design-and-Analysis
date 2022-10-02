#include <iostream>
#include <ctime>
#include <ratio>

#include <stdlib.h>
#include <time.h>

int main(){

	
	using namespace std;

  
	int numElements;
	cout << "Enter the number of elements: ";
	cin >> numElements;

	int maxValue;
	cout << "Enter the maximum value: ";
	cin >> maxValue;
	
	srand(time(NULL));
	

	int *array = new int[numElements];
	
	for (int index = 0; index < numElements; index++){
		array[index] = 1 + (rand() % maxValue);
		cout << array[index] << " ";
	}

	cout << endl;
	
	
	 /* Implement here your algorithm to determine the largest and second largest integers of the array and print their values
	 */

	int max = array[0];
  int second_max = array[1];
  
  if (second_max > max)
  {
    max = array[1];
    second_max = array[0];
  }
  
  for(int index = 2; index < numElements; index++)
  {
    if (array[index] > max)
    {
      second_max = max;
      max = array[index];
    }

    else if (array[index] > second_max && array[index] < max)
    {
      second_max = array[index];
    }

    if (max == second_max && array[index] < max)
    {
      second_max = array[index];
    }
  }

  cout << "Maximum: " << max << endl;
  cout << "Second Maximum: " << second_max << endl;
	
	delete[] array;
	
	system("pause");

return 0;
}