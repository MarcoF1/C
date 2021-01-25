#include <iostream>

using namespace std;


void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}






int main() {
    // read N and M
    int N, M;
    cin >> N >> M;
    
    // read the lists
    int unsortedLists[N][M];
    for(int i = 0; i < N; i++) {
        int num;
        int j = 0;
        while(j < M) {
            cin >> num;
            unsortedLists[i][j] = num;
            j++;
        }
    }

    // sort the lists
    for(int i = 0; i < N; i++) {
        mergeSort(unsortedLists[i], 0, M-1);
    }

    

    int sortedLists[N][M];
    
    
    int lastUsedDigit = INT_MAX;
    for(int j = 0; j < N; j++) {
        int biggestDigitSoFar = INT_MIN;
        int foundDigitIndex = 0;
        
        for(int i = 0; i < N; i++) {
            int lastDigit = unsortedLists[i][M-1];

            if(lastDigit > biggestDigitSoFar && lastDigit < lastUsedDigit) {
                biggestDigitSoFar = lastDigit;
                foundDigitIndex = i;
            }
        }
        for(int k = 0; k < M; k++) {
            sortedLists[j][k] = unsortedLists[foundDigitIndex][k]; 
        }
        lastUsedDigit = biggestDigitSoFar;
    }
    
    // print the list
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(j == 0 && i != 0) {
                cout << "\n" << sortedLists[i][j] << " ";
            }
            else {
                cout << sortedLists[i][j] << " ";
            }
            
        }
    }

}



