#include "linkedList.h"
#include <iostream>

using namespace std;

linkedList::linkedList()
{
  head = nullptr;
  tail = nullptr;
  count = 0;
}

void linkedList::insertAtEnd(int x) {
  node* temp = new node;
  temp->num = x;
  temp->next = nullptr;

  if (head == nullptr) {
      head = temp;
      tail = temp;
  }
  else {
      tail->next = temp;
      tail = tail->next;
  }

  count++;
}
void linkedList::insertAtFront(int x) {
  node* temp = new node;
  temp->num = x;
  temp->next = nullptr;

  if (head == nullptr) {
    head = temp;
    tail = temp;
  }
  else {
    temp->next = head;
    head = temp;
  }
}

bool linkedList::search(int x) const {
  node* current = head;
  while (current->next != nullptr) {
    if (current->num == x) {
      return true;
    }
    current = current->next;
  }
  /*if (current->num == x) { //needed if the while uses current->next
    return true;
  }*/
  return false;
}

void linkedList::print() const {
  node* current = head;
  while (current->next != nullptr) {
      cout << current->num << "->";
      current = current->next;
  }
  cout << current->num;
  cout << endl;
}




