#include <iostream>
using namespace std;
int main(){
	int sum;
	cin>>sum;
	while(sum--){
		long long n,a,b;
		cin>>n>>a>>b;
		long result;
		if(b/2>=a){
			result=a*n;
			cout<<result<<endl;
		}else{//如果一次买俩比较便宜 
			if((n&1)==0){//是偶数
				result=n/2*b;
				cout<<result<<endl; 
			}else{
				result=(n+1)/2*b-b+a;
				cout<<result<<endl;
			}
		}
		result=0;	
	} 
	return 0;
}
