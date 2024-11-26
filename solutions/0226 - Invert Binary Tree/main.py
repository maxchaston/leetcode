# 226. Invert Binary Tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        # base case
        if root is None:
            return root

        # swap nodes
        tmp = root.left
        root.left = root.right
        root.right = tmp

        # go down
        root.left = self.invertTree(root.left)
        root.right= self.invertTree(root.right)

        # go up 
        return root
