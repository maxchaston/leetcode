# 60. Permutation Sequence
import math

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

'''
Solution explanation:

Calculate the number of permutations under each element, traverse straight
down the corrent node in the "tree" based on permutation number trying to find.

Not sure how this was a hard.
'''

def factorial(n):
    if n<=1:
        return 1
    return n * factorial(n-1)

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        l = list(range(1, n+1))
        tmp_k = k
        found = []
        while len(l)>1:
            layer_perm_num = factorial(len(l)-1) # number of possible permutations under each tree node
            index = math.ceil((tmp_k/layer_perm_num)-1)
            num = l[index]
            found.append(l[index])
            del l[index]
            tmp_k-=index*layer_perm_num
        found.append(l[0])
        s = ""
        for x in found:
            s+=str(x)
        return s

x = Solution()
print(x.getPermutation(3, 3))
    
