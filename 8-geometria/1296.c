#include<math.h>
#include<stdio.h>
#include<string.h>
//
double apolloniu(double x,double y,double z){
	return ((2.0/3.0)*pow(-pow(x,2.0)+2.0*pow(y,2.0)+2.0*pow(z,2.0),0.5));
}
double herons(double x,double y,double z){
	return (x+y+z)/2.0;
}

int main(){
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF){
		double edge_a=apolloniu(a,b,c),
			   edge_b=apolloniu(b,a,c),
			   edge_c=apolloniu(c,a,b);
		if(isnan(edge_a)|isnan(edge_b)|isnan(edge_c)|!isfinite(edge_a)|!isfinite(edge_b)|!isfinite(edge_c)){
			printf("-1.000\n");
			continue;
		}

		double semi_p=herons(edge_a,edge_b,edge_c),out=pow((semi_p*(semi_p-edge_a)*(semi_p-edge_b)*(semi_p-edge_c)),0.5);
		const double exact=1e-7;
		if(isnan(out)|out<=exact){
			printf("-1.000\n");
			continue;
		}
		printf("%.3lf\n",out);
	}
	return 0;
}
