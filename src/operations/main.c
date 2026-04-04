#include "push_swap.h"

void print_op(t_stack *a, t_stack *b, char *last_op)
{
    int i;
    int current;

    printf("\n");

    printf("\nafter %s\n", last_op);
    printf("stack a (size: %d | start: %d | end: %d)\n", a->size, a->start, a->end);
    printf("items: ");
    i = 0;
    current = a->start;
    while (i < a->size)
    {
        printf("[%d] ", a->value[current]);
        current = (current + 1) % a->capacity;
        i++;
    }
    printf("\nstack b (size: %d | start: %d | end: %d)\n", b->size, b->start, b->end);
    printf("items: ");
    i = 0;
    current = b->start;
    while (i < b->size)
    {
        printf("[%d] ", b->value[current]);
        current = (current + 1) % b->capacity;
        i++;
    }
    printf("\n\n");
}

int main(void)
{
    t_stack a;
    t_stack b;

    
    init_stacks(&a, &b);
    fill_stack_a(&a);

    return (0);
}