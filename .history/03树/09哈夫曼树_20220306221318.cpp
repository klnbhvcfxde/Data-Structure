#include<iostream>
using namespace std;
#define MaxSize 1000
#define MinData -1000 
int A[] = { 1,3,5,8 };  // Ԥ�ȶ����һ��Ȩֵ 
int A_length = 4;  // �����䳤�� 
typedef struct HeapStruct *MinHeap;
typedef struct TreeNode *HuffmanTree;
struct HeapStruct {  // ��Ź��������Ķ� 
	HuffmanTree *data;   // ��ֵ������  
	int size;   // �ѵĵ�ǰ��С  
	int capacity; // �������	
};
struct TreeNode { // �������� 
	int weight;  //Ȩֵ
	HuffmanTree Left;  // ������ 
	HuffmanTree right; // ������ 
};

MinHeap Create_H(); // ��ʼ����
HuffmanTree Create_T(); // ��ʼ���������� 
void sort(MinHeap H, int i); // ��������С�� 
void adjust(MinHeap H); // ������С�� 
void BuildMinHeap(MinHeap H);  // ���� 
HuffmanTree Delete(MinHeap H); // ɾ����С��Ԫ�� 
void Insert(MinHeap H, HuffmanTree Huff);  // ������С��Ԫ�� 
void PreOrderTraversal(HuffmanTree Huff); // ������� 
HuffmanTree Huffman(MinHeap H); // ���������Ĺ��� 

// ��ʼ����
MinHeap Create_H() 
{
	MinHeap H;
	HuffmanTree Huff;
	H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * (MaxSize + 1));
	H->capacity = MaxSize;
	H->size = 0;
	// �������ڱ� 
	Huff = Create_T();  // ��ʼ���������� 
	Huff->weight = MinData;
	H->data[0] = Huff;
	return H;
}

// ��ʼ���������� 
HuffmanTree Create_T() 
{
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = 0;
	Huff->Left = NULL;
	Huff->right = NULL;
	return Huff;
}

// ��������С�� 
void sort(MinHeap H, int i) 
{
	int Parent, Child;
	int temp = H->data[i]->weight; // ȡ����ǰ"�����"ֵ
	for (Parent = i; Parent * 2 <= H->size; Parent = Child) 
	{
		Child = 2 * Parent;
		if ((Child != H->size) && (H->data[Child + 1]->weight < H->data[Child]->weight))
			Child++;
		if (H->data[Child]->weight >= temp)
			break;
		else
			H->data[Parent] = H->data[Child];
	}
	H->data[Parent]->weight = temp;
}

// ������С�� 
void adjust(MinHeap H) 
{
	for (int i = H->size / 2; i > 0; i--)
		sort(H, i);// ÿ��"����С��"���� 
}

// ���� 
void BuildMinHeap(MinHeap H) 
{
	// ��Ȩֵ�������
	HuffmanTree Huff;
	for (int i = 0; i < A_length; i++) 
	{
		Huff = Create_T();
		Huff->weight = A[i];
		H->data[++H->size] = Huff;
	}
	// ������ 
	adjust(H);
}

// ɾ����С��Ԫ��
HuffmanTree Delete(MinHeap H) 
{
	int Parent, Child;
	HuffmanTree T = H->data[1];  // ȡ�������Ĺ������� 
	HuffmanTree temp = H->data[H->size--]; // ȡ�����һ��������������Ȩֵ 
	for (Parent = 1; Parent * 2 <= H->size; Parent = Child) 
	{
		Child = 2 * Parent;
		if ((Child != H->size) && (H->data[Child + 1]->weight < H->data[Child]->weight))
			Child++;
		if (H->data[Child]->weight >= temp->weight)
			break;
		else
			H->data[Parent] = H->data[Child];
	}
	H->data[Parent] = temp;
	// ����һ�� HuffmanTree ��㣬���ϸղ�ȡ������Ȩֵ�����ظý�� 
	return T;
}

// ����һ����������
void Insert(MinHeap H, HuffmanTree Huff) 
{
	int weight = Huff->weight; // ȡ��Ȩֵ
	int i = ++H->size;
	for (; H->data[i / 2]->weight > weight; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = Huff;
}

//������� 
void PreOrderTraversal(HuffmanTree Huff) 
{
	if (Huff) 
	{
		cout << Huff->weight << " ";
		PreOrderTraversal(Huff->Left);
		PreOrderTraversal(Huff->right);
	}
}

// ���������Ĺ��� 
HuffmanTree Huffman(MinHeap H) 
{
	HuffmanTree T;
	BuildMinHeap(H); // ���� 
	int times = H->size;
	// �� times-1 �κϲ� 
	for (int i = 1; i < times; i++) 
	{
		T = (HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Left = Delete(H);   // �Ӷ���ɾ��һ����㣬��Ϊ��T�����ӽ�� 
		T->right = Delete(H);  // �Ӷ���ɾ��һ����㣬��Ϊ��T�����ӽ�� 
		T->weight = T->Left->weight + T->right->weight; // ���¼���Ȩֵ 
		Insert(H, T);  // �ټӽ����� 
	}
	T = Delete(H);
	return T;
}

int main() 
{
	MinHeap H;
	HuffmanTree Huff;
	H = Create_H();
	Huff = Huffman(H);
	PreOrderTraversal(Huff);
	cout << endl;
	system("pause");
	return 0;
}