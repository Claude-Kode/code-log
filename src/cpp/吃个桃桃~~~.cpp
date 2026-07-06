//ͷ�ļ�
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
//�궨��
#define endl '\n'
#define mod 99824353ll
//�����ռ�����
using namespace std;
//ȫ�ֱ���&����
struct taotao{
	int number;
	int sub;
	void clear(){
		number=0;
		sub=0;
	}
}a[2001];
//��������
int cmp(const taotao& a,const taotao& b){
	return a.number > b.number;
}
//����
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for( int i=0;i<n+1;i++){
			cin>>a[i].number;
			a[i].sub=i;
		}
		sort(a,a+n+1,cmp);
		long long result=0;
		for( int i=1;i<n+1;i++){
			if(a[i].number==0){break;}
			result+=abs(a[i].sub-a[i-1].sub);
			a[i-1].clear();
		}
		cout<<result<<endl;
	}
	return 0;
}
