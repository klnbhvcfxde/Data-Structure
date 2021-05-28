#include<iostream>
using namespace std;
#define MaxSize 100
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode {
	ElementType Data[MaxSize];
	int front;   // ��¼��ͷ 
	int rear;    // ��¼��β 
};
Queue Q;

Queue CreateQueue();  // ��ʼ������ 
void AddQ(Queue Q, ElementType item);  //  ���
int IsFull(Queue Q); // �ж϶����Ƿ����� 
ElementType DeleteQ(Queue Q);  // ���� 
int IsEmpty(Queue Q); // �ж϶����Ƿ�Ϊ�� 

// ��ʼ�� 
Queue CreateQueue() {
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

// �ж϶����Ƿ�����
int IsFull(Queue Q) {
	return ((Q->rear + 1) % MaxSize == Q->front);
}

// ��� 
void AddQ(Queue Q, ElementType item) {
	if (IsFull(Q)) {
		cout << "������" << endl;
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MaxSize;  //front��rearָ����ƶ����á���1ȡ�ࡱ��,������˳��洢�ġ�ѭ��ʹ�á�
		Q->Data[Q->rear] = item;
	}
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(Queue Q) {
	return (Q->front == Q->rear);
}

// ����
ElementType DeleteQ(Queue Q) {
	if (IsEmpty(Q)) {
		cout << "���п�" << endl;
		return 0;
	}
	else {
		Q->front = (Q->front + 1) % MaxSize;
		return Q->Data[Q->front];
	}
}

int main() {
	Q = CreateQueue();

	AddQ(Q, 1);
	cout << "1���" << endl;

	AddQ(Q, 2);
	cout << "2���" << endl;

	AddQ(Q, 3);
	cout << "3���" << endl;

	cout << DeleteQ(Q) << "����" << endl;
	cout << DeleteQ(Q) << "����" << endl;

	system("pause");

	return 0;
}