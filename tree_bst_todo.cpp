#include <iostream>
#include <string>
using namespace std;

struct bst {
	bst* leftChild;
	int key;
	bst* rightChild;
};

typedef bst* bstPtr;


void inorder(bstPtr t)
{
	if (t) {
		inorder(t->leftChild);
		cout << " " << t->key << " ";
		inorder(t->rightChild);
	}
}


// HW 1
bstPtr itersearch(bstPtr tree, int k)
{
	while (tree) {
		if (k == tree->key) return tree;
		if (k < tree->key) tree = tree->leftChild;
		if (k > tree->key) tree = tree->rightChild;
	}
	return tree;

}

// key ������ �˻�
bstPtr search(bstPtr tree, int k)
{
	if (!tree) return NULL;
	if (k == tree->key) return tree;
	if (k < tree->key) return search(tree->leftChild, k);
	return search(tree->rightChild, k);
}

// HW 2
// insert �� ���ؼ� search �� ����
bstPtr modifiedSearch(bstPtr tree, int k)
{
	bstPtr temp = new bst;
	temp = NULL;
	while (tree) {
		if (k == tree->key) return NULL;
		temp = tree;
		if (k < tree->key) tree = tree->leftChild;
		else tree = tree->rightChild;
	}
	return temp;
}

void insert(bstPtr& node, int k)
{
	bstPtr ptr, temp = modifiedSearch(node, k);

	ptr = new bst;
	ptr->key = k;
	ptr->leftChild = ptr->rightChild = NULL;

	if (!node) node = ptr;

	if (temp) {
		if (k < temp->key) temp->leftChild = ptr;
		else temp->rightChild = ptr;
	}
}

// HW 3
/************************************  DELETE  *******************************************/
/*

modifiedSearchDelete
findBig
deleteBST

*/

bstPtr modifiedSearchDelete(bstPtr tree, int k, bstPtr& parent, int& op)
{
	bstPtr temp = new bst; temp = NULL;

	// tree �� ������ ��� NULL �� ����
	while (tree) {
		if (k == tree->key) {
			temp = tree;
			break;
		}
		parent = tree;
		if (k < tree->key) tree = tree->leftChild;
		else tree = tree->rightChild;

	}
	if (!tree) return NULL;

	if (parent->leftChild == temp) op = 1;
	else op = 2;

	return temp;
}

bstPtr findBig(bstPtr tree, bstPtr& parent, int& op)
{
	op = 1;
	while (tree->rightChild) {
		op = 2;
		parent = tree;
		tree = tree->rightChild;
	}
	return tree;
}

void deleteBST(bstPtr& node, int k)
{
	bstPtr parent, a, biggest;
	int op;

	parent = new bst;

	a = modifiedSearchDelete(node, k, parent, op);
	//  a �� leaf �� ���, parent �� child �� null
	//  a  child �� 1 ���, node �޸� ��ȯ, child �� parent �� child ��
	//  a  child �� 2 ���, left subtree �� ���� ū���� �����ͼ� node->key ��
	//                      left subtree �� ���� ū���� ��� ���� �ݺ� 

	if (!a->leftChild && !a->rightChild) {
		if (op == 1) parent->leftChild = NULL;
		else parent->rightChild = NULL;
		delete a; return;
	}

	if (!a->leftChild) {
		if (op == 1) parent->leftChild = a->rightChild;
		else parent->rightChild = a->rightChild;
		delete a; return;
	}

	if (!a->rightChild) {
		if (op == 1) parent->leftChild = a->leftChild;
		else parent->rightChild = a->leftChild;
		delete a; return;
	}

	parent = a;
	biggest = findBig(a->leftChild, parent, op);
	a->key = biggest->key;

	if (!biggest->leftChild) {
		parent->rightChild = NULL;
		delete biggest;
	}
	else {
		if (op == 1) parent->leftChild = biggest->leftChild;
		if (op == 2) parent->rightChild = biggest->leftChild;
		delete biggest;
	}
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
void main()
{
	bstPtr tree = new bst;
	tree = NULL;

	insert(tree, 30);
	insert(tree, 40);
	insert(tree, 5);
	insert(tree, 2);
	insert(tree, 80);

	cout << endl << "Tree1: ";
	inorder(tree);

	insert(tree, 35);
	cout << endl << "Tree2: ";
	inorder(tree);

	deleteBST(tree, 30);
	cout << endl << "Tree4: ";
	inorder(tree);

	system("pause");
}
