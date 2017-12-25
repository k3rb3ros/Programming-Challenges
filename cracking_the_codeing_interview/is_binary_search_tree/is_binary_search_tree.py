class node:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

#return the maximum value of the given (sub) tree
def max(node, _max):
    if (not node is None):
    
        if (node.data > _max):
            _max = node.data

        _max = max(node.left, _max)
        _max = max(node.right, _max)

    return _max

#return the minimum value of the given (sub) tree
def min(node, _min):
    if (not node is None):

        if (node.data < _min):
            _min = node.data

        _min = min(node.left, _min)
        _min = min(node.right, _min)

    return _min

#logic flow continues unless we find a node that breaks the BST pattern 
def check_binary_search_tree_(root):
    if (not root is None):
        if (root.left is not None and not root.left.data <= root.data):
            return False
        if (root.right is not None and not root.right.data > root.data):
            return False

        if (max(root.left, -2147483648) >= root.data or
            min(root.right, 2147483647) <= root.data):
            return False

        if (not check_binary_search_tree_(root.left) or
            not check_binary_search_tree_(root.right)):
            return False

    return True
