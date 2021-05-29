#include<iostream>
using namespace std;
#include<vector> 
#include<queue>
#include<algorithm>

typedef struct TreeNode *BinTree;
struct TreeNode {
	int Data;  // ��ֵ 
	BinTree Left;    // ����ӽ�� 
	BinTree Right;   // �Ҷ��ӽ�� 
};
BinTree CreatBinTree();   // ����һ��������
void  PreOrderTraversal_Recursion(BinTree BT);  // ����ݹ����
void PreOrderTraversal(BinTree BT);   // ���������������
void InOrderTraversal_Recursion(BinTree BT);  // ����ݹ����
void InOrderTraversal(BinTree BT);    // ��������������
void PostOrderTraversal_Recursion(BinTree BT);  // ����ݹ����
void PostOrderTraversal(BinTree BT);  // ������������Ҹ� 

typedef struct SNode *Stack;
struct SNode {
	BinTree Data;
	Stack Next;
};


Stack CreateStack();  // ��ʼ����ջ 
int IsEmpty(Stack S);  // �ж���ջ�Ƿ�Ϊ�� 
void Push(Stack S, BinTree item);  // ��ջ 
BinTree Pop(Stack S);  // ��ջ


// ��ʼ�� 
Stack CreateStack() 
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

// �ж��Ƿ�Ϊ�� 
int IsEmpty(Stack S) 
{
	return (S->Next == NULL);
}

// ��ջ
void Push(Stack S, BinTree item) 
{
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Data = item;
	// ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ��� 
	tmp->Next = S->Next;
	S->Next = tmp;
}

// ��ջ
BinTree Pop(Stack S) 
{
	Stack First;
	BinTree TopVal;
	if (IsEmpty(S)) 
	{
		cout << "��ջ��" << endl;
		return 0;
	}
	else 
	{
		First = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ��� 
		S->Next = First->Next;  //�ѵ�һ��Ԫ�ش���ջɾ�� 
		TopVal = First->Data;   // ȡ����ɾ������ֵ 
		free(First);  // �ͷſռ� 
		return TopVal;
	}
}

BinTree Insert(int Data) 
{
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TreeNode));
	BT->Data = Data;
	BT->Left = NULL;
	BT->Right = NULL;
	return BT;
}

// ��ʼ�������� 
BinTree CreatBinTree() 
{
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TreeNode));
	return BT;
}

// ����ݹ�
void  PreOrderTraversal_Recursion(BinTree BT)
{
	if(BT){
		cout << BT->Data;  // ��ӡ��
		PreOrderTraversal_Recursion(BT->Left);  // ����������
		PreOrderTraversal_Recursion(BT->Right);  // ����������
	}
} 

// ����ǵݹ� 
void PreOrderTraversal(BinTree BT) 
{
	BinTree T = BT;
	Stack S = CreateStack();  // ��������ʼ����ջ S
	while (T || !IsEmpty(S)) {  // ������Ϊ�ջ��ջ���� 
		while (T) {
			Push(S, T);    // ѹջ����һ�������ý�� 
			cout << T->Data;  // ���ʽ��
			T = T->Left;   // ���������� 
		}
		if (!IsEmpty(S)) {  // ����ջ���� 
			T = Pop(S);    // ��ջ���ڶ��������ý�� 
			T = T->Right;  // �����ҽ�� 
		}
	}
}

// ����ݹ� 
void InOrderTraversal_Recursion(BinTree BT)
{
	if(BT){
		InOrderTraversal_Recursion(BT->Left);  // ����������
		cout << BT->Data;  // ��ӡ��
		InOrderTraversal_Recursion(BT->Right);  // ����������
	}
} 

// ����ǵݹ�
void InOrderTraversal(BinTree BT) 
{
	BinTree T = BT;
	Stack S = CreateStack();  // ��������ʼ����ջ S
	while (T || !IsEmpty(S)) {  // ������Ϊ�ջ��ջ���� 
		while (T) {
			Push(S, T);    // ѹջ
			T = T->Left;   // ���������� 
		}
		if (!IsEmpty(S)) {  // ����ջ���� 
			T = Pop(S);    // ��ջ
			cout << T->Data;  // ���ʽ��
			T = T->Right;  // �����ҽ�� 
		}
	}
}

// ����ݹ�
void PostOrderTraversal_Recursion(BinTree BT)
{
	if(BT)
	{
		PostOrderTraversal_Recursion(BT->Left);  // ����������
		PostOrderTraversal_Recursion(BT->Right);  // ����������
		cout << BT->Data;  // ��ӡ��
	}
} 

// ������� 
void PostOrderTraversal(BinTree BT) 
{
	BinTree T = BT;
	Stack S = CreateStack();  // ��������ʼ����ջ S
	vector<BinTree> v;
	Push(S, T);
	while (!IsEmpty(S)) {  // ������Ϊ�ջ��ջ���� 
		T = Pop(S);
		v.push_back(T);
		if (T->Left)
			Push(S, T->Left);
		if (T->Right)
			Push(S, T->Right);
	}
	reverse(v.begin(), v.end());  // ��ת 
	for (int i = 0; i < v.size(); i++)
	    cout << v[i]->Data;
}

// ��α���
void LevelOrderTraversal(BinTree BT) 
{
	queue<BinTree> q;
	BinTree T;
	if (!BT)
		return;
	q.push(BT);  // BT ��� 
	while (!q.empty()) {
		T = q.front();  // ���ʶ���Ԫ�� 
		q.pop();  // ����
		cout << T->Data;
		if (T->Left)
			q.push(T->Left);
		if (T->Right)
			q.push(T->Right);
	}
}
// ���Ҷ�ӽ��
void  FindLeaves(BinTree BT) 
{
	if (BT) 
	{
		if (!BT->Left && !BT->Right)
			cout << BT->Data;  // ��ӡҶ�ӽ��
		FindLeaves(BT->Left);  // ���������� 
		FindLeaves(BT->Right);  // ���������� 
	}
}

// �����߶�
int  GetHeight(BinTree BT) 
{
	int HL, HR, MaxH;
	if (BT) {
		HL = GetHeight(BT->Left);  // ���������߶� 
		HR = GetHeight(BT->Right);  // ���������߶� 
		MaxH = (HL > HR) ? HL : HR;
		return MaxH + 1;  // ��ǰ���߶�Ϊ�����������ĸ߶�+1 
	}
	else
		return 0;
}
int main() 
{
	BinTree BT;
	BT = CreatBinTree();
	BT->Data = 1;
	BT->Left = Insert(2);
	BT->Right = Insert(3);
	BT->Left->Left = Insert(4);
	BT->Left->Right = Insert(6);
	BT->Left->Right->Left = Insert(5);
	BT->Right->Left = Insert(7);
	BT->Right->Right = Insert(9);
	BT->Right->Left->Right = Insert(8);

	cout << "����ݹ������";
	PreOrderTraversal_Recursion(BT);
	cout << "\n����ǵݹ������";
	PreOrderTraversal(BT);

	cout << "\n����ݹ������";
	InOrderTraversal_Recursion(BT);
	cout << "\n����ǵݹ������";
	InOrderTraversal(BT);

	cout << "\n����ݹ������";
	PostOrderTraversal_Recursion(BT);
	cout << "\n����ǵݹ������";
	PostOrderTraversal(BT);

	cout << "\n��α�����";
	LevelOrderTraversal(BT);

	cout << "\n���Ҷ�ӽ�㣺";
	FindLeaves(BT);

	cout << "\n������ĸ߶ȣ�" << GetHeight(BT) << endl;

	system("pause");

	return 0;
}