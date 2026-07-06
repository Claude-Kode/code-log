#include <stdio.h>
#define  mod (int)(1e9+7)
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		long long result=1;
		if(n>2&&k>2){
			result*=k%mod;
			for(int i=0;i<n-1;i++){
				result*=(k-1);
				result=result%mod
			}
		}
		printf("%lld\n",result);
	}
	return 0;
}
