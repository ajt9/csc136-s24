#include "linkedList.h"
#include <iostream>
using namespace std;

int main()
{
  linkedList myList;

  myList.insertAtFront(2);
  myList.insertAtEnd(3);
  myList.insertAtEnd(5);
  myList.insertAtEnd(7);
  myList.insertAtEnd(9);
  myList.insertAtFront(1);

  myList.print();

  cout << myList.search(9) << endl;
  
  myList.deleteNode(1);
  myList.deleteNode(9);
  myList.print();

  linkedList newList(myList);
  newList.print();


  // adding more lists segfaults
  // linkedList List1;
  // linkedList List2(List1);

  // List2.print();
  
}
