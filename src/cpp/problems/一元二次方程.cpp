#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a!=0){//是二元一次方程 
			if(b*b-4*a*c>0){
				printf("2\n");
			}else if(b*b-4*a*c==0){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}else{//不是二元一次方程
			if(b!=0){//线性方程 
				printf("1\n");
			}else{//常数函数 
				if(c!=0){
					printf("0\n");
				}else{
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}
