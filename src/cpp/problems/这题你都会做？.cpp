#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define mod 998244353
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string a;
	cin >> a;
	int len=a.length();
	//双索引外扩展,最小是2
	for(int i=0;i<len-1;i++){
		if(a[i]==a[i+1]){
			cout<<2<<endl;
			return 0;
		}
	}
	//单索引外扩展，最小是3
	for(int i=1;i<len-1;i++){
		if(a[i-1]==a[i+1]){
			cout<<3<<endl;
			return 0;
		}
	}
	cout <<-1<<endl;
	return 0；
}
