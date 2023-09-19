#include <iostream>
#include "myArray.h"
#include "List.h"

using namespace std;

void testMatrixModule() {
	// 050923
	int m, n;
	cin >> m >> n;
	M myArr = init(m, n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			myArr[i][j] = rand() % 10 + 1;

	cout << "PRINT\n";
	print(myArr, m, n);

	cout << "\nTRANPOSED\n";
	M myArrT = transpose(myArr, m, n);
	print(myArrT, n, m);

	cout << "\nANOTHER\n";
	M myArr_2 = init(m, n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			myArr_2[i][j] = rand() % 10 + 1;
	print(myArr_2, m, n);

	cout << "\nSUM\n";
	M res = sum(myArr, myArr_2, m, n);
	print(res, m, n);

	int alpha = rand() % 10 + 1;
	cout << "\nSCALAR " << alpha << " RES: \n";
	scalarate(myArr, alpha, m, n);
	print(myArr, m, n);
}

void testListModule() {
	//120923
	TList head = initHead(1);
	addToHead(head, 2);
	addToHead(head, 3);
	printList(head);
	addAfter(head->next, 5);
	printList(head);
	eraseHead(head);
	printList(head);
	TList tmp = searchEl(head, 5);
	cout << tmp->value << '\n';
	reversePrintList(head);
}

void taskListModule() {
	int N = 10, E;
	TList head = initHead(rand() % 11);
	for (int i = 0; i < N; ++i)
		addToHead(head, rand() % 11);
	printList(head);
	cout << "Enter 'E' Element:\n";
	cin >> E;
	for (TList cur = head; cur != nullptr;) {
		if (cur->value == E) {
			addAfter(cur, cur->value);
			cur = cur->next->next;
			continue;
		}
		cur = cur->next;
	}
	printList(head);
	cout << '\n';
}

