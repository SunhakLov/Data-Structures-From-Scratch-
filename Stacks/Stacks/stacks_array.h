//
//  stacks.h
//  Stacks
//
//  Created by Sunhak Lov on 10/28/24.
//

#ifndef stacks_h
#define stacks_h

#include <iostream>
using namespace std ;
template <typename T>
class stacks{
private:
    T storage[1024] ;
    int top_index = -1 ;
public:
    void push(T ) ;
    void pop() ;
    bool isEmpty() ;
    int top();
    int size() ;
    T& operator[](int index);
    void print_stack() ;
};

template <typename T>
void stacks<T>::push(T value){
    top_index++ ;
    storage[top_index] = value ;
}

template <typename T>
void stacks<T>::pop(){
    top_index-- ;
}

template <typename T>
bool stacks<T>::isEmpty(){
    if (top_index == -1)
        return 1 ;
    else
        return 0 ;
}

template <typename T>
int stacks<T>::top(){
    return storage[top_index] ;
}

template <typename T>
int stacks<T>::size(){
    return top_index + 1 ;
}

template <typename T>
T& stacks<T>::operator[](int index){
    return storage[index] ;
}

template <typename T>
void stacks<T>::print_stack(){
    cout << "|  |" << endl ;
    for(int i = top_index; i > -1 ; i--){
        cout << "|" << storage[i] << "|"<< endl ;
    }
    cout << "|__|" << endl ;
}


#endif /* stacks_h */
