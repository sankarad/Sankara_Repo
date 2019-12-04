#ifndef INT_LIST_H
#define INT_LIST_H

#include <stdbool.h>

/* A node in a singly-linked list of integers.
   value is the "payload" of this node
   next is a pointer to the next node in the list, or NULL if this is the last node of the list
 */
struct IntNode {
  int value;
  struct IntNode * next;
};

/* Constructs a new IntNode holding the value v, and with next pointer n (could be NULL).
 */
struct IntNode * newIntNode(int v, struct IntNode * n); 

/* A list struture.
   Holds a pointer to the first IntNode of the list (or NULL if the list is empty).
 */
struct IntList {
  struct IntNode * head;
};

/* Constructs a new empty IntList.
 */
struct IntList * newIntList();

/* Frees the memory occupied by list.
 */
void deleteIntList(struct IntList * list);

/* Adds the value v as the first value of the IntList list. 
 */
void insertFront(struct IntList * list, int v);

/* Removes the first value from the IntList list, if it is not empty.
   If list is empty, has no effect.
 */
void removeFront(struct IntList * list);

/* Returns true if list is empty, false otherwise */
bool isEmpty(struct IntList * list);

/* Returns the number of items in this list (0 if the list is empty) */
int  size(struct IntList * list);

/* Returns a pointer to the IntNode containing the first value in list, if list is not empty. 
   Returns NULL if list is empty. */
struct IntNode * getFront(struct IntList * list);

/* Returns a pointer to a new IntList holding a pointer to the first IntNode of the rest of the list, if list is not empty. 
   Returns NULL if list is empty. */
struct IntList * getRest(struct IntList *);

/* Prints a textual representation of the list to standard output */
void printIntList(struct IntList *);

#endif
