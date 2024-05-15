#include "stack.h"

void Stack::push(int value) {
  insert(0, value);
}

int Stack::pop() {
  if (size_ == 0) return -1;
  int value = get(0);
  remove(0);
  return value;
}

int Stack::peek() {
  if (size_ == 0) return -1;
  return get(0);
}

Stack& Stack::operator+=(int value) {
  push(value);
  return *this;
}
