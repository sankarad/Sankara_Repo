#include <stdio.h>
#include <stdlib.h>
#include "StringList.h"

char * makeStringOnHeap(char s[]) {
  int len = 0;
  while (s[len++] != '\0');
  char * n;
  n = malloc(sizeof(char)*len);
  for (int i=0; i<len; i++) {
    n[i] = s[i];
  }
  printf("\"%s\" = \"%s\"\n",n,s);
  return n;
}

int main() {
  struct StringList *allStrings, *evenStrings, *oddStrings;
  allStrings = newStringList();
  evenStrings = newStringList();
  oddStrings = newStringList();
  int numberOfStrings = 11;
  char * strings[numberOfStrings];
  strings[0] = makeStringOnHeap("Buffy");
  strings[1] = makeStringOnHeap("Xander");
  strings[2] = makeStringOnHeap("Willow");
  strings[3] = makeStringOnHeap("Cordelia");
  strings[4] = makeStringOnHeap("Rupert");
  strings[5] = makeStringOnHeap("Oz");
  strings[6] = makeStringOnHeap("Spike");
  strings[7] = makeStringOnHeap("Rupert");
  strings[8] = makeStringOnHeap("Dawn");
  strings[9] = makeStringOnHeap("Tara");
  strings[10] = makeStringOnHeap("Angel");

  for (int i=0; i<numberOfStrings; i++) {
    printf("Inserting \"%s\" into ",strings[i]);
    printStringList(allStrings);
    printf("\n");
    insertFront(allStrings,strings[i]);
  }
  for (int i=0; i<numberOfStrings; i=i+2) {
    printf("Inserting \"%s\" into ",strings[i]);
    printStringList(evenStrings);
    printf("\n");
    insertFront(evenStrings,strings[i]);
  }
  for (int i=1; i<numberOfStrings; i=i+2) {
    printf("Inserting \"%s\" into ",strings[i]);
    printStringList(oddStrings);
    printf("\n");
    insertFront(oddStrings,strings[i]);
  }
  printf("Before \"Spike\" to \"SpIke\" and other edits\n");
  printStringList(allStrings);
  printf(" has size %d\n", size(allStrings));
  printStringList(evenStrings);
  printf(" has size %d\n", size(evenStrings));
  printStringList(oddStrings);
  printf(" has size %d\n", size(oddStrings));
  strings[6][2] = 'I';
  strings[5][0] = 'A';
  strings[5][1] = 'U';
  printf("After \"Spike\" to \"SpIke\" and other edits\n");
  printStringList(evenStrings);
  printf(" has size %d\n", size(evenStrings));

  /* DELETE #1 */
  //  deleteStringList(evenStrings);

  printStringList(oddStrings);
  printf(" has size %d\n", size(oddStrings));

  /* DELETE #2 */
  //  deleteStringList(oddStrings);

  printStringList(allStrings);
  printf(" has size %d\n", size(allStrings));

  /* DELETE #3 */
  //  deleteStringList(allStrings);

  return 0;
}
