import copy

class Car:
    def __init__(self,ID,init,end)->None:
        self.ID=ID;
        self.init=init;
        self.end=end;
        return

    def display(self):
        print("{} {} {}|".format(self.ID,self.init,self.end),end='')

class Node:
    def __init__(self,new_car,prev):
        self.value=copy.deepcopy(new_car)
        self.next=None
        self.prev=prev

class Head_ll:
    def __init__(self):
        self.head=Node(None,None)
        self.first=self.head
        self.last=self.head

    def insert(self,new_value):
        if self.head.value==None:
            self.head.value=new_value
            self.head.next=Node(None,self.head)
            self.head=self.head.next
            self.last=self.head
            return

        if self.head.prev==None:
            self.head.prev=Node(new_value,None)
            self.head.prev.next=self.head
            self.head=self.head.prev
            self.first=self.head
            return

        temp=self.head
        self.head=self.head.prev
        self.head.next=Node(new_value,self.head)

        self.head=self.head.next
        self.head.next=temp
        temp.prev=self.head

    def delete(self):
        if self.head.prev==None:
            self.head.value=None;
            if self.head.next!=None:
                self.head=self.head.next
                self.head.prev=None
            self.first=self.head
            return
        if self.head.value==None:
            self.head=self.head.prev
            self.head.value=None
            self.head.next=None
            self.last=self.head
            return

        temp=self.head.next
        self.head=self.head.prev
        self.head.next=temp
        temp.prev=self.head

    def move_left(self):
        self.head=self.first
    def move_right(self):
        self.head=self.last

    def forward(self,amount_steps):
        for i in range(amount_steps):
            if(self.head.next==None or self.head.next.value==None):
                return;
            self.head=self.head.next
    def back(self,amount_steps):
        for i in range(amount_steps):
            if(self.head.prev==None):
                return
            self.head=self.head.prev

    def display_left(self):
        temp=copy.deepcopy(self)
        while(temp.head.value!=None):
            temp.head.value.display()
            temp.head=temp.head.next
        print()

    def display_right(self):
        temp=copy.deepcopy(self)
        while(temp.head!=None and temp.head.value!=None):
            temp.head.value.display()
            temp.head=temp.head.prev
        print()

def left_parking(parking,ID_car):
    parking.move_left();
    while(parking.head.value!=None and parking.head!=None):
        if parking.head.value.ID==ID_car:
            parking.delete()
            return
        parking.head=parking.head.next

def insert_parking(parking,length_park,ID_car,length_car):
    parking.move_left()
    if length_car>length_park:
        return 0
    if parking.head.value==None or parking.head.value.init>=length_car:
        parking.insert(Car(ID_car,0,length_car-1))
        return 1
    prev_end=parking.head.value.end
    parking.head=parking.head.next
    while(parking.head!=None and parking.head.value!=None):
        curr_car=parking.head.value
        if curr_car.init-prev_end>length_car:
            parking.insert(Car(ID_car,prev_end+1,prev_end+length_car))
            return 1
        prev_end=parking.head.value.end
        parking.head=parking.head.next
    if length_park-prev_end>length_car:
        parking.insert(Car(ID_car,prev_end+1,prev_end+length_car))
        return 1
    return 0



"""
tst=Head_ll()

for i in range(10):
    ID=chr(i%26+65)+chr((i+1)%26+65)+chr((i+2)%26+65)
    temp=Car(ID,i,i)
    tst.insert(temp)

tst.move_left()
tst.head=tst.head.next.next
tst.insert(Car("ALTF4",0,0))
tst.move_right()
tst.delete()
tst.move_left()
tst.display_left()
"""

while 1:
    try:
        [length,quotes]=input().split()
    except:
        break
    length=int(length)
    quotes=int(quotes)
    parking=Head_ll()
    tot=0

    while(quotes):
        inp=input().split()
        if len(inp)<3:
            left_parking(parking,inp[1])
        if len(inp)==3 and insert_parking(parking,length,inp[1],int(inp[2])):
            tot+=10

        quotes-=1
    print(tot)
