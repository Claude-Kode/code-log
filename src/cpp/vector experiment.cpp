//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main (){
//	vector < int > sb = {5,8,4,3,7,76588,48};
//	int target = 10 ;
//	 auto result_ptr = find_if( sb.begin() , sb.end(), [ target ]( int x ){
//		return x > target ;
//	} ) ;
//	cout << *result_ptr ; 
//	return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main (){
	vector < int > sb = {5,8,723578994,3,7,76584358,48,346,3463468,53,56,3,442722345,45,567825,6};
	int target = 10 ;
	auto result_ptr = find_if( sb.begin() , sb.begin() + 7 , [target, count = 0]( int x )mutable{
		target = 114514;
		if ( x > target ) {
			count++ ;
			if ( count == 3 ) return true ; 
		}
		return false ;
	} ) ;
	cout << *result_ptr ; 
	return 0;
}
