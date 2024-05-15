#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
  while (head_ != nullptr) {
    Node *temp = head_;
    head_ = head_->next_;
    delete temp;
  }
}

void LinkedList::print() {
  Node *current = head_;
  while (current != nullptr) {
    std::cout << current->value_ << " ";
    current = current->next_;
  }
  std::cout << std::endl;
}

void LinkedList::insert(int index, int value) {
  if (index < 0 || index > size_) return;

  Node *newNode = new Node(value);
  if (index == 0) {
    newNode->next_ = head_;
    head_ = newNode;
  } else {
    Node *current = head_;
    for (int i = 0; i < index - 1; ++i) {
      current = current->next_;
    }
    newNode->next_ = current->next_;
    current->next_ = newNode;
  }
  size_++;
}

int LinkedList::get(int index) {
  if (index < 0 || index >= size_) return -1;

  Node *current = head_;
  for (int i = 0; i < index; ++i) {
    current = current->next_;
  }
  return current->value_;
}

void LinkedList::remove(int index) {
  if (index < 0 || index >= size_) return;

  Node *toDelete = head_;
  if (index == 0) {
    head_ = head_->next_;
  } else {
    Node *current = head_;
    for (int i = 0; i < index - 1; ++i) {
      current = current->next_;
    }
    toDelete = current->next_;
    current->next_ = toDelete->next_;
  }
  delete toDelete;
  size_--;
}
