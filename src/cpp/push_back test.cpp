//头文件
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
//宏定义
#define endl '\n'
//命名空间声明
using namespace std;
//全局变量&数组

string error1 = " Doesn't have this value in this list !!! " ;
string error2 = " Doesn't have node_pos you intput in this list !!! " ;

typedef struct mylist {
	int value  = 0 ;
	mylist* next_node_ptr = nullptr ;
	
}list;

list head_node = { 0 , nullptr };
list* head_ptr = nullptr ; 
list* tail_ptr = nullptr ;

string* error1_ptr = &error1 ;
string* error2_ptr = &error2 ;

//函数声明

void list_push_back ( int input_value ) { //返回指向下一个节点的指针
	list* new_node = tail_ptr ;
	if ( new_node == nullptr )  {
		new_node = ( list* ) malloc ( sizeof ( list ) ) ;
		head_ptr = new_node ;
	}
	new_node -> value = input_value ;
	new_node -> next_node_ptr = ( list* ) malloc ( sizeof ( list ) ) ;
	tail_ptr = new_node -> next_node_ptr ;
	tail_ptr -> next_node_ptr = nullptr ;
}

list* list_search ( int search_value , list* begin_search , list* end_search ) { // begin_search指针直接写头指针即可 ,搜索范围是从begin指向的node开始，到end_search为止
	list* search_ptr = begin_search ;
	list* search_result_ptr = nullptr ;
	while ( search_ptr != end_search ) {
		if ( search_ptr -> value == search_value ) {
			search_result_ptr = search_ptr ;
			return search_result_ptr ;//返回 指向 拥有与要搜索的value相等 的node 的指针
		} else {
			search_ptr = ( search_ptr -> next_node_ptr ) ;
		}
	}
	return  nullptr ;
}

void list_insert ( int insert_pos_value , int insert_value ) { //单向插入，只能在指定位置的后面插入 ，这里的pos指的是要插入的值的位置
	list* insert_pos = list_search ( insert_pos_value , head_ptr , tail_ptr ) ;
	list* temp = insert_pos -> next_node_ptr ; 
	insert_pos -> next_node_ptr = ( list* ) malloc ( sizeof ( list ) ) ;
	insert_pos -> next_node_ptr -> value = insert_value ;
	insert_pos -> next_node_ptr -> next_node_ptr = temp ;
}

void list_print () {
	mylist* print_ptr = head_ptr ;
	int list_serial_number = 1 ;
	while ( print_ptr != tail_ptr ){
		cout << list_serial_number << ' ' << print_ptr -> value << endl ;
		list_serial_number ++ ;
		print_ptr = print_ptr -> next_node_ptr ;
	}
}
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// push_back test
	
	cout << " push_back test " << endl ;
	list_push_back ( 1 ) ;
	list_push_back ( 2 ) ;
	list_push_back ( 3 ) ;
	list_push_back ( 4 ) ;
	list_push_back ( 5 ) ;
	list_push_back ( 6 ) ;
	list_push_back ( 7 ) ;
	list_push_back ( 8 ) ;
	list_push_back ( 9 ) ;
	list_push_back ( 10 ) ;
	list_push_back ( 114514 ) ;
	cout << " the original list is : " << endl ;
	list_print() ;
	cout << tail_ptr -> value ;
	
	// insert test 
	
	cout << "insert test " << endl ;
	cout << "the original list is : " << endl ;
	list_print() ;
	
	list_insert ( 3 , 250 ) ;
	list_insert ( 4 , 251 ) ;
	list_insert ( 5 , 252 ) ;
	list_insert ( 6 , 253 ) ;
	list_insert ( 7 , 254 ) ;
	list_insert ( 8 , 255 ) ;
	
	cout << "after inserting , the list is : " << endl ;
	list_print () ;
	cout << endl ;
	
	return 0 ;
}
