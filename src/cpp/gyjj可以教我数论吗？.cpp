#include <stdio.h>
#include <string.h>
char s[1000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int laji;
		scanf("%d",&laji);
		scanf("%s",s);
		if(strstr(s,"gcd")!=NULL||strstr(s,"lcm")!=NULL){
			printf("gyjjtxdy!\n");	
		}else{
			printf("I'm not satisfied!!!\n");
		}
	}
	return 0;
}
