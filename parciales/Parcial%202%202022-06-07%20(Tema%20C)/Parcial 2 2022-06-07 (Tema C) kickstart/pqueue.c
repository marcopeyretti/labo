#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    node_p *queue;
    priority_t prio;
    unsigned int size;
};

struct s_node {
    pqueue_elem elem;
    node_p next;
};

static struct s_node * create_node(pqueue_elem e) {
    struct s_node* new_node=malloc(sizeof(*new_node));
    assert(new_node!=NULL);
    new_node->elem=e;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool invrep(pqueue q) {
    return q!=NULL;
}

pqueue pqueue_empty(priority_t min_priority) {
    pqueue q=NULL;
    q=malloc(sizeof(*q));
    q->queue=calloc(min_priority+1,sizeof(*q->queue));
    q->size=0;
    q->prio=0;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) {
    assert(invrep(q));
    node_p new_node=create_node(e),aux=NULL;
    if(q->queue[priority]==NULL)
    {
        q->queue[priority]=new_node;
    }
    else
    {
        aux=q->queue[priority];
        while(aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=new_node;
    }
    q->size++;
    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return q->size==0; 
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    pqueue_elem qelem=q->queue[pqueue_peek_priority(q)]->elem;
    return qelem;
}

priority_t pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t peek_priority=0;
    if(q!=NULL)
    {
    while (q->size>0 && q->queue[peek_priority]==NULL )
    {
           peek_priority++;   
    }
    }
    return peek_priority;
}

size_t pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    node_p aux;
    aux=q->queue[pqueue_peek_priority(q)];
    q->queue[pqueue_peek_priority(q)]=q->queue[pqueue_peek_priority(q)]->next;
    destroy_node(aux);
    assert(invrep(q));
    q->size--;
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    while(q->size>0)
    {
        q=pqueue_dequeue(q);
    }
    free(q->queue);
    q->queue=NULL;
    free(q);
    q=NULL;
    return q;
}

