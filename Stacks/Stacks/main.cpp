#include <iostream>
//#include "stacks_array.h"
#include "stacks_linked_list.h"
using namespace std ;


int main() {
    stacks<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
    stack.push(25);
    stack.push(99);
    int num=10;
      stack.push(num);
    
    int n = stack.size();
    cout << "Size : " << n << endl;
    
    stack.print_stack() ;
    
    stack.pop();
    stack.pop();
      stack.pop();
  
    int m = stack.size();
    cout << "Size after pop 3 times: " << m << endl;
    stack.print_stack() ;
    
    while (!stack.isEmpty()) {
        cout << stack.top() <<" \n";
        stack.pop();
    }
    
    int o = stack.size();
    cout << "Size after pop till end: " << o << endl;
    stack.print_stack() ;
    stack.pop();
}
