#include "ulliststr.h"
#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// QUESTION: how should I approach this?
std::string* ULListStr::getValAtLoc(size_t loc) const{
    int idx = (int) loc;
    Item* cur = head_;
    //cout << "first " << cur->first << " last " << cur->last << endl;
    while(idx >= 0){
        int size = (int)cur->last - (int)cur->first;
        if(idx < size){
            //cout << "idx " << idx << "cur first " << cur->first << endl;
            return &(cur->val[idx + cur->first]);
        }
        else{
            idx -= size;
            cur = cur->next;
        }
    }
    return nullptr;
}

std::string const& ULListStr::back() const{
    return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const{
    return head_->val[head_->first];
}

void ULListStr::pop_back(){
    
    // if size reaches 0, deallocates the Item
    if(size_ == 1){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    
    // else just gets rid of the front number: WHAT HAPPENS
    else{
        tail_->last--;
        
        // if deletes all the items in tail, deallocates the current head
        if(tail_->first == tail_->last){
            Item* temp = tail_;
            tail_ = tail_->prev;
            tail_->next = NULL;
            delete temp;
        }
    }
    
    // decrements size
    size_--;
    
}

void ULListStr::pop_front(){
    
    // if size reaches 0, deallocates the Item
    if(size_ == 1){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    
    // else just gets rid of the front number: WHAT HAPPENS
    else{
        head_->first++;
        
        // if deletes all the items in head, deallocates the current head
        if(head_->first == head_->last){
            Item* temp = head_;
            head_ = head_->next;
            head_->prev = NULL;
            delete temp;
        }
    }
    
    // decrements size
    size_--;
    
}

void ULListStr::push_front(const std::string& val)
{
    // if there's room at the beginning of the list
    if(!empty() && head_->first > 0){
        head_->val[head_->first - 1] = val;
        head_->first--;
    }
    
    else{
        Item* front = new Item();
        front->val[ARRSIZE - 1] = val;
        
        // if there's no room at the front of the list
        if(!(empty())){
            head_->prev = front;
            front->next = head_;
            head_ = front;
        }
        
        // if the list is empty
        if(empty()){
            tail_ = front;
            head_ = tail_;
            tail_->next = NULL;
        }
        
        head_->first = ARRSIZE - 1;
        head_->last = ARRSIZE;
        head_->prev = NULL;
    }
    
    // increments size
    size_++;
}

void ULListStr::push_back(const std::string& val)
{
    // if there is room at the end of the list
    if(!empty() && tail_->last < ARRSIZE){
        tail_->val[tail_->last] = val;
        tail_->last++;
    }
    
    else{
        Item* back = new Item();
        back->val[0] = val;
        
        // if there's no room at the end of the list
        if(!empty()){
            tail_->next = back;
            back->prev = tail_;
            tail_ = back;
            tail_->last++;
        }
        
        // if list is empty
        if(empty()){
            tail_ = back;
            head_ = tail_;
            head_->prev = NULL;
            tail_->last = 1;
        }
        
        tail_->first = 0;
        tail_->next = NULL;
    }
    
    // increments size
    size_++;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}