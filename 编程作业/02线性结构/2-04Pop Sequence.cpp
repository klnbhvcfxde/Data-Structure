#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int main() 
{
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) 
	{
		stack<int> s;
		vector<int> v(n + 1);
		for (int j = 1; j <= n; j++)  //������Ҫ�жϵ��Ƿ�����Ƕ�ջ��ջ������
			cin >> v[j];
		int cur = 0;  //��ջ�Ĵ���
		for (int j = 1; j <= n; j++)
		{
			s.push(j);  //������1,...,n��˳������ѹ���ջ
			if (s.size() > m)  //���s�Ĵ�С�Ѿ����ڶ�ջ��������˵����û��Ԫ�ظ���Ҫ�жϵ�pop���е���Ԫ�ض�Ӧ�϶������������pop���в������Ƕ�ջ��pop����
				break;
			while (!s.empty() && s.top() == v[cur + 1])  //��s��Ϊ����s��ջ��Ԫ������Ҫ�жϵ�pop���е�Ԫ�ض�Ӧ��ʱ��������Ԫ��
			{
				s.pop();  //����
				cur++;  //��ջ�Ĵ���+1
			}
		}
		if (cur == n)  //��ջ��������push���еĳ��ȣ�˵����Ҫ�жϵ�pop���е�����Ԫ�ؾ��ѳ�ջ�����pop���п����Ƕ�ջ��pop����
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}