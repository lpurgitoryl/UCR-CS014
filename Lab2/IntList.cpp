#include "IntList.h"


IntList::IntList(){
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->next = dummyTail;
    dummyHead->prev = nullptr;
    dummyTail->next = nullptr;
    dummyTail->prev = dummyHead; 
}

IntList::~IntList(){
    IntNode* curr = dummyHead;
     cout << "decon" << endl;
    
    while( curr != nullptr){
        IntNode* tmp = curr->next;
        delete curr;
        curr = tmp;
    }
}

void IntList::push_front(int value){
    IntNode* newNode = new IntNode(value);

    if( dummyTail->prev == dummyHead && dummyHead->next == dummyTail ){
        dummyHead->next = newNode;
        dummyTail->prev = newNode;

        newNode->next = dummyTail;
        newNode->prev = dummyHead;

        return;
    }
    else{
         IntNode* headNextNode = dummyHead->next;
         headNextNode->prev = newNode;
         dummyHead->next = newNode;

         newNode->next = headNextNode;
         newNode->prev = dummyHead;

         return;
    }
    
}
bool IntList::empty() const{
    if( dummyHead->next == dummyTail && dummyTail->prev == dummyHead){
        return true;
    }

    return false;  
}
// void pop_front(): Removes the node at the front end of the list (the node after the dummy head). 
// Does nothing if the list is already empty. This must be an O(1) operation.
void IntList::pop_front(){
   //list of one //list of two //etc

   if( empty() == true){
       return;
   }
   else{
        IntNode* headNextNode = dummyHead->next;
        IntNode* headNextNextNode = dummyHead->next->next;

        dummyHead->next = headNextNextNode;
        headNextNextNode->prev = dummyHead;

        delete headNextNode;
   }
}
void IntList::pop_back(){
    if( empty() == true){
        return;
    }
    else{
        IntNode* tailPrev = dummyTail->prev;
        IntNode* tailPrevPrev = tailPrev->prev; 

        tailPrevPrev->next = dummyTail;
        dummyTail->prev = tailPrevPrev;

        delete tailPrev;
   }
}
void IntList::push_back(int value){
    //dont need to check if emptybc it will add new node anyway
    IntNode* newNode = new IntNode(value);
    IntNode* tailPrev = dummyTail->prev;

    tailPrev->next = newNode;
    dummyTail->prev = newNode;

    newNode->next = dummyTail;
    newNode->prev =tailPrev;

    return;  

}

ostream &operator<<(ostream & out, const IntList & rhs){
    if( rhs.empty() == true){
        return out;
    }

      for(  IntNode* curr = rhs.dummyHead->next ; curr != rhs.dummyTail ; curr = curr->next ){
            if(curr->next == rhs.dummyTail){
            out << curr->data;
            return out;
            }
            
            out << curr->data << " ";
        } 


    return out;
}

void IntList::printReverse() const{
    IntNode* curr;

    if(empty() == true){
        return;
    }
   
 for( curr = dummyTail->prev ;  (curr != dummyHead->next) ; curr = curr->prev ){
    cout << curr->data  << " ";
          
    } 

    cout << dummyHead->next->data;
}