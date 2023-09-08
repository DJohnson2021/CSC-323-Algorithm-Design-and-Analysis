#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>//clock_t, clock, CLOCKS_PER_SEC

using namespace std;

void SortBasedOnFinishTimes(int* activityIDs, int* startTimes, int* finishTimes, int numActivities){
	
	// Implement a sorting algorithm of your choice to sort the array pointed by
	// finishTimes.
	
	/* Note that at the end of the sorting process, the contents in the arrays representing the activity IDs and the start times should be also rearranged to correspond to the sorted order of the finish times
	*/
	
	// I used bubble sort because of how easy it is to implement
	
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	
	for(int i = 0; i < numActivities - 1; i++){
	    for(int j = 0; j < numActivities - i - 1; j++){
	        if(finishTimes[j] > finishTimes[j + 1]){
	            
	            temp1 = finishTimes[j];
	            finishTimes[j] = finishTimes[j + 1];
	            finishTimes[j + 1] = temp1;
	            
	            temp2 = startTimes[j];
	            startTimes[j] = startTimes[j + 1];
	            startTimes[j + 1] = temp2;
	            
	            temp3 = activityIDs[j];
	            activityIDs[j] = activityIDs[j + 1];
	            activityIDs[j + 1] = temp3;
	        }
	    }
	}
}



void PrintArray(int* array, int arraySize){
	
	for (int index = 0; index < arraySize; index++){
		
		cout << array[index] << "\t";
	}
	
	cout << endl;
	
	
}


int main(){
	
	int numActivities;
	cout << "Enter the number of activities: ";
	cin >> numActivities;
	
	srand(time(NULL));
	
	int *activityIDs = new int[numActivities];
	int *startTimes = new int[numActivities];
	int *finishTimes = new int[numActivities];
	
	int maxDiffSuccessiveStartTime = 3;
	int maxActivityDuration = 6;
	
	startTimes[0] = 1;
	
	for (int index = 0; index < numActivities; index++){
		
		activityIDs[index] = index+1;
		
		if (index > 0)
			startTimes[index] = startTimes[index-1] + 1 + (rand() % maxDiffSuccessiveStartTime);
		
		finishTimes[index] = startTimes[index] + 1 + (rand() % maxActivityDuration);
		
	}
	
	cout << "Before sorting: " << endl;	
	cout << "Activities and their start/finish times " << endl;
	PrintArray(activityIDs, numActivities);
	PrintArray(startTimes, numActivities);
	PrintArray(finishTimes, numActivities);
	

	
	SortBasedOnFinishTimes(activityIDs, startTimes, finishTimes, numActivities);
	
	cout << "After sorting: " << endl;
	cout << "Activities and their start/finish times " << endl;
	PrintArray(activityIDs, numActivities);
	PrintArray(startTimes, numActivities);
	PrintArray(finishTimes, numActivities);


	cout << endl;
	
	
	
	/* Implement here the greedy algorithm to determine the sequence of non-overlapping activities in the increasing order of their finish times.
	*/
	
	// All activities whose start times are less than or equal to that of the current finish time are ruled out from consideration.
	// The next activity chosen is the activity (from the sorted list based on finish times) whose start time is greater than the current finish time.
    // Based on this line from the assignment prompt, the if condition should check for > not >=
    
    // Variable to record the current finish times
	int current_finish_time = 0;
	
	cout << "Selected Activities: ";
	
	// The first activity was chosen in both examples in the assignment prompt
	cout << activityIDs[0] << " ";
	
	// Very simple logic
	// While traversing through the startTimes array check if the finish time of the currently selected activity is less than 
	// the start times of the next activity
	// If so, move the current finish time to the right at that array index.
	// Similar to binary search, there is no need to create a entire new array to hold the selected Activities
	// It is simpler to move the index and print out the selected Activities as the loop runs
	
	for(int index = 1; index < numActivities; index++){
	    if(startTimes[index] > finishTimes[current_finish_time]) {
	        
	        current_finish_time = index;
	        cout << activityIDs[index] << " " ;
	    }
	}
	
	system("pause");
	
	return 0;
	
}
