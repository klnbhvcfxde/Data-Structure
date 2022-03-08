#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT);
void InorderTraversal(BinTree BT);

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
BinTree Find(BinTree BST, ElementType X);
BinTree FindMin(BinTree BST);
BinTree FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	cin >> N;
	for (i = 0; i < N; i++) 
	{
		cin >> X;
		BST = Insert(BST, X);
	}
	cout << "Preorder:";
	PreorderTraversal(BST); 
	cout << endl;
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	cin >> N;
	for (i = 0; i < N; i++) 
	{
		cin >> X;
		Tmp = Find(BST, X);
		if (Tmp == NULL)
			cout << X << " is not found" << endl;
		else {
			cout << Tmp->Data << " is found" << endl;
			if (Tmp == MinP)
				cout << Tmp->Data << " is the smallest key" << endl;
			if (Tmp == MaxP) 
				cout << Tmp->Data << " is the largest key" << endl;
		}
	}
	cin >> N;
	for (i = 0; i < N; i++) 
	{
		cin >> X;
		BST = Delete(BST, X);
	}
	cout << "Inorder:"; 
	InorderTraversal(BST); 
	cout << endl;

	return 0;
}

// ���ҵݹ�ʵ�� 
BinTree Find(BinTree BST, ElementType X)
{
	if (!BST)  // ��������Ϊ�գ����� NULL 
		return NULL;
	if (X < BST->Data) // �ȸ����С��ȥ���������� 
		return Find(BST->Left, X);
	else if (BST->Data < X)  // �ȸ�����ȥ���������� 
		return Find(BST->Right, X);
	else if (BST->Data == X) // �ҵ��� 
		return BST;
}

// ������Сֵ�ĵݹ�ʵ��
BinTree FindMin(BinTree BST)
{
	if (!BST)    // ���Ϊ���ˣ����� NULL 
		return NULL;
	else if (BST->Left)   // �������������������֧�������� 
		return FindMin(BST->Left);
	else  // �ҵ��� 
		return BST;
}

// �������ֵ�ķǵݹ�ʵ��
BinTree FindMax(BinTree BST)
{
	if (BST)  // ������� 
		while (BST->Right)   // ֻҪ������������ 
			BST = BST->Right;
	return BST;
}

// ����
BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST)  // ���Ϊ�գ���ʼ���ý��
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	}
	else  // ��Ϊ��
	{
		if (X < BST->Data)  // ���С��������� 
			BST->Left = Insert(BST->Left, X);
		else if (BST->Data < X)  // ����󣬹����ұ� 
			BST->Right = Insert(BST->Right, X);
		// �����ȣ�ʲô�������� 
	}
	return BST;
}

// ɾ��
BinTree Delete(BinTree BST, ElementType X)
{
	BinTree tmp;
	if (!BST)
		cout << "Not Found" << endl;
	else if (X < BST->Data)   // X �ȵ�ǰ���ֵС������������������ɾ�� 
		BST->Left = Delete(BST->Left, X);
	else if (BST->Data < X)   // X �ȵ�ǰ���ֵ������������������ɾ�� 
		BST->Right = Delete(BST->Right, X);
	else  //  �ҵ���ɾ�����
	{
		if (BST->Left && BST->Right)  // ��ɾ������������ӽ��
		{
			tmp = FindMin(BST->Right);   // �ҵ���������ֵ��С��
			BST->Data = tmp->Data;     // ���ҵ���ֵ���ǵ�ǰ��� 
			BST->Right = Delete(BST->Right, tmp->Data);   // ��ǰ���ҵ�����������Сֵ���ɾ�� 
		}
		else  // ��ɾ�����ֻ��һ�����ӽ���û�к��ӽ��
		{
			tmp = BST;
			if (!BST->Left && !BST->Right)  // û�к��ӽ�� 
				BST = NULL;
			else if (BST->Left && !BST->Right)  // ֻ�����ӽ�� 
				BST = BST->Left;
			else if (!BST->Left && BST->Right)  // ֻ���Һ��ӽ�� 
				BST = BST->Right;
			free(tmp);
		}
	}
	return BST;
}

// ������� 
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		cout << BT->Data << " ";  // ��ӡ�� 
		PreorderTraversal(BT->Left);  // ���������� 
		PreorderTraversal(BT->Right);  // ���������� 
	}
}

// ������� 
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);  // ���������� 
		cout << BT->Data << " ";  // ��ӡ�� 
		InorderTraversal(BT->Right);  // ���������� 
	}
}