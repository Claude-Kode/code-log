#include <stdio.h>
int arr2[10000];
int main(){
	int times=4; 
	int temp=0;
	while(times--){
		int a=0,value=0;//a��ֽ������ b����������ֵ 
		scanf("%d",&a);
		for(int i=0;i<a;i++){
			scanf("%d",&value);	
			arr2[value]++;//Ƶ�ʷ�  arr2�±������ֵ ���ݵ���Ƶ�� 
			if(temp<=value){//�������ֵ 
				temp=value;
			} 
		}
	}
	int result=0;
	for(int i=1;i<=temp;i++){
		if(arr2[i]<4&&arr2[i]>0){//Ƶ�ʴ���0С��4��˵������ֵֽ�ƴ�������Ҫ���� 
			result+=4-arr2[i];
		} 
	}
	printf("%d",result);
	return 0;
}
