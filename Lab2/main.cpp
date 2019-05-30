#include "IntList.h"
#include <iostream>

using namespace std;

int main(){
    cout <<"Testing Doubly Linked List" << endl;

    cout << "Enter Number " << endl;
    int number;
    cin >> number ;
    cout << endl;
   
   if(number == 1) {
   cout <<"Testing push back on empty list" << endl;
   IntList newList;

   newList.push_back(15);
   cout << newList << endl << endl;
    
   cout << "should have output 15 above" << endl;
    

    
    cout << "push front on IntList with 19, 18, and 18" << endl;
    newList.push_front(19);
    newList.push_front(18);
    newList.push_front(18);

    cout << newList << endl;

    cout << endl << "should have 18,18,19,15" << endl;
    
   } 
 else if(number == 2) {
   cout <<"Testing push back" << endl;
   IntList newList;

   newList.push_back(15);
   cout << newList << endl;
    
   cout << "should have output 15 above" << endl;
    

    
    cout << "push front on IntList with 19, 18, and 18" << endl;
    newList.push_front(19);
    newList.push_front(18);
    newList.push_front(18);

    cout << newList << endl;

    cout << endl << "should have 18,18,19,15" << endl << endl;;

    cout << endl << "Now testing pop front " << endl;
    newList.pop_front();

    cout << "Should now have 18,19,15" << endl << endl;

    cout << "Now testing pop back" << endl;
    newList.pop_back();

    cout << "should have 18,19" << endl;

    cout << newList << endl;
    
   } 


     else if(number == 3) {
   cout <<"Testing push back" << endl;
   IntList newList;

   newList.push_back(15);
   cout << newList << endl;
    
   cout << "should have output 15 above" << endl;
    

    
    cout << "push front on IntList with 19, 18, and 18" << endl;
    newList.push_front(19);
    newList.push_front(18);
    newList.push_front(18);

    cout << newList << endl;

    cout << endl << "should have 18,18,19,15" << endl << endl;;

    cout << endl << "Now testing pop front " << endl;
    newList.pop_front();

    cout << "Should now have 18,19,15" << endl << endl;
    cout << newList << endl;

    cout << "Now testing pop back" << endl;
    newList.pop_back();

    cout << "should have 18,19" << endl;

    cout << newList << endl;

    cout << "push front values 3, 2  and 1" << endl;
    newList.push_front(3);
    newList.push_front(2);
    newList.push_front(1);

    cout << "should now have 1, 2, 3, 18, 19" << endl;
    cout << newList << endl;
    cout << "now reversing the list" << endl;
    cout << "should have 19, 18, 3, 2, 1" << endl;

    newList.printReverse();

    cout << endl;
    
   } 

    
    



    return 0;
}