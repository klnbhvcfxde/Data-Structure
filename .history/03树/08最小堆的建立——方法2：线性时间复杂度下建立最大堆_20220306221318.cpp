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

// �������ƶѵ�"ɾ������" 
void sort(MaxHeap H, int i)  //���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ����
{
	int Child, Parent;
	int temp = H->data[i];  // �õ���ǰ"������ֵ" 
	for (Parent = i; Parent * 2 <= H->size; Parent = Child) 
	{
		Child = 2 * Parent;
		if ((Child != H->size) && (H->data[Child] < H->data[Child + 1]))
			Child++;  //Childָ�������ӽ��Ľϴ���
		if (temp >= H->data[Child])
			break;
		else
			H->data[Parent] = H->data[Child];
	}
	H->data[Parent] = temp;
}

// ������(����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������)
void BuildHeap(MaxHeap H) 
{
	for (int i = H->size / 2; i > 0; i--)  //�����һ�����ĸ��ڵ㿪ʼ���������1
	{
		// ��ÿ���к��ӽ��Ľ����Ϊ����㣬�����������ж����� 
		sort(H, i);
	}
}

// ���� 
void Traversal(MaxHeap H) 
{
	for (int i = 1; i <= H->size; i++) 
	{
		cout << H->data[i] << " ";
	}
	cout << endl;
}

int main() 
{
	MaxHeap H;
	H = Create_T();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> H->data[++H->size];
	BuildHeap(H);
	Traversal(H);
	system("pause");
	return 0;
}