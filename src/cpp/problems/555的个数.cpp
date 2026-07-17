#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int n ;
	cin >> n ;
	int result = 0 ；
	for ( int i = 0 ; i < 10 ; i++ ){
		if ( pow ( 10 , i ) + 555 > n ){  result++ ; }
	}
	
	return 0;
}
