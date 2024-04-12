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
  
}
