class BinaryTree:
    def __init__(self,valueNode)->None:
        self.value=valueNode
        self.left=None
        self.right=None
        self.display=None
    def appendElement(self,node,newValue)->None:
        if not node.left and newValue<node.value+1:
            node.left=BinaryTree(newValue)
            return
        if not node.right and newValue>node.value:
            node.right=BinaryTree(newValue)
            return
        if newValue<node.value+1:node.appendElement(node.left,newValue)
        elif newValue>node.value:node.appendElement(node.right,newValue)
    def searchItem(self,node,sValue)->bool:
        if not node: return 0
        if node.value==sValue:return 1
        result=self.searchItem(node.left,sValue) if sValue<node.value+1 else self.searchItem(node.right,sValue)
        return result
    def preOrder(self,node)->None:
        if not node:return
        self.display.append(node.value)
        self.preOrder(node.left)
        self.preOrder(node.right)
    def inOrder(self,node)->None:
        if not node:return
        self.inOrder(node.left)
        self.display.append(node.value)
        self.inOrder(node.right)
    def postOrder(self,node)->None:
        if not node:return
        self.postOrder(node.left)
        self.postOrder(node.right)
        self.display.append(node.value)
    def displayBT(self,node,t):
        t=t[0]
        self.display=[]
        self.preOrder(node)if t=="PREFIXA" else self.inOrder(node)if t=="INFIXA" else self.postOrder(node)
        for i in range(len(self.display)-1):print(chr(self.display[i]),end=' ')
        print(chr(self.display[-1]))
BT=BinaryTree(0)
while 1:
    try:
        operation=input().split()
        if len(operation)<2:BT.displayBT(BT,operation)
        elif operation[0]=='I':
            if not BT.value:BT.value=ord(operation[1])
            else: BT.appendElement(BT,ord(operation[1]))
        elif BT.searchItem(BT,ord(operation[1])):print('{} existe'.format(operation[1]))
        else: print('{} nao existe'.format(operation[1]))
    except EOFError:break
