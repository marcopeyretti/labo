#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) 
{
    unsigned int length=0,i=0;
    while (s[i] != '\0') 
    {
        length++;
        i++;
        assert(i!=FIXSTRING_MAX);
    }
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) 
{
    for(unsigned int i=0;i<fstring_length(s1) && i<fstring_length(s2);i++)
    {
        if(s1[i]!=s2[i])
        {
            return 0;
        }
    }
    return 1;
}

bool fstring_less_eq(fixstring s1, fixstring s2) 
{
    for(unsigned int i=0;i<fstring_length(s1) && i<fstring_length(s2);i++)
    {
        if(s1[i]>s2[i])
        {
            return 0;
        }
    }
    return 1;
}

