#include <iostream>
using namespace std;

typedef struct listNode* listPtr;

struct listNode {
	int data;
	listPtr link;
};

//data =  val �� ���ο� ��带 ü��   first  �� ���   x �ڿ� ����

void insert(listPtr& first, listPtr x, int val)
{
	listNode* temp;
	temp = new listNode;
	temp->data = val;

	if (first) {
		temp->link = x->link;
		x->link = temp;
	}
	else { temp->link = NULL; first = temp; }
}

/* first �� ����Ʈ���� ��� trail �ڿ� �ִ� ��� x �� ���� */
void del(listPtr& first, listPtr trail, listPtr x)
{
	if (trail)
		trail->link = x->link;
	else
		first = (first)->link;
	delete x;
}

void print(listPtr mylist) {
	if (!mylist) cout << "NULL";
	for (; mylist; mylist = mylist->link)
		cout << mylist->data << ", ";

	cout << endl;
}

/* Invert a Chain */
listPtr invert(listPtr lead) {
	listPtr middle, trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;

}


//// concatenate two chains
listPtr concat(listPtr ptr1, listPtr ptr2) {
	listPtr temp;
	temp = ptr1;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = ptr2;
	return ptr1;
}

//// find the length of a list
int length(listPtr ptr) {
	int count = 0;
	while (ptr) {
		count++;
		ptr = ptr->link;
	}
	return count;
}




void main()
{
	listPtr mylist, x, mlist, nlist;
	mylist = NULL; x = NULL;

	insert(mylist, x, 30);
	print(mylist);

	if (mylist->link) x = mylist->link; else x = mylist;

	insert(mylist, x, 20);
	print(mylist);

	insert(mylist, x, 40);
	print(mylist);

	if (mylist->link) x = mylist->link; else x = mylist;


	del(mylist, mylist, x);
	print(mylist);


	mlist = invert(mylist);
	print(mlist);

	nlist = concat(mylist, mlist);
	print(nlist);

	cout << length(mlist) << endl;

	system("pause");
}