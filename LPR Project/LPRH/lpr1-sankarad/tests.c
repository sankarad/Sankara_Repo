#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CUnit.h"
#include "Basic.h"
#include "recipe.h"

void runTest0(char filename , char * target, Book expected) {
  Book actual = newBook();
  CU_ASSERT_EQUAL(expected,actual);
}
void runTest1(char * filename, char * target, Recipe *  expected) {
  Recipe * actual = newRecipe(char * name, int servings);
  CU_ASSERT_EQUAL(expected,actual);
}
void runTest2(char * filename, char * target, Ingredient * expected) {
  Ingredient * actual = newIngredient(char * name, int caloriesPerGram);
  CU_ASSERT_EQUAL(expected,actual);
}
void runTest3(char * filename, char * target, Pantry * expected) {
  Pantry * actual = newPantry();
  CU_ASSERT_EQUAL(expected,actual);
}
void test_00(void) { runFileTest0("recipe", "cusine", ""); }
void test_01(void) { runFileTest1("recipe", " ", ""); }
void test_02(void) { runFileTest2("recipe", " "," " ); }
void test_03(void) { runFileTest3("recipe", " ", "" ); }

int init_suite1(void) { return 0; }    /* The suite initialization function. */
int clean_suite1(void) { return 0; }   /* The suite cleanup function. */

/* The main() function for setting up and running the tests.
 *  * Returns a CUE_SUCCESS on successful running, another
 *   * CUnit error code on failure.
 *    */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (
          (NULL == CU_add_test(pSuite, "file01:therefore", test_01))
              || (NULL == CU_add_test(pSuite, "file03:was", test_02))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
      
