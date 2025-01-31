storeDigits=None
def splitNum(x,storeNum)->None:
    while x:
        storeNum.append(x%10);
        x//=10
def regenerateNum(index,storeNum)->int:
    result=0
    for i in range(index+1):result+=storeNum[i]*10**i
    return result
def interval(tight,index,storeNum)->int:
    if index<0:
        ret=[0 for i in range(10)]
        return ret
    if storeDigits[index][9] and not tight:return storeDigits[index];
    rep=9 if not tight else storeNum[index]
    amountDigits=[0 for i in range(10)]
    for i in range(rep+1):
        #print('{})'.format(i),end='')
        newTight=tight if i==storeNum[index] else 0
        temp=interval(newTight,index-1,storeNum)
        for j in range(10):amountDigits[j]+=temp[j]
        amountDigits[i]+=10**(index)if not newTight else regenerateNum(index-1,storeNum)+1
    if not tight and not storeDigits[index][9]:
        for i in range(10):storeDigits[index][i]+=amountDigits[i]
    #print('{}'.format(str(amountDigits)[1:-1]),end='|')
    return amountDigits
def minusZeros(index)->int:
    result=0
    if index<2:return result
    for i in range(index):
        result+=10**i
    return result-1
#
storeDigits=[[0 for i in range(10)] for j in range(10)]
while 1:
    [a,b]=list(map(int,input().split()))
    if not a and not b:break
    digitsB=[]
    splitNum(b,digitsB)
    tempB=interval(1,len(digitsB)-1,digitsB)
    tempB[0]-=minusZeros(len(digitsB))
    #
    digitsA=[]
    splitNum(a-1,digitsA)
    if not(len(digitsA)):digitsA.append(0)
    tempA=interval(1,len(digitsA)-1,digitsA)
    tempA[0]-=minusZeros(len(digitsA))
    for i in range(9):print('{}'.format(tempB[i]-tempA[i]),end=' ')
    print(tempB[9]-tempA[9])
