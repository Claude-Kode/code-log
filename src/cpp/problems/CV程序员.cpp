//这道题就是求从小到大有多少个不一样的数 
#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;
int arr[10000000];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	int n=0;
    	cin>>n;
    	int max=0;
    	for(int i=0;i<n;i++){
    		int temp;
    		cin>>temp;
    		arr[temp]++;
    		if(max<temp){
    			max=temp;
			}
		}
		int result=0;
		for(int i=0;i<=max;i++){
			if(arr[i]!=0){
				result++;
				arr[i]=0;
			}
		}
		cout<<result<<endl;
	}
    return 0;
}
