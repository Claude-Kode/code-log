 #include <stdio.h>
 #include <string.h>
 char str[105],result[105]={'\0'};// (\0)的字典序最小 
 int main(){
 	int n;
 	scanf("%d",&n);
 	for(int i=0;i<n;i++){
 		scanf("%s",str);
 		if(strcmp(str,result)>=0){//比较字典序 
 			strcpy(result,str); //直接复制过去 
		 }
	 }
	 printf("%s",result);
	 return 0;
 }
