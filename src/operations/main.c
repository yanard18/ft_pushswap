# include "../../inc/push_swap.h"

void print_op(t_stack *a, t_stack *b)
{
    for (int i = 0; i < a->capacity; i++)
    {
        if (i == a->start && i == a->end && a->size > 0)
            printf("Index [%02d]: %-10d <--- START & END\n", i, a->value[i]);
        else if (i == a->start)
            printf("Index [%02d]: %-10d <--- START\n", i, a->value[i]);
        else if (i == a->end)
            printf("Index [%02d]: %-10d <--- END\n", i, a->value[i]);
        else
            printf("Index [%02d]: %-10d\n", i, a->value[i]);
    }
    printf("\n");
    for (int i = 0; i < a->capacity; i++)
    {
        if (i == b->start && i == b->end && b->size > 0)
            printf("Index [%02d]: %-10d <--- START & END\n", i, b->value[i]);
        else if (i == b->start)
            printf("Index [%02d]: %-10d <--- START\n", i, b->value[i]);
        else if (i == b->end)
            printf("Index [%02d]: %-10d <--- END\n", i, b->value[i]);
        else
            printf("Index [%02d]: %-10d\n", i, b->value[i]);
    }
    printf("\n\n");
}

// void print_op(t_stack *a, t_stack *b)
// {
//     int i;
//     int current;

//     printf("\n");

//     printf("stack a (size: %d | start: %d | end: %d)\n", a->size, a->start, a->end);
//     printf("items: ");
//     i = 0;
//     current = a->start;
//     while (i < a->size)
//     {
//         printf("[%d] ", a->value[current]);
//         current = (current + 1) % a->capacity;
//         i++;
//     }
//     printf("\nstack b (size: %d | start: %d | end: %d)\n", b->size, b->start, b->end);
//     printf("items: ");
//     i = 0;
//     current = b->start;
//     while (i < b->size)
//     {
//         printf("[%d] ", b->value[current]);
//         current = (current + 1) % b->capacity;
//         i++;
//     }
//     printf("\n\n");
// }

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int *numbers;
    int size;
    int i;

    numbers = malloc(sizeof(int) * size);

    i = 0;
    size = argc - 1;
    while (i < size)
    {
        numbers[i] = ps_atoi(argv[i + 1]);
        i++;
    }

    init_stack(&a, size);
    init_stack(&b, size);
    fill_stack(&a, numbers, size);

    print_op(&a, &b);

    ra(&a);
    print_op(&a, &b);

    ra(&a);
    print_op(&a, &b);

    ra(&a);
    print_op(&a, &b);
    
    pb(&a, &b);
    print_op(&a, &b);

    pb(&a, &b);
    print_op(&a, &b);

    pb(&a, &b);
    print_op(&a, &b);

    rb(&b);
    print_op(&a, &b);

    pa(&a, &b);
    print_op(&a, &b);

    pa(&a, &b);
    print_op(&a, &b);

    pa(&a, &b);
    print_op(&a, &b);
    
    return (0);
}