#include<iostream>
using namespace std;
#include<algorithm>
#define MaxNum 1001
int LevelOrder[MaxNum];
int j = 0;

void InOrder_BST(int root, int N, int InOrder[]) 
{
	if (root <= N) 
	{
		//��ȫ�������ڲ������ʱ���±�Ϊi�Ľ������Ӻ��Һ��ӵ��±�ֱ�Ϊ2i,2i+1
		InOrder_BST(root * 2, N, InOrder);
		LevelOrder[root] = InOrder[j++];
		InOrder_BST(root * 2 + 1, N, InOrder);
	}
}

int main() 
{
	int N, InOrder[MaxNum];
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> InOrder[i];
	}
	sort(InOrder, InOrder + N);  //�������������������Ϊһ����������У�������������ݽ����������к�������ȫ����������������������
	InOrder_BST(1, N, InOrder);
	cout << LevelOrder[1];
	for (int i = 2; i <= N; i++) 
	{
		cout << " " << LevelOrder[i];
	}
	system("pause");
	return 0;
}