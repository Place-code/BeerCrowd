#include<iostream>
//
int isRectangle(float x,float y,float z){
	if(y*y+z*z==x*x)return 1;
	else return 0;
}
//
int main(){
	float a[3];
	std::cin>>a[0]>>a[1]>>a[2];
	if(!isRectangle(a[0],a[1],a[2]))std::cout<<"Nao eh retangulo!\n";
	else std::cout<<"AREA = "<<int(a[1]*a[2]+((a[2]/2.0)*(a[2]/2.0)*3.0)/2.0-(a[2]*a[1])/2.0)<<"\n";
	return 0;
}
