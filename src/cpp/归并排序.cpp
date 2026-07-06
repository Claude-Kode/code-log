// class Solution {
// public:
//     int reversePairs(vector<int>& record) {
//         // increasing
//         vector<int> sortedSequence ;
//         int res = 0 ; 
//         for ( int &a : record ) {
//             // 对于每个数字 在有序序列中寻找插入的位置 
//             // 这个位置的索引和总长度的差就是逆序对的个数
//             // 位置就是插入后的位置 也就是他会取代第一个等于他的位置
//             auto insertPos = lower_bound( sortedSequence.begin() , sortedSequence.end() , 1LL + a ) ; 
//             res += sortedSequence.end() - insertPos ; 
//             sortedSequence.insert( insertPos , a ) ; 
//         }
//         return res ; 
//     }
// } ;

// class Solution {

// vector<int> temp ; 

// int mergeSort( vector<int> &arr , int l , int r , int cnt ) {
//     if ( l >= r ) 
//         return 0 ; 
//     int mid = ( l + r ) / 2 ; 
//     int newCnt = mergeSort( arr , l , mid , cnt ) + mergeSort( arr , mid + 1 , r , cnt ) ; 

//     int i = l , j = mid + 1 ;
//     int pos = l ;  
//     while ( i <= mid && j <= r ) {
//         if ( arr[i] <= arr[j] ) {
//             temp[pos ++] = arr[i ++] ;
//         }
//         else {
//             temp[pos ++] = arr[j ++] , newCnt += mid - i + 1 ;
//         }
//     }
//     while ( i <= mid ) 
//         temp[pos ++] = arr[i ++] ; 
//     while ( j <= r )
//         temp[pos ++] = arr[j ++] ; 
//     for ( int i = l ; i <= r ; i ++ ) 
//         arr[i] = temp[i] ;  
//     return newCnt ; 
// }


// public:
//     int reversePairs(vector<int>& record) {
//         temp.resize( record.size() ) ;
//         return mergeSort( record , 0 , record.size() - 1 , 0 ) ; 
//     }
// } ;

#include <iostream>
#include <vector>

#define endl '\n'
#define int long long

signed main() {

    int l , r ; cin >> l >> r ; 
    int dis = r - l ; 
    vector<int> record ;
    int base = 1 ; 
    while ( dis ) {
        if ( temp & 1 ) record.push_back( base ) ; 
        temp >>= 1 ;
        base <<= 1 ;
    }
    for ( auto &a : record ) {
        cout << l ' ' ;
        l += a ;
        cout << l << ' ' ;
        cout << endl ; 
    }  

    return 0 ; 
}
  
