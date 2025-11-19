#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int dp[numsSize];

    dp[0] = nums[0];
    dp[1] = MAX(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[numsSize - 1];
}

int main() {
    int n;

    printf("Enter the number of houses: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter the money in each house [space seperated]: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = rob(nums, n);
    printf("%d\n", result);

    free(nums);

    return 0;
}