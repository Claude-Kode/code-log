#include <stdio.h>
#include <string.h>
	struct{
		int age;
		int price;
		char name[100];
	}a[21];//储存数据的结构体 
	struct{
		int age;
		int price;
		char name[100];
	}temp1[1];//价格排序的中间结构体 
	struct{
		int age;
		int price;
		char name[100];
	}temp2[1];//年龄排序的中间结构体 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %s",&a[i].age,&a[i].price,&a[i].name);
	}
	for(int i=0;i<n-1;i++){//开始冒泡  先冒价格  中间结构体是temp1  从大到小 
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
				if(a[j].age<a[j+1].age){//年龄从大到小 中间结构体是temp2  注意不要再写一个冒泡了 只比较相邻两项即可 
					temp2[0].age=a[j].age;
					temp2[0].price=a[j].price;
					strcpy(temp2[0].name,a[j].name);
				
					a[j].age=a[j+1].age;
					a[j].price=a[j+1].price;
					strcpy(a[j].name,a[j+1].name);
				
					a[j+1].age=temp2[0].age;
					a[j+1].price=temp2[0].price;
					strcpy(a[j+1].name,temp2[0].name);
								
				}	
			}
		} 
	}
	for(int i=0;i<n;i++){
		printf("%d %d %s\n",a[i].age,a[i].price,a[i].name);
	} 
	return 0;
}
