#include<iostream>
using namespace std;

/* ͼ���ڽӾ����ʾ�� */
#define MaxVertexNum 100    // ��󶥵�����Ϊ100
typedef int Vertex;         // �ö����±��ʾ����,Ϊ����
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ����
typedef char DataType;        // ����洢������������Ϊ�ַ���

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;    // �����<V1,V2> 
	WeightType Weight;  // Ȩ�� 
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;   // ������ 
	int Ne;   // ����
	WeightType G[MaxVertexNum][MaxVertexNum];  //�ڽӾ���
	DataType Data[MaxVertexNum]; // �涥������� 
	/* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph;  // ���ڽӾ���洢��ͼ����


// ��ʼ��ͼ 
MGraph CreateGraph(int VertexNum) 
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));  // ����ͼ
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < VertexNum; V++)
		for (W = 0; W < VertexNum; W++)
			Graph->G[V][W] = 0;
	return Graph;
}

// ����� 
void Insert(MGraph Graph, Edge E) 
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
			Insert(Graph, E);
		}
	}

	// ������������ݵĻ�����������
	for (V = 0; V < Graph->Nv; V++)
		cin >> (Graph->Data[V]);

	return Graph;
}

// ����ͼ
void Print(MGraph Graph) 
{
	Vertex V, W;
	for (V = 0; V < Graph->Nv; V++) 
	{
		for (W = 0; W < Graph->Nv; W++)
			cout << Graph->G[V][W];
		cout << endl;
	}
}

int main() 
{
	MGraph Graph;
	Graph = BuildGraph();
	Print(Graph);
	system("pause");
	return 0;
}