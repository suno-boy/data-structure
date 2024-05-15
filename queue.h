#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

class Queue : public LinkedList {
public:
  void push(int value);
  int pop();
  int peek();
  Queue& operator+=(int value);
};

#endif
