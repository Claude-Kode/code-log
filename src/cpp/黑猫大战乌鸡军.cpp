#include <stdio.h>
#include <string.h>
char str[10000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a=0,b=0,c=0;
		scanf("%d %d %d",&a,&b,&c);
		scanf("%s",str);
		int len=strlen(str);
		int q=0,u=0;//表示QvQ和UwU的数量 
		for(int i=1;3*i<=len;i++){
			if(str[3*i-1]=='Q'){
				q++;
			}else{
				u++;
			}
		}
		int way1=q*a+u*b;//不转化 豆沙辣！
		int way2=q*c+(q+u)*b;//把q都转成u沙 
		int way3=u*c+(q+u)*a;//把u都转成q沙
		if(way1<=way2&&way1<=way3){
			printf("%d\n",way1);
		}else if(way2<way1&&way2<way3){
			printf("%d\n",way2);
		}else{
			printf("%d\n",way3);
		}
		str[0]='\0';
	}
	return 0;
}
