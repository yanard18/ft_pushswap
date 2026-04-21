#include "push_swap.h"

void ra(t_stack **a, t_ctx *ctx, int print)
{
    t_stack *first;
    t_stack *last;

    if (!*a || !(*a)->next)
        return ;

    first = *a;
    last = stack_last(*a);

    *a = first->next;
    first->next = NULL;
    last->next = first;

    if (print)
    {
        write(1, "ra\n", 3);
        if (ctx && ctx->bench)
        {
            ctx->benchmark.ra++;
            ctx->benchmark.total_ops++;
        }
    }
}

void rb(t_stack **b, t_ctx *ctx, int print)
{
    t_stack *first;
    t_stack *last;

    if (!*b || !(*b)->next)
        return ;

    first = *b;
    last = stack_last(*b);

    *b = first->next;
    first->next = NULL;
    last->next = first;

    if (print)
    {
        write(1, "rb\n", 3);
        if (ctx && ctx->bench)
        {
            ctx->benchmark.rb++;
            ctx->benchmark.total_ops++;
        }
    }
}

void rr(t_stack **a, t_stack **b, t_ctx *ctx)
{
    int can_ra;
    int can_rb;

    can_ra = (a && *a && (*a)->next);
    can_rb = (b && *b && (*b)->next);

    if (!can_ra && !can_rb)
        return ;

    ra(a, ctx, 0);
    rb(b, ctx, 0);

    write(1, "rr\n", 3);
    if (ctx && ctx->bench)
    {
        ctx->benchmark.rr++;
        ctx->benchmark.total_ops++;
    }
}