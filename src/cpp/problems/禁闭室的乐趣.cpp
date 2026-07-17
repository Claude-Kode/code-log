//用桶的思维，把字符串的长度塞进桶里，遍历后只要不是偶数就是输出NO 
#include <iostream>
#include <string>
using namespace std;
int buckle[1001];
int main(){
	ios_base::sync_with_stdio(false);cin.tie (0);cout.tie (0);
	int n;
	cin>>n;
	int max=0;
	string temp,result;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(i==0){result=temp;}
		int len=temp.length();
		buckle[len]++;
		if(max<len){max=len;}
	}
	for(int i=0;i<max;i++){
		if((buckle[i]&1)==1){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<result;
	return 0;
}
