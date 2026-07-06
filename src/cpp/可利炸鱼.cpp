#include <stdio.h>
#include <string.h>
string f(int n){
	if(n==0){
		printf("0");
	}
	for(int i=0;i<=n;i++){
		printf("i/(i+f(i+1))");
}	
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		printf("%s",f(n));	
	} 
	return 0;
}
