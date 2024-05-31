#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "stringbuffer.h"

struct s_stringbuffer
{
    struct s_node *first;
    struct s_node *last;
    unsigned int size;
};

struct s_node
{
    char c;
    struct s_node *nextchar;
};

typedef struct s_node *node_t;

// Representation invariant
static bool invrep(stringbuffer sb)
{
    bool valid = false;
    valid = sb != NULL;
    return valid;
}

// Creates a single node in dynamic memory with a given char
static node_t create_node(char c)
{
    node_t newnode = NULL;
    newnode = malloc(sizeof(*newnode));
    newnode->c = c;
    newnode->nextchar = NULL;
    assert(newnode != NULL);
    return newnode;
}

// Destroy a single node
static node_t destroy_node(node_t node)
{
    node->nextchar = NULL;
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}

// Public functions of the Abstract Data Type
stringbuffer stringbuffer_empty(void)
{
    stringbuffer sb = malloc(sizeof(*sb));
    sb->first = NULL;
    sb->last = NULL;
    sb->size = 0;
    assert(invrep(sb) && stringbuffer_is_empty(sb));
    return sb;
}

stringbuffer stringbuffer_create(const char *word)
{
    assert(word != NULL);
    node_t newnode = NULL;
    node_t first = NULL;
    node_t last = NULL;
    newnode = malloc(sizeof(word));
    first = malloc(sizeof(*first));
    last = malloc(sizeof(*last));
    unsigned int pos = 2;
    stringbuffer sb = stringbuffer_empty();
    if (sizeof(word) == 0)
    {
        sb->first = NULL;
        sb->last = NULL;
    }
    else
    {
        first->c = word[0];
        last->c = word[sizeof(word)];
        if (sizeof(word) > 1)
        {
            newnode->c = word[1];
            first->nextchar = newnode;
            sb->first = first;
            while (newnode != last)
            {
                newnode = newnode->nextchar;
                newnode->c = word[pos];
                pos++;
            }
            sb->last = last;
            newnode->nextchar = sb->last;
            assert(invrep(sb));
        }
        else
        {
            sb->first = first;
            sb->last = last;
        }
        sb->size = sb->size + sizeof(word);
    }
    return sb;
}

bool stringbuffer_is_empty(stringbuffer sb)
{
    assert(invrep(sb));
    if (sb->first == NULL)
    {
        assert(invrep(sb));
        return true;
    }
    else
    {
        assert(invrep(sb));
        return false;
    }
}

stringbuffer stringbuffer_append(stringbuffer sb, const char c)
{
    assert(invrep(sb));
    node_t newnode = create_node(c);
    if (sb->last != NULL)
    {
        sb->last->nextchar = newnode;
        sb->last = sb->last->nextchar;
    }
    else
    {
        sb->first = newnode;
        sb->last = newnode;
    }
    assert(invrep(sb) && !stringbuffer_is_empty(sb));
    sb->size++;
    return sb;
}

char stringbuffer_char_at(stringbuffer sb, unsigned int index)
{
    assert(invrep(sb) && !stringbuffer_is_empty(sb) && index < stringbuffer_length(sb));
    unsigned pos = 0;
    node_t node = sb->first;
    while (pos < index)
    {
        node = node->nextchar;
        pos++;
    }
    return node->c;
}

stringbuffer stringbuffer_remove(stringbuffer sb, unsigned int index)
{
    assert(invrep(sb));
    node_t node = sb->first, prev = NULL;
    unsigned pos = 0;
    if (index < sb->size)
    {
        prev = node;
        while (pos < index)
        {
            prev = node;
            node = node->nextchar;
        }
        prev->nextchar = node->nextchar;
        free(node);
        sb->size--;
    }
    assert(invrep(sb));
    return sb;
}

stringbuffer stringbuffer_replace(stringbuffer sb, const char c, unsigned int index)
{
    assert(invrep(sb) && index < stringbuffer_length(sb));
    node_t node = sb->first;
    unsigned pos = 0;
    while (pos < index)
    {
        node = node->nextchar;
    }
    node->c = c;
    assert(invrep(sb));
    return sb;
}

unsigned int stringbuffer_length(stringbuffer sb)
{
    assert(invrep(sb) && stringbuffer_is_empty(sb) == (sb->size == 0));
    return sb->size;
}

char *stringbuffer_to_string(stringbuffer sb)
{
    assert(invrep(sb));
    char *string = malloc(sizeof(*string));
    unsigned int pos = 1;
    string[0] = sb->first->c;
    node_t newnode = sb->first->nextchar;
    if (sb->size > 1)
    {
        while (pos < sb->size - 1)
        {
            string[pos] = newnode->c;
            newnode = newnode->nextchar;
        }
        string[sb->size - 1] = sb->last->c;
    }
    return string;
}

void stringbuffer_dump(stringbuffer sb)
{
    assert(invrep(sb));
    node_t node = sb->first;
    while (node != NULL)
    {
        printf("%c", node->c);
        node = node->nextchar;
    }
    printf("\n");
}

stringbuffer stringbuffer_destroy(stringbuffer sb)
{
    assert(invrep(sb));
    node_t newnode = sb->first;
    while (sb->first != NULL)
    {
        sb->first = sb->first->nextchar;
        destroy_node(newnode);
        newnode = sb->first;
    }
    free(newnode);
    free(sb);
    sb = NULL;
    assert(sb == NULL);
    return sb;
}
