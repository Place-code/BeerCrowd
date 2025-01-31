import java.util.Scanner;
import java.lang.System;
//
class Adj_list{
	class Vector{
		int array[],index,length,explored;
		Vector(int sizeVector){ // constructor
			array=new int[sizeVector];
			index=0;
			length=sizeVector;
			explored=0;
		}
		public void append(int newValue){
			if(index>length-1){
				int[]new_block=new int[length*2];
				System.arraycopy(array,0,new_block,0,length);
				length*=2;
				array=new_block;
			}
			array[index]=newValue;
			++index;
		}
		public void display(){
			for(int i=0;i<index;++i)System.out.print(array[i]+" ");
			System.out.print("\n");
		}
	}
	Vector list[];
	int size,explored[],tot;
	Adj_list(int Size_adj_list){
		list=new Vector[Size_adj_list];
		for(int i=0;i<Size_adj_list;++i)list[i]=new Vector(1);
		size=Size_adj_list;
		tot=0;
	}
	public void display_adj_list(){
		for(int i=0;i<size;++i)list[i].display();
		System.out.println();
	}
	public void DFS(int current_node,int previous_node){
		for(int i=0;i<list[current_node].index;++i){
			int aux=list[current_node].array[i];
			if(list[aux].explored==1)continue;
			//System.out.print(aux+" ");
			list[aux].explored=1;
			DFS(aux,current_node);
		}
		++tot;
	}
}

public class _1076{
	public static void main(String args[]){
		int rep;
		Scanner scan=new Scanner(System.in);
		rep=scan.nextInt();
		for(int i=0;i<rep;++i){
			int init,vertics,edges;
			init=scan.nextInt();
			//
			vertics=scan.nextInt();
			edges=scan.nextInt();
			//
			Adj_list adj=new Adj_list(vertics);
			for(int j=0;j<edges;++j){
				int v1,v2;
				v1=scan.nextInt();
				v2=scan.nextInt();
				adj.list[v1].append(v2);
				adj.list[v2].append(v1);
			}
			adj.list[init].explored=1;
			adj.DFS(init,init);
			System.out.println((adj.tot-1)*2);
		}
	}
}
