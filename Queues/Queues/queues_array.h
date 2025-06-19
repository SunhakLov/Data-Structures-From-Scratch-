//
//  queues_array.h
//  Queues
//
//  Created by Sunhak Lov on 10/29/24.
//

#ifndef queues_array_h
#define queues_array_h

template <typename T>
class queues{
public:
    void enqueue(const T&) ;
    void dequeue() ;
    T& front () ;
    T& back() ;
    int size() const ;
    void print_queue() ;
private:
    T storage[1024] ;
    int last_index = 0 ;
    int front_index = 0 ;
    int count = 0 ;
};

template <typename T>
void queues<T>::enqueue(const T& value) {
    storage[last_index] = value ;
    last_index++ ;
    last_index %= 1024 ;
    count++ ;
}

template <typename T>
void queues<T>::dequeue() {
    front_index++ ;
    front_index %= 1024 ;
    count-- ;
}

template <typename T>
T& queues<T>::front () {
    return storage[front_index] ;
}

template <typename T>
T& queues<T>::back() {
    //return storage[(last_index - 1 + 1024) % 1024] ;
    return storage[last_index-1 +1024] % 1024 ;
}

template <typename T>
int queues<T>::size() const {
    return count ;
}

template <typename T>
void queues<T>::print_queue() {
    std::cout << "front of the queue : " ;
    for(int i = 0; i < count ; i++){
        int index = (front_index + i)% 1024 ;
        //int index = i ;
        std::cout << storage[index] << " ";
    }
    std::cout << ": last of the queue" << std::endl ;
}

#endif /* queues_array_h */
