#include "push_swap.h"

void pb(t_stack **a, t_stack **b, t_ctx *ctx)
{
    t_stack *node_to_move;

    if (!*a)
        return ;

    node_to_move = *a;
    *a = (*a)->next;
    node_to_move->next = *b;
    *b = node_to_move;
    write(1, "pb\n", 3);
    if (ctx && ctx->bench)
    {
        ctx->benchmark.pb++;
        ctx->benchmark.total_ops++;
    }
}

void pa(t_stack **a, t_stack **b, t_ctx *ctx)
{
    t_stack *node_to_move;

    if (!*b)
        return ;
    node_to_move = *b;
    *b = (*b)->next;
    node_to_move->next = *a;
    *a = node_to_move;
    write(1, "pa\n", 3);
    if (ctx && ctx->bench)
    {
        ctx->benchmark.pa++;
        ctx->benchmark.total_ops++;
    }
}

void sa(t_stack **a, t_ctx *ctx, int print)
{
    int tmp;

    if (!*a || !(*a)->next)
        return ;

    tmp = (*a)->value;
    (*a)->value = (*a)->next->value;
    (*a)->next->value = tmp;

	tmp = (*a)->normalized_value;
    (*a)->normalized_value = (*a)->next->normalized_value;
    (*a)->next->normalized_value = tmp;

    if (print)
    {
        write(1, "sa\n", 3);
        if (ctx && ctx->bench)
        {
            ctx->benchmark.sa++;
            ctx->benchmark.total_ops++;
        }
    }
}        

void sb(t_stack **b, t_ctx *ctx, int print)
{
     int tmp;

    if (!*b || !(*b)->next)
        return ;

    tmp = (*b)->value;
    (*b)->value = (*b)->next->value;
    (*b)->next->value = tmp;

	tmp = (*b)->normalized_value;
	(*b)->normalized_value = (*b)->next->normalized_value;
    (*b)->next->normalized_value = tmp;

    if (print)
    {        
        write(1, "sb\n", 3);
        if (ctx && ctx->bench)
        {
            ctx->benchmark.sb++;
            ctx->benchmark.total_ops++;
        }
    }
}

void ss(t_stack **a, t_stack **b, t_ctx *ctx)
{
    int can_swap_a;
    int can_swap_b;

    can_swap_a = 0;
    can_swap_b = 0;
    if (*a && (*a)->next)
        can_swap_a = 1;
    if (*b && (*b)->next)
        can_swap_b = 1;
    if (!can_swap_a && !can_swap_b)
        return ;
    if (can_swap_a)
        sa(a, ctx, 0);
    if (can_swap_b)
        sb(b, ctx, 0);
    if (ctx && ctx->bench)
    {
        ctx->benchmark.ss++;
        ctx->benchmark.total_ops += 2;
    }
    write(1, "ss\n", 3);
}
