#include <iostream>
using namespace std;

// #include "solution.h"
// int countWaysToMakeChangeHelper(int denominations[], int numDenominations, int value,int& count){
// 	//Write your code here
// 	if (value==0){
// 		return 1;
// 	}
// 	if(value<0){
// 		return 0;
// 	}
// 	for(int i=0;i<numDenominations;i++){
// 		count=count+countWaysToMakeChangeHelper(denominations+i, numDenominations, value-denominations[i], count)+countWaysToMakeChangeHelper(denominations+i, numDenominations, value, count);
// 	}
// 	return count;
// }
// int countWaysToMakeChangeH(int denominations[], int numDenominations, int value,int** arr){
// 	if (value == 0) {
//         return 1;
//     }
//     if (value < 0 || numDenominations <= 0) {
//         return 0;
//     }
//     if(arr[value][numDenominations]!=-1){
//         return arr[value][numDenominations];
//     }
//     // Recursive call including current denomination and excluding it
//     int including = countWaysToMakeChangeH(denominations, numDenominations, value - denominations[numDenominations - 1],arr);
//     int excluding = countWaysToMakeChangeH(denominations, numDenominations - 1, value,arr);
    
//     arr[value][numDenominations]=including + excluding;
//     return arr[value][numDenominations];
// }
// int countWaysToMakeChange(int denominations[], int numDenominations, int value){
//     int*arr=new int[value+1];
//     for(int i=0;i<value+1;i++){
//         arr[i]=new int[numDenominations+1];
//     }
//     for(int i=0;i<value+1;i++){
//         for(int j=0;j<numDenominations+1;j++){
//             arr[i][j]=-1;
//         }
//     }
//     return countWaysToMakeChangeH(denominations, numDenominations, value, arr);
// }
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int** arr = new int*[value + 1];
    for(int i = 0; i < value + 1; i++){
        arr[i] = new int[numDenominations + 1];
    }
    for(int j = 0; j < numDenominations + 1; j++){
        arr[0][j] = 1;
    }
    for(int i = 1; i < value + 1; i++){
        for(int j = 1; j < numDenominations + 1; j++){
            int including = (i - denominations[j - 1] >= 0) ? arr[i - denominations[j - 1]][j] : 0;
            int excluding = arr[i][j - 1];
            int ans = including + excluding;
            arr[i][j] = ans;
        }
    }
    return arr[value][numDenominations];
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}