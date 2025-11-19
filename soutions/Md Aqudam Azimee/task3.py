def count_above_median(nums):
    nums.sort()
    
    mid = len(nums) // 2
    
    median = nums[mid] 

    count = 0
    for i in range(len(nums)):     
        if nums[i] > median:        
            count = count + 1

    return count

# Driver Code (do not modify)
n = int(input())
arr = list(map(int, input().split()))

print(count_above_median(arr))