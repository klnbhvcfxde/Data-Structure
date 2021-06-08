#include<iostream>
using namespace std;

#define MAXTABLESIZE 100000   // �����ٵ����ɢ�б��� 
typedef int Index;  // ɢ�е�ַ����
typedef int ElementType;  // �ؼ�������������
typedef Index Position;  // ��������λ����ɢ�е�ַ��ͬһ����

// ɢ�е�Ԫ״̬���ͣ��ֱ��Ӧ���кϷ�Ԫ�ء��յ�Ԫ������ɾ��Ԫ��
typedef enum {Legitimate, Empty, Deleted} EntryType;  // ���嵥Ԫ״̬���� 

typedef struct HashEntry Cell;  // ����ɢ�б�Ԫ����
struct HashEntry {   //  ��ϣ���ֵ��Ԫ 
	ElementType Data;  // ���Ԫ��
	EntryType Info;  // ��Ԫ״̬	
};

typedef struct HashTbl *HashTable;  // ɢ�б�����
struct HashTbl {  // ��ϣ��ṹ�� 
	int TableSize;   // �����󳤶� 
	Cell *Cells;   // ���ɢ�е�Ԫ���ݵ�����
};

int NextPrime(int N);  // �������� 
HashTable CreateTable(int TableSize); // ������ϣ�� 
Index Hash(int Key, int TableSize);   // ��ϣ���� 

// �������� 
int NextPrime(int N)  // ���ش���N�Ҳ�����MAXTABLESIZE����С����
{
	int p = (N % 2) ? N + 2 : N + 1;  // �Ӵ��� N ���¸�������ʼ
	int i;

	while (p <= MAXTABLESIZE) 
	{
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p%i))  // p �������� 
				break;
		if (i == 2)  // for����������˵��p������
			break;
		p += 2;  // ������̽�¸����� 
	}
	return p;
}

// ������ϣ�� 
HashTable CreateTable(int TableSize) 
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize = NextPrime(TableSize);  // ��֤ɢ�б���󳤶������� 
	H->Cells = (Cell *)malloc(sizeof(Cell)*H->TableSize);  // ��ʼ����Ԫ���� 
	for (int i = 0; i < H->TableSize; i++)  // ��ʼ����Ԫ����״̬Ϊ���յ�Ԫ��
		H->Cells[i].Info = Empty;
	return H;
}

// ƽ��̽����� 
Position Find(HashTable H, ElementType Key) 
{
	Position CurrentPos, NewPos;
	int CNum = 0;   // ��¼��ͻ����
	CurrentPos = NewPos = Hash(Key, H->TableSize);  // ��ʼɢ��λ��
 
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) // ����λ�õĵ�Ԫ�ǿգ����Ҳ���Ҫ�ҵ�Ԫ��ʱ��������ͻ
	{
		// ͳ��1�γ�ͻ�����ж���ż��
		if (++CNum % 2) { // ��ͻ�����η��� 
			NewPos = CurrentPos + (CNum + 1) / 2 * (CNum + 1) / 2;  // ����Ϊ+[(CNum+1)/2]^2
			while (H->TableSize <= NewPos)  // ���Խ�磬һֱ��ֱ���ٴν���߽�
			{
				NewPos -= H->TableSize;  // ����Ϊ�Ϸ���ַ
			}
		}
		else   // ��ͻż���η���
		{  
			NewPos = CurrentPos - CNum / 2 * CNum / 2;  // ����Ϊ-(CNum/2)^2 
			while (NewPos < 0)  // ���Խ�磬һֱ��ֱ���ٴν���߽�
			{
				NewPos += H->TableSize;  // ����Ϊ�Ϸ���ַ
			}
		}
	}
	return NewPos;  // ��ʱNewPos������Key��λ�ã�������һ���յ�Ԫ��λ�ã���ʾ�Ҳ�����
}

// ����
bool Insert(HashTable H, ElementType Key, int i) 
{
	Position Pos = Find(H, Key);  // �ȼ��Key�Ƿ��Ѿ�����
	if (H->Cells[Pos].Info != Legitimate)  // ��������Ԫû�б�ռ��˵��Key���Բ����ڴ� 
	{
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		return true;
	}
	else 
	{
		cout << "��ֵ�Ѵ���" << endl;
		return false;
	}
}

// ������������ϣ���� 
Index Hash(int Key, int TableSize) 
{
	return Key % TableSize;
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
		Insert(H, tmp, i);
	}
	for (int i = 0; i < H->TableSize; i++)
		cout << i << " " << H->Cells[i].Data << endl;
	system("pause");
	return 0;
}