#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode {
	ElementType Data;
	Stack Next;
};
Stack S;

Stack CreateStack();  // ��ʼ����ջ 
int IsEmpty(Stack S);  // �ж���ջ�Ƿ�Ϊ�� 
void Push(Stack S, ElementType item);  // ��ջ 
ElementType Pop(Stack S);  // ��ջ


// ��ʼ�� 
Stack CreateStack() {
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

// �ж��Ƿ�Ϊ�� 
int IsEmpty(Stack S) {
	return (S->Next == NULL);
}

// ��ջ
void Push(Stack S, ElementType item) {
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Data = item;
	// ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ��� 
	tmp->Next = S->Next;
	S->Next = tmp;
}

// ��ջ
ElementType Pop(Stack S) {
	Stack First;
	ElementType TopVal;
	if (IsEmpty(S)) {
		cout << "��ջ��" << endl;
		return NULL;
	}
	else {
		First = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ��� 
		S->Next = First->Next;  //�ѵ�һ��Ԫ�ش���ջɾ�� 
		TopVal = First->Data;   // ȡ����ɾ������ֵ 
		free(First);  // �ͷſռ� 
		return TopVal;
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