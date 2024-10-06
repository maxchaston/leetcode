#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int* returnArray = malloc(sizeof(int) * 2);
    for (int i=0; i<numsSize-1; i++)
    {
        for (int j=i+1; j<numsSize; j++)
        {
            printf("checking %d, %d\n", nums[i], nums[j]);
            if (nums[i] + nums[j] == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            } 
        }
    }
    return NULL;
}

int main() 
{
	int nums[4] = {2,7,11,15};
	int* returnArray = twoSum(&nums, 4, 9);
	printf("[%d,%d]", returnArray[0], returnArray[1]);
	free(returnArray);
	return 0;
}
