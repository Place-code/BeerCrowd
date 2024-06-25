#include <iostream>
#include <cstring>
using namespace std;
//
int main(){
	int x[2],tot=1;
	string inp;
	getline(cin,inp);
	char *split=strtok(&inp[0], " ");
	for(int i=0;i<2;i++){
		x[i]=stoi(split);
		split=strtok(NULL," ");
	}
	while(tot<=x[1]){
		for(int j=0;j<x[0];j++){
		    cout<<tot;
		    if(j<x[0]-1){
		        cout<<"-";
		    }
		    ++tot;
		     if(tot>x[1]){
			break;
		     }   
		   }
		cout<<"\n";
	}
	return 0;
}