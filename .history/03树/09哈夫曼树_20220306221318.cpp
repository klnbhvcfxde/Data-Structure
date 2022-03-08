#include<iostream>
using namespace std;
#define MaxSize 1000
#define MinData -1000 
int A[] = { 1,3,5,8 };  // 预锟饺讹拷锟斤拷锟揭伙拷锟饺ㄖ� 
int A_length = 4;  // 锟斤拷锟斤拷锟戒长锟斤拷 
typedef struct HeapStruct *MinHeap;
typedef struct TreeNode *HuffmanTree;
struct HeapStruct {  // 锟斤拷殴锟斤拷锟斤拷锟斤拷锟斤拷亩锟� 
	HuffmanTree *data;   // 锟斤拷值锟斤拷锟斤拷锟斤拷  
	int size;   // 锟窖的碉拷前锟斤拷小  
	int capacity; // 锟斤拷锟斤拷锟斤拷锟�	
};
struct TreeNode { // 锟斤拷锟斤拷锟斤拷锟斤拷 
	int weight;  //权值
	HuffmanTree Left;  // 锟斤拷锟斤拷锟斤拷 
	HuffmanTree right; // 锟斤拷锟斤拷锟斤拷 
};

MinHeap Create_H(); // 锟斤拷始锟斤拷锟斤拷
HuffmanTree Create_T(); // 锟斤拷始锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷 
void sort(MinHeap H, int i); // 锟斤拷锟斤拷锟斤拷锟斤拷小锟斤拷 
void adjust(MinHeap H); // 锟斤拷锟斤拷锟斤拷小锟斤拷 
void BuildMinHeap(MinHeap H);  // 锟斤拷锟斤拷 
HuffmanTree Delete(MinHeap H); // 删锟斤拷锟斤拷小锟斤拷元锟斤拷 
void Insert(MinHeap H, HuffmanTree Huff);  // 锟斤拷锟斤拷锟斤拷小锟斤拷元锟斤拷 
void PreOrderTraversal(HuffmanTree Huff); // 锟斤拷锟斤拷锟斤拷锟� 
HuffmanTree Huffman(MinHeap H); // 锟斤拷锟斤拷锟斤拷锟斤拷锟侥癸拷锟斤拷 

// 锟斤拷始锟斤拷锟斤拷
MinHeap Create_H() 
{
	MinHeap H;
	HuffmanTree Huff;
	H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * (MaxSize + 1));
	H->capacity = MaxSize;
	H->size = 0;
	// 锟斤拷锟斤拷锟斤拷锟节憋拷 
	Huff = Create_T();  // 锟斤拷始锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷 
	Huff->weight = MinData;
	H->data[0] = Huff;
	return H;
}

// 锟斤拷始锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷 
HuffmanTree Create_T() 
{
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = 0;
	Huff->Left = NULL;
	Huff->right = NULL;
	return Huff;
}

// 锟斤拷锟斤拷锟斤拷锟斤拷小锟斤拷 
void sort(MinHeap H, int i) 
{
	int Parent, Child;
	int temp = H->data[i]->weight; // 取锟斤拷锟斤拷前"锟斤拷锟斤拷锟�"值
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

// 锟斤拷锟斤拷锟斤拷小锟斤拷 
void adjust(MinHeap H) 
{
	for (int i = H->size / 2; i > 0; i--)
		sort(H, i);// 每锟斤拷"锟斤拷锟斤拷小锟斤拷"锟斤拷锟斤拷 
}

// 锟斤拷锟斤拷 
void BuildMinHeap(MinHeap H) 
{
	// 锟斤拷权值锟斤拷锟斤拷锟斤拷锟�
	HuffmanTree Huff;
	for (int i = 0; i < A_length; i++) 
	{
		Huff = Create_T();
		Huff->weight = A[i];
		H->data[++H->size] = Huff;
	}
	// 锟斤拷锟斤拷锟斤拷 
	adjust(H);
}

// 删锟斤拷锟斤拷小锟斤拷元锟斤拷
HuffmanTree Delete(MinHeap H) 
{
	int Parent, Child;
	HuffmanTree T = H->data[1];  // 取锟斤拷锟斤拷锟斤拷锟侥癸拷锟斤拷锟斤拷锟斤拷 
	HuffmanTree temp = H->data[H->size--]; // 取锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟饺ㄖ� 
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
	// 锟斤拷锟斤拷一锟斤拷 HuffmanTree 锟斤拷悖�锟斤拷锟较刚诧拷取锟斤拷锟斤拷锟斤拷权值锟斤拷锟斤拷锟截该斤拷锟� 
	return T;
}

// 锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
void Insert(MinHeap H, HuffmanTree Huff) 
{
	int weight = Huff->weight; // 取锟斤拷权值
	int i = ++H->size;
	for (; H->data[i / 2]->weight > weight; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = Huff;
}

//锟斤拷锟斤拷锟斤拷锟� 
void PreOrderTraversal(HuffmanTree Huff) 
{
	if (Huff) 
	{
		cout << Huff->weight << " ";
		PreOrderTraversal(Huff->Left);
		PreOrderTraversal(Huff->right);
	}
}

// 锟斤拷锟斤拷锟斤拷锟斤拷锟侥癸拷锟斤拷 
HuffmanTree Huffman(MinHeap H) 
{
	HuffmanTree T;
	BuildMinHeap(H); // 锟斤拷锟斤拷 
	int times = H->size;
	// 锟斤拷 times-1 锟轿合诧拷 
	for (int i = 1; i < times; i++) 
	{
		T = (HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Left = Delete(H);   // 锟接讹拷锟斤拷删锟斤拷一锟斤拷锟斤拷悖�锟斤拷为锟斤拷T锟斤拷锟斤拷锟接斤拷锟� 
		T->right = Delete(H);  // 锟接讹拷锟斤拷删锟斤拷一锟斤拷锟斤拷悖�锟斤拷为锟斤拷T锟斤拷锟斤拷锟接斤拷锟� 
		T->weight = T->Left->weight + T->right->weight; // 锟斤拷锟铰硷拷锟斤拷权值 
		Insert(H, T);  // 锟劫加斤拷锟斤拷锟斤拷 
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
	return 0;
}