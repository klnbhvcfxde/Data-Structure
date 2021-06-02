#include<iostream>
using namespace std;
#include<queue>
#define MaxVertex 100
typedef int Vertex;
int G[MaxVertex][MaxVertex];
bool visit[MaxVertex];
int Ne, Nv;

// ��ͼ 
void BuildGraph() 
{
	cin >> Nv;    // ������
	for (int i = 0; i < Nv; i++) 
	{
		visit[i] = false;   // ��Ϊδ���� 
		for (int j = 0; j < Nv; j++)
			G[i][j] = 0;  // ��ʼ���ڽӾ���
	}
	cin >> Ne;  // ����
	for (int i = 0; i < Ne; i++) 
	{
		int v1, v2;
		cin >> v1 >> v2;
		G[v1][v2] = 1;  // ����� <V1,V2>
		G[v2][v1] = 1;  // ����� <V2,V1>
	}
}

void DFS(Vertex v) 
{
	visit[v] = true;	// ����ѷ��� 
	cout << " " << v;
	for (int i = 0; i < Nv; i++)
		if (!visit[i] && G[v][i])
			DFS(i);
}

void BFS(Vertex v) 
{
	queue<Vertex> q;
	visit[v] = true;	// ����ѷ��� 
	cout << " " << v; 
	q.push(v);	// ���
	while (!q.empty()) 
	{
		// ���Ӷ���Ԫ�� 
		Vertex tmp = q.front();
		q.pop();
		for (Vertex i = 0; i < Nv; i++) 
		{
			// ���δ�����ʹ����Һ͸ճ���Ԫ������ 
			if (!visit[i] && G[i][tmp]) 
			{
				visit[i] = true;
				cout << " " << i;
				q.push(i);
			}
		}
	}
}

// ������ͨ�� 
void ListComponents() 
{
	for (Vertex i = 0; i < Nv; i++)
		if (!visit[i]) 
		{
			cout << "{";
			DFS(i);
			cout << " }" << endl;
		}

	// ��ʼ����״̬ 
	for (Vertex i = 0; i < Nv; i++)
		visit[i] = false;

	for (Vertex i = 0; i < Nv; i++)
		if (!visit[i]) 
		{
			cout << "{";
			BFS(i);
			cout << " }" << endl;
		}
}

int main() 
{
	BuildGraph();
	ListComponents();
	system("pause");
	return 0;
}