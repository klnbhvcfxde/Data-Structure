#include<iostream>
using namespace std;
#include<queue>

#define INF 100000
#define MaxVertex 105
typedef int Vertex;
int G[MaxVertex][MaxVertex];
int parent[MaxVertex];   // 并查集
int dist[MaxVertex]; // 距离
int Nv;    // 结点
int Ne;    // 边
int sum;  // 权重和
queue<Vertex> MST;  // 最小生成树

// 初始化图信息
void BuildGraph()
{
	Vertex v1, v2;
	int w;
	cin >> Nv >> Ne;
	for (int i = 1; i <= Nv; i++)
	{
		for (int j = 1; j <= Nv; j++)
			G[i][j] = 0;  // 初始化图
		dist[i] = INF;   // 初始化距离
		parent[i] = -1;  // 初始化并查集
	}
	// 初始化点
	for (int i = 0; i < Ne; i++)
	{
		cin >> v1 >> v2 >> w;
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
}

// Prim算法前的初始化
void IniPrim(Vertex s)
{
	dist[s] = 0;
	MST.push(s);
	for (Vertex i = 1; i <= Nv; i++)
		if (G[s][i]) {
			dist[i] = G[s][i];
			parent[i] = s;
		}
}

// 查找未收录中dist最小的点
Vertex FindMin()
{
	int min = INF;
	Vertex xb = -1;
	for (Vertex i = 1; i <= Nv; i++)
		if (dist[i] && dist[i] < min)
		{
			min = dist[i];
			xb = i;
		}
	return xb;
}

void Prim(Vertex s)
{
	IniPrim(s);
	while (1)
	{
		Vertex v = FindMin();
		if (v == -1)
			break;
		sum += dist[v];
		dist[v] = 0;
		MST.push(v);
		for (Vertex w = 1; w <= Nv; w++)
			if (G[v][w] && dist[w])
				if (G[v][w] < dist[w])
				{
					dist[w] = G[v][w];
					parent[w] = v;
				}
	}
}

void Print()
{
	cout << "被收录顺序：" << endl;
	while (!MST.empty())
	{
		cout << MST.front() << " ";
		MST.pop();
	}
	cout << endl;
	cout << "权重和为：" << endl;
	cout << sum << endl;
}

int main()
{
	BuildGraph();
	Prim(1);
	Print();
	system("pause");
	return 0;
}