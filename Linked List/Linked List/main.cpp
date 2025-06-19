#include <iostream>
#include "linked_list.h"

int main(){
    node<int>* my_list = nullptr ;
    
    insert_before(my_list, 12) ;
    insert_before(my_list, -1) ;
    insert_before(my_list, 92) ;
    insert_after(my_list, 0);
    print_list(my_list) ;
    cout << "length is : " << list_length(my_list) << '\n'  ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    reverse_list(my_list) ;
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    cout << "Set node number 3 to -13 : " << set(my_list,-13,3) << '\n' ;
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    cout << "Get address at index 3 : " << get(my_list,3) << "\n" ;
    cout << "Get value at index 3 : " << get(my_list,3)-> key << "\n" ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    cout << "Insert value 20 after index 3 : " << "\n" ;
    insert(my_list, 20, 3) ;
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    int sumNode = sum(my_list) ;
    cout << "Sum result: " << sumNode << "\n" ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    cout << "Delete value 20 after index 3 : " << "\n" ;
    delete_node(my_list,3);
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    delete_last(my_list) ;
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    delete_first(my_list) ;
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
    
    delete_list(my_list) ;
    print_list(my_list) ;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << "\n" ;
}
