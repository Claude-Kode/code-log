#include <stdio.h>
int arr1[10],arr2[10];
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",arr1[i]);
		arr2[arr1[i]]++;
		sum+=arr1[i];
	}
	for(int i=0;i<n;i++){
		if(arr2[i]!=0){
			printf("%d %d\n",i,arr2[i]);
		}
	}
	printf("%.2lf",(double)sum/n); 
	return 0;
}
