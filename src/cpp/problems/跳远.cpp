//找寻低于当前体力值中最大的沙坑
//桶排序以后遍历到第一个不符合条件的打印上一个
//由于不得重复跳过一个沙坑所以用erase删去 
//好像不用啊哈哈 
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int shakeng[1001],buckle[1001];
int main(){
	int n,k;
	cin>>n>>k;
	int max=0;
	for(int i=0;i<n;i++){
		cin>>shakeng[i];
		buckle[shakeng[i]]++;
		if(max<shakeng[i]){
			max=shakeng[i];
		}
	}
	int result=0;
	for(int i=0;i<max;i++){
		if(buckle[i]!=0){
			result++;
			if(i>=k){
				result--;
				break;
			}	
		}
	}
	cout<<result;
	return 0;
}
*/ 
#include <iostream>
using namespace std;
int main(){int n,k;
	cin>>n>>k;
	int result=0,len=0;
	for(int i=0;i<n;i++){
		cin>>len;
		if(len>=k){
			result++;
		}
	}
	cout<<result;
	return 0;
}
