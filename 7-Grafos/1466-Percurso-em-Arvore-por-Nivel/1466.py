from collections import deque

class BinaryTree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        if data < self.data:
            if self.left is not None:
                self.left.insert(data)
            else:
                self.left = BinaryTree(data)
        else:
            if self.right is not None:
                self.right.insert(data)
            else:
                self.right = BinaryTree(data)

def bfs(node):
    visited, queue = [], deque([node])
    while queue:
        n = queue.popleft()
        visited.append(n.data)
        if n.left is not None:
            queue.append(n.left)
        if n.right is not None:
            queue.append(n.right)
    return visited

for i in range (int(input())):
    input()
    nodes = list(map(int, input().split()))
    tree = BinaryTree(nodes[0])
    nodes.remove(nodes[0])
    for q in nodes:
        tree.insert(q)
    print (f"Case {i+1}:")
    Bfs = bfs(tree)
    for index, q in enumerate (Bfs):
        if index == len(Bfs) - 1:
            print(q)
        else:
            print(q, '',end='')
    print ()