#include<iostream>
using namespace std;
#define MaxData 100000
#define ERROR -1
typedef int ElementType;
typedef struct HeapStruct*MaxHeap;
struct HeapStruct {
	ElementType *Elements;  //�洢��Ԫ�ص�����
	int Size;  //�ѵĵ�ǰԪ�ظ���
	int Capacity;  //�ѵ��������
};

MaxHeap Create_T(int MaxSize);  // ���� 
bool IsFull(MaxHeap H);    // �ж϶��Ƿ���
bool Insert(MaxHeap H, ElementType item);   // ����Ԫ��
bool IsEmpty(MaxHeap H);    //  �ж϶��Ƿ�Ϊ��
ElementType DeleteMax(MaxHeap H);  // ɾ�������ض������Ԫ��
void LevelOrderTraversal(MaxHeap H);  // ������� 

// ���� (��������ΪMaxSize�Ŀյ�����)
MaxHeap Create_T(int MaxSize) 
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	// Elements[0] ��Ϊ�ڱ�����Ԫ�ش�  Elements[1] ��ʼ��� 
	H->Elements = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;  // "�ڱ�"���ڶ������п��ܵ�ֵ 
	return H;
}

// ���룬����ȫ�����������һ��λ�ò��� 
bool Insert(MaxHeap H, ElementType item) 
{
	if (IsFull(H)) 
	{
		cout << "�����������޷����룡" << endl;
		return false;
	}
	int i = ++H->Size;  //iָ��������е����һ��Ԫ�ص�λ��
	for (; H->Elements[i / 2] < item; i /= 2)  // �����ұ�item��Ľ��(H->Elements[0]���ڱ�Ԫ�أ���С�ڶ��е����Ԫ�أ�����˳������)
		H->Elements[i] = H->Elements[i / 2];  //  ���¸�ֵ 
	H->Elements[i] = item;  //item���� 
	return true;
}

ElementType DeleteMax(MaxHeap H)  //������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ�����
{
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H))
	{
		cout << "������Ϊ��" << endl;
		return ERROR;
	}
	MaxItem = H->Elements[1];  //ȡ����������ֵ
	temp = H->Elements[H->Size--];  //�õ���ȫ���������һ��Ԫ��,�����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)   //Parent=1�Ƚ����������һ��Ԫ�طŵ�1��λ�ã��б�������Parent*2<=H->size�б��Ƿ��������
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))  //Child!=H->Size��ʾChild��Ϊ��ǰ���һ����㣬��Parent���Һ��ӽ��
			Child++;  //Childָ�������ӽ��Ľϴ���
		//��temp�Ҹ����ʵ�λ��  
		if (temp >= H->Elements[Child])  //�����ǰ���Һ��ӽ���temp��С��˵��tempλ���Ѿ�����
			break;
		else  //�ƶ�tempԪ�ص���һ��
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;  //�ں��ʵ�λ�ð�temp�Ž�ȥ
	return MaxItem;
}

// �ж��Ƿ��Ѿ��� 
bool IsFull(MaxHeap H) 
{
	return (H->Size == H->Capacity);
}

// �ж��Ƿ�Ϊ��
bool IsEmpty(MaxHeap H) 
{
	return !H->Size;
}

// �������
void LevelOrderTraversal(MaxHeap H) 
{
	cout << "��������Ľ���ǣ�";
	for (int i = 1; i <= H->Size; i++) 
	{
		cout << H->Elements[i]<<" ";
	}
	cout << endl;
}

int main() 
{
	MaxHeap H;
	int MaxSize = 100;
	H = Create_T(MaxSize);
	Insert(H, 55);
	Insert(H, 66);
	Insert(H, 44);
	Insert(H, 33);
	Insert(H, 11);
	Insert(H, 22);
	Insert(H, 88);
	Insert(H, 99);
	/*
		 99
		/  \
	   88  66
	  / \  / \
	 55 11 22 44
	/
   33
	*/
	LevelOrderTraversal(H);
	DeleteMax(H);
	LevelOrderTraversal(H);
	DeleteMax(H);
	LevelOrderTraversal(H);
	DeleteMax(H);
	LevelOrderTraversal(H);
	DeleteMax(H);
	LevelOrderTraversal(H);
	return 0;
}