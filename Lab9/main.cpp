#include <iostream>
#include <ctime>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize);

int main (){
    int set1[NUMBERS_SIZE];
    int set2[NUMBERS_SIZE];
    int set3[NUMBERS_SIZE];

    fillArrays(set1, set2, set3);
    clock_t Start = clock();
    //call sort function here
    Quicksort_midpoint(set1, 0, NUMBERS_SIZE - 1);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    
    cout << "It took " << elapsedTime << " for the Quick_Sort_midpoint on set1 " << endl; 


return 0;

}

int Partition (int arr[], int i, int k){
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    //calculates middles element
    // i is starting index of arr, k is last index of the arr 
    midpoint = i + ( k - i) / 2 ;
    pivot = arr[midpoint];

    l = i;
    h = k;

    while (!done){
        while (arr [l] < pivot){
            ++l;
        }

        while (pivot < arr[h]){
            --h;
        }

        if ( l >= h){
            done = true;
        }

        else {
            temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;

            ++l;
            --h;
        }
       
    }

     return h;
}

void Quicksort_midpoint(int numbers[], int i, int k){
   int j = 0;

   if ( i >= k){
       return;
   } 

   j = Partition(numbers, i, k);

   Quicksort_midpoint(numbers, i , j);
   Quicksort_midpoint(numbers, j + 1, k );
}


