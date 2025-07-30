from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        longestSubarrayLength = 0
        length = 0
        maxi = max(nums)

        for num in nums:
            if num == maxi:
                length += 1
            else:
                longestSubarrayLength = max(longestSubarrayLength, length)
                length = 0

        return max(longestSubarrayLength, length)
