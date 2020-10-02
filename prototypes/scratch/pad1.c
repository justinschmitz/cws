#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   wordlen = (- 10 1)

 */

/* 
   char *cpunt (char *word, char buff[], size_t start, char end) {
      
   }
*/

int main () {

  const char *word = "We are";

  unsigned int wordlen = strlen(word);

  unsigned int index;
  for (index = 0; index < wordlen; index++)
    {
      if (word[index] == ' ')
	{
	  break;
	}

      putc(word[index], stdout);
    }
  
  
  return 0;
}
