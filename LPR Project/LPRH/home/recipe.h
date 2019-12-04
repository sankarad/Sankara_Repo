#ifndef COUNTS
#define COUNTS

#include <stdbool.h>


typedef struct {
	char * name;
	char * ingredient;
	int quant;
	int servings;
}Book;

typedef struct {

char * name;
int servings;

}Recipe;

typedef struct {
char * name ;
int calpg;

}Ingredient;


typedef struct{

int ingredients;
int quantities;

}Pantry;

void newBook();
Recipe * newRecipe(char * name, int servings);
Ingredient * newIngredient( char * name, int caloriesPerGram);
void newPantry();
int RecipeCreator(Recipe * food, Ingredient cont);





#endif

