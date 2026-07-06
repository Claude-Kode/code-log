//0¾Í--£¬1¾Í++
#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	int max=0,min=0,height=0;
    	string step;
    	cin>>step;
		int len=step.length(); 
        for(int i=0;i<len;i++){
        	step[i]=='0'?height--:height++;
        	if(max<height){max=height;}
        	if(min>height){min=height;}
		}
		cout<<max-min<<endl;
    }
    return 0;
}
