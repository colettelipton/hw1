/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
 Node* n5 = new Node(8, nullptr);
    Node* n4 = new Node(4, n5);
    Node* n3 = new Node(6, n4);
    Node* n2 = new Node(2, n3);
    Node* n1 = new Node(1, n2);
    
    Node* odds = NULL;
    Node* evens = NULL;
    
    split(n1, odds, evens);
    
    Node* cur = odds;
    cout << "odds" << endl;
    while(cur != nullptr){
        Node* temp = cur;
        cout << cur->value << endl;
        cur = cur->next;
        delete temp;
    }
    
    cur = evens;
    cout << "evens" << endl;
    while(cur != nullptr){
        Node* temp = cur;
        cout << cur->value << endl;
        cur = cur->next;
        delete temp;
    }
    
    return 0;

}
