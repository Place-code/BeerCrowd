using System;
using System.Collections;

class Car{
	public string plate;
	public int start,end;

	public Car(string plate,int start,int end){
		this.plate=plate;
		this.start=start;
		this.end=end;
	}
	public void display(){
		Console.Write(plate+" "+start+" "+end+"|");
	}
}
class Node{
	public Node next;
	public Node prev;

	public Car automotive;

	public Node(Car new_car,Node prev){
		this.automotive=new_car;
		this.next=null;
		this.prev=prev;
	}
}
class Head_ll{
	public Node head;
	public Node first;
	public Node last;

	public Head_ll(){
		this.head=new Node(null,null);
		this.first=head;
	}
	public void insert(Car new_car){
		if(head.automotive==null){
			head.automotive=new_car;
			head.next=new Node(null,head);
			last=head;
			head=head.next;
			return;
		}
		if(head.prev==null){
			head.prev=new Node(new_car,null);
			head.prev.next=head;
			head=head.prev;
			first=head;
			return;
		}

		Node temp=head;
		head=head.prev;
		head.next=new Node(new_car,head);
		head=head.next;
		head.next=temp;
		temp.prev=head;
	}
	public void delete(){
		if(head.prev==null){
			head.automotive=null;
			if(head.next!=null&&head.next.automotive!=null){
				head=head.next;
				head.prev=null;
			}
			first=head;
			return;
		}
		if(head.automotive==null){
			head=head.prev;
			head.automotive=null;
			head.next=null;
			last=head.prev;
			return;
		}
		Node temp=head.next;
		head=head.prev;
		head.next=temp;
		temp.prev=head;
		if(temp.next==null||temp.next.automotive==null)
			last=temp.prev;
	}
	public void move_start(){
		head=first;
	}
	public void move_end(){
		head=last;
	}
	public void display_left(){
		Node temp=first;
		while(temp.automotive!=null){
			temp.automotive.display();
			temp=temp.next;
		}
		Console.Write("\n");
	}
	public void display_right(){
		Node temp=last;
		while(temp!=null&&temp.automotive!=null){
			temp.automotive.display();
			temp=temp.prev;
		}
		Console.WriteLine();
	}
	public bool empty(){
		return (first==last&&first.automotive==null);
	}
}

class Question{
	static void let_parking(Head_ll refers,string plate_car){
		refers.move_start();
		while(refers.head.automotive!=null){
			if(refers.head.automotive.plate==plate_car){
				refers.delete();
				return;
			}
			refers.head=refers.head.next;
		}
	}
	static bool enter_parking(Head_ll refers,int length_park,string plate_car,int length_car){
		refers.move_start();
		if(length_car>length_park)
			return false;
		if(refers.head.automotive==null||refers.head.automotive.start>=length_car){
			refers.insert(new Car(plate_car,0,length_car-1));
			return true;
		}
		int prev_end=refers.head.automotive.end;
		refers.head=refers.head.next;
		while(refers.head.automotive!=null){
			Car temp=refers.head.automotive;
			if(temp.start-prev_end>length_car){
				refers.insert(new Car(plate_car,prev_end+1,prev_end+length_car));
				return true;
			}
			prev_end=temp.end;
			refers.head=refers.head.next;
		}
		if(length_park-prev_end>length_car){
			refers.insert(new Car(plate_car,prev_end+1,prev_end+length_car));
			return true;
		}
		return false;
	}
	static void Main(){
		String[] temp;
		String EOF;
		while((EOF=Console.ReadLine())!=null){
			temp=EOF.Split();
			int length=int.Parse(temp[0]),quotes=int.Parse(temp[1]),tot=0;
			Hashtable desk=new Hashtable();
			Head_ll parking=new Head_ll();
			for(int i=0;i<quotes;++i){
				temp=Console.ReadLine().Split();
				if(temp.Length<3&&desk.ContainsKey(temp[1])){
					let_parking(parking,temp[1]);
					desk.Remove(temp[1]);
				}
				if(temp.Length==3&&int.TryParse(temp[2],out int ok)&&enter_parking(parking,length,temp[1],ok)){
					if(!desk.ContainsKey(temp[1]))
						desk.Add(temp[1],true);
					tot+=10;
				}
			}
			Console.WriteLine(tot);
		}
	}
}
