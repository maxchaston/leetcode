# 60. Permutation Sequence

'''
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"

Example 3:

Input: n = 3, k = 1
Output: "123"

 

Constraints:

    1 <= n <= 9
    1 <= k <= n!
'''

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        self.count = 0
        self.k = k
        self.n = n
        l = list(range(1, n+1))
        ret = flatten(self.recursivePermute([], l))
        s = ""
        for x in ret:
            s+=str(x)
        return s
    def recursivePermute(self, processed, remaining):
        if remaining == []:
            self.count+=1
            print(self.count)
            if self.count==self.k:
                print(f"Found {processed}")
                return processed
        found = []
        for num in remaining:
            tmp_remain = remaining.copy()
            tmp_processed = processed.copy()
            tmp_processed.append(num)
            tmp_remain.remove(num)
            found.append(self.recursivePermute(tmp_processed, tmp_remain))
        return list(filter(lambda x: x!=[], found))
    def test(self):
        print(self.recursivePermute([], list(range(1, 10))))

def flatten(possiblyNestedList):
    # Flatten abritrarily nested list
    if not isinstance(possiblyNestedList, list):
        return
    flattened = []
    for item in possiblyNestedList:
        if isinstance(item, list):
            flattened.extend(flatten(item))
        else:
            flattened.append(item)
    return flattened


x = Solution()
print(x.getPermutation(4, 9))
    
