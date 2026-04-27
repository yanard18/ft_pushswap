#include "push_swap.h"

void set_adaptive_string(t_ctx *ctx, float disorder)
{
	if (disorder < 0.2)
		ctx->benchmark.strategy = "Adaptive / O(n²)";
	else if (disorder >= 0.2 && disorder < 0.5)
		ctx->benchmark.strategy = "Adaptive / O(n√n)";
	else if (disorder >= 0.5)
		ctx->benchmark.strategy = "Adaptive / O(nlogn)";
}

void	adaptive_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	float 	disorder;

	if (!stack_a || !*stack_a)
		return ;
		
	disorder = calculate_disorder(*stack_a);
	set_adaptive_string(ctx, disorder);

	if (handle_small_stacks(stack_a, stack_b, ctx))
		return ;
	if (disorder == 0.0)
		return ;
	else if (disorder < 0.2)
		simple_sort(stack_a, stack_b, ctx);
	else if (disorder >= 0.2 && disorder < 0.5)
		medium_sort(stack_a, stack_b, ctx);
	else if (disorder >= 0.5)
		complex_sort(stack_a, stack_b, ctx);
}
