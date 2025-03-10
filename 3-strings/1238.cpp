#include<iostream>
//
int main(){
	int r;
	for(std::cin>>r;r>0;--r){
		std::string str1,str2;
		std::cin>>str1>>str2;
		for(size_t i=0;i<std::max(str1.size(),str2.size());++i){
			if(i<str1.size())
				std::printf("%c",str1[i]);
			if(i<str2.size())
				std::printf("%c",str2[i]);
		}
		std::printf("\n");
	}

	return 0;
}
