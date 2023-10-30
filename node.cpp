#include <cstddef>
#include <iostream>
#include "node.h"

node::node(int val) : data(val) {
    prev = NULL;
    next = NULL;
}

node::~node() {
    prev = NULL;
    next = NULL;
}

void node::destroyList() {
    node* n;
    node* ptr = prev;
    while (ptr) {
        n = ptr->prev;
        delete ptr;
        ptr = n;
    }

    ptr = next;
    while (ptr) {
        n = ptr->next;
        delete ptr;
        ptr = n;
    }
    delete this;
}

bool node::contains(int val) {
    if (data == val) {
        return true;
    }

    node* ptr = prev;
    while (ptr) {
        if (ptr->data == val)
            return true;
        ptr = ptr->prev;
    }

    ptr = next;
    while (ptr) {
        if (ptr->data == val)
            return true;
        ptr = ptr->next;
    }

    return false;
}

void node::insert(int val) {
    if (val == data)
        return;

    node* nNode = new node(val);

    node* ptr;
    if (val < data) {
        ptr = this;
        while (val < ptr->data && ptr->prev) {
            ptr = ptr->prev;
        }
        if (val > ptr->data) {
            if (ptr->data == val) {
                delete nNode;
                return;
            }
            nNode->prev = ptr;
            nNode->next = ptr->next;
            nNode->next->prev = nNode;
            ptr->next = nNode;
        } else {
            nNode->next = ptr;
            ptr->prev = nNode;
        }
    } else {
        ptr = this;
        while (val > ptr->data && ptr->next) {
            ptr = ptr->next;
        }
        if (val < ptr->data) {
            if (ptr->data == val) {
                delete nNode;
                return;
            }
            nNode->next = ptr;
            nNode->prev = ptr->prev;
            ptr->prev = nNode;
            nNode->prev->next = nNode;
        } else {
            nNode->prev = ptr;
            ptr->next = nNode;
        }
    }
}

void node::print() {
    node* ptr = this->head();
    while (ptr) {
        if (ptr->prev)
            std::cout << "->";
        if (ptr == this)
            std::cout << '[';
        std::cout << ptr->data;
        if (ptr == this)
            std::cout << ']';
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void unlink(node* n) {
    if (n->prev) {
        if (n->next) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        } else {
            n->prev->next = NULL;
        }
    } else {
        if (n->next) {
            n->next->prev = NULL;
        }
    }
    n->prev = NULL;
    n->next = NULL;
}

node* node::remove(int val) {
    if (data == val) {
        unlink(this);
        return this;
    }

    node* ptr = prev;
    while (ptr) {
        if (ptr->data == val) {
            unlink(ptr);
            return ptr;
        }
        ptr = ptr->prev;
    }

    ptr = next;
    while (ptr) {
        if (ptr->data == val) {
            unlink(ptr);
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}

node* node::head() {
    node* ptr = this;
    while (ptr->prev) {
        ptr = ptr->prev;
    }
    return ptr;
}

node* node::tail() {
    node* ptr = this;
    while (ptr->next) {
        ptr = ptr->next;
    }
    return ptr;
}

void insertAfter(node* first, node* p) {
    p->prev = first;
    p->next = first->next;
    if (p->next)
        p->next->prev = p;
    first->next = p;
}
void node::insert(node* n) {
    if (this->contains(n->data))
        return;

    node* ptr = this->head();
    node* nptr = n->head();

    if (nptr->data < ptr->data) {
        ptr->prev = nptr;
        nptr = nptr->next;
        ptr->prev->next = ptr;
        ptr = ptr->prev;
        nptr->prev = NULL;
    }

    node* p;
    while (ptr->next && nptr) {
        while (ptr->next && nptr->data > ptr->next->data) {
            ptr = ptr->next;
        }
        if (ptr->next) {
            if (nptr->data == ptr->next->data) {
                nptr = nptr->next;
                delete nptr->prev;
                nptr->prev = NULL;
            } else {
                p = nptr;
                nptr = nptr->next;

                insertAfter(ptr, p);

                if (nptr)
                    nptr->prev = NULL;
                ptr = ptr->next;
            }
        }
    }

    node* next1;
    while (nptr) {
        next1 = nptr->next;
        insertAfter(ptr, nptr);
        ptr = ptr->next;
        nptr = next1;
    }
}

int node::length() {
    int l = 1;
    node* ptr = prev;
    while (ptr) {
        l++;
        ptr = ptr->prev;
    }

    ptr = next;
    while (ptr) {
        l++;
        ptr = ptr->next;
    }
    return l;
}
