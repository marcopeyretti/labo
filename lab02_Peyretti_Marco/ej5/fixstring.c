#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {

    unsigned int tam=0;

    for (int i = 0; s[i] != '\0' ; i++){
        tam++;
     }
     return tam;

}

bool fstring_eq(fixstring s1, fixstring s2) {

    bool guarda=true;
    unsigned int i=0;
  while (s1[i] != '\0' && s2[i]!='\0'){
        if(s1[i]!=s2[i]){

        guarda= false;

     }
     i++;
   
  }
 if (s1[i]!='\0' || s2[i]!='\0')    
 {
    guarda=0;
 }
    return guarda;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {

    bool min = true;
    bool eq=0;
    unsigned int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'&& eq==0) {
            if(s1[i]<s2[i]){
                eq=1;
            }

            if(s1[i]>s2[i]){
                eq=1;
                min=0;
            }
            i++;

        }
        if(s1[i]!='\0' && eq==0){
                min=1;
            }

    return min;

}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);


}



