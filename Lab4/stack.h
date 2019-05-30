#ifndef _STACK_H
#define _STACK_H

#include <stdexcept>
#include <iostream>
using namespace std;

#define MAX_SIZE 20

template<typename T>
class stack{
    
    private:
        
        T data[MAX_SIZE];

        int size;
    
    public:

        stack(){
           size = 0;
        }

   void push(T val){
    try{  
        if(size == MAX_SIZE){
            throw overflow_error("std::overflow_error");
        }
        
    }
    catch( overflow_error & excpt ){
        cout << "Called push on full stack.";
    }

    if(size == 0){
    
        data[size] = val;
        size = size + 1;
        
    }
    else
    {
        data[size] = val;
        size = size + 1;
    }
    
    }

    void pop(){
        try {
            if(size == 0){
                throw out_of_range("std::outofrange");
             }
        }
        catch( out_of_range  & excpt ){
            cout << "Called pop on empty stack.";
        }

         size = size -1;
    }
    T top(){
      
        try{
            if(size == 0){
                throw underflow_error("std::underflow_error");
            }
           
           
        }
        catch( underflow_error& excpt ){
            cout << "Called top on empty stack." << endl;
            exit(1);
        }
    return data[size -1];
    }

    bool empty(){
        if(size == 0){
            return true;
        }
    return false;
    }

};

#endif