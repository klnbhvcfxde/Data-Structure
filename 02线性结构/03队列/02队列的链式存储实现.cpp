#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct QNode *Queue;
struct Node {
	ElementType Data;
	struct Node *Next;
};
struct QNode {
	struct Node *rear;    // ָ���β��� 
	struct Node *front;   // ָ���ͷ��� 
};
Queue Q;

Queue CreateQueue();  // ��ʼ������ 
void AddQ(Queue Q, ElementType item);  //  ���
ElementType DeleteQ(Queue Q);  // ���� 
int IsEmpty(Queue Q); // �ж϶����Ƿ�Ϊ�� 

// ��ʼ�� 
Queue CreateQueue() {
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// �Ƿ�Ϊ�� 
int IsEmpty(Queue Q) {
	return (Q->front == NULL);
}

// ���
void AddQ(Queue Q, ElementType item) {
	struct Node *node;
	node = (struct Node *)malloc(sizeof(struct Node));
	node->Data = item;
	node->Next = NULL;
	if (Q->rear == NULL) {  //��ʱ���п� 
		Q->rear = node;
		Q->front = node;
	}
	else { //��Ϊ�� 
		Q->rear->Next = node;  // �������� 
		Q->rear = node;   // rear ��Ȼ������� 
	}
}

// ����
ElementType DeleteQ(Queue Q) {
	struct Node *FrontCell;
	ElementType FrontElem;
	if (IsEmpty(Q)) {
		cout << "���п�" << endl;
		return 0;
	}
	FrontCell = Q->front;
	if (Q->front == Q->rear) { // ������ֻ��һ��Ԫ�� 
		Q->front = Q->rear = NULL;
	}
	else {
		Q->front = Q->front->Next;
	}
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
}

int main() {
	Q = CreateQueue();

	cout << "���1" << endl;
	AddQ(Q, 1);

	cout << "���2" << endl;
	AddQ(Q, 2);

	cout << "���3" << endl;
	AddQ(Q, 3);

	cout << "����" << DeleteQ(Q) << endl;
	cout << "����" << DeleteQ(Q) << endl;
	cout << "����" << DeleteQ(Q) << endl;
	cout << DeleteQ(Q) << endl;

	system("pause");

	return 0;
}