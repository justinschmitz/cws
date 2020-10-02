#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/keywords.h"

static unsigned int keywords_get_next_index () {
  unsigned int index;
  for (index = 0; index < MAX_KEYWORD_LIST_SIZE; index++)
    {
      if (keywords[index] == (keyword_t) 0x0)
	{
	  return index;
	}
    }

  return (unsigned int) 0;
}

static void print_keyword (keyword_t keyword) {
  if (keyword)
    {
      if (keyword->word)
	{
	  printf("%d %s\n", keyword->count, keyword->word);
	}
    }
}

keyword_t add_keyword (const char *word) {
  if (!word)
    {
      return (keyword_t) 0x0;
    }
  
  const unsigned int current_keyword_index =	\
    keywords_get_next_index ();
  
  if (current_keyword_index > MAX_KEYWORD_LIST_SIZE-1)
    {
      return (keyword_t) 0x0;      
    }

  keyword_t keyword = find_keyword(word);

  if (keyword)
    {
      keyword->count++;
      return keyword;
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

keyword_t find_keyword(const char *word) {
  if (!word)
    {
      return (keyword_t) 0x0;
    }
  
  unsigned int index;
  for (index = 0; index < MAX_KEYWORD_LIST_SIZE; index++)
    {
      if (keywords[index] != (keyword_t) 0x0)
	{
	  if (keywords[index]->word == word)
	    {
	      return keywords[index];
	    }
	}
    }

  return (keyword_t) 0x0;
}

void print_keywords(void) {
  unsigned int index;
  for (index = 0; index < MAX_KEYWORD_LIST_SIZE; index++)
    {
      if (keywords[index] != (keyword_t) 0x0)
	{
	  print_keyword(keywords[index]);
	}
    }
}

void clean_keywords(void) {
  unsigned int index;
  for (index = 0; index < MAX_KEYWORD_LIST_SIZE; index++)
    {
      if (keywords[index] != (keyword_t) 0x0)
	{
	  free(keywords[index]);
	  keywords[index] = (keyword_t) 0x0;
	}
    }
}
