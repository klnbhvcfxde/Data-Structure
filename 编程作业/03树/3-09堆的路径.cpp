#include<iostream>
using namespace std;
const int MinData = -100000;  // �ڱ�ֵ
const int MaxSize = 1005;   // ������ 
typedef struct HeapStruct *Heap;
struct HeapStruct {
	int *data;   // ��ֵ������ 
	int size;   // ��ǰԪ�ظ��� 
	int capacity;  // ������� 
};

// ��ʼ����
Heap Create()
{
	Heap H;
	H = (Heap)malloc(sizeof(struct HeapStruct));
	H->data = (int *)malloc(sizeof(int) * (MaxSize + 1));
	H->size = 0;
	H->capacity = MaxSize;
	H->data[0] = MinData;
	return H;
}

// ����
void Insert(Heap H, int x)
{
	int i = ++H->size;  // ָ���������һ�� 
	for (; H->data[i / 2] > x; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = x;
}

// ��ӡ·�� 
void Print(Heap H, int i)
{
	for (; i > 0; i /= 2)
	{
		cout << H->data[i];
		if (i != 1)
			cout << " ";
	}
	cout << endl;
}

int main()
{
	Heap H;
	H = Create();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		Insert(H, t);
	}
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		Print(H, t);
	}
	system("pause");
	return 0;
}