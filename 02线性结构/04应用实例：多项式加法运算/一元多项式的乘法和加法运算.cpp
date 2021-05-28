#include<iostream> 
using namespace std;

typedef struct PolyNode {
	int coef;//ϵ�� 
	int exp;//ָ�� 
	struct PolyNode *next;
} *Polynomial;

Polynomial read(Polynomial P);
void print(Polynomial P);
Polynomial getMuti(Polynomial P1, Polynomial P2);
Polynomial getAdd(Polynomial P1, Polynomial P2);

Polynomial read(Polynomial P) 
{
	Polynomial s = NULL, temp;
	P = (struct PolyNode*)malloc(sizeof(struct PolyNode));
	temp = P;
	int n, COEF, EXP;
	cout << "����ʽ��������";
	cin >> n;
	cout << "����ʽÿ���Ӧ��ϵ����ָ����";
	for (int i = 0; i < n; i++) 
	{
		cin >> COEF >> EXP;
		if (COEF != 0) 
		{
			s = (struct PolyNode *)malloc(sizeof(struct PolyNode));
			s->coef = COEF; 
			s->exp = EXP;
			P->next = s;
			P = s;
		}
	}
	P->next = NULL;
	return temp;
}


void print(Polynomial P) 
{
	int num = 0, temp = 0;  //temp����ͳ��P�����ж��ٸ�Ԫ�أ�num ����ͳ���ж��ٸ�ϵ��Ϊ0���� 
	Polynomial val = P;
	while (val->next) 
	{
		val = val->next;
		temp++;
	}
	if (P->next != NULL) 
	{
		while (P->next) 
		{
			if (P->next->coef != 0) 
			{
				cout << P->next->coef << " " << P->next->exp;
				Polynomial val = P->next;
				while (val->next&&val->next->coef == 0) 
				{
					val = val->next;
				}
				if (val->next == NULL)
					cout << endl;
				else
					cout << " ";
			}
			else
				num++;
			P = P->next;
		}
		if (num == temp)
			cout << 0 << " " << 0 << endl;
	}
	else
		cout << 0 << " " << 0 << endl;
}


Polynomial getAdd(Polynomial P1, Polynomial P2) 
{
	Polynomial P, temp = NULL, s = NULL;
	P = (struct PolyNode *)malloc(sizeof(struct PolyNode));
	temp = P;

	while (P1->next&&P2->next) 
	{
		if (P1->next->exp > P2->next->exp) 
		{
			s = (struct PolyNode *)malloc(sizeof(struct PolyNode));
			s->coef = P1->next->coef;
			s->exp = P1->next->exp;
			P->next = s;
			P = s;
			P1 = P1->next;
		}
		else if (P1->next->exp < P2->next->exp) 
		{
			s = (struct PolyNode *)malloc(sizeof(struct PolyNode));
			s->coef = P2->next->coef;
			s->exp = P2->next->exp;
			P->next = s;
			P = s;
			P2 = P2->next;
		}
		else 
		{
			s = (struct PolyNode *)malloc(sizeof(struct PolyNode));
			s->coef = P2->next->coef + P1->next->coef;
			s->exp = P2->next->exp;
			P->next = s;
			P = s;
			P1 = P1->next;
			P2 = P2->next;
		}
	}
	if (P1->next)
		P->next = P1->next;
	else
		P->next = P2->next;
	return temp;
}


Polynomial getMuti(Polynomial P1, Polynomial P2) {
	/*
	���������ǲ��õ��ǣ�������롣
	1�����ó�P2�ĵ�һ�������P1��ÿһ����ˣ��Ӷ��õ�P
	2�����ó�P2�ĵڶ��������P1��ÿһ����ˣ�Ȼ��ÿ��һ��ͽ�����뵽P��
	3�������ظ�����Ĳ��裬���յõ�P�������ӡ����
	*/
	Polynomial P, temp = NULL, s = NULL;
	P = (struct PolyNode *)malloc(sizeof(struct PolyNode));
	temp = P;
	Polynomial Pa = P1;

	//�ó�P2�ĵ�һ�������P1��ÿһ�����,�Ӷ��õ�P
	while (Pa->next) {
		s = (struct PolyNode *)malloc(sizeof(struct PolyNode));
		s->coef = Pa->next->coef * P2->next->coef;  //P1��ÿһ����P2�ĵ�һ���ϵ�����
		s->exp = Pa->next->exp + P2->next->exp;  //P1��ÿһ����P2�ĵ�һ���ָ�����
		P->next = s;
		P = s;
		Pa = Pa->next;
	}
	P->next = NULL;
	P = temp;
	Polynomial Pb = P2->next;
	while (Pb&&Pb->next) 
	{
		Pa = P1;
		while (Pa->next) 
		{
			s = (struct PolyNode *)malloc(sizeof(struct PolyNode));
			s->coef = Pa->next->coef * Pb->next->coef;
			s->exp = Pa->next->exp + Pb->next->exp;
			while (P->next) 
			{
				if (s->exp > P->next->exp) 
				{
					Polynomial val = P->next;
					P->next = s;
					s->next = val;
					break;
				}
				else if (s->exp == P->next->exp)
				{
					P->next->coef += s->coef;
					break;
				}
				P = P->next;
			}
			if (P->next == NULL) 
			{
				P->next = s;
				s->next = NULL;
			}
			P = temp;
			Pa = Pa->next;
		}
		Pb = Pb->next;
	}
	return temp;
}

int main() 
{
	Polynomial P1 = NULL;
	Polynomial P2 = NULL;
	Polynomial P = NULL;
	cout << "P1��" << endl;
	P1 = read(P1);
	cout << "P2��" << endl;
	P2 = read(P2);

	cout << "P1*P2��";
	P = getMuti(P1, P2);
	print(P);

	cout << "P1+P2��";
	P = getAdd(P1, P2);
	print(P);

	system("pause");
	return 0;
}