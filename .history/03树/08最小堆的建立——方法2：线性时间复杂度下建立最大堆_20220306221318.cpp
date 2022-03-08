#include<iostream>
using namespace std;
const int MaxData = 100000;  // 锟节憋拷值
const int MaxSize = 1005;   // 锟斤拷锟斤拷锟斤拷 
using namespace std;
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
	int *data;   // 锟斤拷值锟斤拷锟斤拷锟斤拷 
	int size;   // 锟斤拷前元锟截革拷锟斤拷 
	int capacity;  // 锟斤拷锟斤拷锟斤拷锟� 
};

// 锟斤拷始锟斤拷锟斤拷
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

// 锟斤拷锟斤拷锟斤拷锟狡堆碉拷"删锟斤拷锟斤拷锟斤拷" 
void sort(MaxHeap H, int i)  //锟斤拷锟剿ｏ拷锟斤拷H锟斤拷锟斤拷H->Data[p]为锟斤拷锟斤拷锟接堆碉拷锟斤拷为锟斤拷锟斤拷
{
	int Child, Parent;
	int temp = H->data[i];  // 锟矫碉拷锟斤拷前"锟斤拷锟斤拷锟斤拷值" 
	for (Parent = i; Parent * 2 <= H->size; Parent = Child) 
	{
		Child = 2 * Parent;
		if ((Child != H->size) && (H->data[Child] < H->data[Child + 1]))
			Child++;  //Child指锟斤拷锟斤拷锟斤拷锟接斤拷锟侥较达拷锟斤拷
		if (temp >= H->data[Child])
			break;
		else
			H->data[Parent] = H->data[Child];
	}
	H->data[Parent] = temp;
}

// 锟斤拷锟斤拷锟斤拷(锟斤拷锟斤拷H->Data[]锟叫碉拷元锟截ｏ拷使锟斤拷锟斤拷锟斤拷锟窖碉拷锟斤拷锟斤拷锟斤拷)
void BuildHeap(MaxHeap H) 
{
	for (int i = H->size / 2; i > 0; i--)  //锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷母锟斤拷诘憧�始锟斤拷锟斤拷锟斤拷锟斤拷锟�1
	{
		// 锟斤拷每锟斤拷锟叫猴拷锟接斤拷锟侥斤拷锟斤拷锟轿�锟斤拷锟斤拷悖�锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟叫讹拷锟斤拷锟斤拷 
		sort(H, i);
	}
}

// 锟斤拷锟斤拷 
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
	return 0;
}