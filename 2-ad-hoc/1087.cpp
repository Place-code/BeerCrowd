#include<iostream>
//
int end;
bool inRange(int x,int y){
	for(int i=0;i<2;++i){
		int adX=(i==0)?1:0,adY=(i==0)?0:1;
		for(int j=0;j<8;++j){
			if(((x*adY+j*adX)*10+y*adX+j*adY)==end)return true;
		}
	}
	int auxX=x-y,auxY=0;
	for(;auxX<8&&auxY<8;++auxX,++auxY){
		if(auxX*10+auxY==end)return true;
	}
	//F(x)=8-x y=8-x-1 -> x=8-y-1
	auxX=x-(7-y);auxY=7;
	for(;auxX<8&&auxY>-1;++auxX,--auxY){
		if(auxX*10+auxY==end)return true;
	}
	return false;
}

int main(){
	int x1,y1,x2,y2;
	while(std::cin>>x1>>y1>>x2>>y2&&x1!=0&&y1!=0&&x2!=0&&y2!=0){
		if(x1==x2&&y1==y2){
			std::cout<<"0\n";
			continue;
		}
		end=(x2-1)*10+y2-1;
		if(inRange(x1-1,y1-1))std::cout<<"1\n";
		else std::cout<<"2\n";
	}
}
