#include<iostream>
using namespace std;
#include<string>
#include<queue>

#define INF 100000
#define MaxVertex 105
typedef int Vertex;
int G[MaxVertex][MaxVertex];
int parent[MaxVertex];   // 并查集最小生成树
int Nv;    // 结点
int Ne;    // 边
int sum;  // 权重和

struct Node {
	Vertex v1;
	Vertex v2;
	int weight; // 权重
	// 重载运算符成最大堆
	bool operator < (const Node &a) const
	{
		return weight > a.weight;
	}
};
queue<Node> MST;  // 最小生成树
priority_queue<Node> q;  // 最小堆

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
		parent[i] = -1;
	}
	// 初始化点
	for (int i = 0; i < Ne; i++)
	{
		cin >> v1 >> v2 >> w;
		struct Node tmpE;
		tmpE.v1 = v1;
		tmpE.v2 = v2;
		tmpE.weight = w;
		q.push(tmpE);
	}
}

//  路径压缩查找
//找祖先
int Find(int x)
{
	if (parent[x] < 0)
		return x;
	else
		return parent[x] = Find(parent[x]);
}

//  按秩归并
void Union(int x1, int x2)
{
	x1 = Find(x1);
	x2 = Find(x2);
	if (parent[x1] < parent[x2])
	{
		parent[x1] += parent[x2];
		parent[x2] = x1;
	}
	else
	{
		parent[x2] += parent[x1];
		parent[x1] = x2;
	}
}

/*伪代码
这个算法是把各个最小边找出来, 零散的也没关系, 只要不形成环. 慢慢就拼合到一起了
void Kruskal ( Graph G ){
    MST = { };
    while ( MST 中不到|V|-1条边 &&  E中还有边 ) {
        从 E 中取一条权重最小的边 E<V,W>;    // 最小堆
        将 E<V,W> 从 E 中删除;
        if ( E<V,W> 不在 MST 中构成回路 )  // 并查集
            将 E<V,W> 加入MST;
        else
            彻底无视 E<V,W>;
    }
    if ( MST 中不到|V|-1条边 )
        Error("图不连通");
}
*/
void Kruskal()
{
	// 最小生成树的边不到 Nv-1 条且还有边
	while (MST.size() != Nv - 1 && !q.empty())
	{
		Node E = q.top();  // 从最小堆取出一条权重最小的边
		q.pop(); // 出队这条边
		if (Find(E.v1) != Find(E.v2))
		{  // 检测两条边是否在同一集合
            //sum权重和, 最小生成树最小的是所有边的权重和
			sum += E.weight;
			Union(E.v1, E.v2);     // 并起来
			MST.push(E);
		}
	}

}

void Print()
{
	cout << "被收录顺序(每条边对应的顶点1 顶点2 权重)：" << endl;
	while (!MST.empty())
	{
		Node a = MST.front();
		cout << a.v1 << " " << a.v2 << " " << a.weight << endl;
		MST.pop();
	}
	cout << "权重和为：" << endl;
	cout << sum << endl;
}


int main()
{
	BuildGraph();
	Kruskal();
	Print();
	return 0;
}