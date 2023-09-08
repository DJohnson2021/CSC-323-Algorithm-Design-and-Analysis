#include <iostream>
#include <fstream>

#include <string>
#include <cstring> // for string tokenizer and c-style string processing

using namespace std;

int main(){

	string coinInfoFilename;
	cout << "Enter filename: ";
	cin >> coinInfoFilename;
	
	int numCoinValues;
	cout << "Enter the number of coin values: ";
	cin >> numCoinValues;
		
	int TargetSumValue;
	cout << "Enter the target sum of the coin values: ";
	cin >> TargetSumValue;
		
	int* CoinValues = new int[numCoinValues+1];  // the + 1 is to account for coin indexex 0 with a value of $0
	int* MinNumCoins = new int[TargetSumValue+1]; // the + 1 is to account for indexex 0 with a value of $0
	int* LastCoinPicked = new int[TargetSumValue+1]; // the + 1 is to account for indexex 0 with an invalid value of -1

	CoinValues[0] = 0;
	MinNumCoins[0] = 0;
	LastCoinPicked[0] = -1;
		
		
	ifstream coinInfoFileReader(coinInfoFilename);
	
	if (!coinInfoFileReader){
		cout << "File cannot be opened!! ";
		return 0;
	}

	int numCharsPerLine = 25;
	
	char *line = new char[numCharsPerLine];	
	// '25' is the maximum number of characters per line
	
	coinInfoFileReader.getline(line, numCharsPerLine, '\n');	
	// '\n' is the delimiting character to stop reading the line

	
	
	while (coinInfoFileReader){
			
		char* cptr = strtok(line, " \t");
		
		string coinindexexToken(cptr);
		int coinindexex = stoi(coinindexexToken);

		cptr = strtok(NULL, " \t");
		
		string coinValueToken(cptr);
		int coinValue = stoi(coinValueToken);

		CoinValues[coinindexex] = coinValue;
		
		coinInfoFileReader.getline(line, numCharsPerLine, '\n');	
		
	}


	// Implement the algorithm here and the print the output as shown in the sample screenshot
	
	// Initialize dynamic programming matrix
	int dpMatrix[TargetSumValue + 1][numCoinValues + 1];
	
	for(int sum = 1; sum <= TargetSumValue; sum++){
	    if(sum % CoinValues[1] == 0){
	        dpMatrix[sum][1] = sum / CoinValues[1];
	        LastCoinPicked[sum] = CoinValues[1];
	    }
	    else{
	        dpMatrix[sum][1] = sum + 1;
	    }
	}
	
	// Set all elements in first row to 0
	for(int i = 0; i <= numCoinValues; i++){
	    dpMatrix[0][i] = 0;
	}
	
	for(int sum = 1; sum <= TargetSumValue; sum++){
	    for(int index = 2; index <= numCoinValues; index++){
	        if(sum < CoinValues[index]){
	            dpMatrix[sum][index] = dpMatrix[sum][index - 1];
	        }
	        else{
	            if(1 + dpMatrix[sum - CoinValues[index]][index] < dpMatrix[sum][index - 1]){
	                LastCoinPicked[sum] = CoinValues[index];
	            }
	            
	            dpMatrix[sum][index] = min(dpMatrix[sum][index - 1], 1 + dpMatrix[sum-CoinValues[index]][index]);
	        }
	    }
	    
	    MinNumCoins[sum] = dpMatrix[sum][numCoinValues];
	}
	
	// Print sum list
	cout << "Sum\t";
	
	for(int i = 1; i <= TargetSumValue; i++){
	    cout << i << ' ';
	}
	
	cout << endl;

    // Print minimum number of coins
    cout << "MNC\t";

    for(int i = 1; i <= TargetSumValue; i++){
        cout << MinNumCoins[i] << ' ';
    }
    
    cout << endl;

    // Print last coin pickup
    cout << "LCP\t";
    
    for(int i = 1; i <= TargetSumValue; i++){
        cout << LastCoinPicked[i] << ' ';
    }
    
    cout << endl;

    cout << "Coins to be picked for target sum " << TargetSumValue << endl;

    int sum = TargetSumValue;
    
    // Print the minimum number of coins needed to satisfy the TargetSumValue
    while(sum){
        cout << LastCoinPicked[sum] << ' ';
        sum -= LastCoinPicked[sum];
    }
    
    cout << endl;
	
	
	system("pause");
	
    return 0;
}

