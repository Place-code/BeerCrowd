#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
// structs nodes
struct node{
	int v1;
	int v2;
	int wg;
};

struct set_node{
	struct node**set;
	size_t index;
	size_t max_l;
};

struct node*create_node(int v1,int v2,int wg){
	struct node*new_node=malloc(sizeof(struct node));
	new_node->v1=v1;
	new_node->v2=v2;
	new_node->wg=wg;

	return new_node;
}

void*create_set_node(size_t max_len){
	struct set_node*new=malloc(sizeof(struct set_node));

	new->index=0;
	new->max_l=max_len;
	new->set=malloc(sizeof(struct node)*max_len);
	
	return new;
}

// functions for structs
int gw(const struct node*n){ // get weight of a node
	return n->wg;
}
int sgw(const struct set_node*nn,const size_t id){ // get a weight in a index of set_node
	return gw(nn->set[id]);
}
int sgs(const void*nn){ // get current size of set_node
	return ((struct set_node*)nn)->index;
}
void*sgf(const void*nn){ // get first falue of set_node
	return ((struct set_node*)nn)->set[0];
}
void*sgl(const void*nn){
	struct set_node*target=(struct set_node*)nn;
	return target->set[target->index-1];
}

int comp_node(const void*poin,size_t id1,size_t id2){ // compare the weight of index id1 and id2 of struct set_node
	struct set_node*target=(struct set_node*)poin;
	if(sgw(target,id1)>sgw(target,id2))return 1;
	return 0;
}
void swap_node(void*poin,size_t id1,size_t id2){ // swap two values between index id1 and id2
	struct set_node*target=(struct set_node*)poin;
	struct node*big=target->set[id1],*small=target->set[id2];

	big->v1+=small->v1;
	small->v1=big->v1-small->v1;
	big->v1-=small->v1;

	big->v2+=small->v2;
	small->v2=big->v2-small->v2;
	big->v2-=small->v2;

	big->wg+=small->wg;
	small->wg=big->wg-small->wg;
	big->wg-=small->wg;
}
void append_set_node(void*poin,int*array,size_t len){
	struct set_node*ref=(struct set_node*)poin;
	if(ref->index>ref->max_l){
		ref->set=realloc(ref->set,sizeof(struct node)*ref->max_l*2);
		ref->max_l*=2;
	}
	ref->set[ref->index]=create_node(array[0],array[1],array[2]);
	++ref->index;
}
void pandr(void*point,const void*point2){
	struct set_node*target=(struct set_node*)point;
	struct node*replacer=(struct node*)point2;
	target->set[0]=replacer;
	--target->index;
}
void display_set_node(const struct set_node*display){
	for(size_t i=0;i<display->index;++i){
		struct node*tst=display->set[i];
		printf("%i %i %i|",tst->v1,tst->v2,tst->wg);
	}
	printf("\n");
}
// ======HEAP========
struct heap{ // a heap
	void	*storage; // the storage variable

