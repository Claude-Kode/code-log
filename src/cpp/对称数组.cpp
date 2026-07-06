#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;
int buckle[100001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		int number=0;
		cin>>number;
		buckle[number]++;   
    }
    for(int i=0;i<n;i++){
    	if((buckle[i]&1)==1){//如果是奇数 
    		cout<<"NO";
    		return 0;
		}
	}
    cout<<"YES";
    return 0;
}
