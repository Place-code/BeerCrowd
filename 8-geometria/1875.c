#include<stdio.h>
#include<string.h>
//
int points(int issuer,int receiver){
	if(issuer==(int)'B'&&receiver==(int)'R')
		return 2;
	else if(issuer==(int)'B')
		return 1;

	if(issuer==(int)'G'&&receiver==(int)'B')
		return 2;
	else if(issuer==(int)'G')
		return 1;

	if(issuer==(int)'R'&&receiver==(int)'G')
		return 2;
	else
		return 1;
}

int main(){
	int rep;
	for(scanf("%i",&rep);rep;--rep){
		int goals,score[]={0,0,0};
		for(scanf("%i",&goals);goals;--goals){
			char team_1[5],team_2[5];
			scanf("%s %s",team_1,team_2);

			if(!strcmp(team_1,"B"))
				score[0]+=points((int)team_1[0],(int)team_2[0]);
			if(!strcmp(team_1,"G"))
				score[1]+=points((int)team_1[0],(int)team_2[0]);
			if(!strcmp(team_1,"R"))
				score[2]+=points((int)team_1[0],(int)team_2[0]);
		}
		if(score[0]>score[1]&&score[0]>score[2])
			printf("blue\n");
		else if(score[1]>score[0]&&score[1]>score[2])
			printf("green\n");
		else if(score[2]>score[0]&&score[2]>score[1])
			printf("red\n");
		else if(score[0]==score[1]&&score[1]==score[2])
			printf("trempate\n");
		else if(score[0]==score[1]||score[0]==score[2]||score[1]==score[2])
			printf("empate\n");
	}

	return 0;
}
