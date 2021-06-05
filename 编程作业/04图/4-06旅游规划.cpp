#include<iostream>
using namespace std;
#define INF 1000000
#define MaxVertex 505

typedef int Vertex;
int value[MaxVertex][MaxVertex];    //�շѾ���
int G[MaxVertex][MaxVertex];    //�������
int dist[MaxVertex];  // ����
int cost[MaxVertex];  // ����
bool collected[MaxVertex];  // ����¼����

int N;   // ���еĸ���
int M;   // ���ٹ�·������
int S;  // �����صĳ��б��
int D;  // Ŀ�ĵصĳ��б��

// ��ʼ��ͼ��Ϣ
void BuildGraph() 
{
	Vertex v1, v2, w1, w2;
	cin >> N >> M >> S >> D;  // ���룺���еĸ��������ٹ�·�������������صĳ��б�š�Ŀ�ĵصĳ��б��
	for (Vertex i = 0; i < N; i++) 
	{
		for (Vertex j = 0; j < N; j++) 
		{
			G[i][j] = INF;
			value[i][j] = INF;
		}
		cost[i] = 0;
		collected[i] = false;
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++) 
	{
		cin >> v1 >> v2 >> w1 >> w2;  // ���룺����1������2�����ٹ�·���ȡ��շѶ�
		G[v1][v2] = w1;
		G[v2][v1] = w1;
		value[v1][v2] = w2;
		value[v2][v1] = w2;
	}
}

void Init() 
{
	dist[S] = 0;
	collected[S] = true;
	for (Vertex i = 0; i < N; i++)
		if (G[S][i]) 
		{
			dist[i] = G[S][i];
			cost[i] = value[S][i];
		}
}

// ����δ��¼������dist��С��
Vertex FindMin() 
{
	int min = INF;
	Vertex x = -1;
	for (Vertex i = 0; i < N; i++)
		if (S != i && !collected[i] && dist[i] < min) 
		{
			min = dist[i];
			x = i;
		}
	return x;
}


void Dijkstra() 
{
	Init();
	while (1) 
	{
		Vertex v = FindMin();
		if (v == -1)
			break;
		collected[v] = true;
		for (Vertex w = 0; w < N; w++) 
		{
			if (!collected[w] && G[v][w]) 
			{
				if (dist[v] + G[v][w] < dist[w]) 
				{
					dist[w] = dist[v] + G[v][w];
					cost[w] = cost[v] + value[v][w];
				}
				else if (dist[v] + G[v][w] == dist[w] && cost[v] + value[v][w] < cost[w]) 
				{
					cost[w] = cost[v] + value[v][w];
				}
			}
		}
	}
}

int main() 
{
	BuildGraph();
	Dijkstra();
	cout << dist[D] << " " << cost[D] << endl;
	system("pause");
	return 0;
}