#include <stdio.h>
int kefangwen[101],haoyou[101][101],dianzan[101];//二维数组第一个是自己，第二个是别人（下标） 
//下标从1开始哦 
int main(){
	int t=0;
	scanf("%d",&t);
	while(t--){
		int n=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&kefangwen[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&haoyou[i][j]);
				if(kefangwen[j]==1){
					dianzan[j]++;
				}else{//空间不可访问
					if(haoyou[i][j]==1){
						dianzan[j]++;
					}//不是好友不用写不加就行了 
				}
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",dianzan[i]);
			dianzan[i]=0;
		}
        printf("\n");
	}
	return 0;
}
