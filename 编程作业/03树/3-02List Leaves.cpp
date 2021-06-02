#include<iostream>
using namespace std;
#define MaxTree 10
#define Null -1
#include<queue>

#define Tree int
struct TreeNode {
	Tree left;   // ���������±� 
	Tree right;  // ���������±� 
}T[MaxTree];

// �������������ظ����
Tree BuildTree(struct TreeNode T[])
{
	int i, n;
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
			cin >> left >> right;
			if (left != '-')
			{
				T[i].left = left - '0';   //�����벻Ϊ'-',���ַ���ȥ�ַ�0ת��Ϊ������ֵ
				check[T[i].left] = 1; //���ھ�̬�����г��ֹ�����ֵ���Ϊ1
			}
			else if (left == '-')
				T[i].left = Null;
			if (right != '-')
			{
				T[i].right = right - '0';
				check[T[i].right] = 1;
			}
			else if (right == '-')
				T[i].right = Null;
		}

		for (i = 0; i < n; i++)
		{
			if (!check[i])
				break;
		}
		root = i;

	}
	return root;
}

//������������Ҷ���
void PrintLeava(int root)
{
	if (root == Null)  //��������Ϊ��֤���ǿ���
	{
		cout << "-1" << endl;
		return;
	}

	queue<int>q;
	q.push(root);
	int i = 0;
	int leave[MaxTree];
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		if (T[s].left == Null && T[s].right == Null)  //����ý���û��������û���Һ��Ӿ���Ҷ��
		{
			leave[i++] = s;
		}
		else
		{
			if (T[s].left != Null)/*������Ӳ�Ϊ�վ�push����*/
			{
				q.push(T[s].left);
			}
			if (T[s].right != Null)  //����Һ��Ӳ�Ϊ�վ�push�Һ���
			{
				q.push(T[s].right);
			}
		}
	}
	for (int j = 0; j < i; j++)  //��˳�����Ҷ��
	{
		if (j < i - 1)  //��������֮�������һ���ո�
		{
			cout << leave[j] << " ";
		}
		else  //j=i-1Ϊ��β�����ж���Ŀո�
		{
			cout << leave[j];
		}
	}
}

int main()
{
	Tree root = BuildTree(T);
	PrintLeava(root);
	system("pause");
	return 0;
}