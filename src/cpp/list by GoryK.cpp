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
list* head_ptr = head_node.next_node_ptr ; 
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

void list_delete ( int delete_value , list* delete_start_pos , list* delete_end_pos ) { // intput the value you want to delete 
	list* delete_pos = list_search ( delete_value , delete_start_pos , delete_end_pos ) ;
	list* prev_delete_pos = delete_start_pos ;
	while ( prev_delete_pos -> next_node_ptr != delete_pos ) {
		prev_delete_pos = prev_delete_pos -> next_node_ptr ;
	}
	//得到指向 含有 要删除的值的node的 指针
	//要先释放delete_pos所指向的node中的指针，在释放该结构体
	list* temp = delete_pos -> next_node_ptr ;
	delete_pos -> next_node_ptr = nullptr ;
	free ( delete_pos ) ;
	prev_delete_pos -> next_node_ptr = temp ;
}

void list_modify ( int original_value , int modify_value , list* modify_range_start , list* modify_range_end ) {
	list* modify_pos = list_search ( original_value , modify_range_start , modify_range_end ) ;
	modify_pos -> value = modify_value ;
}

bool list_empty_judge ( list head_node ) {
	if ( head_node.next_node_ptr == nullptr ) return true ;
	return false ;
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

//idea
/*
单向链表实现
1.头节点，value为空，指针指向第一节点，NULL为空链表，与empty函数连用
2.尾指针，即当前链表的最后一个NULL的指针
3.插入函数，malloc一个mylist大小的内存
4.删除函数，该节点上一个指针直接指向隔一个的下一个链表，然后是是放中间链表的内存
5.修改函数直接修改即可
6.搜索函数，从头节点开始匹配value值即可
*/
//代码
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// push_back test
	
	cout << "push_back test " << endl ;
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
	cout << "the original list is : " << endl ;
	list_print() ;
	
	// search test
	
	cout << "search test test " << endl ;
	
	list* search_result_1 = list_search ( 1 	 , head_ptr , tail_ptr ) ;
	list* search_result_2 = list_search ( 2 	 , head_ptr , tail_ptr ) ;
	list* search_result_3 = list_search ( 3 	 , head_ptr , tail_ptr ) ;
	list* search_result_4 = list_search ( 4 	 , head_ptr , tail_ptr ) ;
	list* search_result_5 = list_search ( 5      , head_ptr , tail_ptr ) ;
	list* search_result_6 = list_search ( 6      , head_ptr , tail_ptr ) ;
	list* search_result_7 = list_search ( 7      , head_ptr , tail_ptr ) ;
	list* search_result_8 = list_search ( 114514 , head_ptr , tail_ptr ) ;
//	list* search_result_9 = list_search ( 666    , head_ptr , tail_ptr ) ; 没写报错，不会写啊
	
	cout << search_result_1 -> value << endl ;
	cout << search_result_2 -> value << endl ;
	cout << search_result_3 -> value << endl ;
	cout << search_result_4 -> value << endl ;
	cout << search_result_5 -> value << endl ;
	cout << search_result_6 -> value << endl ;
	cout << search_result_7 -> value << endl ;
	cout << search_result_8 -> value << endl ;
	cout << endl ;
	
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
	
	// delete test
	
	cout << "delete test " << endl ;
	cout << "the original list is : " << endl ;
	list_print() ;
	
	list_delete ( 250 , head_ptr , tail_ptr ) ;
	list_delete ( 251 , head_ptr , tail_ptr ) ;
	list_delete ( 252 , head_ptr , tail_ptr ) ;
	list_delete ( 253 , head_ptr , tail_ptr ) ;
	list_delete ( 254 , head_ptr , tail_ptr ) ;
	list_delete ( 255 , head_ptr , tail_ptr ) ;
	
	cout << "after deleting , the list is : " << endl ;
	list_print () ;
	cout << endl ;
	
	// modify test 
	
	cout << "modify test " << endl ;
	cout << "the original list is : " << endl ;
	list_print() ;
	
	list_modify ( 1 , 2 , head_ptr , tail_ptr ) ;
	list_modify ( 3 , 4 , head_ptr , tail_ptr ) ;
	list_modify ( 5 , 6 , head_ptr , tail_ptr ) ;
	list_modify ( 7 , 8 , head_ptr , tail_ptr ) ;
	list_modify ( 9 , 0 , head_ptr , tail_ptr ) ;
	
	cout << "after modifying , the list is : " << endl ;
	list_print () ;
	cout << endl ;
	
	// empty test 
	cout << "Guess whether the list is empty ? " ;
	cout << endl ;
	cout << "The answer is :" ;
	cout << endl ;
	list_empty_judge ( head_node ) ? cout << "it's full !!! " : cout << "it's empty !!! " ;
	
	return 0;
}
//questions ：
/*

*/
