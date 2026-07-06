//找出最高和第二高
//选中的不是最高的就输出最高的
//是最高的输出第二高
/*
#include <iostream>
using namespace std;
int height[1000005];
int main(){
	int n;
	cin>>n;
	//怎么把找最高和第二高塞进同一段代码？
	int max1=0,max2=0;
	for(int i=0;i<n;i++){
		cin>>height[i];
		if(height[i]>max1){
			max1=height[i];
		}
	} 
	for(int i=0;i<n;i++){
		if(height[i]>max2&&height[i]!=max1){
			max2=height[i];
		}
	} 
	if(max2==0){
		max2=max1;
	}
	for(int i=0;i<n;i++){
		if(height[i]!=max1){
			cout<<max1<<' ';
		}else{
			cout<<max2<<' ';
		}
	} 
	return 0;
} 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int height[1000005],cpy[1000005];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>height[i];
	} 
	memcpy(cpy,height,4*n);
	sort(cpy,cpy+n,greater<int>());
	for(int i=0;i<n;i++){
		height[i]!=cpy[0]?cout<<cpy[0]<<' ':cout<<cpy[1]<<' ';
	}
	return 0;
}


















