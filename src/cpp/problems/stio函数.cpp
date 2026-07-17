#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int arr[10001],pre[10001],suf[10001],diff[10001];
void build_pre(itn arr[],int n,int pre[]){
	pre[0]=0;
	for(int i=0;i<n;i++){
		pre[i+1]=pre[i]+arr[i];
	}
}
void build_suf(int arr[],int n,int suf[]){
	suf[n]=0;
	for(int i=n-1;i>=0;i--){
		suf[i]=suf[i+1]+arr[i];
	}
}
void build_diff(int arr[],int n,int diff[]){
	diff[0]=arr[0];
	for(int i=1;i<n;i++){
		diff[i]=arr[i]-arr[i-1];
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build_suf(arr,n,suf);
	for(int i=0;i<n;i++){
		cout<<suf[i]<<' ';
	}
	return 0;
} 

