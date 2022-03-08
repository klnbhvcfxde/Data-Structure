#include<iostream>
using namespace std;
const int MaxData = 100000;  // �ڱ�ֵ
const int MaxSize = 1005;   // ������ 
using namespace std;
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
	int *data;   // ��ֵ������ 
	int size;   // ��ǰԪ�ظ��� 
	int capacity;  // ������� 
};

// ��ʼ����
MaxHeap Create_T() 
{
	MaxHeap H;
	H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->data = (int *)malloc(sizeof(int) * (MaxSize + 1));
	H->size = 0;
	H->capacity = MaxSize;
	H->data[0] = MaxData;
	return H;
}

// �ж��Ƿ��Ѿ��� 
bool IsFull(MaxHeap H)
{
	return (H->size == H->capacity);
}

// �ж��Ƿ�Ϊ��
bool IsEmpty(MaxHeap H)
{
	return !H->size;
}

// ����
void Insert(MaxHeap H, int x) 
{
	if (IsFull(H)) 
	{
		cout << "�����������޷����룡" << endl;
		return;
	}
	int i = ++H->size;  // ָ���������һ�� 
	for (; H->data[i / 2] < x; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = x;
}

// ���� 
void Traversal(MaxHeap H) 
{
	for (int i = 1; i <= H->size; i++)
		cout << H->data[i] << " ";
	cout << endl;
}

int main() 
{
	MaxHeap H;
	H = Create_T();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		int t;
		cin >> t;
		Insert(H, t);
	}
	Traversal(H);
	return 0;
}