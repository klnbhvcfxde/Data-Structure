#include<iostream>
using namespace std;
#define MaxSize 1000
typedef int ElementType;
typedef struct {
	ElementType Data; // ��ֵ
	int Parent;  // ָ�򸸽�� 
}SetType;

// ���� 
int Find(SetType S[], ElementType X) 
{
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);  // �ҵ������и�ֵ��Ӧ���±� 
	if (MaxSize <= i) // ���û���ҵ������� -1 
		return -1;
	for (; S[i].Parent >= 0; i = S[i].Parent); 	// �ҵ��ý��ĸ���� 
	return i; // ���ظ����������S�е��±� 
}

// �� 
void Union(SetType S[], ElementType X1, ElementType X2) 
{
	int root1 = Find(S, X1);  // �ҵ� X1 �ĸ�����±� 
	int root2 = Find(S, X2);  // �ҵ� X2 �ĸ�����±� 
	// ����������±겻ͬ��˵������һ������
	if (root1 != root2) 
	{
		S[root1].Parent = root2;   // ��X1�ҵ�X2�ļ��� 
	}
}

int main() 
{
	SetType S[MaxSize];
	// ��ʼ�����飬�����ȫ��ָ��-1 
	for (int i = 0; i < MaxSize; i++) 
	{
		S[i].Data = i + 1;
		S[i].Parent = -1;
	}
	cout << Find(S, 5) << endl;
	Union(S, 3, 5);
	cout << Find(S, 4) << endl;
	cout << Find(S, 3) << endl;
	Union(S, 1, 3);
	Union(S, 2, 4);
	Union(S, 8, 6);
	cout << Find(S, 6) << endl;
	cout << Find(S, 8) << endl;
	system("pause");
	return 0;
}