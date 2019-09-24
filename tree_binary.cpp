#include <iostream>
using namespace std;

struct node {
	char data;
	node *left;
	node *right;
};
typedef node* treePtr;

void inorder(treePtr ptr)
{
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data;
		inorder(ptr->right);
	}
}

void iter_inorder(treePtr ptr)
{
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data;
		inorder(ptr->right);
	}
}

void preorder(treePtr ptr)
{
	if (ptr) {
		cout << ptr->data;
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(treePtr ptr)
{
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data;
	}
}

treePtr copy(treePtr original)
{
	treePtr temp;
	if (original) {
		temp = new node;
		temp->left = copy(original->left);
		temp->right = copy(original->right);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}

int equal(treePtr first, treePtr second)
{
	return((!first && !second) || (first && second && (first->data == second->data)
		&& equal(first->left, second->left) &&
		equal(first->right, second->right)));
}

void make_tree(char c, treePtr l, treePtr r, treePtr& tr)
{
	treePtr temp;
	temp = new node;

	temp->data = c;
	temp->left = l;
	temp->right = r;

	tr = temp;
}

int main()
{
	treePtr l, r, tr, tr2;

	// 1. 슬라이드  pg 21 에 있는 트리 tr 을 생성하라 
	make_tree('A', NULL, NULL, l);
	make_tree('B', NULL, NULL, r);
	make_tree('/', l, r, l);
	make_tree('C', NULL, NULL, r);
	make_tree('*', l, r, l);
	make_tree('D', NULL, NULL, r);
	make_tree('*', l, r, l);
	make_tree('E', NULL, NULL, r);
	make_tree('+', l, r, tr);

	// inorder traversal, preorder traversal, postorder traversal of tr 
	inorder(tr); cout << endl;
	preorder(tr); cout << endl;
	postorder(tr); cout << endl;

	// 2. tr2 를 tr 와 동일하게 생성하라
	tr2 = copy(tr);

	// inorder traversal, preorder traversal, postorder traversal of tr2
	inorder(tr2); cout << endl;
	preorder(tr2); cout << endl;
	postorder(tr2); cout << endl;

	if (equal(tr, tr2)) cout << "Two tres are equal \n";

	system("pause");
	delete l, r, tr;
	return 0;
}