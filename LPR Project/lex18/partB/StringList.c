#include <stdio.h>
#include <stdlib.h>
#include "StringList.h"

struct StringNode * newStringNode(char * v, struct StringNode * n) {
  struct StringNode * node;
  node = malloc(sizeof(*node));
  (*node).value = v;
  (*node).next = n;
  return node;
}

struct StringList * newStringList() {
  struct StringList * list;
  list = malloc(sizeof(*list));
  (*list).head = NULL;
  return list;
}

void deleteStringList(struct StringList * list) {
  if (isEmpty(list)) {
     free(list);
  }
  else {
    do {
      struct StringNode * first;
      struct StringList * oldList;
      oldList = list;
      first = getFront(oldList);
      list = getRest(oldList);
      (*first).value = NULL;
      (*first).next = NULL;
      free(first);
      free(oldList);
    } while (!isEmpty(list));
  }
}

void insertFront(struct StringList * list, char * v) {
  (*list).head = newStringNode(v, (*list).head);
}

void removeFront(struct StringList * list) {
  if (!isEmpty(list)) {
    (*list).head = (*((*list).head)).next;
  }
}

bool isEmpty(struct StringList * list) {
  return (*list).head == NULL;
}

int size(struct StringList * list) {
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

struct StringNode * getFront(struct StringList * list) {
  return (*list).head;
}

struct StringList * getRest(struct StringList * list) {
  if (isEmpty(list)) {
    return NULL;
  }
  struct StringList * rest;
  rest = newStringList();
  (*rest).head = (*((*list).head)).next;
  return rest;
}

void printStringList(struct StringList * list) {
  printf("[ ");
  if (!isEmpty(list)) {
    do {
      struct StringNode * first;
      first = getFront(list);
      printf("\"%s\" ",(*first).value);
      list = getRest(list);
    } while (!isEmpty(list));
  }
  printf("]");
}


