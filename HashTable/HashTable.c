#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101

typedef struct nlist{
  struct nlist *next;
  char *name;
  char *def;
}HASH_TABLE;

static HASH_TABLE *hashtab[HASHSIZE];

unsigned int hash(char *str)
{
    unsigned hashval;
    
    for(hashval =0; *str != '\0'; str++)
      hashval = *str + 31 * hashval;
      
    return hashval % HASHSIZE;
}

char *strdup(char *s)
{
    char *p = NULL;
    p = (char*)malloc(strlen(s)+1);
    if(p != NULL){
      strcpy(p,s);
    }
    return p;
}

HASH_TABLE *lookup(char *s)
{
    HASH_TABLE *np;
    
    for((np = hashtab[hash(s)]); np != NULL; np = np->next)
      if(strcmp(np->name, s) == 0)
        return np;
        
    return NULL;
}

HASH_TABLE *install(char *name, char *defn)
{
  HASH_TABLE *np;
  unsigned int hashval;
  
  if((np=lookup(name)) == NULL) {
    np = (HASH_TABLE*) malloc (sizeof(HASH_TABLE));
    if((np == NULL) || (np->name = strdup(name)) == NULL)
        return NULL;
        
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    free((void*)np->defn);
  }
  
  if((np->defn=strdup(def)) == NULL)
    return NULL;
    
  return np;
  
}

int main()
{
  HASH_TABLE *np = install("one","I");
}