#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Ingredient.h"

struct Ingredient * newIngredient(char * n, int cpg) {
  struct Ingredient * this;
  this = malloc(sizeof(*this));
  this -> name = n;
  this -> caloriesPerGram = cpg;
  return this;
}

struct Ingredient * mergeIngredients(struct Ingredient * a, struct Ingredient * b) {
  a -> caloriesPerGram += b->caloriesPerGram;
  return a;
}

int digitLength(int n) {
  return 1+ (int) (log10(n));
}

char * i2a(int n) {
  char * this;
  this = (char *)malloc((sizeof(char) * digitLength(n) ));
// SEGFAULT OCCURS: I am unsure of why the seg fault  continues even though 
// multiple changes have been made in attempt to fix the problem.  
sprintf(this,"%d",n);
  printf("n is %d, s is \"%s\"\n",n,this);
free(this);
  return this;

}


char * toString(struct Ingredient * a) {
  if (a == NULL || a->name == NULL) {
  free(a);
  return "NULL";
  }
  char * s2 = i2a(a->caloriesPerGram);
  
int len1 = strlen(a->name);
  int len2 = strlen(s2);
  char * string;
  string = malloc(sizeof(char)*(len1 + len2) + 1);
  for (int i=0; i<len1; i++) { string[i] = a->name[i]; }
  for (int i=0; i<len2; i++) { string[len1+i] = s2[i]; }
  string[len1+len2]='\0';
  
return string;
}
