// header file
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
// macro definition
#define endl '\n'
#define int long long
// namespace declarations
using namespace std ;
// global variables && arrays
int answer[10] ;
bool beenUsed[10] = { false } ;
// functions declarations
void DFS ( int n , int step ) {
	// search from 1 , if there is an answer , go further , step will ++
	// if step == n + 1 , there must be n search result , which can be formed into an answer then you can out put
	// when step reach to n + 1 , when the code executed up to for loop
	// there is no i = n + 1 , so return to the last function , which step == n 
	// and the code executed to " beenUsed[i] = false " , the because i == n already , for loop end , return to previous layer function
	// in this layer , step == n - 1 and in the for loop , i = n - 1  you should understand that i is the value of the elements in the array-answer
	// the step symbols how many lanyers of the function now is , also the number of elements in the array-answer
	// come back , the 
	
	if ( step == n + 1 ) { 
		for ( int i = 1 ; i <= n ; i ++ ) {
			cout << answer[i] << ' ' ;  
		}
		cout << endl ;
	} else {
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( beenUsed[i] == false ) {
				beenUsed[i] = true ;
				answer[step] = i ;
				DFS ( n , step + 1 ) ;
				beenUsed[i] = false ;
			}
		}
		return ;
	}
}
//idea
/*
DFS implementation ideas
1. store the node that the corrent node can approach
2. start from a fixed node (usually given by problem )
3. 
*/
// code area
signed main(){
	ios_base :: sync_with_stdio ( false ) ; cin.tie ( nullptr ) ; cout.tie ( nullptr ) ;
	int n ;
	cin >> n ;
	DFS ( n , 1 ) ; 
	return 0 ;
}
//questions ：
/*

*/
