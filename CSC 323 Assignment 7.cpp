#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>


using namespace std;

int main(){
	
	string rowSequence;
	cout << "Enter the rowSequence: ";
	cin >> rowSequence;
	
	string columnSequence;
	cout << "Enter the columnSequence: ";
	cin >> columnSequence;
	
	int numRows = rowSequence.length()+1;
	int numCols = columnSequence.length()+1;

	
	int** twoDimTable = new int*[numRows];
	for (int rowIndex = 0; rowIndex < numRows; rowIndex++){
		twoDimTable[rowIndex] = new int[numCols];
	}
	
	
	/* Implement the LCS algorithm below and print the contents of the two dimensional
	table at the end of the algorithm, the longest common sub sequence and its length */
	
	
	// Set the entire first row and column to zero
	for (int i = 0; i < numRows; i++){
	    for (int j = 0; j < numCols; j++){
	        if (i == 0 || j == 0){
	            twoDimTable[i][j] = 0;
	        }
	    }
	}
	
	
    // Actual algorithm
	for (int i = 1; i < numRows; i++){
	    for (int j = 1; j < numCols; j++){
	        // Check if the characters in the strings match
	        if (rowSequence[i - 1] == columnSequence[j - 1]){
	            // Increase the predicted length of the lcs
	            twoDimTable[i][j] = twoDimTable[i - 1][j - 1] + 1;
	        }
	        else if (twoDimTable[i - 1][j] >= twoDimTable[i][j - 1]){
	            twoDimTable[i][j] = twoDimTable[i - 1][j];
	        }
	        else{
	            twoDimTable[i][j] = twoDimTable[i][j - 1];
	        }
	    }
	}
	
	string lcs = "";
	string lcs2 = "";
	
	int i = numRows - 1; 
	int j = numCols - 1;
	
	while (i > 0 && j > 0){
	    if (rowSequence[i - 1] == columnSequence[j - 1]){
	        lcs += rowSequence[i - 1];
	        i--;
	        j--;
	    }
	    else if (twoDimTable[i - 1][j] >= twoDimTable[i][j - 1]){
	        i--;
	    }
	    else{
	        j--;
	    }
	}
	
	
	i = numRows - 1; 
	j = numCols - 1;
	
	while (i > 0 && j > 0){
	    if (rowSequence[i - 1] == columnSequence[j - 1]){
	        lcs2 += rowSequence[i - 1];
	        i--;
	        j--;
	    }
	    else if (twoDimTable[i - 1][j] > twoDimTable[i][j - 1]){
	        i--;
	    }
	    else{
	        j--;
	    }
	}
	
	reverse(lcs.begin(), lcs.end());
	reverse(lcs2.begin(), lcs2.end());
	
	cout << "Row Sequence: " << rowSequence << endl;
	cout << "Column Sequence: " << columnSequence << endl;
	
	for (int i = 0; i < numRows; i++){
	    for (int j = 0; j < numCols; j++){
	        cout << twoDimTable[i][j] << " ";
	    }
	    cout << endl;
	}
	
	
	if (lcs.length() == lcs2.length()){
	    if (lcs == lcs2){
	         cout << "There is 1 Longest Common Subsequence: " << lcs << endl;
	    }
	    else{
	        cout << "There are 2 Longest Common Subsequences!" << endl;
	        cout << "LCS1: " << lcs << endl;
	        cout << "LCS2: " << lcs2 << endl;
	    }
	}
	else if (lcs.length() > lcs2.length()){
	    cout << "There is 1 Longest Common Subsequence: " << lcs << endl;
	}
	else{
	    cout << "There is 1 Longest Common Subsequence: " << lcs2 << endl;
	}
	
	system("pause");
	
	return 0;
	
}

