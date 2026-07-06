#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;
int arr[10000];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	int temp=0;
    	cin>>temp;
    	arr[temp]++;
	}
	for(int i=0;i<=n*m;i++){
		if(arr[i]==0){
			cout<<i;
		}
	}
    return 0;
}
//数组可千万别开里面了 
