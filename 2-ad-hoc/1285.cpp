#include<iostream>
#include<cstring>
//
int pontuation(int sco,int rec){
	if(sco==(int)'R'&&rec==(int)'B')
		return 1;
	else if(sco==(int)'R')
		return 2;
	
	if(sco==(int)'B'&&rec==(int)'R')
		return 2;
	else if(sco==(int)'B')
		return 1;
	
	if(sco==(int)'G'&&rec==(int)'R')
		return 1;
	else if(sco==(int)'G')
		return 2;

	return 0;
}


int main(){
	int rep;
	for(std::scanf("%i",&rep);rep;--rep){
		int score,points[3];
		memset(points,0,sizeof(points));
		for(std::scanf("%i",&score);score;--score){
			char scored[10],conceded[10];
			std::scanf("%s %s",scored,conceded);

			int goal=pontuation((int)scored[0],(int)conceded[0]);
			if((int)scored[0]==(int)'R')
				points[0]+=goal;
			if((int)scored[0]==(int)'G')
				points[1]+=goal;
			if((int)scored[0]==(int)'B')
				points[2]+=goal;
		}
		if(!points[0])points[0]=-1;
		if(!points[1])points[1]=-2;
		if(!points[2])points[2]=-3;

		if(points[0]==points[1]&&points[1]==points[2])
			printf("trempate\n");
		else if(points[0]==points[1]|points[1]==points[2]|points[0]==points[2])
			printf("empate\n");
		else if(points[0]>points[1]&&points[0]>points[2])
			printf("red\n");
		else if(points[1]>points[0]&&points[1]>points[2])
			printf("green\n");
		else if(points[0]>points[1]&&points[2]>points[0])
			printf("blue\n");
	}
	return 0;
}
