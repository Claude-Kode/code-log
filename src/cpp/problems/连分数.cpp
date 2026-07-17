//写出一个递归函数，开三个字符数组
//由于要插入 
#include <stdio.h>
#include <string.h>
void f(int n){
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
