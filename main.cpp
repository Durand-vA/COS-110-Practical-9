/*
Output for this main is inside output.txt
Note that output.txt is what my program prints when running this main, thus you should get exactly the same output as the textfile
*/
#include <iostream>
#include "node.h"

int main() {
    node* list1 = new node(2);
    list1->insert(4);
    list1->insert(6);
    list1->insert(8);
    list1->insert(10);

    node* list2 = new node(5);
    list2->insert(1);
    list2->insert(3);
    list2->insert(7);
    list2->insert(9);

    list1->print();
    list2->print();

    list1->insert(list2);
    list1->print();
    list2->print();

    list1->destroyList();

    node* list3 = new node(10);

    int arr[20] = {4,7,18,16,14,15,8,13,10,2,3,9,11,20,5,6,1,12,21,17};

    for (int i = 0; i < 20; i++) {
        list3->insert(arr[i]);
    }

    list3->print();

    // Test contains function with different test cases on list3
    std::cout << "list3 contains 10: " << list3->contains(10) << std::endl;
    std::cout << "list3 contains 20: " << list3->contains(20) << std::endl;
    std::cout << "list3 contains 21: " << list3->contains(21) << std::endl;
    std::cout << "list3 contains 22: " << list3->contains(22) << std::endl;
    std::cout << "list3 contains 1: " << list3->contains(1) << std::endl;
    std::cout << "list3 contains 2: " << list3->contains(2) << std::endl;

    // Test remove function with different test cases on list3
    std::cout << "Testing list remove function:" << std::endl;
    delete list3->remove(11);
    list3->print();
    delete list3->remove(20);
    list3->print();
    delete list3->remove(21);
    list3->print();
    list3->remove(22);
    list3->print();
    delete list3->remove(1);
    list3->print();

    list3->tail();

    std::cout << "Testing list length function:" << std::endl;
    std::cout << "list3 length: " << list3->length() << std::endl;

    node* list4 = new node(11);

    list3->insert(11);
    list4->insert(list3);
    list4->print();
    list3->print();


    list3->destroyList();
    return 0;
}