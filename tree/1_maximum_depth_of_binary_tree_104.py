import binary_tree

class Solution1:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

class Solution2:
    def __init__(self):
        self.depth, self.res = 0, 0
    
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.traverse(root)
        return res
    
    def traverse(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.depth += 1
        if not root.left and not root.right:
            self.res = max(self.res, self.depth)
        if root.left:
            traverse(root.left)
        if root.right:
            traverse(root.right)
        self.depth -= 1
        return

class Solution3:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        queue = [root]
        depth = 0

        while queue:
            n = len(queue)
            for i in range(n):
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            depth += 1
        return depth
