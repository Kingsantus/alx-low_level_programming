#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

int jump_search(int *array, size_t size, int value)
{
    size_t jump_step = (size_t)sqrt(size);
    size_t left = 0, right = 0;
    
    size_t i = left;
     
    if (array == NULL)
        return (-1);

    while (right < size && array[right] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", right, array[right]);
        left = right;
        right += jump_step;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", left, right);
   
    while (i < size && i <= right)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i);
        ++i;
    }

    return (-1);
}
