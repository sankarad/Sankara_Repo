#include <stdio.h>
#include <stdlib.h>
#include "IntList.h"

struct IntNode * newIntNode(int v, struct IntNode * n) {
  struct IntNode * node;
  node = malloc(sizeof(*node));

 (*node).value = v;
  (*node).next = n;
  return node;
}

struct IntList * newIntList() {
  struct IntList * list;
  list = malloc(sizeof(*list));
  
(*list).head = NULL;
  return list;
}

void deleteIntList(struct IntList * list) {
 
	while(!isEmpty(list)){
	struct IntList * rest;
	
	//printIntList(rest1);
	rest=getFront(rest);
	free(rest);
	//free(rest1);

	 
//struct IntList * print;
  //    struct IntList * get;
	free(list);	
}
  // TODO Define this function
}

void insertFront(struct IntList * list, int v) {
  (*list).head = newIntNode(v, (*list).head);

}

void removeFront(struct IntList * list) {
  if (!isEmpty(list)) {
    (*list).head = (*((*list).head)).next;
  }
}

bool isEmpty(struct IntList * list) {
  return (*list).head == NULL;
}

int size(struct IntList * list) {
  int size = 0;
  if (!isEmpty(list)) {
     do {
	size++;
	list = getRest(list);
     }
     while (!isEmpty(list));
  }
  return size;
}

struct IntNode * getFront(struct IntList * list) {
  return (*list).head;
}

struct IntList * getRest(struct IntList * list) {
  if (isEmpty(list)) {
    return NULL;
  }
  struct IntList * rest;
  rest = newIntList();
  (*rest).head = (*((*list).head)).next;

  return rest;
}

void printIntList(struct IntList * list) {
  printf("[ ");
  if (!isEmpty(list)) {
    do {
      struct IntNode * first;
      first = getFront(list);
      printf("%d ",(*first).value);
      list = getRest(list);
    } while (list != NULL && !isEmpty(list));
  }
  printf("]");
	
}


