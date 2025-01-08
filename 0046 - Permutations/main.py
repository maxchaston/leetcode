# 46. Permutations

# A pretty easy one, was working on 60 - Permutation Sequence and most of this was from my first attempt at that

class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        return self.recurse([], nums)

    def recurse(self, processed, remaining):
        if remaining == []:
            return [processed]
        found = []
        for num in remaining:
            tmp_processed = processed.copy()
            tmp_remaining= remaining.copy()
            tmp_processed.append(num)
            tmp_remaining.remove(num)
            print(tmp_remaining, tmp_processed)
            found+=(self.recurse(tmp_processed, tmp_remaining))
        return found
    def test(self):
        print(self.permute([1,2,3,4,5]))

x = Solution()
x.test()    
