#include "push_swap.h"

void print_benchmark(t_ctx *ctx)
{
    if (!ctx || ctx->bench == 0)
        return ;
    
    printf("[bench] disorder: %.2f%%\n", ctx->benchmark.disorder);
    printf("[bench] strategy: %s\n", ctx->benchmark.strategy);
    printf("[bench] total_ops: %d\n", ctx->benchmark.total_ops);
    printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
        ctx->benchmark.sa, ctx->benchmark.sb, ctx->benchmark.ss, 
        ctx->benchmark.pa, ctx->benchmark.pb);
    printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
        ctx->benchmark.ra, ctx->benchmark.rb, ctx->benchmark.rr, 
        ctx->benchmark.rra, ctx->benchmark.rrb, ctx->benchmark.rrr);
}