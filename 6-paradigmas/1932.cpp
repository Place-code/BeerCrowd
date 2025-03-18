#include<iostream>
//
int main(){
	int quotes,price;
	scanf("%i %i",&quotes,&price);
	int left,right,tot_temp=0,tot=0;
	scanf("%i",&left);
	while(quotes>1){
		scanf("%i",&right);
		if(right-left>=tot_temp){
			tot_temp=std::max(tot_temp,right-left-price);
		}else if(tot_temp){
			tot+=tot_temp;
			left=right;
			tot_temp=0;
		}else{
			left=std::min(left,right);
		}
		--quotes;
	}
	tot+=tot_temp;
	printf("%i\n",tot);

	return 0;
}
