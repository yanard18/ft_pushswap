#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack
{
    int *value;
    int capacity;
    int size;
    int start;
    int end;
} t_stack;

int	ps_atoi(const char *str);
void push(t_stack *s, int value);
int pop(t_stack *s);
void init_stacks(t_stack *a, t_stack *b, int count);
void fill_stack_a(t_stack *a, int *valid_ints, int count);

#endif