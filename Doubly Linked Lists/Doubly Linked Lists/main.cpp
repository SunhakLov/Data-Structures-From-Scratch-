//
//  main.cpp
//  Doubly Linked Lists
//
//  Created by Sunhak Lov on 10/22/24.
//

#include <iostream>
using namespace std ;

template <typename T>
struct Node{
    T key;
    Node<T>* next ;
    Node<T>* prev ;
};

template <typename T>
void printDLL(Node<T>*& myDLL){
    Node<T>* tempDLL = myDLL ;
    
    cout << "Nullptr <=> " ;
    
    while(tempDLL){
        cout << tempDLL-> key << " <=> " ;
        tempDLL = tempDLL-> next ;
    }
    
    cout << "Nullptr" << "\n" ;
}

template <typename T>
void prepend(Node<T>*& myDLL, T value){
    Node<T>* newNode = new Node<T> { value } ;
    newNode-> next = myDLL ;
    
    if(myDLL != nullptr)
        myDLL-> prev = newNode ;
    
    newNode-> prev = nullptr ;
    myDLL = newNode ;
}

template <typename T>
void append(Node<T>*& myDLL, T value){
    if(myDLL == nullptr)
        prepend(myDLL, value) ;
    else{
        Node<T>* newNode = new Node<T> { value } ;
        Node<T>* temp = myDLL ;
        while(temp-> next != nullptr)
            temp = temp->next ;
        newNode-> prev = temp ;
        temp-> next = newNode ;
    }
}

template <typename T>
void deleteDLL (Node<T>*& myDLL){
    if(myDLL == nullptr)
        cout << "DLL was empty" << "\n" ;
    Node<T>* temp = myDLL ;
    while(temp){
        myDLL = myDLL-> next ;
        delete temp ;
        temp = myDLL ;
    }
    myDLL = nullptr ;
    cout << "DLL was deleted succefully" << '\n' ;
}

template <typename T>
void deleteLast (Node<T>*& myDLL){
    
    if(myDLL == nullptr)
        cout << "The list is empty & can't be deleted anymore" << '\n' ;
    else if(myDLL-> next == nullptr){
        delete myDLL ;
        myDLL = nullptr ;
    }
    
    Node<T>* temp = myDLL ;
    while(temp-> next != nullptr)
        temp = temp-> next ;
    temp-> prev-> next = nullptr ;
    delete temp ;
    temp = nullptr ;
}

template <typename T>
void deletefirst (Node<T>*& myDLL){
    
    if(myDLL == nullptr){
        cout << "The list is empty & can't be deleted anymore" << '\n' ;
        return ;
    }
    else if(myDLL-> next == nullptr){
        delete myDLL ;
        myDLL = nullptr ;
        return ;
    }
    
    Node<T>* temp = myDLL ;
    
    myDLL = myDLL-> next ;
    myDLL-> prev = nullptr ;
    
    delete temp ;
    temp = nullptr ;
}

template <typename T>
int lengthDLL(Node<T>*& myDLL){
    int length = 0 ;
    Node<T>* temp = myDLL ;
    
    while(temp){
        temp= temp->next ;
        length++ ;
    }
    
    return length ;
}

template <typename T>
Node<T>* get(Node<T>*& myDLL , int index) {
    
    if(myDLL==nullptr){
        cout << "The list is empty" << "\n" ;
        return nullptr ;
    }
    
    if(index < 0 || index > lengthDLL(myDLL)){
        cout << "Out of Bounce" << "\n" ;
        return nullptr ;
    }
    
    Node<T>* temp = myDLL ;
    for (int i = 1 ; i < index ; i++){
        temp = temp-> next ;
    }
    return temp ;
}

template <typename T>
void set(Node<T>*& myDLL , T value, int index) {
    
    if(myDLL==nullptr){
        cout << "The list is empty; Can't set any element" << "\n" ;
        return ;
    }
    
    if(index < 0 || index > lengthDLL(myDLL)){
        cout << "Out of Bounce" << "\n" ;
        return ;
    }
    
    Node<T>* temp = get(myDLL,index) ;
    temp->key = value ;
}

template <typename T>
void insert(Node<T>*& myDLL , T value, int index) {
    
    if(myDLL==nullptr){
        prepend(myDLL, value) ;
        return ;
    }
    else {
        Node<T>* newNode = new Node<T> { value } ;
        Node<T>* temp = get(myDLL, index) ;
        
        newNode-> next = temp-> next ;
        newNode-> prev = temp ;
        
        temp-> next = newNode ;
        temp = temp-> next ;
        temp-> prev = newNode ;
        return ;
    }
}

int main() {
    
    Node<int>* myDLL = nullptr ;
    prepend(myDLL, 12) ;
    prepend(myDLL, 2) ;
    prepend(myDLL, 0) ;
    printDLL(myDLL) ;
    
    cout << '\n' ;
    
    append(myDLL, 90) ;
    printDLL(myDLL)  ;
    
    cout << '\n' ;
    
    deleteLast(myDLL) ;
    printDLL(myDLL)  ;

    cout << '\n' ;
    
    prepend(myDLL, 70) ;
    printDLL(myDLL) ;

    cout << '\n' ;
    
    cout << "Get the adress of the node located at index 3 : " << get(myDLL,3) << '\n' ;
    cout << "Get the value of the node located at index 3 : " << get(myDLL,3)->key << '\n' ;
    cout << "Get the length of the DLL : " << lengthDLL(myDLL)<< '\n' ;
    printDLL(myDLL) ;

    cout << '\n' ;
    
    cout << "Set the node located at index 4 to 8 : " << '\n' ;
    set(myDLL, 8, 4) ;
    printDLL(myDLL) ;
    
    cout << '\n' ;
    
    cout << "Insert a new node ( 10 ) after the index 2 : " << '\n' ;
    insert(myDLL, 10, 2) ;
    printDLL(myDLL) ;
    
    cout << '\n' ;
    
    deletefirst(myDLL) ;
    printDLL(myDLL) ;

    cout << '\n' ;
    
    deleteDLL(myDLL) ;
    printDLL(myDLL)  ;
    
    cout << '\n' ;
    
    
    return 0;
}
