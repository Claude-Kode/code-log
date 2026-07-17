#include <stdio.h>
int arr1[100001],arr2[200001];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int max=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
		arr2[arr1[i]]++;
		if(max<arr1[i]){
			max=arr1[i];
		}
	}
	long long result=0; 
	for(int i=0;i<=max-k;i++){
		if(arr2[i]!=0&&arr2[i+k]!=0){
			result+=(long long)arr2[i+k]*arr2[i];
		}
	}
	printf("%lld",result);
	return 0;
}
//从下标依次往上面加c的下标的元素不等于零 
