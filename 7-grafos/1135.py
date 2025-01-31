import sys

adjList,inAdj,weight,pathDFS,index=None,None,None,[],[]

def DFS(node,size)->None:
    stack=[node]
    lastNode=[0]
    explored=[0 for i in range(size)]
    while stack:
        pathDFS.append(stack[-1]);
        index[stack[-1]]=len(pathDFS) if not index[stack[-1]] else index[stack[-1]]
        if not inAdj[stack[-1]]:
            stack.pop()
            lastNode.pop()
            continue
        for i in range(lastNode[-1],len(adjList[inAdj[stack[-1]]-1])):
            aux=adjList[inAdj[stack[-1]]-1][i]
            lastNode[-1]+=1
            stack.append(aux)
            stack.append(-1)
            lastNode.append(0)
            lastNode.append(-1)
            explored[aux]=1
            break
        stack.pop()
        lastNode.pop()

def log2(n)->int:
    i=1
    while((1<<(i+1))<n+1):
        i+=1
    return i

def logTw2(size):
    result=[[0 for i in range(log2(size)+1)]for i in range(size)]
    for i in range(size):result[i][0]=i
    i=1
    while((1<<i)<size+1):
        j=0
        while(j+(1<<i)-1<size):
            result[j][i]=result[j][i-1]if pathDFS[result[j][i-1]]<pathDFS[result[j+(1<<(i-1))][i-1]] else result[j+(1<<(i-1))][i-1]
            j+=1
        i+=1
    return result
def ProcessQ(amountQ,amountV)->None:
    for i in range(amountV):
        index.append(0)
    DFS(0,amountV);
    adjList.clear()
    inAdj.clear()
    small=logTw2(len(pathDFS))
    for i in range(amountQ):
        [source,destiny]=(sys.stdin.readline().strip()).split()
        source=int(source)
        destiny=int(destiny)
        if index[source]>index[destiny]:
            destiny+=source
            source=destiny-source
            destiny-=source
        ind1,ind2=index[source]-1,index[destiny]-1
        temp=log2(ind2-ind1+1)
        commonVertic=pathDFS[small[ind1][temp]] if pathDFS[small[ind1][temp]]<pathDFS[small[ind2-(1<<temp)+1][temp]] else pathDFS[small[ind2-(1<<temp)+1][temp]]
        sys.stdout.write(str(weight[source]+weight[destiny]-weight[commonVertic]*2))
        if(i<amountQ-1):sys.stdout.write(' ')
        else: sys.stdout.write('\n')
    pathDFS.clear()
    index.clear()

while (x:=int(input())):
    inAdj,tempRep,sizeAdj=[0 for i in range(x)],[],0
    weight=inAdj.copy()
    for i in range(1,x):
        [v,length]=(sys.stdin.readline().strip()).split()
        if not inAdj[int(v)]:
            sizeAdj+=1
            inAdj[int(v)]=sizeAdj
        weight[i]=weight[int(v)]+int(length)
        tempRep.append(int(v))
    adjList=[[] for i in range(sizeAdj)]
    for i in range(x-1):
        adjList[inAdj[tempRep[i]]-1].append(i+1)
    amountQ=int(input())
    ProcessQ(amountQ,x)
