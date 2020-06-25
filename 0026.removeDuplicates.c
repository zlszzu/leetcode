int removeDuplicates(int* nums, int numsSize){
    int i, j;
    int retSize = numsSize;
    for (i = 0, j = 1; j < numsSize; ++j) {
        if (nums[i] == nums[j]) {
            --retSize;
        } else if (i + 1 == j) {
            ++i;
        } else {
            ++i;
            nums[i] = nums[j];
        }
    }

    return retSize;
}