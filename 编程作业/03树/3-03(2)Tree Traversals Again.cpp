#include <iostream>
using namespace std;
#define MaxTree 30
#include <stack>
#include<string>

int pre[MaxTree], in[MaxTree], post[MaxTree];

//ǰ����ʼλ�ã�������ʼλ�ã�������ʼλ�ã�Ԫ�ظ���
void PostOrder(int prel, int inl, int postl, int n)
{
	if (n == 0)
		return;//�ݹ����
	if (n == 1)
	{
		post[postl] = pre[prel];
		return;
	}
	int root = pre[prel];
	post[postl + n - 1] = root;
	int i;
	for (i = 0; i < n; i++)  //�ҵ����������е�λ��
	{
		if (in[inl + i] == root)
			break;
	}
	int L = i;  //������������
	int R = n - (i + 1);  //�����������
	PostOrder(prel + 1, inl, postl, L);  //����������
	PostOrder(prel + L + 1, inl + L + 1, postl + L, R);  //����������
}

int main()
{
	int n, num;
	cin >> n;
	int p = 0, k = 0;
	string s;
	stack<int> st;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> s;
		if (s == "Push")
		{
			cin >> num;
			pre[p++] = num;
			st.push(num);
		}
		else
		{
			in[k++] = st.top();
			st.pop();
		}
	}
	PostOrder(0, 0, 0, n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << post[i];
		else
			cout << " " << post[i];
	}
	system("pause");
	return 0;
}