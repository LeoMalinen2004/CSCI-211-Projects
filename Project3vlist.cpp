// vlist.cpp
// Malinen, Leo
// ldmalinen

#include "video.h"
#include "vlist.h"
#include <iostream>
using namespace std;

  //insert class to insert the objects into the linked list
    void Vlist::insert(int data) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = newnode;
        }
        else if (data < head->data) {
            newnode->next = head;
            head = newnode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data <= data) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
//remove class to traverse through the linked list to remove
    void Vlist::remove(int data) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            return;
        }
        if (current == head) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }
        // delete the node to free up the memory
        delete current;
    }
