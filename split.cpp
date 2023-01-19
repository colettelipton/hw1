/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
using namespace std;

/* Add a prototype for a helper function here if you need */

void push(Node*& head, Node*& append){
    if(head->next == nullptr){
        head->next = append;
        return;
    }
    push(head->next, append);
}

void split(Node*& in, Node*& odds, Node*& evens)
{
    bool ch = false;
    if(in == nullptr){
        in = NULL;
        return;
    }
    
    if(evens == NULL || odds == NULL){
        if(evens == NULL){
            if(!ch && in->value % 2 == 0){
                evens = in;
                in = in->next;
                evens->next = nullptr;
                ch = true;
            }
        }
        if(odds == NULL){
            if(!ch && in->value % 2 == 1){
                odds = in;
                in = in->next;
                odds->next = nullptr;
                ch = true;
            }
        }
    }
    
    if(!ch && !(evens == nullptr) && in->value % 2 == 0){
        push(evens,in);
        Node* temp = in;
        in = in->next;
        temp->next = nullptr;
        ch = true;
    }
    
    if(!ch && !(odds == nullptr) && in->value % 2 == 1){
        push(odds,in);
        Node* temp = in;
        in = in->next;
        temp->next = nullptr;
        ch = true;
    }
    split(in,odds,evens);
}

/* If you needed a helper function, write it here */
