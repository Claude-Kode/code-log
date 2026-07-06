#include <stdio.h>
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&c);
		if(a==0){//aµÈÓÚÁã
			if(b==0){
				if(c==0){
					printf("-1\n");
				}else{
					printf("0\n");
				}
			}else{//a=0 b!=0
				printf("1\n");
			}
		}else{
			if(b==0){//a!=0 b==0
				if(c==0){
					printf("1\n");
				}else{
					printf("2\n");
				}
			}else{//a!=0 b!=0
				if(c==0){
					printf("2\n");
				}else{
					if(b*b-4*a*c>0){
						printf("2\n");
					}else if(b*b-4*a*c==0){
						printf("1\n");
					}else{
						printf("0\n");
					}
				}
			}
		}
	}
	return 0;
}
