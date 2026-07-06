#include <stdio.h>
int TH(int time){
	if(time==1){
		return 1;
	}
	return 2*TH(time)+1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int time;
		scanf("%d",time);
		printf("%d\n",TH(time));
	}
	return 0; 
}
