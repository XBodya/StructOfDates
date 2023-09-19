#define TList Node*

struct Node {
	TList next;
	int value;
};

void printList(TList);

void reversePrintList(TList);

TList initHead(int);

void addAfter(TList&, int);

void addToHead(TList&, int);

void eraseHead(TList&);

TList searchEl(TList, int);





