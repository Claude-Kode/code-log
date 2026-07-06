//ͷ�ļ�
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
//�궨��
#define endl '\n'
//�����ռ�����
using namespace std;
//ȫ�ֱ���&����

//��������


int main(){
    std::vector<int> a(10000) ;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    a[0]=a.back()=23;
    // try
    {

        a.at( 10000000 ) = 100 ;
    }
    // catch(...)
    {

    }
    int t,v;
    cin>>t;
    for(int i=0;i<t;i++){
        cout << "Y" ;
    	// int a,b,k;
    	// cin>>a>>b>>k;
        // if(abs(b-a)%k==0){
        // 	cout<<"YES"<<endl;
		// }else{
		// 	cout<<"NO"<<endl; 
		// }
        cin >> v ;
    }
    return 0;
}
