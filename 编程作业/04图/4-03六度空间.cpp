#include <iostream>
using namespace std;
#include<iomanip>
#include <queue>
#include <algorithm>
typedef int Vertex;

const int N = 10010;
const int M = 40000;
int G[N][N];
int n, m;
bool visited[N];

int BFS(Vertex v)
{
	queue<int> q;
	visited[v] = true;
	int level = 0;  // ����
	int last = v;  // ��¼ÿһȦ�����һ����
	int tail = 0;  // ����ÿһȦ�����һ����
	int count = 1;   // 6���ڵĵ���
	q.push(v);
	while (!q.empty()) 
	{
		int temp = q.front();
		q.pop();
		for (int w = 0; w < n; w++) 
		{
			if (!visited[w] && G[temp][w]) 
			{
				visited[w] = true;
				q.push(w);
				tail = w;  // ���µ�ǰȦ�����һ����ı��
				count++;
			}
		}

		if (last == temp)  // ����õ�ǰ�����������һ�����
		{
			level++;  // ���� +1
			last = tail;   // ���� last 
		}
		if (level == 6)
			break;  // ֻ����6�㣬6���ֹͣ
	}
	return count;
}

void init() 
{
	for (int i = 0; i < n; i++) 
	{
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		int V1, V2;
		cin >> V1 >> V2;
		G[V1 - 1][V2 - 1] = 1;
		G[V2 - 1][V1 - 1] = 1;
	}

	for (int i = 0; i < n; i++) 
	{
		init();
		visited[i] = false;
		cout << i + 1 << ":" << setiosflags(ios::fixed) << setprecision(2) << 1.0*BFS(i) * 100 / n << "%" << endl;
	}
	system("pause");
	return 0;
}