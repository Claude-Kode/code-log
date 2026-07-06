#include <stdio.h>
#include <string.h>
char str[50]; 
int main(){
	scanf("%[^\n]",str);
	int sign=0;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='h'&&sign==0){
			sign++;
	    }else if(str[i]=='x'&&sign==1){
	    	sign++;
		}else if(str[i]=='c'&&sign==2){
	    	sign++;
		}else if(str[i]=='t'&&sign==3){
	    	sign++;
		}else if(str[i]=='c'&&sign==4){
	    	sign++;
		}else if(str[i]=='l'&&sign==5){
	    	sign++;
		}
    }
    if(sign>=6){
    	printf("I am glad to hear that.\n");
	}else{
		printf("I do not know what r u talking about!");
	}
	return 0;
}
