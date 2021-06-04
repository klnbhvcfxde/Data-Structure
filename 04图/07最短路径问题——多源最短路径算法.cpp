#include<iostream>
using namespace std;

/* �ڽӾ��󴢴桪����Դ���·�㷨 */

#define INFINITY 65535   // ����Ϊ˫�ֽ��޷������������ֵ65535      
#define MaxVertexNum 100   //��󶥵�����Ϊ100     
typedef int Vertex;   //�ö����±��ʾ����,Ϊ����
typedef int WeightType;   //�ߵ�Ȩֵ��Ϊ����

// ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  // ������
	int Ne;  // ����
	WeightType G[MaxVertexNum][MaxVertexNum];  // �ڽӾ���
};
typedef PtrToGNode MGraph; // ���ڽӾ���洢��ͼ����

//�ߵ����ݽṹ
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;  // �����<V1, V2>
	WeightType Weight;  // Ȩ��
};
typedef PtrToENode Edge;

// ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));  // ����ͼ
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V <= Graph->Nv; V++)
		for (W = 0; W <= Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

// ����� 
void InsertEdge(MGraph Graph, Edge E) 
{
	// ����� <V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;

	// ���������ͼ������Ҫ����� <V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}

// ��ͼ 
MGraph BuildGraph() 
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	cin >> Nv;   // ���붥���� 
	Graph = CreateGraph(Nv);  // ��ʼ����Nv�����㵫û�бߵ�ͼ

	cin >>(Graph->Ne);  // ������� 
	if (Graph->Ne != 0)  // ����б�
	{
		E = (Edge)malloc(sizeof(struct ENode));  // �����߽��
		for (i = 0; i < Graph->Ne; i++) 
		{
			cin >> E->V1 >> E->V2 >> E->Weight;// ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� 
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}

//��Դ���·��
bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum])
{
	Vertex i, j, k;

	// ��ʼ��
	for (i = 1; i <= Graph->Nv; i++)
		for (j = 1; j <= Graph->Nv; j++) 
		{
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}

	for (k = 1; k <= Graph->Nv; k++)
		for (i = 1; i <= Graph->Nv; i++)
			for (j = 1; j <= Graph->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) 
				{
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0)  // �����ָ�ֵȦ
						return false;  // ������ȷ��������ش�����
					path[i][j] = k;
				}
	return true;  // �㷨ִ����ϣ�������ȷ���
}

//·���Ĵ�ӡ
void PrintPath(Vertex path[][MaxVertexNum], Vertex v1, Vertex v2)
{
	cout << v2 << " ";
	while (1) 
	{
		if (path[v1][v2] != -1)
			cout << path[v1][v2] << " ";
		else
			break;
		v2 = path[v1][v2];
	}
	cout << v1 << endl;
}

int main() 
{
	MGraph Graph = BuildGraph();

	WeightType Weight[MaxVertexNum][MaxVertexNum];
	Vertex path[MaxVertexNum][MaxVertexNum];
	Floyd(Graph, Weight, path);

	cout << "������Ҫ��ѯ���·�����������㣺";
	Vertex v1, v2;
	cin >> v1 >> v2;
	cout << "���·��Ϊ��";
	PrintPath(path, v1, v2);
	cout << "���·����Ӧ��ȨֵΪ��" << Weight[v1][v2] << endl;

	system("pause");
	return 0;
}