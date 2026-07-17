#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int arr[100000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	fill_n(arr,n,0);
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	return 0;
}
