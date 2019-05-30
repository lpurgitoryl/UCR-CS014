#include "Heap.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;


Heap::Heap(): numItems(0){
}

void Heap::enqueue(PrintJob* newJob){

     if(numItems == 0){
        arr[0] = newJob;
        numItems = 1;
        return;
        }
    else if(numItems == 1){
        numItems += 1;
        arr[numItems - 1] = newJob;
        if(arr[0]->getPriority() < arr[1]->getPriority() ){
            swap(arr[0], arr[1]);
        }
        return;
    }
    
    else if(numItems < MAX_HEAP_SIZE){
        //start of insert algo

        numItems += 1;
        arr[numItems - 1 ] = newJob;
        int tempNodeCount = numItems;
        while ( tempNodeCount > 0)
        {
            int innerParent =  (tempNodeCount  - 1) /2;
            if(arr[innerParent]->getPriority() < arr[tempNodeCount - 1]->getPriority()){
                    swap(arr[innerParent], arr[tempNodeCount - 1] );
            }
            tempNodeCount -=1;
            
        }
        
    }
    
}

PrintJob* Heap::highest(){
    if(numItems == 0){
        return nullptr;
    }
    return arr[0];
}

void Heap::dequeue(){
    if(numItems == 0){
        return;
    }
    
    if(numItems == 1){
        numItems = 0;
        return;
    }
    else if(numItems == 2){
       swap(arr[0], arr[1]);
       numItems -= 1;
       return;
    }
    swap(arr[0], arr[numItems - 1]);
    numItems -= 1;
    
    trickleDown(0);


}

void Heap::trickleDown(int index){//items
    int left = (2 * index) + 1;
    int right = left + 1;

    if( left < numItems && right < numItems){
        if( arr[left]->getPriority() > arr[right]->getPriority()){
            swap(arr[index], arr[left]);
            trickleDown(left);
        }
        else if(arr[right]->getPriority() > arr[left]->getPriority()){
            swap(arr[index], arr[right]);
            trickleDown(right);
        }
    }
    else if( left < numItems ){
        if(arr[left]->getPriority() > arr[index]->getPriority()){
            swap(arr[index], arr[left]);
        }
    }

    return;

    
}


void Heap::print(){
    if(numItems == 0){
        return;
    }
        cout << "Priority: " << arr[0]->getPriority() <<
        ", Job Number: " << arr[0]->getJobNumber() << 
        ", Number of Pages: " << arr[0]->getPages() << endl;
        
}
