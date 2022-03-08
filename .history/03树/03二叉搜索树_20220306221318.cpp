#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct TreeNode *BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

// ���ҵݹ�ʵ�� 
BinTree Find(ElementType X, BinTree BST) 
{
	if (!BST)  // ��������Ϊ�գ����� NULL 
		return NULL;
	if (X < BST->Data) // �ȸ����С��ȥ���������� 
		return Find(X, BST->Left);
	else if (BST->Data < X)  // �ȸ�����ȥ���������� 
		return Find(X, BST->Right);
	else if (BST->Data == X) // �ҵ��� 
		return BST;
}

// ���ҷǵݹ�ʵ��
BinTree IterFind(ElementType X, BinTree BST) 
{
	while (BST) 
	{
		if (X < BST->Data)
			BST = BST->Left;
		else if (BST->Data < X)  // �ȸ�����ȥ���������� 
			BST = BST->Right;
		else if (BST->Data == X) // �ҵ��� 
			return BST;
	}
	return NULL;
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
BinTree Insert(ElementType X, BinTree BST) 
{
	if (!BST)  // ���Ϊ�գ���ʼ���ý��
	{ 
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	}
	else  // ��Ϊ��
	{ 
		if (X < BST->Data)  // ���С��������� 
			BST->Left = Insert(X, BST->Left);
		else if (BST->Data < X)  // ����󣬹����ұ� 
			BST->Right = Insert(X, BST->Right);
		// �����ȣ�ʲô�������� 
	}
	return BST;
}

// ɾ��
BinTree Delete(ElementType X, BinTree BST) 
{
	BinTree tmp;
	if (!BST)
		cout << "Ҫɾ����Ԫ��δ�ҵ�";
	else if (X < BST->Data)   // X �ȵ�ǰ���ֵС������������������ɾ�� 
		BST->Left = Delete(X, BST->Left);
	else if (BST->Data < X)   // X �ȵ�ǰ���ֵ������������������ɾ�� 
		BST->Right = Delete(X, BST->Right);
	else  //  �ҵ���ɾ�����
	{ 
		if (BST->Left && BST->Right)  // ��ɾ������������ӽ��
		{ 
			tmp = FindMin(BST->Right);   // �ҵ���������ֵ��С��
			BST->Data = tmp->Data;     // ���ҵ���ֵ���ǵ�ǰ��� 
			BST->Right = Delete(tmp->Data, BST->Right);   // ��ǰ���ҵ�����������Сֵ���ɾ�� 
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
void  InOrderTraversal(BinTree BT) 
{
	if (BT) 
	{
		InOrderTraversal(BT->Left);  // ���������� 
		cout << BT->Data;  // ��ӡ�� 
		InOrderTraversal(BT->Right);  // ���������� 
	}
}

int main() {
	BinTree BST = NULL;

	BST = Insert(5, BST);
	BST = Insert(7, BST);
	BST = Insert(3, BST);
	BST = Insert(1, BST);
	BST = Insert(2, BST);
	BST = Insert(4, BST);
	BST = Insert(6, BST);
	BST = Insert(8, BST);
	BST = Insert(9, BST);
	/*
				5
			   /\
			  3  7
			 /\	 /\
			1 4 6  8
			\      \
			 2      9
	*/

	cout << "��������Ľ���ǣ�";
	InOrderTraversal(BST);
	cout << endl;

	cout << "������Сֵ�ǣ�" << FindMin(BST)->Data << endl;
	cout << "�������ֵ�ǣ�" << FindMax(BST)->Data << endl;
	cout << "����ֵΪ3�Ľ�����������ֵΪ��" << Find(3, BST)->Left->Data << endl;
	cout << "����ֵΪ7�Ľ�����������ֵΪ��" << IterFind(7, BST)->Right->Data << endl;

	cout << "ɾ��ֵΪ5�Ľ��" << endl;
	Delete(5, BST);
	/*
				6
			   /\
			  3  7
			 /\	  \
			1 4    8
			\      \
			 2      9
	*/

	cout << "��������Ľ���ǣ�";
	InOrderTraversal(BST);
	cout << endl;


	return 0;
}