#include<iostream>
using namespace std;
#define MaxSize 1000
#define MinData -1000 
int A[] = { 1,3,5,8 };  // 预先定义好一组权值 
int A_length = 4;  // 定义其长度 
typedef struct HeapStruct *MinHeap;
typedef struct TreeNode *HuffmanTree;
struct HeapStruct {  // 存放哈夫曼树的堆. 堆里能存树节点
	HuffmanTree *data;   // 存值的数组  
	int size;   // 堆的当前大小  
	int capacity; // 最大容量	
};
struct TreeNode { // 哈夫曼树 
	int weight;  //权值
	HuffmanTree Left;  // 左子树 
	HuffmanTree right; // 右子树 
};

MinHeap Create_H(); // 初始化堆
HuffmanTree Create_T(); // 初始化哈夫曼树 
void sort(MinHeap H, int i); // 调整子最小堆 
void adjust(MinHeap H); // 调整最小堆 
void BuildMinHeap(MinHeap H);  // 建堆 
HuffmanTree Delete(MinHeap H); // 删除最小堆元素 
void Insert(MinHeap H, HuffmanTree Huff);  // 插入最小堆元素 
void PreOrderTraversal(HuffmanTree Huff); // 先序遍历 
HuffmanTree Huffman(MinHeap H); // 哈夫曼树的构建 

// 初始化堆
MinHeap Create_H() 
{
	MinHeap H;
	HuffmanTree Huff;
	H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * (MaxSize + 1));
	H->capacity = MaxSize;
	H->size = 0;
	// 给堆置哨兵 
	Huff = Create_T();  // 初始化哈夫曼树 
	Huff->weight = MinData;
	H->data[0] = Huff;
	return H;
}

// 初始化哈夫曼树 
HuffmanTree Create_T() 
{
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = 0;
	Huff->Left = NULL;
	Huff->right = NULL;
	return Huff;
}

// 调整子最小堆 
void sort(MinHeap H, int i) 
{
	int Parent, Child;
	int temp = H->data[i]->weight; // 取出当前"根结点"值
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

// 调整最小堆 
void adjust(MinHeap H) 
{
	for (int i = H->size / 2; i > 0; i--)
		sort(H, i);// 每个"子最小堆"调整 
}

// 建堆 
void BuildMinHeap(MinHeap H) 
{
	// 将权值读入堆中
	HuffmanTree Huff;
	for (int i = 0; i < A_length; i++) 
	{
		Huff = Create_T();
		Huff->weight = A[i];
		H->data[++H->size] = Huff;
	}
	// 调整堆 
	adjust(H);
}

// 删除最小堆元素
HuffmanTree Delete(MinHeap H) 
{
	int Parent, Child;
	HuffmanTree T = H->data[1];  // 取出根结点的哈夫曼树 
	HuffmanTree temp = H->data[H->size--]; // 取出最后一个结点哈夫曼树的权值 
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
	// 构造一个 HuffmanTree 结点，附上刚才取出来的权值，返回该结点 
	return T;
}

// 插入一个哈夫曼树
void Insert(MinHeap H, HuffmanTree Huff) 
{
	int weight = Huff->weight; // 取出权值
	int i = ++H->size;
	for (; H->data[i / 2]->weight > weight; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = Huff;
}

//先序遍历 
void PreOrderTraversal(HuffmanTree Huff) 
{
	if (Huff) 
	{
		cout << Huff->weight << " ";
		PreOrderTraversal(Huff->Left);
		PreOrderTraversal(Huff->right);
	}
}

// 哈夫曼树的构造 
HuffmanTree Huffman(MinHeap H) 
{
	HuffmanTree T;
	BuildMinHeap(H); // 建堆 
	int times = H->size;
	// 做 times-1 次合并 
	for (int i = 1; i < times; i++) 
	{
		T = (HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Left = Delete(H);   // 从堆中删除一个结点，作为新T的左子结点 
		T->right = Delete(H);  // 从堆中删除一个结点，作为新T的右子结点 
		T->weight = T->Left->weight + T->right->weight; // 重新计算权值 
		Insert(H, T);  // 再加进堆中 
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
