lass PriorityQueue:
    def __init__(self,length):
        self.length=length
        self.arrayWeight=[0 for i in range(self.length)]
        self.arrayVertic=[0 for i in range(self.length)]
        self.index=0;
    def shiftUp(self,i):
        while(i and self.arrayWeight[i]<self.arrayWeight[(i-1)//2]):
            self.arrayWeight[(i-1)//2]+=self.arrayWeight[i]
            self.arrayWeight[i]=self.arrayWeight[(i-1)//2]-self.arrayWeight[i]
            self.arrayWeight[(i-1)//2]-=self.arrayWeight[i]
            
            self.arrayVertic[(i-1)//2]+=self.arrayVertic[i]
            self.arrayVertic[i]=self.arrayVertic[(i-1)//2]-self.arrayVertic[i]
            self.arrayVertic[(i-1)//2]-=self.arrayVertic[i]
            i=(i-1)//2
    def shiftDown(self,i):
        temp=i
        if (i*2)+1<self.index+1:
            if self.arrayWeight[temp]>self.arrayWeight[(i*2)+1] :
                temp=(i*2)+1
        if (i*2)+2<self.index+1:
            if self.arrayWeight[temp]>self.arrayWeight[(i*2)+2]:
                temp=(i*2)+2
        if temp!=i:
            self.arrayWeight[i]+=self.arrayWeight[temp]
            self.arrayWeight[temp]=self.arrayWeight[i]-self.arrayWeight[temp]
            self.arrayWeight[i]-=self.arrayWeight[temp]
            
            self.arrayVertic[i]+=self.arrayVertic[temp]
            self.arrayVertic[temp]=self.arrayVertic[i]-self.arrayVertic[temp]
            self.arrayVertic[i]-=self.arrayVertic[temp]
            self.shiftDown(temp)
    def extract_min(self):
        result=[self.arrayVertic[0],self.arrayWeight[0]]
        self.index-=1
        self.arrayWeight[0]=self.arrayWeight[self.index]
        self.arrayVertic[0]=self.arrayVertic[self.index]
        self.shiftDown(0)
        return result
    def insert(self,vertice,weight):
        self.arrayWeight[self.index]=weight
        self.arrayVertic[self.index]=vertice
        if self.index>self.length-2:
            self.length*=2
            for i in range(self.length):
                self.arrayWeight.append(0)
                self.arrayVertic.append(0)
        self.shiftUp(self.index)
        self.index+=1
    def clear(self):
        self.arrayWeight.clear()
        self.arrayVertic.clear()
    def displayQueue(self):
        print('{}\n{}'.format(str([i for i in self.arrayVertic])[1:-1],str([i for i in self.arrayWeight])[1:-1]))

adj,weights=None,None
def Dijkstra(lengthQueue,origin,destiny):
    queue=PriorityQueue(lengthQueue)
    queue.insert(origin,0)
    minimum=[0 for i in range(lengthQueue)]
    minimum[origin]=1
    minimum[destiny]=-1
    while queue.index:
        aux=queue.extract_min()
        if (aux[1]>minimum[destiny]-1 and minimum[destiny]!=-1):
            queue.clear()
            return minimum[destiny]
        for i in range(len(adj[aux[0]])):
            auxV,auxW=adj[aux[0]][i],weights[aux[0]][i]
            if (((aux[0]<destiny-1 and auxV==aux[0]+1)or(aux[0]>destiny))and(minimum[auxV]>aux[1]+auxW or not minimum[auxV])):
                queue.insert(auxV,aux[1]+auxW)
                minimum[auxV]=aux[1]+auxW
            if (auxV==destiny and (minimum[destiny]>aux[1]+auxW or minimum[destiny]==-1) and (aux[0]>destiny or aux[0]==destiny-1)):
                minimum[destiny]=aux[1]+auxW
    return minimum[destiny]
while(True):
    x=list(map(int,input().split()))
    if not x[0] and not x[1] and not x[2] and not x[3]:break
    adj=[[] for i in range(x[0])]
    weights=[[] for i in range(x[0])]
    for i in range(x[1]):
        [v1,v2,weight]=list(map(int,input().split()))
        adj[v1].append(v2)
        adj[v2].append(v1)
        weights[v1].append(weight)
        weights[v2].append(weight)
    print(Dijkstra(x[0],x[3],x[2]-1))
    adj=[]
    weights=[]
