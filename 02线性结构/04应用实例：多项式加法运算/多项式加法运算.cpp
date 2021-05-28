#include<iostream>
using namespace std;

struct PolyNode {
	int coef;  //ϵ��
	int expon;  //ָ��
	struct PolyNode *link;  //ָ����һ���ڵ��ָ��
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

Polynomial PolyAdd(Polynomial P1, Polynomial P2);
void Attach(int c, int e, Polynomial *pRear);
int Compare(int a, int b);
void PrintPoly(Polynomial P);

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));  //Ϊ�����ͷ���룬�Ȳ���һ����ʱ�ս����Ϊ�������ʽ����ͷ
	front = rear;  //��front��¼�������ʽ����ͷ���
	while (P1 && P2)  //����������ʽ���з����������ʱ
	{
		switch (Compare(P1->expon, P2->expon))
		{
		case 1:  //P1�е�������ָ���ϴ�
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1:  //P2�е�������ָ���ϴ�
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
			break;
		case 0:  //��������ָ�����
			sum = P1->coef + P2->coef;
			if (sum)  //ע���ж�ϵ�����Ƿ�Ϊ0
				Attach(sum, P1->expon, &rear);
			P1 = P1->link;
			P2 = P2->link;
			break;
		}
	}
	//��δ���������һ������ʽ�����нڵ����θ��Ƶ��������ʽ��ȥ
	for (; P1; P1 = P1->link)  //P1��Ϊ��
		Attach(P1->coef, P1->expon, &rear);
	for (; P2; P2 = P2->link)  //P2��Ϊ��
		Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;  //��frontָ��������ʽ��һ��������
	free(temp);  //�ͷ���ʱ�ձ�ͷ���
	return front;
}

int Compare(int a, int b) 
{
	if (a > b)
		return 1;
	else if (a < b) 
		return -1;
	else 
		return 0;
}

// ����һ���ڵ�
void Attach(int c, int e, Polynomial *pRear)  //�����ڱ���������Ҫ�ı䵱ǰ������ʽβ��ָ���ֵ�����Ժ������ݽ������ǽ��ָ��ĵ�ַ��*pRearָ��β��
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));  //�����½��
	P->coef = c;  //���½�㸳ֵ
	P->expon = e;
	P->link = NULL;  
	//��Pָ����½����뵽��ǰ������ʽβ��ĺ���
	(*pRear)->link = P;  // β�ڵ�ָ��P
	*pRear = P;  //�޸�pRearָ��ָ���ֵ
}

void PrintPoly(Polynomial P)
{
	Polynomial tmp = P;
	for (; tmp; tmp = tmp->link)
	{ 
		cout << tmp->coef << "  " << tmp->expon << "    ";
	}
	cout << endl;
}

int main()
{
	int P1Coef[5] = { 3, 4, -1, 2, -1 };
	int P1expon[5] = { 5, 4, 3, 1, 0 };
	int P2Coef[4] = { 2, 1, -7, 1 };
	int P2expon[4] = { 4, 3, 2, 1 };

	P1 = (Polynomial)malloc(sizeof(struct PolyNode));
	P2 = (Polynomial)malloc(sizeof(struct PolyNode));

	Polynomial P1Rear;
	P1Rear = P1;

	Polynomial P2Rear;
	P2Rear = P2;

	for (int i = 0; i < 5; ++i)
	{
		Attach(P1Coef[i], P1expon[i], &P1Rear); // ע�����ﴫ���ǵ�ַ������
	}
	P1 = P1->link; // ��Ϊ��һ���ڵ�û�д洢���ݣ����� P1 Ҫ����Ųһλ

	for (int i = 0; i < 4; ++i)
	{
		Attach(P2Coef[i], P2expon[i], &P2Rear);
	}
	P2 = P2->link;

	Polynomial res = PolyAdd(P1, P2);

	cout << "P1��   ";
	PrintPoly(P1);
	cout << "P2��   ";
	PrintPoly(P2);
	cout << "P1+P2��";
	PrintPoly(res);

	system("pause");

	return 0;
}