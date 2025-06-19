//
//  stacks_linked_list.h
//  Stacks
//
//  Created by Sunhak Lov on 10/29/24.
//

#ifndef stacks_linked_list_h
#define stacks_linked_list_h
#include<iostream>

template <typename T>
struct node{
    T key ;
    node<T>* next = nullptr ;
} ;

template <typename T>
class stacks{
private:
    node<T>* storage = nullptr ;
    int count = 0 ;
public:
    void push(T value) ;
    void pop () ;
    int size() ;
    void print_stack() ;
    bool isEmpty() ;
    T top() ;
};

template <typename T>
void stacks<T>::push(T value) {
    node<T>* newNode = new node<T> { value } ;
    newNode-> next = storage ;
    storage = newNode ;
    count++ ;
}

template <typename T>
void stacks<T>::pop () {
    if(count <= 0)
        std::cout << "Can't delete an empty stacks" << std::endl ;
    else{
        node<T>* temp = storage ;
        storage = storage-> next ;
        delete temp ;
        count-- ;
        std::cout << "Top of the stack has popped !!" << std::endl ;
    }
}

template <typename T>
int stacks<T>::size() {
    return count ;
}

template <typename T>
void stacks<T>::print_stack() {
    node<T>* temp = storage ;
    std::cout << "|  |" << std::endl ;
    while (temp){
        std::cout << "|" << temp-> key << "|"  << std::endl ;
        temp = temp-> next ;
    }
    std::cout <<"|__|" << std::endl ;
}

template <typename T>
bool stacks<T>::isEmpty() {
    if(count == 0)
        return true ;
    else return false ;
}

template <typename T>
T stacks<T>::top() {
    return storage->key ;
}


#endif /* stacks_linked_list_h */
