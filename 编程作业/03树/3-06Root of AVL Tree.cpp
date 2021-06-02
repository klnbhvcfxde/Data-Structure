#include<iostream>
using namespace std;
typedef struct AVLNode *AVLTree;
struct AVLNode {
	int data;     // ��ֵ 
	AVLTree left;  // ������ 
	AVLTree right;  // ������ 
	int height;  // ���� 
};

// �������ֵ 
int Max(int a, int b)
{
	return a > b ? a : b;
}

// �������ߣ���������-1 
int getHeight(AVLTree A)
{
	return A == NULL ? -1 : A->height;
}

// LL��ת
// ��B���������ڳ�������A�����������ٽ�A����B���������ϣ�����B��Ϊ��ǰ�����ĸ�
AVLTree LLRotation(AVLTree A)
{
	// ��ʱ���ڵ���A 
	AVLTree B = A->left;  // BΪA��������  
	A->left = B->right;  // B������������A���������� 
	B->right = A;   // A����B���������� 
	A->height = Max(getHeight(A->left), getHeight(A->right)) + 1;
	B->height = Max(getHeight(B->left), A->height) + 1;
	return B;  // ��ʱBΪ����� 
}

// RR��ת
// ��B���������ڳ����ҵ�A���������ϣ��ٽ�A����B���������ϣ�����B��Ϊ��ǰ�����ĸ�
AVLTree RRRotation(AVLTree A)
{
	// ��ʱ���ڵ���A 
	AVLTree B = A->right;  // BΪA��������
	A->right = B->left;   // B������������A����������
	B->left = A;   // A����B����������
	A->height = Max(getHeight(A->left), getHeight(A->right)) + 1;
	B->height = Max(getHeight(B->left), A->height) + 1;
	return B;  // ��ʱBΪ����� 
}

// LR��ת 
// �Ƚ�B(A->left)��Ϊ��������RR��ת���ٽ�A��Ϊ��������LL��ת
AVLTree LRRotation(AVLTree A)
{
	// ��RR��ת
	A->left = RRRotation(A->left);
	// ��LL��ת 
	return LLRotation(A);
}

// RL��ת
// �Ƚ�B(A->right)��Ϊ��������LL��ת���ٽ�A��Ϊ��������RR��ת
AVLTree RLRotation(AVLTree A)
{
	// �� LL ����
	A->right = LLRotation(A->right);
	// �� RR ���� 
	return RRRotation(A);
}

AVLTree Insert(AVLTree T, int x)
{
	if (!T)  // ����ý��Ϊ�գ���ʼ�����
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
		T->height = 0;
	}
	else   // ����Ϊ��
	{
		if (x < T->data)  // ������
		{
			T->left = Insert(T->left, x);
			if (getHeight(T->left) - getHeight(T->right) == 2)   // ������������������߶Ȳ�Ϊ 2 
			{
				if (x < T->left->data)  // LL��ת 
					T = LLRotation(T);
				else if (x > T->left->data)  // LR��ת
					T = LRRotation(T);
			}
		}
		else if (x > T->data)   // ������
		{
			T->right = Insert(T->right, x);
			if (getHeight(T->right) - getHeight(T->left) == 2)
			{
				if (x < T->right->data)  // RL��ת 
					T = RLRotation(T);
				else if (x > T->right->data)  // RR��ת
					T = RRRotation(T);
			}
		}
	}
	//�������� 
	T->height = Max(getHeight(T->left), getHeight(T->right)) + 1;
	return T;
}

int main()
{
	AVLTree T = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		T = Insert(T, tmp);
	}
	cout << T->data << endl;
	system("pause");
	return 0;
}