#include "queue.h"

void Queue::push(int value) {
  insert(size_, value);
}

int Queue::pop() {
  if (size_ == 0) return -1;
  int value = get(0);
  remove(0);
  return value;
}

int Queue::peek() {
  if (size_ == 0) return -1;
  return get(0);
}

Queue& Queue::operator+=(int value) {
  push(value);
  return *this;
}
