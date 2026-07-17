//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组
typedef struct BinaryTree {
	int value ; 
	struct BinaryTree* L ;
	struct BinaryTree* R ;
	BinaryTree ( int intput_value ) : value (intput_value) , L  (nullptr) , R (nullptr) {} 
} node ;
node* root = nullptr ;
//函数声明
node* searchNode( int search_value ) { 
	node* temp_ptr = root ; //搜索过程中用的指针
	while ( temp_ptr != nullptr ) {
		if ( search_value > temp_ptr -> value ) {
			temp_ptr = temp_ptr -> R ;
		} else if ( search_value < temp_ptr -> value ) {
			temp_ptr = temp_ptr -> L ;
		} else {
			return temp_ptr ;
		}
	}
	return nullptr ;
}

void createNode ( int input_value ) {
	node* temp_ptr = root ; // 注意此处创建新指针意图是为了区分初始化空树和插入这两种不同情况哦
	if ( root == nullptr ) {
		root = new node( input_value ) ;
		return ;
	}
	while ( 1 ) {
		if ( input_value > temp_ptr -> value ) { //在temp_ptr指向的节点的r处，创建一个新的节点
			if ( temp_ptr -> R == nullptr ) {
				temp_ptr -> R = new node ( input_value ) ;
				return ;
			}
			temp_ptr = temp_ptr -> R ;
		} else if ( input_value < temp_ptr -> value ) {
			if ( temp_ptr -> L == nullptr ) {
				temp_ptr -> L = new node ( input_value ) ;
				return ;
			}
			temp_ptr = temp_ptr -> L ;
		} else {
			return ;
		}
	}
}
/*
删除函数分为几种情况
1.删除的是叶子节点
直接删即可
2.删除的是中间节点
中间节点有一个节点
有两个节点
把右子树接到左子树上，用左子树代替被删除的节点
或者把左子树街道右子树上，用右子树代替被删除的节点
*/
void deleteNode ( int delete_value ) {
	node* search_result = searchNode ( delete_value ) ;
	if ( search_result -> R == nullptr && search_result -> L == nullptr ) {
		
	}else if ( search_result -> R == nullptr && search_result -> L != nullptr ) {
		
	}
}
//idea
/*
1.初始化一个空的根节

*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	createNode( 10  ) ;
	createNode( 100 ) ;
	createNode( 20  ) ;
	createNode( 14  ) ;
	createNode( 1   ) ;
	createNode( 8   ) ;
	createNode( 2   ) ;
	createNode( 4   ) ;
	
	cout << searchNode( 10  ) -> value << endl ;
	cout << searchNode( 100 ) -> value << endl ;
	cout << searchNode( 20  ) -> value << endl ;
	cout << searchNode( 14  ) -> value << endl ;
	cout << searchNode( 1   ) -> value << endl ;
	cout << searchNode( 8   ) -> value << endl ;
	cout << searchNode( 2   ) -> value << endl ;
	cout << searchNode( 4   ) -> value << endl ;
	return 0;
}
//questions ：
/*

*/
