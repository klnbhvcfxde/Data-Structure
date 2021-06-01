#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List HeadCreatList() //ͷ�巨��������
{
	List L = (List)malloc(sizeof(PtrToNode));   //��ʼ���ձ�����һ��ͷ���
	L->Next = NULL;        //ͷָ��Ϊ��
	for (int i = 0; i < 2; i++) 
	{
		List p = (List)malloc(sizeof(struct Node));  //pָ��������Ľ��
		cout << "����Ҫ����ĵ�" << i + 1 << "��Ԫ�أ�";
		cin >> p->Data;
		p->Next = L->Next;
		L->Next = p;
	}
	return L;
}

List TailCreatList() //β�巨��������
{
	List L = (List)malloc(sizeof(PtrToNode));   //��ʼ���ձ�����һ��ͷ���
	L->Next = NULL;        //ͷָ��Ϊ��
	List last = L;     //lastΪָ��β����ָ��
	for (int i = 0; i < 2; i++)
	{
		List p = (List)malloc(sizeof(struct Node));  //pָ��������Ľ��
		cout << "����Ҫ����ĵ�" << i + 1 << "��Ԫ�أ�";
		cin >> p->Data;
		last->Next = p;
		last = p;  //lastָ��β���
	}
	last->Next = NULL;

	return L;
}

void Print(List L)
{
	if (L->Next)
	{
		List p = L;
		while (p->Next)
		{
			p = p->Next;
			cout << p->Data << " ";
		}
	}
	else
	{
		cout << "NULL";  //���������NULL 
	}
	cout << endl;
}

int main()
{
	//ͷ�巨
	cout << "ͷ�巨��������" << endl;
	List L1 = HeadCreatList();
	cout << "L1��";
	Print(L1);

	//β�巨
	cout << "β�巨��������" << endl;
	List L2 = TailCreatList();
	cout << "L2��";
	Print(L2);

	system("pause");

	return 0;
}