//#include<iostream>
//using namespace std;
//
///* �ڽӾ��󴢴桪����Ȩͼ�ĵ�Դ���·�㷨 */
//
//#define ERROR 0        
//#define INFINITY 65535   // ����Ϊ˫�ֽ��޷������������ֵ65535      
//#define MaxVertexNum 100   //��󶥵�����Ϊ100     
//typedef int Vertex;   //�ö����±��ʾ����,Ϊ����
//typedef int WeightType;   //�ߵ�Ȩֵ��Ϊ����
//
//int Visited[MaxVertexNum];
//int dist[MaxVertexNum];
//int path[MaxVertexNum];
//
//// �ߵĶ���
//typedef struct ENode *PtrToENode;
//struct ENode {
//	Vertex V1, V2;   // �����<V1, V2>
//	WeightType Weight;  // Ȩ��
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
//	Graph->G[E->V1][E->V2] = E->Weight;
//	/* ��������ͼ����Ҫ�����<V2, V1> */
//	//Graph->G[E->V2][E->V1] = 1;    
//}
//
//// ��ͼ 
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
//	cin >>(Graph->Ne);  // ������� 
//	if (Graph->Ne != 0)  // ����б�
//	{
//		E = (Edge)malloc(sizeof(struct ENode));  // �����߽��
//		for (i = 0; i < Graph->Ne; i++) 
//		{
//			cin >> E->V1 >> E->V2 >> E->Weight;// ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� 
//			InsertEdge(Graph, E);
//		}
//	}
//
//	return Graph;
//}
//
///* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
///* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
///* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
//bool IsEdge(MGraph Graph, Vertex V, Vertex W)
//{
//	return Graph->G[V][W] < INFINITY ? true : false;
//}
//
//// ����δ����¼�����е���Сdist��
//Vertex FindMinDist(MGraph Graph) 
//{
//	Vertex MinV, V;
//	int MinDist = INFINITY;
//
//	for (V = 1; V <= Graph->Nv; V++) 
//	{
//		if (Visited[V] == false && dist[V] < MinDist)  // ��Vδ����¼����dist[V]��С 
//		{
//			MinDist = dist[V];  // ������С����
//			MinV = V;  // ������С����
//		}
//	}
//	if (MinDist < INFINITY)  // ���ҵ���Сdist
//		return MinV;  // ���ض�Ӧ�Ķ����±�
//	else return ERROR;  // �������Ķ��㲻���ڣ����ش�����
//}
//
//// ��SΪ��������ڽӾ���洢��ͼGraph����BFS����
//bool Dijkstra(MGraph Graph, Vertex S)
//{
//	Vertex V, W;
//
//	// ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ
//	for (V = 1; V <= Graph->Nv; V++) 
//	{
//		dist[V] = Graph->G[S][V];
//		if (dist[V] < INFINITY)
//			path[V] = S;
//		else
//			path[V] = -1;
//		Visited[V] = false;
//	}
//	// �Ƚ�������뼯��
//	dist[S] = 0;
//	Visited[S] = true;
//
//	while (1)
//	{
//		// �ҵ�δ�����붥����dist��С��
//		V = FindMinDist(Graph);
//		if (V == ERROR)  // ��������V������
//			break;  //�㷨����  
//		Visited[V] = true;  //��¼V  
//
//		for (W = 1; W <= Graph->Nv; W++)  //��ͼ��ÿ������W  
//			if (Visited[W] == false && Graph->G[V][W] < INFINITY)  //��Wδ����¼������V���ڽӵ�
//			{  
//				if (Graph->G[V][W] < 0)  //���и���  
//					return false;  //������ȷ��������ش�����  
//				if (dist[V] + Graph->G[V][W] < dist[W])  //����¼Vʹ��dist[W]��С  
//				{
//					dist[W] = dist[V] + Graph->G[V][W];  //����dist[W]  
//					path[W] = V;  //����S��W��·��  
//				}
//			}
//	}/*while����*/
//	return true;  //�㷨ִ����ϣ�������ȷ���
//}
//
//int main() 
//{
//	MGraph Graph = BuildGraph();
//
//	for (int i = 1; i <= MaxVertexNum; i++) 
//	{ 
//		Visited[i] = false; 
//		dist[i] = INFINITY; 
//		path[i] = -1; 
//	}
//	Dijkstra(Graph, 1);
//	for (int i = 1; i <= Graph->Nv; i++) 
//	{
//		cout << "�� " << i << " ��Դ�� 1 ����̾����ǣ�" << dist[i] << "  ��һ������ǣ�" << path[i] << endl;
//	}
//	system("pause");
//	return 0;
//}