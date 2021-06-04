//#include<iostream>
//using namespace std;
//
///* �ڽӾ��󴢴桪����Ȩͼ�ĵ�Դ���·�㷨 */
//
//#define INFINITY 65535   // ����Ϊ˫�ֽ��޷������������ֵ65535      
//#define MaxVertexNum 100   //��󶥵�����Ϊ100     
//typedef int Vertex;   //�ö����±��ʾ����,Ϊ����
//typedef int WeightType;   //�ߵ�Ȩֵ��Ϊ����
//#define ERROR 0  
//
//int Visited[MaxVertexNum];
//int dist[MaxVertexNum];
//int path[MaxVertexNum];
//
//// �ߵĶ���
//typedef struct ENode *PtrToENode;
//struct ENode {
//	Vertex V1, V2;      // �����<V1, V2>
//};
//typedef PtrToENode Edge;
//
//// ͼ���Ķ���
//typedef struct GNode *PtrToGNode;
//struct GNode {
//	int Nv;  // ������
//	int Ne;  // ����
//	WeightType G[MaxVertexNum][MaxVertexNum];  // �ڽӾ���
//};
//typedef PtrToGNode MGraph; // ���ڽӾ���洢��ͼ����    
//
//struct Node {
//	int Data;
//	struct Node *Next;
//};
//
//struct QNode {
//	struct Node *rear;
//	struct Node *front;
//};
//typedef struct QNode *Queue;
//
//// ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
//MGraph CreateGraph(int VertexNum)
//{
//	Vertex V, W;
//	MGraph Graph;
//
//	Graph = (MGraph)malloc(sizeof(struct GNode));  // ����ͼ
//	Graph->Nv = VertexNum;
//	Graph->Ne = 0;
//	/* ��ʼ���ڽӾ��� */
//	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
//	for (V = 0; V <= Graph->Nv; V++)
//		for (W = 0; W <= Graph->Nv; W++)
//			Graph->G[V][W] = INFINITY;
//
//	return Graph;
//}
//
//void InsertEdge(MGraph Graph, Edge E)
//{
//	/* ����� <V1, V2> */
//	Graph->G[E->V1][E->V2] = 1;
//	/* ��������ͼ����Ҫ�����<V2, V1> */
//	//Graph->G[E->V2][E->V1] = 1;  
//}
//
//MGraph BuildGraph()
//{
//	MGraph Graph;
//	Edge E;
//	Vertex V;
//	int Nv, i;
//
//	cin >> Nv;   // ���붥���� 
//	Graph = CreateGraph(Nv);  // ��ʼ����Nv�����㵫û�бߵ�ͼ
//
//	cin >> (Graph->Ne);  // ������� 
//	if (Graph->Ne != 0)  // ����б�
//	{
//		E = (Edge)malloc(sizeof(struct ENode));  // �����߽��
//		for (i = 0; i < Graph->Ne; i++)
//		{
//			cin >> E->V1 >> E->V2;// ����ߣ���ʽΪ"��� �յ�"�������ڽӾ��� 
//			InsertEdge(Graph, E);
//		}
//	}
//
//	return Graph;
//}
//
//int IsEmpty(Queue Q) 
//{
//	return(Q->front == NULL);
//};
//
//Queue CreateQueue() 
//{
//	Queue PtrQ;
//	PtrQ = (Queue)malloc(sizeof(struct QNode));
//	struct Node *rear;
//	struct Node *front;
//	rear = (Node*)malloc(sizeof(struct Node));
//	rear = NULL;
//	front = (Node*)malloc(sizeof(struct Node));
//	front = NULL;
//	PtrQ->front = front;
//	PtrQ->rear = rear;
//	return PtrQ;
//};
//
//int DeleteQ(Queue PtrQ) 
//{
//	struct Node *FrontCell;
//	int FrontElem;
//
//	if (IsEmpty(PtrQ)) 
//	{
//		cout << "���п�" << endl;
//		return ERROR;
//	}
//	FrontCell = PtrQ->front;
//	if (PtrQ->front == PtrQ->rear)
//		PtrQ->front = PtrQ->rear = NULL;
//	else {
//		PtrQ->front = PtrQ->front->Next;
//	}
//	FrontElem = FrontCell->Data;
//	free(FrontCell);
//	return FrontElem;
//}
//
//void InsertQ(int item, Queue PtrQ)
//{
//	struct Node *FrontCell;
//	FrontCell = (Node*)malloc(sizeof(struct Node));
//	FrontCell->Data = item;
//	FrontCell->Next = NULL;
//
//	if (IsEmpty(PtrQ))
//	{
//		PtrQ->front = FrontCell;
//		PtrQ->rear = FrontCell;
//	}
//	else {
//		PtrQ->rear->Next = FrontCell;
//		PtrQ->rear = FrontCell;
//	}
//};
//
///* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
///* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
///* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
//bool IsEdge(MGraph Graph, Vertex V, Vertex W)
//{
//	return Graph->G[V][W] < INFINITY ? true : false;
//}
//
//// ��SΪ��������ڽӾ���洢��ͼGraph����BFS����
//void Unweighted(MGraph Graph, Vertex S)
//{
//	// dist[]��path[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊ-1
//	Queue Q = CreateQueue(); // �����ն���, MaxSizeΪ�ⲿ����ĳ���
//	Vertex V, W;
//
//	// ���ʶ���S
//	dist[S] = 0;  // ���S�ѷ���
//	InsertQ(S, Q); // S�����
//
//	while (!IsEmpty(Q))
//	{
//		V = DeleteQ(Q);  // ����V
//		for (W = 1; W <= Graph->Nv; W++) // ��V��ÿ���ڽӵ�W->AdjV
//			if ((dist[W] == -1) && (IsEdge(Graph, V, W)))    // ��W->AdjVδ������
//			{
//				dist[W] = dist[V] + 1;
//				cout << "�� " << W << " ��Դ�� " << S << " ����̾����ǣ�" << dist[W];
//				// ���ʶ���W
//				path[W] = V;
//				cout << "  ����һ���ڵ��ǣ�" << path[W] << endl;
//				InsertQ(W, Q); // W�����
//			}
//	} /* while����*/
//}
//
//int main() 
//{
//	MGraph Graph = BuildGraph();
//
//	for (int i = 1; i <= MaxVertexNum; i++)
//	{
//		Visited[i] = false;
//		dist[i] = path[i] = -1;
//	}
//	Unweighted(Graph, 3);
//	system("pause");
//	return 0;
//}