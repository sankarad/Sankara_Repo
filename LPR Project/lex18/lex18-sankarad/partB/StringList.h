#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <stdbool.h>

/* A node in a singly-linked list of strings (i.e. values of type char *).
   value is the "payload" of this node
   next is a pointer to the next node in the list, or NULL if this is the last node of the list
 */
struct StringNode {
  char * value;
  struct StringNode * next;
};

/* Constructs a new StringNode holding the value v, and with next pointer n (could be NULL).
 */
struct StringNode * newStringNode(char * v, struct StringNode * n); 

/* A list struture.
   Holds a pointer to the first StringNode of the list (or NULL if the list is empty).
 */
struct StringList {
  struct StringNode * head;
};

/* Constructs a new empty StringList.
 */
struct StringList * newStringList();

/* Frees the memory occupied by list.
 */
void deleteStringList(struct StringList * list);

/* Adds the value v as the first value of the StringList list. 
 */
void insertFront(struct StringList * list, char * v);

/* Removes the first value from the StringList list, if it is not empty.
   If list is empty, has no effect.
 */
void removeFront(struct StringList * list);

/* Returns true if list is empty, false otherwise */
bool isEmpty(struct StringList * list);

/* Returns the number of items in this list (0 if the list is empty) */
int  size(struct StringList * list);

/* Returns a pointer to the StringNode containing the first value in list, if list is not empty. 
   Returns NULL if list is empty. */
struct StringNode * getFront(struct StringList * list);

/* Returns a pointer to a new StringList holding a pointer to the first StringNode of the rest of the list, if list is not empty. 
   Returns NULL if list is empty. */
struct StringList * getRest(struct StringList * list);

/* Prints a textual representation of the list to standard output */
void printStringList(struct StringList * list);

#endif
