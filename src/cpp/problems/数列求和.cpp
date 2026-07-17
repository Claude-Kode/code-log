#include <stdio.h>
int arr1[1000],arr2[1000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",arr1[i]);
		arr2[arr1[i]]++;
	}
	for(int i=0;i<n;i++){
		if(arr2[i]!=0){
			printf("%d %d\n",i,arr2[i]);
		}
	}
	return 0;
}
