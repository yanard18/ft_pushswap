#include "../../inc/push_swap.h"

void pb(t_stack *a, t_stack *b)
{
    if (a->size == 0)
        return ;
    stack_push(b, stack_pop(a), 1);
    write(1, "pb\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return ;
    stack_push(a, stack_pop(b), -1);
    write(1, "pa\n", 3);
}

void sa(t_stack *a)
{
    if (a->size < 2)
        return ;
    int first = a->start;
    int second = (a->start + 1) % a->capacity;
    
    int tmp = a->value[first];
    a->value[first] = a->value[second];
    a->value[second] = tmp;
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    if (b->size < 2)
        return ;
    int first = b->start;
    int second = (b->start + 1) % b->capacity;
    
    int tmp = b->value[first];
    b->value[first] = b->value[second];
    b->value[second] = tmp;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    int tmp;
    int first;
    int second;

    if (a->size >= 2)
    {
        first = a->start;
        second = (a->start + 1) % a->capacity;
        tmp = a->value[first];
        a->value[first] = a->value[second];
        a->value[second] = tmp;
    }
    if (b->size >= 2)
    {
        first = b->start;
        second = (b->start + 1) % b->capacity;
        tmp = b->value[first];
        b->value[first] = b->value[second];
        b->value[second] = tmp;
    }
    write(1, "ss\n", 3);
}