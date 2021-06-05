#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<algorithm>

int n, m;
#define MINLEN 42.5
#define MaxVertex 105
struct Pointer {  // ������λ����Ϣ
	int x;   // ������ 
	int y;   // ������ 
}point[MaxVertex];
bool answer = false;  // ��¼007�ܷ�ȫ����
bool visited[MaxVertex] = { false };  // �жϵ�ǰ���Ƿ񱻷��ʹ�
int path[MaxVertex] = { -1 };  // ��¼��Ծ�����вȹ�������

// �жϴӵ�ǰ���ܷ���������
bool isSave(int v) 
{
	if ((point[v].x - m <= -50) || (point[v].x + m >= 50) || (point[v].y - m <= -50) || (point[v].y + m >= 50))
		return true;
	return false;
}

// �ж�2��������Ƿ�����Ծ������
bool Jump(int v1, int v2) 
{ 
	int p1 = pow(point[v1].x - point[v2].x, 2);
	int p2 = pow(point[v1].y - point[v2].y, 2);
	int r = m * m;
	if (p1 + p2 <= r)
		return true;
	return false;
}

// ��007���ڹµ�ʱ����һ�ο���ѡ����������
int FirstJump(int v) 
{
	int p1 = pow(point[v].x, 2);
	int p2 = pow(point[v].y, 2);
	int r = (m + 7.5) * (m + 7.5);
	if (p1 + p2 <= r) 
	{
		return p1 + p2;
	}
	return 0;
}

bool cmp(int a, int b) 
{
	return FirstJump(a) < FirstJump(b);
}

// ��BFS���ж�����Ҫ�ȼ�����������ϰ�
void BFS() 
{ 
	int b[MaxVertex];
	queue<int>q;
	// ����һ���ܲȵ������㰴�����С�����˳������У���Ϊ������Ҫ��֤�ڲȵ�����������ȵ�����£������һ��������̵�
	for (int i = 0; i < n; i++)
		b[i] = i;
	sort(b, b + n, cmp);  // ���յ�һ���ľ����������cmp������0�Ļ�����ô���ͻύ��λ�ã������1������ԭ��λ�ò��䣩�����0 1 2 3 4 5 7 8 9 10 12 13 15 16 6 11 14
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	int last;
	for (int i = 0; i < n; i++) 
	{
		if (FirstJump(b[i]))  // ������ȥ��
		{
			q.push(b[i]);
			visited[b[i]] = true;  // ָ��ǰ�������һ����
			last = b[i];
		}
	}
	int step = 2;  // ��¼����Ҫ��Ծ�Ĵ���
	int tail = 0;
	while (!q.empty()) 
	{
		int p = q.front();
		q.pop();
		if (isSave(p)) 
		{
			int k = 1;
			stack<int> s;
			cout << step << endl;
			while (k < step)
			{
				s.push(p);
				p = path[p];
				k++;
			}
			while (!s.empty())
			{
				p = s.top();
				s.pop();
				cout << point[p].x << " " << point[p].y << endl;
			}
			return;
		}
		for (int i = 0; i < n; i++) 
		{
			if (!visited[i] && Jump(p, i))  // û�ȹ�����������
			{
				q.push(i);
				path[i] = p;  // �ǵõ�ǰ���ӽڵ�ĸ��ڵ�
				visited[i] = true;
				tail = i;  // ָ����һ������һ��Ԫ�� 
			}
		}
		if (last == p)  // ����������һ��
		{
			step += 1;
			last = tail;
		}
	}
	if (q.empty())  // �������Ϊ��  ˵��û����ȥ
	{
		cout << "0" << endl;
	}
}

int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		cin >> point[i].x >> point[i].y;
	}
	if (m >= MINLEN)  // ����ֱ�Ӵӹµ����������ϣ�ֱ�����
	{
		cout << "1" << endl;
		return 0;
	}
	BFS();
	system("pause");
	return 0;
}