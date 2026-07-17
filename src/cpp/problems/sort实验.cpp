#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string arr[10000];
bool cmp(string a,string b){
	if(a=="SB"&&b!="SB"){
		return true;
	}else if(a!="SB"&&b=="SB"){
		return false;
	}else{
		return a<b;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(&arr[0],&arr[n],cmp);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}
//ÑùÀý
//n=10 
//SB sb Sb sB SB 2B SB hah qw DSB  
