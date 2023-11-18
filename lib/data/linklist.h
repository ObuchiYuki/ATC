//
//  linklist.h
//  ATC
//
//  Created by yuki on 2022/04/14.
//

#ifndef linklist_h
#define linklist_h

template <class T>
struct node {
    T x;
    node *right;
    node *left;
    
    node(T _x) : x(_x), right(nullptr), left(nullptr) {}
    
    void insert_left(node *node) {
        if (this->left) this->left->right = node;
        node->left = this->left;
        node->right = this;
        this->left = node;
    }
    
    void insert_right(node *node) {
        if (this->right) this->right->left = node;
        node->right = this->right;
        node->left = this;
        this->right = node;
    }
};

template <class T>
void desc(node<T>* node) {
    auto head = node;
    while (head->left) head = head->left;
    while (head) { cout << head->x << " "; head = head->right; }
}

#endif /* linklist_h */
