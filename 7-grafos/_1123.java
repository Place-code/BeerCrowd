import java.util.Scanner;
import java.util.ArrayList;
//
public class Node{
	int destiny,weight;
	Node(int d,int w){
		this.destiny=d;
		this.weight=w;
	}
}
public class Vector{
	int index,length,current_weight;
	Node array[];
	Vector(int new_length){
		this.array=new Node[new_length];
		this.index=0;
		this.length=new_length;
		this.current_weight=-1;
	}
	public void resize_array(int old_length,int new_length){;
		Node resized_array[]=new Node[new_length];
		for(int i=0;i<old_length;++i)resized_array[i]=array[i];
		array=resized_array;
	}
	public void append(int destiny,int weight){
		if(index>length-1){
			resize_array(index,length*2);
			length*=2;
		}
		array[index]=new Node(destiny,weight);
		++index;
	}
	public Node get0(){
		return array[0];
	}
	public void display_Vector(){
		for(int i=0;i<index;++i)System.out.print("("+array[i].destiny+" "+array[i].weight+") ");
		System.out.println();
	}
}
public class Priority_queue{
	Vector heap_pq;
	Priority_queue(){
		this.heap_pq=new Vector(1);
	}
	private void swap(int id1,int id2){
		heap_pq.array[id1].destiny+=heap_pq.array[id2].destiny;
		heap_pq.array[id1].weight+=heap_pq.array[id2].weight;
		//
		heap_pq.array[id2].destiny=heap_pq.array[id1].destiny-heap_pq.array[id2].destiny;
		heap_pq.array[id2].weight=heap_pq.array[id1].weight-heap_pq.array[id2].weight;
		//
		heap_pq.array[id1].destiny-=heap_pq.array[id2].destiny;
		heap_pq.array[id1].weight-=heap_pq.array[id2].weight;
	}
	private void shiftUp(int index){
		while(index!=0&&heap_pq.array[(index-1)/2].weight>heap_pq.array[index].weight){
			swap(index,(index-1)/2);
			index=(index-1)/2;
		}
	}
	private void shiftDown(int index){
		int temp=index;
		if(index*2+1<heap_pq.index&&heap_pq.array[index*2+1].weight<heap_pq.array[temp].weight)temp=index*2+1;
		if(index*2+2<heap_pq.index&&heap_pq.array[index*2+2].weight<heap_pq.array[temp].weight)temp=index*2+2;
		if(temp!=index){
			swap(index,temp);
			shiftDown(temp);
		}
	}
	public void append_node(int vertex,int weight){
		heap_pq.append(vertex,weight);
		shiftUp(heap_pq.index-1);
	}
	public Node extract(){
		Node result=heap_pq.get0();
		--heap_pq.index;
		heap_pq.array[0]=heap_pq.array[heap_pq.index];
		shiftDown(0);
		return result;
	}
	public boolean empty(){
		return heap_pq.index<1;
	}
}
public class Adj_List{
	Vector adj[];
	int length_list;
	Adj_List(int size_list){
		adj=new Vector[size_list];
		for(int i=0;i<size_list;++i)adj[i]=new Vector(1);
		length_list=size_list;
	}
	public void display_adj_list(){
		for(int i=0;i<length_list;++i){
			System.out.print(i+"->");
			adj[i].display_Vector();
		}
	}
	public int Dijkstra(int source,int end,int range_service){
		Priority_queue queue=new Priority_queue();
		queue.append_node(source,0);
		while(!queue.empty()){
			Node get_last=queue.extract();
			if(adj[get_last.destiny].current_weight>adj[end].current_weight&&adj[end].current_weight!=-1)return adj[end].current_weight;
			//System.out.println("|"+get_last.destiny+" "+get_last.weight+"|");
			for(int i=0;i<adj[get_last.destiny].index;++i){
				Node v=adj[get_last.destiny].array[i];
				if(get_last.destiny<range_service&&v.destiny!=get_last.destiny+1)continue;
				//System.out.print(v.destiny+" "+v.weight+" ");
				if(adj[v.destiny].current_weight>get_last.weight+v.weight|adj[v.destiny].current_weight==-1){
					adj[v.destiny].current_weight=get_last.weight+v.weight;
					if(v.destiny!=end)queue.append_node(v.destiny,adj[v.destiny].current_weight);
				}
			}
		}
		return adj[end].current_weight;
	}
}
public class _1123{
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		while(true){
			int vertics,edges,services_destiny,init;
			vertics=scan.nextInt();
			edges=scan.nextInt();
			services_destiny=scan.nextInt();
			init=scan.nextInt();
			if(vertics==0&&edges==0&&services_destiny==0&&init==0)break;
			Adj_List list=new Adj_List(vertics);
			scan.nextLine();
			for(int i=0;i<edges;++i){
				int v1,v2,cust;
				v1=scan.nextInt();
				v2=scan.nextInt();
				cust=scan.nextInt();
				list.adj[v1].append(v2,cust);
				list.adj[v2].append(v1,cust);
				scan.nextLine();
			}
			//list.display_adj_list();
			System.out.println(list.Dijkstra(init,services_destiny-1,services_destiny));
		}
	}
}
