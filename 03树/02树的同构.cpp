#include<iostream>
using namespace std;
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode {
	ElementType data;    // ��ֵ 
	Tree left;   // ���������±� 
	Tree right;  // ���������±� 
}T1[MaxTree], T2[MaxTree];

// ���ظ����ĵ�һ�ַ��� �����ڵ���δ��������������ŵĺ��棬����һ��check������ȷ����
// �������������ظ����
Tree BuildTree(struct TreeNode T[])
{
	int i;
	int n;
	int check[MaxTree];  //����һ��check������ȷ�����ڵ㣬���ھ�̬������δ���ֵ��±���Ϊ���ڵ�
	char left, right;
	Tree root = Null;   //��nΪ0������Null

	cin >> n;
	if (n) 
	{
		for (i = 0; i < n; i++) 
		{
			check[i] = 0;
		}
		for (i = 0; i < n; i++) 
		{
			cin >> T[i].data >> left >> right;
			if (left != '-') 
			{
				T[i].left = left - '0';   //�����벻Ϊ'-',���ַ���ȥ�ַ�0ת��Ϊ������ֵ
				check[T[i].left] = 1; //���ھ�̬�����г��ֹ�����ֵ���Ϊ1
			}
			else if (left == '-') 
			{
				T[i].left = Null;
			}
			if (right != '-') 
			{
				T[i].right = right - '0';
				check[T[i].right] = 1;
			}
			else if (right == '-') 
			{
				T[i].right = Null;
			}
		}

		for (i = 0; i < n; i++) 
		{
			if (!check[i]) 
			{
				break;
			}
		}
		root = i;

	}
	return root;
}

//// ���ظ����ĵڶ��ַ��� �����ڵ��� = �кź� - ���ҽ���źͣ�
//// �������������ظ����
//Tree BuildTree(struct TreeNode T[])
//{
//	int n;  //nΪ���Ľ����
//	int root = 0;
//	char left, right;
//	cin >> n;
//	if (!n)
//		return Null;
//	for (int i = 0; i < n; i++) 
//	{
//		cin >> T[i].data >> left >> right;
//		if (left == '-')
//			T[i].left = Null;
//		else 
//		{
//			T[i].left = left - '0';
//			root -= T[i].left;
//		}
//		if (right == '-')
//			T[i].right = Null;
//		else 
//		{
//			T[i].right = right - '0';
//			root -= T[i].right;
//		}
//		// 0 �ۼӵ� n-1 
//		root += i;
//	}
//	return root;
//}


// �ж��Ƿ�ͬ��
bool Isomorphic(int R1, int R2) 
{
	if (R1 == Null && R2 == Null)   // ��Ϊ�� 
		return true;
	if (R1 == Null && R2 != Null || R1 != Null && R2 == Null)    // һ��Ϊ�գ�һ����Ϊ��
		return false;
	if (T1[R1].data != T2[R2].data)   // ֵ��ͬ
		return false;
	if ((T1[R1].left == Null) && (T2[R2].left == Null))  //����Ӿ�Ϊ��
	{
		return Isomorphic(T1[R1].right, T2[R2].right);
	}
	if ((T1[R1].left != Null && T2[R2].left != Null) && (T1[T1[R1].left].data == T2[T2[R2].left].data))  // ����Ӳ�Ϊ����ֵ���
		return Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right);
	else   // ����Ӳ�Ϊ����ֵ����  ���� ĳһ�������Ϊ�գ��п�����ߺ��ұ�ͬ�����ұߺ����ͬ����
		return Isomorphic(T1[R1].right, T2[R2].left) && Isomorphic(T1[R1].left, T2[R2].right);
}
int main() {
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	cout << "�Ƿ�ͬ����" << endl;
	if (Isomorphic(R1, R2))
		cout << "��" << endl;
	else
		cout << "��" << endl;

	system("pause");

	return 0;
}