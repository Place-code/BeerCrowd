import java.util.Scanner;
import java.lang.System;
//
class Adj_List{
	public class Vector{
		int array[],index,length,explored;
		Vector(int it_size){
			this.array=new int[it_size];
			this.index=0;
			this.length=it_size;
			this.explored=0;
		}
		public void insert_sort(int id){
			for(int i=id;i>0&&array[i-1]>array[i];--i){
				array[i-1]+=array[i];
				array[i]=array[i-1]-array[i];
				array[i-1]-=array[i];
			}
		}
		public void append(int new_value){
			if(index>length-1){
				int temp[]=new int[length*2];
				System.arraycopy(array,0,temp,0,length);
				length*=2;
				array=temp;
			}
			array[index]=new_value;
			insert_sort(index);
			++index;
		}
		public void display_vetor(){
			for(int i=0;i<index;++i)System.out.print(array[i]+" ");
			System.out.print("\n");
		}
	}
	Vector listAdj[];
	int lengthAdjList;
	Adj_List(int size){
		listAdj=new Vector[size];
		for(int i=0;i<size;++i)listAdj[i]=new Vector(1);
		lengthAdjList=size;
	}
	public void display_hierarchy(int current_node,int depth){
		for(int i=0;i<listAdj[current_node].index;++i){
			int aux=listAdj[current_node].array[i];
			for(int j=0;j<depth*2;++j)System.out.print(" ");
			System.out.print(current_node+"-"+aux);
			if(listAdj[aux].explored==1){
				System.out.println();
				continue;
			}
			System.out.println(" pathR(G,"+aux+")");
			listAdj[aux].explored=1;
			display_hierarchy(aux,depth+1);
		}
	}
}

public class _1081{
	public static void main(String args[]){
		int rep;
		Scanner scan=new Scanner(System.in);
		rep=scan.nextInt();
		for(int i=0;i<rep;++i){
			int vertics,edges,puts[][];
			vertics=scan.nextInt();
			//
			puts=new int[vertics][vertics];
			for(int j=0;j<vertics;++j){
				puts[i]=new int[vertics];
				for(int k=0;k<vertics;++k)puts[i][k]=0;
			}
			//
			edges=scan.nextInt();
			Adj_List list=new Adj_List(vertics);
			for(int j=0;j<edges;++j){
				int v1,v2;
				v1=scan.nextInt();
				v2=scan.nextInt();
				if(puts[v1][v2]==1)continue;
				puts[v1][v2]=1;
				list.listAdj[v1].append(v2);
			}
			System.out.print("Caso "+(i+1)+":\n");
			for(int j=0;j<vertics;++j){
				if(list.listAdj[j].explored==1|list.listAdj[j].index<1)continue;
				list.listAdj[j].explored=1;
				list.display_hierarchy(j,1);
				System.out.println();
			}
		}
	}
}
