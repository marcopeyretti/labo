#include <stdlib.h>  
#include <stdio.h> 
#include "pair.h"

pair_t pair_new(int x, int y)
{
  pair_t p;
  p.fst=x;
  p.snd=y;
  return p;
}

int pair_first(pair_t p)
{
    int x =p.fst;
    return x;
}

int pair_second(pair_t p)
{
    int x=p.snd;
    return x;
}

pair_t pair_swapped(pair_t p)
{
    int aux=p.fst;
    p.fst=p.snd;
    p.snd=aux;
    return p;
}

pair_t pair_destroy(pair_t p)
{
    pair_t *q=NULL;
    q=&p;
    free(q);
    return p;
}