	int		(*compar_func)(const void*,size_t,size_t); // the compare function
	void	(*swap_)(void*,size_t,size_t);// the swap function
	void	(*insert)(void*,int*,size_t);// the insert function
	int		(*get_size)(const void*);// get the size of heap
									 //
	void*	(*get_first_value)(const void*);// get the first heap's value
	void*	(*get_last_value)(const void*);
	void	(*pop)(void*,const void*);
};
struct heap*create_heap(// ceeate a heap
		size_t max_l,

		int(*new_compar)(const void*,size_t,size_t),
		void(*new_swap)(void*,size_t,size_t),
		void(*new_insert)(void*,int*,size_t),
		int(*new_get_size)(const void*),

		void*(*new_get_ft_v)(const void*),
		void*(*new_get_ls_v)(const void*),

		void(*pop)(void*,const void*),

		void*(*create_sub_struct)(size_t)){

	struct heap*new_heap=malloc(sizeof(struct heap));
	new_heap->storage=create_sub_struct(max_l);

	new_heap->compar_func=new_compar;
	new_heap->swap_=new_swap;
	new_heap->insert=new_insert;
	new_heap->get_size=new_get_size;

	new_heap->get_first_value=new_get_ft_v;
	new_heap->get_last_value=new_get_ls_v;
	new_heap->pop=pop;

	return new_heap;
}
// auxiliary heap's functions
int run_comp(struct heap*exe,size_t id1,size_t id2){
	return exe->compar_func(exe->storage,id1,id2);
}
int run_gts(struct heap*exe){
	return exe->get_size(exe->storage);
}
void run_swp(struct heap*exe,int id1,int id2){
	exe->swap_(exe->storage,id1,id2);
}
void run_ins(struct heap*exe,int*array,size_t size){
	exe->insert(exe->storage,array,size);
}
void*run_gfv(struct heap*exe){
	return exe->get_first_value(exe->storage);
}
void*run_glv(struct heap*exe){
	return exe->get_last_value(exe->storage);
}
void run_pop(struct heap*exe,const void*new_value){
	exe->pop(exe->storage,new_value);
}

// heap's operation 
void shift_up(int index,struct heap*pointer){
	if(!index|run_comp(pointer,index,(index-1)/2))return;
	run_swp(pointer,index,(index-1)/2);
	shift_up((index-1)/2,pointer);
}
void shift_dw(int index,struct heap*pointer){
	int temp=index;
	if(index*2+1<run_gts(pointer)&&run_comp(pointer,temp,index*2+1))temp=index*2+1;
	if(index*2+2<run_gts(pointer)&&run_comp(pointer,temp,index*2+2))temp=index*2+2;

	if(temp!=index){
		run_swp(pointer,index,temp);
		shift_dw(temp,pointer);
	}
}
void insert(struct heap*pointer,int*array,size_t len){
	run_ins(pointer,array,len);
	shift_up(run_gts(pointer)-1,pointer);
}
void*extract(struct heap*pointer){
	void*result=run_gfv(pointer);
	run_pop(pointer,run_glv(pointer));
	shift_dw(0,pointer);
	return result;
}
int empty(struct heap*check){
	if(run_gts(check)<1)return 1;
	return 0;
}

int find(int v,int*parent){
	if(parent[v]!=v)parent[v]=find(parent[v],parent);
	return parent[v];
}
int umus(int v1,int v2,int*parent,int*rank){
	int root_v1=find(v1,parent),root_v2=find(v2,parent);

	if(root_v1==root_v2)return 0;

	if(rank[root_v1]<rank[root_v2]){
		parent[root_v1]=root_v2;
	}else if(rank[root_v2]<rank[root_v1]){
		parent[root_v2]=root_v1;
	}else{
		parent[root_v2]=root_v2;
		++rank[root_v1];
	}
	return 1;
}

int main(){
	//struct heap*tst=create_heap(10,comp_node,swap_node,append_set_node,sgs,sgf,sgl,pandr,create_set_node);
	int vertics,edges;
	while(scanf("%i %i",&vertics,&edges)&&vertics&&edges){
		struct heap*kruscal=create_heap(edges,comp_node,swap_node,append_set_node,sgs,sgf,sgl,pandr,create_set_node);
		int previous_size=0;
		for(int i=0;i<edges;++i){
			int array[3];
			scanf("%i %i %i",&array[0],&array[1],&array[2]);
			insert(kruscal,array,3);
			previous_size+=array[2];
		}
		int parent[vertics],rank[vertics],tot_size=0;

		for(size_t i=0;i<vertics;++i){
			parent[i]=i;
			rank[i]=i;
		}

		while(!empty(kruscal)){
			struct node*get=(struct node*)extract(kruscal);
			if(!umus(get->v1,get->v2,parent,rank))continue;
			tot_size+=get->wg;
		}
		printf("%i\n",previous_size-tot_size);
		free(kruscal);
	}
	return 0;
}
