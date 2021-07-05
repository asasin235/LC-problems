class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        n = len(nums)
        m = len(nums[0])
        if n*m != r*c:
            return nums
        else:
            l = []
            res = []
            for i in range(n):
                l.extend(nums[i])
            for i in range(r):
                res.append(l[i*c:i*c+c])
            return res
        