#include <stdio.h>
#include "IntList.h"

int main() {
  struct IntList * myIntList;
  myIntList = newIntList();
  for (int i=0; i<10; i++) {
    printf("Inserting %d into ",i);
    printIntList(myIntList);
    printf("\n");
    insertFront(myIntList,i);
  }
  printIntList(myIntList);
  printf(" has size %d\n", size(myIntList));
  deleteIntList(myIntList);
  return 0;
}
