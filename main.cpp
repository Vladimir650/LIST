#include <iostream>
#include "implementation\list.cpp"
#include "implementation\list.hpp"

int main (){

    blgt::list my_list;

    std::cout << "Empty? " << my_list.empty() << "\n";
    my_list.insert_front(10);
    my_list.insert_back(20);
    my_list.insert_front(5);

    std::cout << "Size: " << my_list.size() << "\n";
    std::cout << "List elements: ";
    for (auto it = my_list.begin(); it != my_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n"; 

    my_list.erase_front();
    my_list.erase_back();

    std::cout << "After erasing front and back:\n";
    std::cout << "Size: " << my_list.size() << "\n";
    std::cout << "List elements: ";
    for (auto it = my_list.begin(); it != my_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}