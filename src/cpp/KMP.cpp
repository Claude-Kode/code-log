// brutal matching subsequence 
#include <iostream>
#include <string>
#include <vector>
using namespace std ;

int main() {
    string str , sample ; cin >> str >> sample ; 
    int l = 0 , r = 0 ; 
    while ( l < sample.size() && r < str.size() ) 
        sample[l] == str[r] ? l ++ , r ++ : r ++ ; 
    l == sample.size() ? cout << "yes" << endl : cout << "no" << endl ;
    
    return 0 ; 
}
