#include <iostream>
#include <string>

#define TList Node*

using namespace std;

struct Node {
	TList next;
	int value;
};

TList initHead(int value) {
	TList result = new Node;
	result->value = value;
	result->next = nullptr;
	return result;
}

void addToHead(TList& head, int value) {
	TList new_head = new Node;
	new_head->value = value;
	new_head->next = head;
	head = new_head;
}

void addAfter(TList &el, int value) {
	TList new_el = new Node;
	new_el->value = value;
	new_el->next = el->next;
	el->next = new_el;
}

void printList(TList head) {
	do {
		cout << head->value << ' ';
		head = head->next;
	} while (head != nullptr);
	cout << '\n';
}

void eraseHead(TList &head) {
	TList prev = head;
	head = head->next;
	delete[] prev;
}
// переделать searchEl чтобы выдавал элемент на текущий элемент
TList searchEl(TList head, int value) {
	TList ans = nullptr;
	do {
		if (head->value == value)
			ans = head;
		head = head->next;
	} while (head->next != nullptr);
	return ans;
}

void reversePrintList(TList head) {
	string output = "";

	do {
		//cout << to_string(head->value) << '\n';
		output += to_string(head->value) + string(" ");
		head = head->next;
	} while (head->next != nullptr);
	output += to_string(head->value);
	for (int i = int(output.length()) - 1; i >= 0; --i)
		cout << output[i];
	cout << '\n';
}


