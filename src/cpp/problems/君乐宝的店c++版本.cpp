#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct nf{
	int age;
	int price;
	string name;
}a[21];
bool cmp(nf a,nf b){
	return a.price!=b.price?a.price>b.price:a.age>b.age;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].age>>a[i].price>>a[i].name;
	}
	sort(a,a+n,cmp); 
	for(int i=0;i<n;i++){
		cout<<a[i].age<<' '<<a[i].price<<' '<<a[i].name<<endl;
	}
	return 0;	
}

