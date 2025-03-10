#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
struct car{
	char*ID;
	short init,end;
};
struct car*create_car(char*new_id,short init,short end){
	struct car*new_car=malloc(sizeof(struct car));
	new_car->ID=malloc(sizeof(char)*(strlen(new_id)+10));
	strcpy(new_car->ID,new_id);
	new_car->init=init;
	new_car->end=end;

	return new_car;
}
void display_car(struct car*ref){
	printf("%s %hi %hi",ref->ID,ref->init,ref->end);
}

struct linked_list{
	struct car*value;
	struct linked_list*next;
	struct linked_list*prev;
};
struct linked_list*create_ll(struct car*new_value,struct linked_list*prev){
	struct linked_list*new_ll=malloc(sizeof(struct linked_list));
	new_ll->value=new_value;
	new_ll->next=NULL;
	new_ll->prev=prev;

	return new_ll;
}
void insert_ll(struct linked_list**ref,struct car*new_value){
	if(!(*ref)->value){
		(*ref)->value=new_value;
		(*ref)->next=create_ll(NULL,(*ref));
		(*ref)=(*ref)->next;
		return;
	}

	if(!(*ref)->prev){
		(*ref)->prev=create_ll(new_value,NULL);
		(*ref)->prev->next=(*ref);
		(*ref)=(*ref)->prev;
		return;
	}

	struct linked_list*cp_ref=create_ll((*ref)->value,NULL);
	cp_ref->next=(*ref)->next;
	cp_ref->next->prev=cp_ref;

	(*ref)=(*ref)->prev;
	free((*ref)->next);
	(*ref)->next=create_ll(new_value,(*ref));
	(*ref)=(*ref)->next;
	(*ref)->next=cp_ref;
	cp_ref->prev=(*ref);
}

void move_left_ll(struct linked_list**ref){
	if(!(*ref)->prev)
		return;
	(*ref)=(*ref)->prev;
	move_left_ll(ref);
}
void move_right(struct linked_list**ref){
	if(!(*ref)->next->value||!(*ref)->value)
		return;
	(*ref)=(*ref)->next;
	move_right(ref);
}
void display_ll_lr(struct linked_list*ref){
	struct linked_list*temp=ref;
	while(temp->value){
		display_car(temp->value);
		printf("|");
		temp=temp->next;
	}
}
void display_ll_rl(struct linked_list*ref){
	struct linked_list*temp=ref;
	while(temp&&temp->value){
		display_car(temp->value);
		printf("|");
		temp=temp->prev;
	}
}

int main(){
	struct linked_list*tst=create_ll(NULL,NULL),*last=tst;
	for(int i=0;i<35;++i){
		char str[]={(char)(i%26+65),(char)((i+1)%26+65),(char)((i+2)%26+65)};
		insert_ll(&last,create_car(str,i,i));
	}
	struct linked_list*epa=tst;
	for(int i=0;i<1;++i)
		epa=epa->next;
	insert_ll(&epa,create_car("capa",5,5));
	display_ll_lr(tst);
	printf("\n");
	display_ll_rl(last->prev);
	printf("\n");

	return 0;
}
