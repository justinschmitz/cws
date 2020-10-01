#include <stdio.h>
#include <stdlib.h>
#include "include/keywords.h"

void test_add_keyword_0 () {
  const char *word = "test_add_keyword_0";
  
  keyword_t keyword = add_keyword(word);
  if (keyword)
    {
      printf("%s: passed\n", keyword->word);
      free(keyword);      
    }
  else
    {
      printf("%s: failed\n", word);
    }  
}

int main (int argc, char *argv[]) {
  test_add_keyword_0 ();
  return 0;
}
