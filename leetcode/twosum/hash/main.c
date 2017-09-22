#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *index; 
    int *tab;
    int len, max, min;
    int i;

    min = 99999999;
	
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < min)
            min = nums[i];
    }
	
    max = target - min;
    len = max - min + 1;

    tab = (int *)malloc(len * sizeof(int));
    index = (int *)malloc(2 * sizeof(int));
    for (i = 0; i< len; i++)
	tab[i] = -1;

    for (i = 0; i < numsSize; i++)
    {
	    if (nums[i] - min < len)
	    {
            if (tab[target - nums[i] -min] != -1)
            {
                index[0] = tab[target - nums[i] - min];
                index[1] = i;
                break;
            }
		    tab[nums[i] - min] = i;
	    }
    }
    free(tab);
    return index;
}

int main(int argc, char *argv[])
{
	int *p;
	int nums[10] = {1, 2, 3, 4, 11, 19, 7, 8, 9, 10};
	p = twoSum(nums, 10, 15); 
	printf("p[0] = %d, p[1] = %d\n", p[0], p[1]);
}
