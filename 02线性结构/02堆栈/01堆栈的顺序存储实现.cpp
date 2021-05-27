#include<iostream>
using namespace std;
#define MaxSize 100   // ��ջԪ�ص������� 
typedef int ElementType; // ElementType ��ʱ����Ϊ int ���� 
typedef struct SNode *Stack;
struct SNode {
	ElementType Data[MaxSize];   // �洢��ջԪ��
	int Top;  // ��¼ջ��Ԫ���±� 
};
Stack S;

Stack CreateStack();  // ��ʼ����ջ 
int IsFull(Stack S); // �ж϶�ջ�Ƿ����� 
int IsEmpty(Stack S);  // �ж϶�ջ�Ƿ�Ϊ�� 
void Push(Stack S, ElementType item);  // ��ջ 
ElementType Pop(Stack S);  // ��ջ

// ��ʼ����ջ 
Stack CreateStack() {
	S = (Stack)malloc(sizeof(struct SNode));
	S->Top = -1;
	return S;
}

// �Ƿ����� 
int IsFull(Stack S) {
	return (S->Top == MaxSize - 1);
}

// �Ƿ�Ϊ�� 
int IsEmpty(Stack S) {
	return (S->Top == -1);
}

// ��ջ 
void Push(Stack S, ElementType item) {
	if (IsFull(S)) {   // Top �� 0 ��ʼ 
		cout << "��ջ��" << endl;
		return;
	}
	else {
		S->Top++;   // ջ��Ԫ�ؼ�һ 
		S->Data[S->Top] = item;   // �Ž����� 
		return;
	}
}

// ��ջ
ElementType Pop(Stack S) {
	if (IsEmpty(S)) {
		cout << "��ջ��" << endl;
		return NULL;
	}
	else {
		ElementType val = S->Data[S->Top];  //ȡ������ 
		S->Top--;  // ջ��Ԫ�ؼ�һ 
		return val;
	}
}
int main() {
	S = CreateStack();

	cout << "1��ջ" << endl;
	Push(S, 1);

	cout << "2��ջ" << endl;
	Push(S, 2);

	cout << "3��ջ" << endl;
	Push(S, 3);

	cout << Pop(S) << "��ջ" << endl;

	cout << Pop(S) << "��ջ" << endl;

	system("pause");

	return 0;
}