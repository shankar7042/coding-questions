class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __repr__(self) -> str:
        return str(self.data)


def levelorder(root):
    if root is None:
        return

    queue = list()
    queue.append(root)
    queue.append(None)  # To verify that the level is end here

    while len(queue) != 0:
        node = queue.pop(0)
        if node is not None:
            print(node.data, end=" ")
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        elif len(queue) != 0:
            queue.append(None)


def inorder(root):
    if root is None:
        return

    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)


def preorder(root):
    if root is None:
        return

    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)


def postorder(root):
    if root is None:
        return

    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")


def levelorder2(root):
    if root is None:
        return

    queue = list()
    queue.append(root)
    queue.append(None)  # To verify that the level is end here
    level = 0
    print(level, '->', end="")
    while len(queue) != 0:
        node = queue.pop(0)
        if node is not None:
            print(node.data, end=" ")
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        elif len(queue) != 0:
            queue.append(None)
            level += 1
            print()
            print(level, '->', end="")


def kthSum(root, k):
    if root is None:
        return -1

    queue = list()
    queue.append(root)
    queue.append(None)
    level = 0
    ans = 0
    while len(queue) != 0:
        node = queue.pop(0)
        if node is not None:
            if level == k:
                ans += node.data
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        elif len(queue) != 0:
            queue.append(None)
            level += 1
    return ans


def total_nodes(root):
    if root is None:
        return 0
    return total_nodes(root.left)+total_nodes(root.right)+1


def sum_nodes(root):
    if root is None:
        return 0
    return sum_nodes(root.left) + sum_nodes(root.right) + root.data


def heigt(root):
    if root is None:
        return 0
    return max(heigt(root.left), heigt(root.right))+1


def sum_replacement(root):
    if root is None:
        return

    sum_replacement(root.left)
    sum_replacement(root.right)

    if root.left is not None:
        root.data += root.left.data
    if root.right is not None:
        root.data += root.right.data


def is_balanced(root):
    if root is None:
        return True

    if is_balanced(root.left) is False:
        return False

    if is_balanced(root.right) is False:
        return False

    lheight = heigt(root.left)
    rheight = heigt(root.right)

    if abs(lheight - rheight) <= 1:
        return True
    else:
        return False


def is_balanced_better(root):
    if root is None:
        return (0, True)

    lh, l_balanced = is_balanced_better(root.left)
    rh, r_balanced = is_balanced_better(root.right)

    return (max(lh, rh) + 1, l_balanced and r_balanced and (abs(lh-rh) <= 1))


def right_view(root: Node):
    if root is None:
        return

    q = list()
    q.append(root)

    while len(q) != 0:
        n = len(q)
        for i in range(n):
            node = q.pop(0)

            if i == n-1:
                print(node.data, end="->")

            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)


def left_view(root):
    if root is None:
        return

    q = list()
    q.append(root)

    while len(q) != 0:
        n = len(q)
        for i in range(n):
            node = q.pop(0)

            if i == 0:
                print(node.data, end="->")
            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)


def get_path(root, n, path):
    if root is None:
        return False
    path.append(root.data)
    if root.data == n:
        return True

    if get_path(root.left, n, path):
        return True

    if get_path(root.right, n, path):
        return True

    path.pop(len(path)-1)
    return False


def lowest_common_ancestor(root, n1, n2):
    path1 = list()
    path2 = list()
    if (not get_path(root, n1, path1)) or (not get_path(root, n2, path2)):
        return

    print(path1)
    print(path2)

    for i in range(min(len(path1), len(path2))):
        if path1[i] != path2[i]:
            break

    return path1[i-1]


def lowest_common_ancester_v2(root, n1, n2):
    if root is None:
        return None

    if root.data == n1 or root.data == n2:
        return root

    leftLCA = lowest_common_ancester_v2(root.left, n1, n2)
    rightLCA = lowest_common_ancester_v2(root.right, n1, n2)

    if leftLCA and rightLCA:
        return root

    if leftLCA is not None:
        return leftLCA

    if rightLCA is not None:
        return rightLCA

    return None


def findDist(root, k, dist):
    if root is None:
        return -1

    if root.data == k:
        return dist

    left = findDist(root.left, k, dist+1)
    if left != -1:
        return left
    return findDist(root.right, k, dist+1)


def shortest_distance_two_nodes(root, n1, n2):
    lca = lowest_common_ancester_v2(root, n1, n2)

    leftDist = findDist(lca, n1, 0)
    rightDist = findDist(lca, n2, 0)

    return leftDist + rightDist


def sortedArrayToBST(nums, low=None, high=None):
    if low <= high:
        mid = (low + high) // 2
        root = Node(nums[mid])
        root.left = sortedArrayToBST(nums, low, mid-1)
        root.right = sortedArrayToBST(nums, mid+1, high)
        return root


x = [-10, -3, 0, 5, 9]
root = sortedArrayToBST(x, 0, len(x)-1)
levelorder2(root)

# root = Node(1)
# root.left = Node(2)
# root.right = Node(3)
# root.left.left = Node(4)
# root.left.right = Node(5)
# root.right.left = Node(6)
# root.right.right = Node(7)

# print(shortest_distance_two_nodes(root, 2, 3))
