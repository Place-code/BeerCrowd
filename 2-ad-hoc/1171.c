#include<stdio.h>
#include<stdlib.h>
//
struct Lista{
    int data;
    struct Lista*next;
};
struct Lista*crie(  int input){
    struct Lista*new_node=(struct Lista*)malloc(sizeof(struct Lista));
    new_node->data=input;
    new_node->next=NULL;
    return new_node;
}
struct Lista*app_end(struct Lista*ref,int value,int rep){
    struct Lista*apend=crie(value),*temp;
    if(!ref){
        return apend;
    }
    temp=ref;
    for(;temp->next;){
        if(temp->data==value&rep==0)
            break;
        temp=temp->next;
    }
    if(temp->data!=value||rep==1)
        temp->next=apend;
    return ref;
}
int in(struct Lista*ref,int comp,int posi){
    if(!ref)
        return -1;
    if(ref->data==comp)
        return posi;
    in(ref->next,comp,posi+1);
}
void printar(struct Lista*aux,struct Lista*aux2){
    if(!aux)
        return;
    printf("%i aparece %i vez(es)\n",aux->data,aux2->data);
    printar(aux->next,aux2->next);
}
void adi(struct Lista*ref,int end){
    struct Lista*temp=ref;
    for(int i=0;i<end;++i){
        temp=temp->next;
    }
    ++temp->data;
    return;
}
void bubble_sort(struct Lista*ref,struct Lista*value){
    if(!ref)
        return;
    struct Lista*init,*end=NULL,*init_2;
    int aux;
    for(;;){
        aux=0;
        init=ref;
        init_2=value;
        while(init->next!=end){
            if(init->data>init->next->data){
                init->next->data+=init->data;
                init->data=init->next->data-init->data;
                init->next->data-=init->data;
                //
                init_2->next->data+=init_2->data;
                init_2->data=init_2->next->data-init_2->data;
                init_2->next->data-=init_2->data;
                aux=1;
            }
            init=init->next;
            init_2=init_2->next;
        }
        end=init;
        if(aux==0)
            break;
    }
    return;
}
int main(){
    int r,ns,x;
    scanf("%i",&r);
    scanf("%i",&ns);
    struct Lista*l1=crie(ns),*l2=crie(1);
    for(int i=0;i<r-1;++i){
        scanf("%i",&ns);
        x=in(l1,ns,0);
        // printf("%i\n",x);
        if(x==-1){
            l2=app_end(l2,1,1);
        } else{
            adi(l2,x);
        }
        l1=app_end(l1,ns,0);
    }
    bubble_sort(l1,l2);
    printar(l1,l2);
    return 0;
}