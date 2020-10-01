#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/keywords.h"

static unsigned int keywords_get_next_index () {
  unsigned int i;
  for (i = 0; i < MAX_KEYWORD_LIST_SIZE; i++)
    {
      if (keywords[i] == (keyword_t) 0x0)
	{
	  return i;
	}
    }

  return 0;
}

keyword_t find_keyword(const char *word) {
  unsigned int i;
  for (i = 0; i < MAX_KEYWORD_LIST_SIZE; i++)
    {
      if (keywords[i] != (keyword_t) 0x0)
	{
	  if (keywords[i]->word == word)
	    {
	      return keywords[i];
	    }
	}
    }

  return (keyword_t) 0x0;
}

keyword_t add_keyword (const char *word) {
  
  if (!word)
    {
      return (keyword_t) 0x0;
    }

  printf("Debug: condition->(!word) passed\n");
  
  const unsigned int current_keyword_index =	\
    keywords_get_next_index ();

  if (current_keyword_index > MAX_KEYWORD_LIST_SIZE-1)
    {
      return (keyword_t) 0x0;      
    }

  if (!find_keyword(word)) 
    {
      return (keyword_t) 0x0;
    }

  keywords[current_keyword_index] =		\
    malloc (sizeof *keywords[0]);

  if (keywords[current_keyword_index] != (keyword_t) 0x0)
    {
      keywords[current_keyword_index]->word  = (char*) word;
      keywords[current_keyword_index]->count = 1;
    }

  return keywords[current_keyword_index];
}
