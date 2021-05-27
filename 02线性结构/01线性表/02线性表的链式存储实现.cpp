#include<iostream>
using namespace std;
typedef int ElementType; // ElementType �ɶ���Ϊ��������
typedef struct LNode *List;
struct LNode 
{
	ElementType Data;   //������ 
	List Next;   // ��һ������ĵ�ַ 
};
List L;

List MakeEmpty(); //��ʼ������ 
int Length(List L);  // �Ա�������ķ����������� 
List FindKth(int K, List L);  // ����Ų��� 
List Find(ElementType X, List L);  // ��ֵ���� 
List Insert(ElementType X, int i, List L);  //�� X ���뵽�� i-1(i>0) �����֮�� 
List Delete(int i, List L); // ɾ���� i(i>0) ����� 
void Print(List L); // �������Ԫ�� 

// ��ʼ������ 
List MakeEmpty() 
{
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	return L;
}

//��� 
int Length(List L) 
{
	List p = L;
	int len = 0;
	while (p)  // �� p ��Ϊ�� 
	{   
		p = p->Next;
		len++;
	}
	return len;
}

// ������� 
List FindKth(int K, List L) 
{
	List p = L;
	int i = 1;  //�� 1 ��ʼ 
	while (p && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K)    // �ҵ��� 
		return p;
	else    // δ�ҵ� 
		return NULL;
}

// ��ֵ����  
List Find(ElementType X, List L) {
	List p = L;
	while (p && p->Data != X)
		p = p->Next;
	// �ҵ��ˣ����� p
	// δ�ҵ������� NULL����ʱ p ���� NULL 
	return p;
}

/* ����
1. �� s ָ��һ���µĽ��
2. �� p ָ������ĵ� i-1 �����
3. s->Next = p->Next���� s ����һ�����ָ�� p ����һ�����
4. p->Next = s���� p ����һ����Ϊ s   */
List Insert(ElementType X, int i, List L) {
	List p, s;
	if (i == 1) {     // �½������ڱ�ͷ 
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = L;
		return s;     //����Ľ��Ϊͷ��� 
	}
	p = FindKth(i - 1, L);   // �ҵ��� i-1 �����
	if (!p) {   // �� i-1 ����㲻���� 
		cout << "������" << endl;
		return NULL;
	}
	else {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;   //�� s ����һ�����ָ�� p ����һ����� 
		p->Next = s;   // �� p ����һ����Ϊ s
		return L;
	}
}

/* ɾ��
1. �� p ָ������ĵ� i-1 �����
2. �� s ָ��Ҫ��ɾ���ĵĵ� i �����
3. p->Next = s->Next��p ָ��ָ�� s ����
4. free(s)���ͷſռ�
*/
List Delete(int i, List L) {
	List p, s;
	if (i == 1) {   //���Ҫɾ��ͷ��� 
		s = L;
		if (L)   // �����Ϊ�� 
			L = L->Next;
		else
			return NULL;
		free(s);   // �ͷű�ɾ����� 
		return L;
	}
	p = FindKth(i - 1, L);    // ���ҵ� i-1 �����
	if (!p || !(p->Next)) {     // �� i-1 ����� i ����㲻���� 
		cout << "������" << endl;
		return NULL;
	}
	else {
		s = p->Next;    // s ָ��� i ����� 
		p->Next = s->Next;  //������ɾ�� 
		free(s);  // �ͷű�ɾ����� 
		return L;
	}
}

// �������Ԫ�� 
void Print(List L) 
{
	List t;
	int flag = 1;
	cout << "��ǰ����Ϊ��";
	for (t = L; t; t = t->Next) 
	{
		cout << t->Data << " ";
		flag = 0;
	}
	if (flag)
		cout << "NULL";
	cout << endl;
}

int main() 
{
	L = MakeEmpty();
	Print(L);

	L = Insert(11, 1, L);
	L = Insert(25, 1, L);
	L = Insert(33, 2, L);
	L = Insert(77, 3, L);
	Print(L);

	cout << "��ǰ������Ϊ��" << Length(L) << endl;

	cout << "��ʱ�����еڶ�������ֵ�ǣ�" << FindKth(2, L)->Data << endl;
	cout << "����22�Ƿ��ڸ������У�";
	if (Find(22, L))
		cout << "�ǣ�" << endl;
	else
		cout << "��" << endl;
	cout << "����33�Ƿ��ڸ������У�";
	if (Find(33, L))
		cout << "�ǣ�" << endl;
	else
		cout << "��" << endl;

	L = Delete(1, L);
	cout << "ɾ���������±�Ϊ1��Ԫ��" << endl;
	L = Delete(3, L);
	cout << "ɾ���������±�Ϊ3��Ԫ��" << endl;
	Print(L);

	system("pause");

	return 0;
}