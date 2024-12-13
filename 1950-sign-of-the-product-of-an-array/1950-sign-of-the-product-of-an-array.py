class Solution:
    def arraySign(self, nums: List[int]) -> int:
        # reduce(func, iterable, init)
        # lambda input arguement: output expression
        return 0 if 0 in nums else reduce(lambda x, y: x * (1 if y > 0 else -1), nums, 1)