#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;
	cin>>t;
	string number;
	char sym;
	while(t--){
		int trush;
		cin>>trush;
		int times=0;//记录1出现的次数 
		cin>>number;
		int len=number.length();
		for(int i=1;i<len;i++){
			if(number[i]==0){
				sym='+';
			}else{
				times++;
				if((times&1)==0){
					sym='+';
				}else{
					sym='-';
				}
			}
			cout<<sym;
		}
		cout<<endl;	
	}
	return 0;
}
