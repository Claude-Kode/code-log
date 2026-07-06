#include <stdio.h>
int main(){
	int T=0;
	scanf("%d",&T);
	int number=0;
	while(T--){
		scanf("%d",&number);
		if(number<=3){
			printf("%d\n",number);
		}else if(number & 1==1){//说明是奇数 
			printf("3\n");
		}else{//说明是偶数 
			printf("2\n");
		} 
	}	
	return 0;
}
