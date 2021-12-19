#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; ++i) {
        int other = target - nums[i];
        for (int j = i + 1; j < numsSize; ++j) {
            if (other == nums[j]) {
                int *result = (int *)malloc(2 * sizeof(int));
                if (result == NULL) {
                    printf("malloc failed\n");
                    return NULL;
                }
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}