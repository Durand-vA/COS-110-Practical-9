#ifndef PRACTICAL_9_NODE_H
#define PRACTICAL_9_NODE_H


class node {
public:
    int data;
    node* prev;
    node* next;

    node(int val);
    ~node();
    void destroyList();
    bool contains(int val);
    void insert(int val);
    void print();
    node* remove(int val);
    node* head();
    node* tail();
    void insert(node* n);
    int length();
};

#endif //PRACTICAL_9_NODE_H
