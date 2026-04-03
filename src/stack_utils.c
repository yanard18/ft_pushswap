#include "push_swap.h"

void push(t_stack *s, int value)
{
    s->start = (s->start - 1 + s->capacity) % s->capacity;
    s->value[s->start] = value;
    if (s->size == 0)
        s->end = s->start;
    s->size++;
}

int pop(t_stack *s)
{
    int value;
    
    value = s->value[s->start];
    s->start = (s->start + 1) % s->capacity;
    s->size--;

    if (s->size == 1)
        s->end = s->start;

    if (s->size == 0)
    {
        s->start = 0;
        s->end = 0;
    }
    
    return (value);
}

void init_stacks(t_stack *a, t_stack *b, int size)
{
    a->value = malloc(sizeof(int) * size);
    b->value = malloc(sizeof(int) * size);

    a->capacity = size;
    b->capacity = size;

    a->size = 0;
    b->size = 0;

    a->start = 0;
    b->start = 0;
}

void fill_stack_a(t_stack *a, int *numbers, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        a->value[i] = numbers[i];
        i++;
    }
    a->size = size;
    a->start = 0;
    a->end = size - 1; 
}