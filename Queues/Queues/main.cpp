//
//  main.cpp
//  Queues
//
//  Created by Sunhak Lov on 10/29/24.
//

#include <iostream>
//#include "queues_array.h"
#include "queues_linked_list.h"

int main() {
    queues<int> queue ;
    queue.enqueue(12) ;
    queue.enqueue(16) ;
    queue.enqueue(77) ;
    queue.enqueue(10) ;
    queue.enqueue(99) ;
    queue.print_queue() ;
    
    std::cout << "After dequeue the first number" << std::endl ;
    queue.dequeue() ;
    queue.print_queue() ;
    
    std::cout << "The front of the line : " << queue.front() << std::endl ;
    std::cout << "The back of the line : " << queue.back() << std::endl ;
    return 0;
}
