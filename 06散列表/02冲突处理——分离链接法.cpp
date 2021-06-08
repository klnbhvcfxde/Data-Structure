#include<iostream>
using namespace std;

#define MAXTABLESIZE 100000   // �����ٵ����ɢ�б���
typedef int Index;  // ɢ�е�ַ����
typedef int ElementType;  // �ؼ�������������

// ������Ķ���
typedef struct LNode *PtrToLNode;
struct LNode {   // ������ 
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable;  // ɢ�б�
struct TblNode {  // ɢ�б��㶨��
	int TableSize;   // �����󳤶� 
	List Heads;  // ָ������ͷ�������� 
};

// �������� 
int NextPrime(int N) 
{
	int p = (N % 2) ? (N + 2) : (N + 1);   // �� tablesize ������� 
	int i;
	while (p <= MAXTABLESIZE) 
	{
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p%i))
				break;
		if (i == 2)  // �ҵ������� 
			break;
		p += 2; // ��һ������
	}
	return p;
}

// ������ϣ�� 
HashTable CreateTable(int TableSize) 
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(sizeof(struct TblNode) * H->TableSize);
	for (int i = 0; i < H->TableSize; i++)
		H->Heads[i].Next = NULL;  // ����ͷ��H->Heads[i] �ǲ��涫���� 
	return H;
}

// ������������ϣ���� 
Index Hash(int TableSize, ElementType Key) 
{
	return  Key % TableSize;
}

// ����
Position Find(HashTable H, ElementType Key) 
{
	Index pos = Hash(H->TableSize, Key);  // ��ʼɢ��λ��
	Position P = H->Heads[pos].Next;  // �Ӹ�����ĵ�1����㿪ʼ 
	while (P && P->Data != Key)  // ��δ����β������Keyδ�ҵ�ʱ
		P = P->Next;
	return P;  // ��ʱP����ָ���ҵ��Ľ�㣬����ΪNULL
}

// ����
bool Insert(HashTable H, ElementType Key) 
{
	Position P, NewCell;
	Index pos;

	P = Find(H, Key);
	if (!P)  // �ؼ���δ�ҵ������Բ��� 
	{
		NewCell = (Position)malloc(sizeof(struct LNode));
		NewCell->Data = Key;
		pos = Hash(H->TableSize, Key);   // ��ʼɢ�б��ַ
		NewCell->Next = H->Heads[pos].Next;  // ��NewCell����ΪH->Heads[Pos]����ĵ�1�����
		H->Heads[pos].Next = NewCell;
		return true;
	}
	else  // �ؼ����Ѵ���
	{
		cout << "��ֵ�Ѵ���" << endl;
		return false;
	}
}

void Print(HashTable H) 
{
	for (int i = 0; i < H->TableSize; i++) 
	{
		cout << i;
		List p = H->Heads[i].Next;
		while (p) 
		{
			cout << " " << p->Data;
			p = p->Next;
		}
		cout << endl;
	}
}

void DestroyTable(HashTable H) 
{
	Position P, tmp;
	for (int i = 0; i < H->TableSize; i++)  // �ͷ�ÿ������Ľ��
	{
		P = H->Heads[i].Next;
		while (P)
		{
			tmp = P->Next;
			free(P);
			P = tmp;
		}
	}
	free(H->Heads);  // �ͷ�ͷ�������
	free(H);  // �ͷ�ɢ�б���
}

int main() 
{
	HashTable H = CreateTable(9);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int tmp;
		cin >> tmp;
		Insert(H, tmp);
	}
	Print(H);
	DestroyTable(H);
	system("pause");
	return 0;
}