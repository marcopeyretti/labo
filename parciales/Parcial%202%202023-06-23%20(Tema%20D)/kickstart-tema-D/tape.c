#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "tape.h"

struct _s_node {
    tape_elem elem;
    struct _s_node *next;
};

typedef struct _s_node * node_t;

struct _s_tape {
    unsigned int size;
    node_t cursor;  // Puntero al elemento actual
    node_t start;   // Puntero al primer nodo de la cinta
};

static bool invrep(tape_t tape) {
    return tape!=NULL;
}

static node_t create_node(tape_elem e) {
    node_t new_node=malloc(sizeof(node_t));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static node_t destroy_node(node_t node) {
        node->next=NULL;
    free(node);
    node=NULL;
    return node;
}

tape_t tape_create(void) {
    tape_t tape=NULL;
    tape=malloc(sizeof(tape_t));
    assert(invrep(tape) && tape_is_empty(tape) && tape_at_start(tape));
    return tape;
}

tape_t tape_rewind(tape_t tape) {
    tape->cursor=tape->start;
    return tape;
}


bool tape_at_start(tape_t tape) {
    return tape->cursor==tape->start;
}

bool tape_at_stop(tape_t tape) {
    return tape->cursor==NULL;
}

bool tape_is_empty(tape_t tape) {
        return tape->size==0;
}

unsigned int tape_length(tape_t tape) {
    return tape->size;
}

tape_t tape_step(tape_t tape) {
    assert(tape->size>0);
    tape->cursor=tape->cursor->next;
    return tape;
}

tape_t tape_insertl(tape_t tape, tape_elem e) {
    node_t new_node=create_node(e),aux_node=tape->start;
    if(tape->start!=NULL)
    {
        new_node->next=tape->cursor;
        if(tape->start==tape->cursor)
        {
            tape->start=new_node;
            tape->cursor=new_node;
        }
        else
        {
        while (aux_node->next != tape->cursor)
        {
            aux_node = aux_node->next;
        }
        aux_node->next=new_node;
        tape->cursor=new_node;
       }
    }
    else 
    {
        tape->start=new_node;
        tape->cursor=new_node;
    }
    tape->size++;
    
    return tape;
}

tape_t tape_insertr(tape_t tape, tape_elem e) {
    assert(invrep(tape) && (!tape_at_stop(tape) || tape_is_empty(tape)));
    node_t new_node=create_node(e);
    if (tape->start!= NULL) {
        new_node->next = tape->cursor->next;
        tape->cursor->next = new_node;
        tape->cursor = new_node;
    } else {
        tape->start = new_node;
        tape->cursor = new_node;
    }
    tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t tape_erase(tape_t tape) {
     node_t n = tape->cursor;
    if (tape->cursor == tape->start)
    {
        tape->start = tape->start->next;
        tape->cursor = tape->start;
    } else
    {
        node_t previo = tape->start;
        while (previo->next != tape->cursor)
        {
            previo = previo->next;
        }
        previo->next = tape->cursor->next;
        tape->cursor = previo->next;

    }

    n = destroy_node(n);
    tape->size--;

    return tape;
}

tape_elem tape_read(tape_t tape) {
    return tape->cursor->elem;
}

void tape_dump(tape_t tape) {
    assert(invrep(tape));
    node_t node=tape->start;
    printf("#");
    while (node != NULL) {
        if (node != tape->cursor) {
            printf("-%c-", node->elem);
        } else {
            printf("-[%c]-", node->elem);
        }
        node = node->next;
    }
    if (tape->cursor==NULL) {
        printf("-[]-");
    }
    printf("#\n");
}

tape_t tape_copy(tape_t tape) {
    tape_t new_tape=NULL;
    new_tape=tape_create();
    node_t new_node=create_node(0);
    if(tape->start!=NULL)
    {
    new_node->elem=tape->start->elem;
    new_tape->start=new_node;
    new_tape->cursor=new_node;
    new_node=tape->start;
    while (new_node->next!=NULL)
    {
        new_tape->cursor->next->elem=new_node->next->elem;
        new_tape->cursor=new_tape->cursor->next;
        new_node=new_node->next;
    }
        new_tape->cursor->next=NULL;
        new_tape->cursor=new_tape->start;
        new_tape->size=tape->size;
    }
    else
    {
        new_tape->start=NULL;
        new_tape->cursor=new_tape->start;
        new_tape->size=tape->size;
    }
    
    return new_tape;
}

tape_t tape_destroy(tape_t tape) {
    node_t new_node=create_node(0);
    while(tape->size>0)
    {
        tape->cursor=tape->start;
        while (tape->cursor!=NULL)
        {
            new_node=tape->cursor;
            tape->cursor=tape->cursor->next;
            destroy_node(new_node);
            tape->size--;
        }
        
    }
    free (tape);
    tape=NULL;
    return tape;
}


