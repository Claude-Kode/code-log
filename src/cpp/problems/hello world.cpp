#include <iostream>
#include <string>
using namespace std;
int main(){
	string garbage;
	getline(cin,garbage);
	string s,t;
	cin>>s>>t;
	if(s.find(t)==std::string::npos){
		cout<<"no\n";
	}else{
		cout<<"yes\n";
	}
	return 0;
}
