#include "../../inc/push_swap.h"

void rra(t_stack *a)
{
    if (a->size < 2)
        return ;
    a->start = (a->start - 1 + a->capacity) % a->capacity;
    a->end = (a->end - 1 + a->capacity) % a->capacity;
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    if (b->size < 2)
        return ;
    b->start = (b->start - 1 + b->capacity) % b->capacity;
    b->end = (b->end - 1 + b->capacity) % b->capacity;
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    if (a->size < 2 && b->size < 2)
        return ;
    if (a->size >= 2)
    {
        a->start = (a->start - 1 + a->capacity) % a->capacity;
        a->end = (a->end - 1 + a->capacity) % a->capacity;
    }
    if (b->size >= 2)
    {
        b->start = (b->start - 1 + b->capacity) % b->capacity;
        b->end = (b->end - 1 + b->capacity) % b->capacity;
    }
    write(1, "rrr\n", 4);
}