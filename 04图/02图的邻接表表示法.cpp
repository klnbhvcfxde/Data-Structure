#include<iostream>
using namespace std;

/* ͼ���ڽӱ��ʾ�� */
#define MaxVertexNum 100  // ��󶥵�����Ϊ100
typedef int Vertex;  // �ö����±��ʾ����,Ϊ����
typedef int WeightType;  // �ߵ�Ȩֵ��Ϊ����
typedef char DataType;  // ����洢������������Ϊ�ַ���

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;  // �����<V1, V2>
	WeightType Weight;  // Ȩ��
};
typedef PtrToENode Edge;

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;  // �ڽӵ��±�
	WeightType Weight;  // ��Ȩ��
	PtrToAdjVNode Next;  // ָ����һ���ڽӵ��ָ��
};

/* �����ͷ���Ķ��� */
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  // �߱�ͷָ��
	DataType Data;  // �涥�������
	/* ע�⣺�ܶ�����£����������ݣ���ʱData���Բ��ó��� */
} AdjList[MaxVertexNum];  // AdjList���ڽӱ�����

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  // ������
	int Ne;  // ����
	AdjList G;  // �ڽӱ�
};
typedef PtrToGNode LGraph;  // ���ڽӱ�ʽ�洢��ͼ����

LGraph CreateGraph(int VertexNum)  // ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
{
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));  // ����ͼ
	Graph->Nv = VertexNum;  // ��ʼ����
	Graph->Ne = 0;  // ��ʼ����
	/* ��ʼ���ڽӱ�ͷָ�� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)  // ����һ���ߵ��ڽӱ�Ķ���ָ��֮�� 
{
	PtrToAdjVNode NewNode;

	/* ����� <V1, V2> */
	// ΪV2�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	// ��V2����V1�ı�ͷ
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/* ��������ͼ����Ҫ����� <V2, V1> */
	// ΪV1�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;

	// ��V1����V2�ı�ͷ
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

// ��ͼ
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	cin >> Nv;  // ���붥�����
	Graph = CreateGraph(Nv);  // ��ʼ����Nv�����㵫û�бߵ�ͼ

	cin >> (Graph->Ne);  // �������
	if (Graph->Ne != 0)  // ����б�
	{
		E = (Edge)malloc(sizeof(struct ENode));  // �����߽��
		for (i = 0; i < Graph->Ne; i++) {
			cin >> E->V1 >> E->V2 >> E->Weight;  // ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ���
			InsertEdge(Graph, E);
		}
	}

	// ������������ݵĻ�����������
	for (V = 0; V < Graph->Nv; V++)
		cin >> (Graph->G[V].Data);

	return Graph;
}

// ��ӡ 
void Print(LGraph Graph) 
{
	Vertex v;
	PtrToAdjVNode temp;
	for (v = 0; v < Graph->Nv; v++) 
	{
		temp = Graph->G[v].FirstEdge;
		cout << v << " ";
		while (temp) 
		{
			cout << temp->AdjV << " ";
			temp = temp->Next;
		}
		cout << endl;
	}
}

int main() 
{
	LGraph Graph;
	Graph = BuildGraph();
	Print(Graph);
	system("pause");
	return 0;
}