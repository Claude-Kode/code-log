#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string number;cin>>number;
		int len=number.length();
		int sub_point=0;
		for(int i=0;i<len;i++){
			if(number[i]=='.'){sub_point=i;}
		}
		for(int i=0;i<7;i++){
			if(i==0){cout<<number[i]<<'.';}
			if(i==sub_point){continue;}
			cout<<number[i];
		}
		cout<<' '<<sub_point-1<<endl;
	}
	return 0;
}
