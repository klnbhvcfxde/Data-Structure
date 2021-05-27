#include<iostream>
using namespace std;
#define MaxSize 100   // ��ջԪ�ص������� 
typedef int ElementType; // ElementType ��ʱ����Ϊ int ���� 
typedef struct DStack *Stack;
struct DStack {
	ElementType Data[MaxSize];   // �洢��ջԪ��
	int Top1; //��ջ1��ջ��ָ��
	int Top2; //��ջ2��ջ��ָ��
};
Stack S;

Stack CreateStack();  // ��ʼ����ջ 
void Push(Stack S, ElementType item, int Tag);  // ��ջ 
ElementType Pop(Stack S, int Tag);  // ��ջ

// ��ʼ����ջ 
Stack CreateStack() 
{
	S = (Stack)malloc(sizeof(struct DStack));
	S->Top1 = -1;
	S->Top2 = MaxSize;
	return S;
}

// ��ջ 
void Push(Stack S, ElementType item, int Tag)  //Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2
{
	if (S->Top2 - S->Top1 == 1) 
	{  
		cout << "��ջ��" << endl;
		return;
	}
	if (Tag == 1)   //�Ե�һ����ջ���в���
	{
		S->Data[++(S->Top1)] = item;
	}
	else {  //�Եڶ�����ջ���в���
		S->Data[--(S->Top2)] = item;
	}
}

// ��ջ
ElementType Pop(Stack S, int Tag) 
{
	if (Tag == 1)  //�Ե�һ����ջ���в���
	{
		if (S->Top1 == -1)  //��ջ1Ϊ��
		{
			cout << "��ջ1��" << endl;
			return NULL;
		}
		else
			return S->Data[(S->Top1)--];
	}

	if (Tag == 2)  //�Եڶ�����ջ���в���
	{
		if (S->Top2 == MaxSize)  //��ջ2Ϊ��
		{
			cout << "��ջ2��" << endl;
			return NULL;
		}
		else
			return S->Data[(S->Top2)++];
	}
}
int main() {
	S = CreateStack();

	cout << "1��ջ1" << endl;
	Push(S, 1, 1);

	cout << "2��ջ1" << endl;
	Push(S, 2, 1);

	cout << "3��ջ1" << endl;
	Push(S, 3, 1);

	cout << "1��ջ2" << endl;
	Push(S, 1, 2);

	cout << "2��ջ2" << endl;
	Push(S, 2, 2);

	cout << "3��ջ2" << endl;
	Push(S, 3, 2);

	cout << Pop(S,1) << "��ջ1" << endl;

	cout << Pop(S,2) << "��ջ2" << endl;

	system("pause");

	return 0;
}