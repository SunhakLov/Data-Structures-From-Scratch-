//
//  linked_list.h
//  Linked List
//
//  Created by Sunhak Lov on 10/21/24.
//

#ifndef linked_list_h
#define linked_list_h

#include <iostream>
using namespace std ;

template <typename T>
struct node{
    T key ;
    node* next = nullptr ;
};

template <typename T>
void insert_before(node<T>*& my_list, const T& key){
    node<T>* new_node = new node<T> {key};
    new_node-> next = my_list ;
    my_list = new_node ;
}

template <typename T>
void insert_after(node<T>*& my_list, const T& key){
    node<T>* new_node = new node<T> {key};
    
    if(my_list == nullptr)
        insert_before(my_list, key) ;
    else
    {
        node<T>* temp = my_list ;
        while(temp-> next != nullptr){
            temp = temp-> next;
        }
        temp -> next = new_node ;
    }
}

template <typename T>
void print_list(node<T>*& my_list){
    node<T>* temp = my_list ;
    while(temp){
        cout << temp-> key << " -> ";
        temp = temp-> next ;
    }
    cout << "nullptr " << endl ;
}

template <typename T>
void delete_last(node<T>*& my_list){
    
    if(my_list == nullptr)
        cout << "Can't Delete Last Node !!! The list is empty !!!" << "\n" ;
    else if(my_list-> next == nullptr){
        node<T>* temp = my_list ;
        my_list = nullptr ;
        delete temp ;
    }
    else{
        node<T>* temp = my_list ;
        node<T>* prev = nullptr ;
        
        while(temp-> next != nullptr){
            prev = temp ;
            temp = temp->next ;
        }
        delete temp ;
        prev->next = nullptr ;
    }
}
template <typename T>
void delete_first(node<T>*& my_list){
    
    node<T>* temp = my_list ;
    
    if(my_list == nullptr)
        cout << "Can't Delete Last Node !!! The list is empty !!!" << "\n" ;
    else if(my_list-> next == nullptr)
        my_list = nullptr ;
    else
        my_list = my_list-> next ;
    delete temp ;
}

template <typename T>
void delete_list(node<T>*& my_list){
    node<T>* temp = my_list ;
    while(temp){
        my_list = my_list->next ;
        delete temp ;
        temp = my_list ;
    }
    cout << "List is cleared" << endl ;
}

template <typename T>
node<T>* get(node<T>*& my_list, int index){
    node<T>* temp = my_list ;
    for(int i = 1 ; i < index ; i++){
        temp = temp-> next ;
    }
    return temp ;
}

template <typename T>
int list_length(node<T>*& my_list){
    node<T>* temp = my_list;
    int length = 0 ;
    while(temp != nullptr){
        length++ ;
        temp = temp-> next ;
    }
    return length ;
}

template <typename T>
bool set(node<T>*& my_list, T value , int index){
    if(index < 1 || index > list_length(my_list)){
        return 0 ;
    }
    else{
        node<T>* temp = get(my_list,index) ;
        temp->key = value ;
        return true ;
    }
}

template <typename T>
void reverse_list(node<T>*& my_list){
    
    node<T>* current = my_list ;
    node<T>* next = nullptr ;
    node<T>* prev = nullptr ;
    
    while(current != nullptr){
        next = current-> next ;
        current-> next = prev ;
        prev = current ;
        current = next ;
    }
    my_list = prev ;
}

template <typename T>
void insert(node<T>*& my_list, T value, int index){
    if(index < 1 || index > list_length(my_list)){
        return ;
    }
    else if (index == 1)
        insert_before(my_list, value) ;
    else if (index == list_length(my_list))
        insert_after(my_list, value) ;
    else{
        node<T>* newNode = new node<T> {value} ;
        node<T>* temp = my_list ;
        for(int i = 1 ; i < index ; i++){
            temp = temp-> next ;
        }
        newNode-> next = temp-> next ;
        temp-> next = newNode ;
    }
}

template <typename T>
void delete_node(node<T>*& my_list, int index){
    if(index < 1 || index > list_length(my_list)){
        return ;
    }
    else if (index == 1)
        delete_first(my_list) ;
    else{
        node<T>* temp = my_list ;
        node<T>* next = nullptr ;
        for(int i = 1 ; i < index ; i++){
            temp = temp-> next ;
        }
        next = temp-> next ;
        temp-> next = next-> next ;
        delete next ;
    }
}

//template <typename T>
//T sum(node<T>* front){
//    T result = 0 ;
//    node<T>* temp = front ;
//    while(temp){
//        result += temp-> key ;
//        temp = temp-> next ;
//    }
//    return result ;
//}


template <typename T>
T sum(node<T>* front){
    if(front == nullptr) return 0;
    
    else return front->key + sum(front-> next) ;
}
#endif /* linked_list_h */
