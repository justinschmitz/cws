#include <stdio.h>
#include <stdlib.h>

#include "include/keywords.h"

void test_add_keyword_0 (void) {
  const char *word = "test_add_keyword_0";
  
  keyword_t keyword = add_keyword(word);
  if (keyword)
    {
      printf("%s: passed\n", keyword->word);
    }
  else
    {
      printf("%s: failed\n", word);
    }

  print_keywords();
  clean_keywords();
}

void test_add_keyword_1 (void) {
  const char *word1 = "test_add_keyword_1";
  const char *word2 = "test_add_keyword_2";
  
  add_keyword(word1);
  add_keyword(word1);
  add_keyword(word2);
  add_keyword(word2);
  add_keyword(word2);

  print_keywords();
  clean_keywords();
}

int main (int argc, char *argv[]) {
  
  test_add_keyword_0 ();
  test_add_keyword_1 ();
  return 0;
}
