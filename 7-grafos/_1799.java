import java.util.Scanner;
import java.lang.System;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.StringTokenizer;
//
class Adj_List{
	class Vector{
		int array[],index,length;
		Vector(int size){
			this.array=new int[size];
			this.index=0;
			this.length=size;
		}
		public void append(int new_value){
			if(index>length-1){
				int temp[]=new int[length*2];
				System.arraycopy(array,0,temp,0,length);
				array=temp;
				length*=2;
			}
			array[index]=new_value;
			++index;
		}
		public int pop(){
			--index;
			return array[index];
		}
		public boolean empty(){
			return index<1;
		}
	}
	Vector list_adj[];
	int size_adj;
	Adj_List(int length_adj){
		list_adj=new Vector[length_adj];
		for(int i=0;i<length_adj;++i)list_adj[i]=new Vector(1);
		this.size_adj=length_adj;
	}
	public int bfs(int source,int destiny){
		int matrix[]=new int[size_adj];
		for(int i=0;i<size_adj;++i)matrix[i]=0;
		Vector queue=new Vector(1);
		queue.append(source);
		for(int i=0;!queue.empty();++i){
			Vector aux=new Vector(1);
			while(!queue.empty()){
				int c_vertex=queue.pop();
				//System.out.print(c_vertex+"->");
				if(c_vertex==destiny)return i;
				for(int v:list_adj[c_vertex].array){
					if(matrix[v]==1)continue;
					//System.out.print(v+" ");
					matrix[v]=1;
					aux.append(v);
				}
				//System.out.print("|");
			}
			queue=aux;
		}
		return 0;
	}
}

public class _1799{
	static public void main(String args[]){		
		int vertexs,edges;
		Scanner scan=new Scanner(System.in);
		vertexs=scan.nextInt();
		edges=scan.nextInt();
		//
		Dictionary<String,Integer>translate=new Hashtable<String,Integer>();
		translate.put("Entrada",0);
		translate.put("*",1);
		translate.put("Saida",2);
		//
		scan.nextLine();
		Adj_List arrays=new Adj_List(vertexs+2);
		for(int i=0;i<edges;++i){
			String str1=scan.nextLine(),s1,s2;
			StringTokenizer strtok=new StringTokenizer(str1);
			s1=strtok.nextToken();
			s2=strtok.nextToken();
			//
			if(translate.get(s1)==null)translate.put(s1,translate.size());
			if(translate.get(s2)==null)translate.put(s2,translate.size());
			//
			arrays.list_adj[translate.get(s1)].append(translate.get(s2));
			arrays.list_adj[translate.get(s2)].append(translate.get(s1));
		}
		System.out.println(arrays.bfs(0,1)+arrays.bfs(1,2));
	}
}
