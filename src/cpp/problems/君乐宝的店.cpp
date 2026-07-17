#include <stdio.h>
#include <string.h>
	struct{
		int age;
		int price;
		char name[100];
	}a[21];
	struct{
		int age;
		int price;
		char name[100];
	}temp1[1];
	struct{
		int age;
		int price;
		char name[100];
	}temp2[1];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %s",&a[i].age,&a[i].price,&a[i].name);
	}
	for(int i=0;i<n-1;i++){//开始冒泡  先冒价格  临时结构体是temp1  从大到小 
		for(int j=0;j<n-1-i;j++){
			if(a[j].price<a[j+1].price){//价格从大到小 
			
				temp1[0].age=a[j].age;
				temp1[0].price=a[j].price;
				strcpy(temp1[0].name,a[j].name);
				
				a[j].age=a[j+1].age;
				a[j].price=a[j+1].price;
				strcpy(a[j].name,a[j+1].name);
				
				a[j+1].age=temp1[0].age;
				a[j+1].price=temp1[0].price;
				strcpy(a[j+1].name,temp1[0].name);

			}else if(a[j].price==a[j+1].price){
				for(int k=0;k<n-1;k++){//第二次冒泡  冒年龄  临时结构体是temp2  从小到大 
					for(int l=0;l<n-1-k;l++){
						if(a[l].age>a[l+1].age){//年龄从大到小 
							
							temp2[0].age=a[l].age;
							temp2[0].price=a[l].price;
							strcpy(temp2[0].name,a[l].name);
				
							a[l].age=a[l+1].age;
							a[l].price=a[l+1].price;
							strcpy(a[l].name,a[l+1].name);
				
							a[l+1].age=temp2[0].age;
							a[l+1].price=temp2[0].price;
							strcpy(a[l+1].name,temp2[0].name);
							
						}	
					}
				}
			}
		} 
	}
	for(int i=0;i<n;i++){
		printf("%d %d %s\n",a[i].age,a[i].price,a[i].name);
	} 
	return 0;
}
