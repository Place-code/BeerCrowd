#include<cmath>
#include<cstdio>
#include<string>
//
double apollonius(double x,double y,double z){
	return (2.0/3.0*std::pow(-std::pow(x,2.0)+2.0*std::pow(y,2.0)+2.0*std::pow(z,2.0),0.5));
}
double heron(double x,double y,double z){
	return (x+y+z)/2.0;
}
int main(){
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF){
		double edga=apollonius(a,b,c),
			   edgb=apollonius(b,a,c),
			   edgc=apollonius(c,a,b);
		if(std::isnan(edga)|std::isnan(edgb)|std::isnan(edgc)){
			printf("-1.000\n");
			continue;
		}

		double semp=heron(edga,edgb,edgc),out=std::pow(semp*(semp-edga)*(semp-edgb)*(semp-edgc),0.5);
		if(std::isnan(out)|out<1e-7){
			printf("-1.000\n");
			continue;
		}
		printf("%.3lf\n",out);
	}
	return 0;
}
