#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

#define endl '\n'
using namespace std;

string error1 = " Doesn't have this value in this list !!! ";
string error2 = " Doesn't have node_pos you input in this list !!! ";

typedef struct mylist {
	int value;
	mylist* next_node_ptr;
	mylist(int val = 0) : value(val), next_node_ptr(nullptr) {}
} list;

list* head_ptr = nullptr;
list* tail_ptr = nullptr;

string* error1_ptr = &error1;
string* error2_ptr = &error2;

void list_push_back(int input_value) {
	list* new_node = new list(input_value);
	if (tail_ptr == nullptr) {
		head_ptr = tail_ptr = new_node;
	} else {
		tail_ptr->next_node_ptr = new_node;
		tail_ptr = new_node;
	}
}

list* list_search(int search_value, list* begin_search) {
	list* search_ptr = begin_search;
	while (search_ptr!= nullptr) {
		if (search_ptr->value == search_value) {
			return search_ptr;
		}
		search_ptr = search_ptr->next_node_ptr;
	}
	return nullptr;
}

void list_insert(int insert_pos_value, int insert_value) {
	list* insert_pos = list_search(insert_pos_value, head_ptr);
	if (insert_pos == nullptr) {
		cerr << *error1_ptr << endl;
		return;
	}
	list* new_node = new list(insert_value);
	new_node->next_node_ptr = insert_pos->next_node_ptr;
	insert_pos->next_node_ptr = new_node;
}

void list_delete(int delete_value) {
	list* prev = nullptr;
	list* current = head_ptr;
	while (current!= nullptr && current->value!= delete_value) {
		prev = current;
		current = current->next_node_ptr;
	}
	if (current == nullptr) {
		cerr << *error1_ptr << endl;
		return;
	}
	if (prev == nullptr) {
		head_ptr = current->next_node_ptr;
	} else {
		prev->next_node_ptr = current->next_node_ptr;
	}
	if (current == tail_ptr) {
		tail_ptr = prev;
	}
	delete current;
}

void list_modify(int original_value, int modify_value) {
	list* modify_pos = list_search(original_value, head_ptr);
	if (modify_pos == nullptr) {
		cerr << *error1_ptr << endl;
		return;
	}
	modify_pos->value = modify_value;
}

bool list_empty_judge() {
	return head_ptr == nullptr;
}

void list_print() {
	list* print_ptr = head_ptr;
	int list_serial_number = 1;
	while (print_ptr!= nullptr) {
		cout << list_serial_number << " " << print_ptr->value << endl;
		print_ptr = print_ptr->next_node_ptr;
		list_serial_number++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// push_back test
	cout << " push_back test " << endl;
	list_push_back(1);
	list_push_back(2);
	list_push_back(3);
	list_push_back(4);
	list_push_back(5);
	list_push_back(7);
	list_push_back(8);
	list_push_back(9);
	list_push_back(10);
	list_push_back(114514);
	cout << " the original list is : " << endl;
	list_print();
	
	// search test
	cout << " search test test " << endl;
	
	list* search_result_1 = list_search(1, head_ptr);
	list* search_result_2 = list_search(2, head_ptr);
	list* search_result_3 = list_search(3, head_ptr);
	list* search_result_4 = list_search(4, head_ptr);
	list* search_result_5 = list_search(5, head_ptr);
	list* search_result_6 = list_search(6, head_ptr);
	list* search_result_7 = list_search(7, head_ptr);
	list* search_result_8 = list_search(114514, head_ptr);
	
	if (search_result_1) cout << search_result_1->value << endl;
	if (search_result_2) cout << search_result_2->value << endl;
	if (search_result_3) cout << search_result_3->value << endl;
	if (search_result_4) cout << search_result_4->value << endl;
	if (search_result_5) cout << search_result_5->value << endl;
	if (search_result_6) cerr << *error1_ptr << endl;
	if (search_result_7) cout << search_result_7->value << endl;
	if (search_result_8) cout << search_result_8->value << endl;
	cout << endl;
	
	// insert test
	cout << " insert test " << endl;
	cout << " the original list is : " << endl;
	list_print();
	
	list_insert(3, 250);
	list_insert(4, 251);
	list_insert(5, 252);
	list_insert(6, 253);
	list_insert(7, 254);
	list_insert(8, 255);
	
	cout << " after inserting, the list is : " << endl;
	list_print();
	cout << endl;
	
	// delete test
	cout << " delete test " << endl;
	cout << " the original list is : " << endl;
	list_print();
	
	list_delete(250);
	list_delete(251);
	list_delete(252);
	list_delete(253);
	list_delete(254);
	list_delete(255);
	
	cout << " after deleting, the list is : " << endl;
	list_print();
	cout << endl;
	
	// modify test
	cout << " modify test " << endl;
	cout << " the original list is : " << endl;
	list_print();
	
	list_modify(1, 2);
	list_modify(3, 4);
	list_modify(5, 6);
	list_modify(7, 8);
	list_modify(9, 0);
	
	cout << " after modifying, the list is : " << endl;
	list_print();
	cout << endl;
	
	// empty test
	cout << " Guess whether the list is empty? " << endl;
	cout << " The answer is :" << endl;
	list_empty_judge()? cout << " it's empty !!! " : cout << " it's full !!! ";
	
	return 0;
}
