//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
//宏定义
#define endl '\n'
#define mod 99824353ll
//命名空间声明
using namespace std;
//全局变量&数组
typedef struct node {
	int value ;
	struct node* lchild ;
	struct node* rchild ;
} node ;
//函数声明

//插入函数
//其实就是在一个树上，不断通过判读位移最终填充的点，最后的点是一个通过了所有判断且为null的位置，创建一个结构体，把值存进去，左叉右叉都打好
//所以只要节点不是null
//如果赋的值大于该当前的节点，下一次调用就调用该节点的右叉
//小于则调用左叉
//最后是null了，就开辟一块空间，然后干该干的
node* insert ( node* t , int val ) {
	if ( t == NULL ) {
		node* newnode = ( node* ) malloc( sizeof (node) ) ;
		newnode -> value = val ;
		newnode -> lchild = NULL ;
		newnode -> rchild = NULL ;
		return newnode ;
	}
	if ( val > t -> value) {
		t -> rchild = insert ( t -> rchild , val ) ;
	} else if ( val < t -> value) {
		t -> lchild = insert ( t -> lchild , val ) ;
	}
	return t ;
}

//查找函数更简单一些
//如果查到的位置是null，说明没有符合条件的数据存在，或者可能直接是空树
//如果查到的位置等于，就return 1
//如果大于或者小于了，就调用该node的l或者r分支进行下一次search函数的调用即可
int search ( node* t , int key ) {
	if ( t == NULL ) return 0 ;
	if ( t -> value == key ) return 1 ;
	if ( key > t -> value ) return search ( t -> rchild , key ) ;
	else if ( key < t -> value ) return search ( t -> lchild , key ) ;
}


// 如果大于节点的value就从该节点的 子r寻找
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	node* root = NULL ;
	root = insert ( root , 100  ) ;
	root = insert ( root , 10   ) ;
	root = insert ( root , 1000 ) ;
	root = insert ( root , 129  ) ;
	root = insert ( root , 8    ) ;
	search ( root , 100     ) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 1082530 ) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 10      ) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 8       ) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 114514  ) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 298		) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 23045 	) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 498 	) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 287253 	) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 12345 	) ? cout << "YES" << endl : cout << "NO" << endl ;
	search ( root , 1919810	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;
//	search ( root , 100 	) ? cout << "YES" << endl : cout << "NO" << endl ;	
//	cout << search ( root , 100 ) << ' ' ;
//	cout << search ( root , 10 ) << ' ' ;
//	cout << search ( root , 1000 ) << ' ' ;
//	cout << search ( root , 129 ) << ' ' ;
//	cout << search ( root , 8 ) << ' ' ;
	return 0;
}
