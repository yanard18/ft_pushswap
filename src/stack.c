#include "push_swap.h"

void swap(t_stack *s)
{
    int tmp;
    int second_index;

    if (s->size < 2)
        return ;
    
    second_index = (s->start + 1) % s->capacity;
    
    tmp = s->value[s->start];
    s->value[s->start] = s->value[second_index];
    s->value[second_index] = tmp;
}

void push(t_stack *s, int value)
{
    if (s->size == 0)
    {
        s->start = 0;
        s->end = 0;
    }
    else 
        s->start = (s->start - 1 + s->capacity) % s->capacity;
    s->value[s->start] = value;
    s->size++;
}

int pop(t_stack *s)
{
    int value;
    
    value = s->value[s->start];
    s->size--;

    if (s->size == 0)
    {
        s->start = 0;
        s->end = 0;
    }
    else
        s->start = (s->start + 1) % s->capacity;
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

    a->end = 0;
    a->end = 0;
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
