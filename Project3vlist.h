// vlist.h
// Malinen, Leo
// ldmalinen

#ifndef VLIST_H
#define VLIST_H

#include "video.h"

class Vlist {
public:
  Vlist() { head = NULL; }
  void insert(int data);
  void remove(int data);
private:
   class Node {
    public:
        int data; // data stored in the node
        Node* next; // pointer to next node in the list
        Node(int data) {
            this->data = data;
            next = nullptr;
        }
    };
  Node *head;
};
#endif
