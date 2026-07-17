#include <stdio.h>
#include <string.h>
char str[50];
char haha[]={"hxctcl"};
int main(){
	scanf("%[^\n]",str);
	int len=strlen(str);
	int sub=0,sign=0;
	for(int i=0;i<len;i++){
		if(sub==6){
			break;
		}
		if(str[i]==haha[sub]){
			sign++;
			sub++;
		}
	}
	if(sign==6){
		printf("I am glad to hear that.\n");
	}else{
		printf("I do not know what r u talking about!\n");
	}
	return 0;
}
