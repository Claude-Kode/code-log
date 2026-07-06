//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

//函数声明

//idea
/*
搞一个queue和set
set用来存储内存中的单词序号
queue决定下一个删除哪一个单词来查找新的单词
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M , N ;
	cin >> M >> N ;
	queue <int> myqueue ;
	set <int> myset ;
	int word ; 
	int count_search = 0 ;
	while ( N -- ) {
		int len = myqueue.size() ;
		cin >> word ;
		if ( myset.find ( word) == myset.end() ) {
			count_search ++ ;
		} else {
			continue ;
		}
		if ( len < M ) {
			myqueue.push ( word ) ;
			myset.insert ( word ) ;
		} else {
			int a = myqueue.front() ;
			myqueue.pop() ;
			myset.erase( a ) ;
			myqueue.push ( word ) ;
			myset.insert ( word ) ;
		}
	}
	cout << count_search << endl ;
	return 0;
}
//questions ：
/*
queue and set 没有初始化大小
find函数没有找到会返回end（）
set的插入，用inset或者emplace或者列表初始化
queue没有去重功能
set函数库内置了find函数 myset.find ( search_ele )即可
queue的pop默认是头删
*/
