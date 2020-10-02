#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

#define MAX_KEYWORD_LIST_SIZE 128

typedef struct __keyword_t {
  unsigned int count;
  char *word;
} *keyword_t;

static keyword_t keywords[MAX_KEYWORD_LIST_SIZE] =	\
  {(keyword_t) 0x0};

extern keyword_t add_keyword(const char*);
extern keyword_t find_keyword(const char*);
extern void print_keywords(void);
extern void clean_keywords(void);
#endif
