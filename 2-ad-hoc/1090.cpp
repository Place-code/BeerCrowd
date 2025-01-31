#include<iostream>
#include<limits>
//
int combination[][4]={{0,1,2,0},{0,10,20,1},{20,21,22,2},{10,11,12,3},{2,12,22,4},{1,11,21,5},{0,11,22,6},{0,21,12,7},{10,1,22,8},{10,21,2,9},{20,11,2,10},{20,1,12,11}}, 
	essential[9][4]={{0,1,6,7},{0,5,8,11},{0,4,9,10},{1,3,8,9},{3,5,6,10},{3,4,7,11},{1,2,10,11},{2,5,7,9},{2,4,6,8}},
	matrix[3][3],
	notIntersection[][2]={{2,3},{4,5},{0,3},{0,2},{1,5},{4,1},{11,9},{8,10},{7,10},{6,11},{7,8},{6,9}},
	explored[12];
//
void displayMatrix(){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			std::cout<<matrix[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}

int mod(){
	int tot=0,modulo=0,little=3;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			tot+=matrix[i][j]/3;
			(matrix[i][j]%3)?++modulo:modulo;
			(matrix[i][j]%3<little&&matrix[i][j]%3&&matrix[i][j]>2)?little=matrix[i][j]%3:little;
		}
	}
	if(modulo>2)tot+=little;
	return tot;
}

int subtractMatrix(int next){
	int impossible[12]={},possibleVertic;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(matrix[i][j])continue;
			for(int k=0;k<4;++k)impossible[essential[i*3+j][k]]=1;
		}
	}
	possibleVertic=(!impossible[next])?next:-1;
	for(int i=0;i<12&&impossible[next];++i){
		if(!impossible[i]){
			possibleVertic=i;
			break;
		}
	}
	//std::cout<<possibleVertic<<"-";
	if(possibleVertic==-1){
		return mod();
	}
	int little=std::numeric_limits<int>::max();
	for(int i=0;i<3;++i){
		int aux=matrix[(combination[possibleVertic][i]-combination[possibleVertic][i]%10)/10][combination[possibleVertic][i]%10];
		if(aux<little)little=aux;
	}
	for(int i=0;i<3;++i)matrix[(combination[possibleVertic][i]-combination[possibleVertic][i]%10)/10][combination[possibleVertic][i]%10]-=little;
	int no=(!explored[notIntersection[next][0]])?notIntersection[next][0]:notIntersection[next][1];
	explored[next]=1;
	return little+subtractMatrix(no);
}
//
int main(){
	int rep;//tsts[100],index=0;
	while(std::cin>>rep&&rep){
		for(int i=0;i<3;++i)std::fill(matrix[i],matrix[i]+3,0);
		for(int i=0;i<rep;++i){
			std::string amount,type;
			std::cin>>amount>>type;
			int row=(type=="circulo"|type=="circulos")?0:(type=="quadrado"|type=="quadrados")?1:2,reel=(amount=="um")?0:(amount=="dois")?1:2;
			++matrix[row][reel];
		}
		/*
		for(int i=0;i<12;++i){
			for(int j=0;j<3;++j)std::cout<<matrix[(combination[i][j]-combination[i][j]%10)/10][combination[i][j]%10]<<" ";
			std::cout<<"\n";
		}*/
		displayMatrix();
		//std::cout<<"\n";
		//tsts[index]=subtractMatrix(0);
		std::cout<<subtractMatrix(0)<<"\n";
		//std::cout<<"\n";
		displayMatrix();
	}
	//for(int i=0;i<index;++i)std::cout<<tsts[i]<<"\n";
	return 0;
}
