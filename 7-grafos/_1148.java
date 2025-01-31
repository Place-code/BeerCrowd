import java.util.Scanner;
//
public class _1148{
	public static void main(String[] args){
		Scanner scan=new Scanner(System.in);
		while(true){
			int vertic,edges;
			vertic=scan.nextInt();
			edges=scan.nextInt();
			if(vertic==0&&edges==0)break;
			scan.nextLine();

			Adj_list adj=new Adj_list(vertic);
			for(int i=0;i<edges;++i){
				int v1,v2,w;
				v1=scan.nextInt();
				v2=scan.nextInt();
				w=scan.nextInt();

				adj.add_nodes(v1-1,v2-1,w);
			}

			/*
			for(int i=0;i<vertic;++i){
				System.out.print(i+"->");
				for(int j=0;j<adj.list[i].gsize();++j){
					Node aux=adj.list[i].array[j];
					System.out.print(aux.gv()+" "+aux.gw()+"|");
				}
				System.out.println();
			}*/

			int queries=scan.nextInt();
			for(int i=0;i<queries;++i){
				int init,end,result;
				init=scan.nextInt();
				end=scan.nextInt();

				result=adj.Dijkstra(init-1,end-1);
				if(result==-1)System.out.println("Nao e possivel entregar a carta");
				else System.out.println(result);
			}
			System.out.println();
		}
		scan.close();
	}
}

class Node{
	int vertic,weight;
	Node(int vert,int weig){
		this.vertic=vert;
		this.weight=weig;
	}
	public int gv(){
		return vertic;
	}
	public int gw(){
		return weight;
	}
}

class Vector{
	int index,max_len;
	Node array[];
	Vector(int max_len){
		this.index=0;
		this.max_len=max_len;
		this.array=new Node[max_len];
	}

	public void add(int new_vertic,int new_weight){
		if(index>max_len-1){
			Node temp[]=new Node[max_len*2];
			for(int i=0;i<max_len;++i)temp[i]=array[i];
			array=temp;
			max_len*=2;
		}
		array[index]=new Node(new_vertic,new_weight);
		++index;
	}
	public Node	gbyid(int index){
		return array[index];
	}

	public int 	gsize(){
		return index;
	}
	public int in(int vertic){
		for(int i=0;i<index;++i){
			if(array[i].gv()==vertic)return i;
		}
		return -1;
	}
}

class Heap{
	Vector head;

	Heap(int size){
		this.head=new Vector(size);
	}

	private void swap(int id1,int id2){
		head.array[id1].vertic+=head.array[id2].vertic;
		head.array[id2].vertic=head.array[id1].vertic-head.array[id2].vertic;
		head.array[id1].vertic-=head.array[id2].vertic;

		head.array[id1].weight+=head.array[id2].weight;
		head.array[id2].weight=head.array[id1].weight-head.array[id2].weight;
		head.array[id1].weight-=head.array[id2].weight;
	}

	private void shift_up(int index){
		if(index==0|head.array[(index-1)/2].gw()<head.array[index].gw())return;
		swap(index,(index-1)/2);
		index=(index-1)/2;

		shift_up(index);
	}
	private void shift_dw(int index){
		int temp=index;
		if(index*2+1<head.gsize()&&head.array[index*2+1].gw()<head.array[temp].gw())temp=index*2+1;
		if(index*2+2<head.gsize()&&head.array[index*2+2].gw()<head.array[temp].gw())temp=index*2+2;
		if(temp!=index){
			swap(index,temp);
			shift_dw(temp);
		}
	}
	public void	insert(int vertic,int weight){
		head.add(vertic,weight);
		shift_up(head.index-1);
	}
	public Node	extract(){
		Node result=head.array[0];
		head.array[0]=head.array[head.index-1];
		--head.index;
		shift_dw(0);

		return result;
	}

	public boolean empty(){
		return head.index<1;
	}
}

class Adj_list{
	Vector list[];
	int size;
	Adj_list(int size){
		this.list=new Vector[size];
		for(int i=0;i<size;++i)this.list[i]=new Vector(10);
		this.size=size;
	}

	public void add_nodes(int index,int vertic,int weight){
		int status;
		if((status=list[vertic].in(index))!=-1){
			list[vertic].array[status].weight=0;
			weight=0;
		}
		list[index].add(vertic,weight);
	}
	
	public int Dijkstra(int init,int end){
		int wbyv[]=new int[size];
		for(int i=0;i<size;++i)wbyv[i]=-1;
		Heap queue=new Heap(size);
		queue.insert(init,0);

		while(!queue.empty()){
			Node get=queue.extract();
			if(get.gw()>wbyv[end]&&wbyv[end]!=-1){
				return wbyv[end];
			}
			for(int i=0;i<list[get.gv()].gsize();++i){
				Node aux=list[get.gv()].array[i];

				if(get.gw()+aux.gw()>wbyv[aux.gv()]-1&&wbyv[aux.gv()]!=-1)continue;
				wbyv[aux.gv()]=get.gw()+aux.gw();

				if(aux.gv()==end)continue;
				queue.insert(aux.gv(),wbyv[aux.gv()]);
			}
		}
		return wbyv[end];
	}
}
