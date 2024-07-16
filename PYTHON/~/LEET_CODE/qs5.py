'''
class Solution:
	def rob(self,nums: list[int]):
		s = 0
		for i in range(0,len(nums)):
			if (i+1) % 2 == 1:
				print(nums[i])
				s += nums[i]
		return s

st = Solution()
nums = [2,7,9,3,1]
print(st.rob(nums))
'''


