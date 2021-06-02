#include<iostream>
using namespace std;

/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100    // ��󶥵�����Ϊ100
#define INFINITY 65535     // ����Ϊ˫�ֽ��޷������������ֵ65535  
#define ERROR 0  
typedef int Vertex;         // �ö����±��ʾ����,Ϊ����
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ����
typedef char DataType;        // ����洢������������Ϊ�ַ���
bool Visited[MaxVertexNum];

// �ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;    // �����<V1,V2> 
	WeightType Weight;  // Ȩ�� 
};
typedef PtrToENode Edge;

// ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;   // ������ 
	int Ne;   // ����
	WeightType G[MaxVertexNum][MaxVertexNum];  //�ڽӾ���
	DataType Data[MaxVertexNum]; // �涥�������(ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó���)
};
typedef PtrToGNode MGraph;  // ���ڽӾ���洢��ͼ����

struct Node {
	int Data;
	struct Node *Next;
};

struct QNode {
	struct Node *rear;
	struct Node *front;
};
typedef struct QNode *Queue;

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

	cin >> (Graph->Ne);  // ������� 
	if (Graph->Ne != 0)  // ����б�
	{
		E = (Edge)malloc(sizeof(struct ENode));  // �����߽��
		for (i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;// ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� 
			InsertEdge(Graph, E);
		}
	}

	// ������������ݵĻ�����������
	for (V = 0; V < Graph->Nv; V++)
		cin >> (Graph->Data[V]);

	return Graph;
}

int IsEmpty(Queue Q) 
{
	return(Q->front == NULL);
};

Queue CreateQueue() 
{
	Queue PtrQ;
	PtrQ = (Queue)malloc(sizeof(struct QNode));
	struct Node *rear;
	struct Node *front;
	rear = (Node*)malloc(sizeof(struct Node));
	rear = NULL;
	front = (Node*)malloc(sizeof(struct Node));
	front = NULL;
	PtrQ->front = front;
	PtrQ->rear = rear;
	return PtrQ;
};

int DeleteQ(Queue PtrQ) 
{
	struct Node *FrontCell;
	int FrontElem;

	if (IsEmpty(PtrQ)) 
	{
		cout << "���п�" << endl;
		return ERROR;
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;
	else 
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
}

void InsertQ(int item, Queue PtrQ) 
{
	struct Node *FrontCell;
	FrontCell = (Node*)malloc(sizeof(struct Node));
	FrontCell->Data = item;
	FrontCell->Next = NULL;

	if (IsEmpty(PtrQ)) 
	{
		PtrQ->front = FrontCell;
		PtrQ->rear = FrontCell;
	}
	else 
	{
		PtrQ->rear->Next = FrontCell;
		PtrQ->rear = FrontCell;
	}
};

/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

// ��SΪ��������ڽӾ���洢��ͼGraph����BFS��
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	Queue Q;
	Vertex V, W;

	Q = CreateQueue();  // �����ն���
	Visit(S);
	Visited[S] = true;  // ���S�ѷ��ʣ�Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse
	InsertQ(S, Q);  // S�����

	while (!IsEmpty(Q)) 
	{
		V = DeleteQ(Q);   // ����V
		for (W = 0; W < Graph->Nv; W++)  // ��ͼ�е�ÿ������W
			// ��W��V���ڽӵ㲢��δ���ʹ�
			if (!Visited[W] && IsEdge(Graph, V, W)) 
			{
				Visit(W);  // ���ʶ���
				Visited[W] = true;  // ���W�ѷ���
				InsertQ(W, Q);  // W�����
			}
	} /* while����*/
}

void Visit(Vertex V)
{
	cout << "���ڷ��ʶ���" << V << endl;
}

int main() 
{
	MGraph Graph = BuildGraph();
	for (int i = 0; i < MaxVertexNum; i++)
	    Visited[i] = false;
	BFS(Graph, 0, Visit);
	system("pause");
	return 0;
}