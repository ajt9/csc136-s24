#include "linkedList.h"
#include <iostream>

using namespace std;

linkedList::linkedList()
{
  head = nullptr;
  tail = nullptr;
  count = 0;
}

linkedList::linkedList(const linkedList& other) {

  if (other.head == nullptr) {
    count = 0;
    head = nullptr;
    tail = nullptr;
  }
  else {
    node* head = new node;
    tail = nullptr;
    count = 0;
    node* temp = other.head;

    while (temp != nullptr) {
      insertAtEnd(temp->num);
      temp = temp->next;

    }
  }
  
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
void linkedList::deleteNode(int x) {
  if (head == nullptr) {
    return;
  } // head is empty

  if (head->num == x) {
    node* temp = head->next;
    if (head == nullptr) { //list contains one element
      tail = nullptr;
    }
    delete head;
    head = temp;
    count--;
    return;
  } //head is deleted

  if (head->num != x) {
      node* prev = head;
      node* curr = head->next;

      bool found = false;

      while (curr != nullptr) {
        if (curr->num == x) {
          found = true;
          break;
        }
        curr = curr->next;
        prev = prev->next;
      }
      if (found) {
        prev->next = curr->next;
        delete curr;
        count--;
        if (prev->next == nullptr) {
          tail = prev;
        } //fix tail pointer if x is last node
      }
      return;
  } //other part is deleted
}

 const linkedList& linkedList::operator=(const linkedList& other) {
  if (this != &other) {
    destroy();

    if (other.head == nullptr) {
      count = 0;
      head = nullptr;
      tail = nullptr;
    }
    else {
        node* head = new node;
        tail = nullptr;
        count = 0;
        node* temp = other.head;

        while (temp != nullptr) {
          insertAtEnd(temp->num);
          temp = temp->next;
        }
    }
  }
  return *this;
}

bool linkedList::search(int x) const {
  node* current = head;
  while (current != nullptr) {
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
  if (head == nullptr) {
    return;
  } //dont print empty list

  node* current = head;
  while (current->next != nullptr) {
      cout << current->num << "->";
      current = current->next;
  }
  cout << current->num;
  cout << endl;
}
void linkedList::destroy() {
  node* temp;

  while (head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  } 

  // delete head;
}

linkedList::~linkedList() {
  destroy();
}



