#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

//define the list node
struct node{
  int num;
  node *next;
};

class linkedList
{
 public:
  linkedList();
  linkedList(const linkedList&);

  void insertAtEnd(int);
  void insertAtFront(int);
  void deleteNode(int);

  const linkedList& operator=(const linkedList& other);

  bool search(int) const;

  void print() const;
  void destroy();

  ~linkedList();

 private:
  node *head;
  node *tail;
  int count;

};

//git add .
//git commit -m "[msg]"
//git push



#endif
