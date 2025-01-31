#include<stdio.h>
//
int isRectangle(float x,float y,float z){
	return (y*y+z*z==x*x);
}
//
int main(){
	float b[3];
	scanf("%f %f %f",&b[0],&b[1],&b[2]);
	if(!isRectangle(b[0],b[1],b[2]))printf("Nao eh retangulo!\n");
	else printf("AREA = %.0f\n",b[1]*b[2]+((b[2]/2.0)*(b[2]/2.0)*3)/2-(b[1]*b[2])/2);
	return 0;
}
