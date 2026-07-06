#include <stdio.h>
int qihuan[100005],didian[100005];
int main(){
	int n,h;//地点数量n和阈值h 
	scanf("%d %d",&n,&h);
	//
	long long sum=0;//去过地点奇幻值总值 
	for(int i=1;i<=n;i++){
		scanf("%d",&qihuan[i]);
		//
	}
	int k;
	scanf("%d",&k);//去过的地点数量 
	//
	for(int i=0;i<k;i++){
		scanf("%d",&didian[i]);//地点的序号
		//
		sum+=qihuan[didian[i]];
		//
		qihuan[didian[i]]/=2;
		// 
		if(sum>h){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("A peaceful night\n");
	return 0;
}
// 
