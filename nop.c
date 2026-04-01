#include "push_swap.h"

int move_counter(int increment)
{
    static int count = 0;

    count += increment;
    return (count);
}