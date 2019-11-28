/**
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 示例:
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 说明:
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n2) 。
 * 进阶: 你能将算法的时间复杂度降低到 O(nlog n) 吗?
 */

#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize);

int main() {
    
    int numsSize;
    
    printf("Please enter numsSize: ");
    scanf("%d", &numsSize);
    
    printf("Please enter nums: ");
    int* nums = (int *)malloc(sizeof(int)*numsSize);
    
    for (size_t i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    int res = lengthOfLIS(nums, numsSize);
    printf("res = %d\n", res);
    
    return 0;

}

int lengthOfLIS(int* nums, int numsSize) {
    
    int maxL = 0;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    
    for (size_t i = 0; i < numsSize; i++) {
        int lo = 0, hi = maxL;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (dp[mid] < nums[i]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        dp[lo] = nums[i];
        if (lo == maxL) {
            maxL++;
        }
    }
    
    return maxL;

}
