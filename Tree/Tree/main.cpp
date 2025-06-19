
#include <iostream>

using namespace std ;

template <typename T>
struct Node{
    T key ;
    Node<T>* right = nullptr,
             left  = nullptr ;
};

template <typename T>
class BinarySearchTree{
public:
    bool insert_node(T value) ;
    bool contain_element(T value) ;
private:
    Node<T>* root = nullptr ;
};

template <typename T>
bool BinarySearchTree<T>::insert_node(T value){
    Node<T>* newNode = new Node {value} ;
    Node<T>* temp = root ;
    
    if(temp == nullptr){
        temp = newNode ;
        return true ;
    }
    while(true){
        if(newNode->key == temp->key) return false ;
        else if(newNode->key > temp->key){
            if(temp-> left == nullptr){
                temp->left = newNode ;
                return true ;
            }
            temp = temp->right ;
        }
        else if (newNode->key < temp->key){
            if(temp-> right == nullptr){
                temp->right = newNode ;
                return true ;
            }
            temp = temp->right ;
        }
        else return false ;
    }
}

template <typename T>
bool BinarySearchTree<T>::contain_element(T value){
    Node<T>* temp = root ;
    
    if(temp == nullptr) return false ;
    
    while(true){
         if(value > temp->key){
             temp = temp->right ;
             if(temp-> key == value) return true ;
        }
        else if (value < temp->key){
            temp = temp->right ;
            if(temp-> key == value)return true ;
        }
        else return false ;
    }
}

int main(){
    
    return 0 ;
}
