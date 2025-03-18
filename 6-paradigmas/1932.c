#include<stdio.h>
//
int main(){
	int quotes,price;
	scanf("%i %i",&quotes,&price);
	int right,left,tot=0,tot_temp=0;
	scanf("%i",&left);
	while(quotes>1){
		scanf("%i",&right);
		if(right-left>=tot_temp){
			tot_temp=(right-left-price>tot_temp)?right-left-price:tot_temp;
		}else if(tot_temp){
			tot+=tot_temp;
			tot_temp=0;
			left=right;
		}else{
			left=(right<left)?right:left;
		}
		--quotes;
	}
	tot+=tot_temp;
	printf("%i\n",tot);
}
