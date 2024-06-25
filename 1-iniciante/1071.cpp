#include <iostream>
using namespace std;
//
int main(){
	int x,y, tot=0;
	cin>>x;
	cin>>y;
	for(int i=y+1;i<x;i++){
		if(i%2){
			tot+=i;
		}
	}
	cout<<tot<<endl;
}