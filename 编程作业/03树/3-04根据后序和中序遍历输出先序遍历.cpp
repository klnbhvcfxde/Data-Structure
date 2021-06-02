#include <iostream>
using namespace std;
#define MaxTree 30
typedef struct Node {
	int data;
	struct Node *left, *right;
}Node, *Tree;

//��֪����ͺ������������һ�ö�����
Tree BuildTree(int n, int *InOrder, int *PostOrder)
{
	if (n == 0)
		return NULL;
	Tree tree = (Tree)malloc(sizeof(Node));
	tree->data = PostOrder[n-1];
	tree->left = tree->right = NULL;
	int i;
	for (i = 0; i < n; i++) 
	{
		if (PostOrder[n-1] == InOrder[i])
			break;
	}
	int L = i;  //������������
 	int R = n - (i + 1);  //�����������
	tree->left = BuildTree(L, InOrder, PostOrder);
    tree->right = BuildTree(R, InOrder + L + 1, PostOrder + L);
	return tree;
}

//�����������
void PreOrder(Tree tree) 
{
	if (!tree)
		return;
	cout << " " << tree->data;
	PreOrder(tree->left);
	PreOrder(tree->right);
}

int main() 
{
	int n;
	cin >> n;
	int InOrder[MaxTree], PostOrder[MaxTree];
	int s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		PostOrder[i] = s;
	}
	 for (int i = 0; i < n; i++)
	 {
	    cin >> s;
	    InOrder[i] = s;
	 }
	 Tree tree = BuildTree(n, InOrder, PostOrder);
	 cout << "Preorder:";
	 PreOrder(tree);
	 system("pause");
	 return 0;
}