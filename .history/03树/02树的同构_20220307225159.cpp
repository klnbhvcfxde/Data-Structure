#include<iostream>
using namespace std;
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode {
	ElementType data;    // 存值
	Tree left;   // 左子树的下标
	Tree right;  // 右子树的下标
}T1[MaxTree], T2[MaxTree];

// 返回根结点的第一种方法 （根节点编号未出现在其他结点编号的后面，创建一个check数组来确定）
// 建二叉树，返回根结点
Tree BuildTree1(struct TreeNode T[]) // 树用数组表示
{
	// 在做的是, 乱序输入节点信息(data,儿子),找到并返回root对应的节点
	int i;
	int n; // 节点数
	int check[MaxTree];  //check数组来确定根节点. 起源不是任何节点的儿子.在静态链表中未出现的下标则为根节点
	char left, right; // 如上struct, 再啰嗦一句, left和right是儿子的下标
	Tree root = Null;   //若n为0，返回Null

	cin >> n;
	if (n)
	{
		for (i = 0; i < n; i++)
		{
			check[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			cin >> T[i].data >> left >> right;
			if (left != '-') // 输入为'-'表示无儿子, 其他都是儿子的下标(不明白为什么要用char类型)
			{
				T[i].left = left - '0';   //若输入不为'-',那字符减去字符0转换为int
				check[T[i].left] = 1; //把在静态链表中出现过的数值标记为1
			}
			else if (left == '-')
			{
				T[i].left = Null;
			}
			if (right != '-')
			{
				T[i].right = right - '0';
				check[T[i].right] = 1;
			}
			else if (right == '-')
			{
				T[i].right = Null;
			}
		}

		for (i = 0; i < n; i++)
		{
			if (!check[i])
			{
				break;
			}
		}
		root = i;

	}
	return root;
}

// 返回根结点的第二种方法 **（根节点编号 = 所有节点编号之和 - 所有节点的左右结点编号和）**
// !!!前提是下标从0开始. 别和data弄混!!!
// 除了root的编号,其他编号都出现过一次
// 建二叉树，返回根结点
Tree BuildTree2(struct TreeNode T[])
{
	int n;  //n为树的结点数
	int root = 0;
	char left, right;
	cin >> n;
	if (!n)
		return Null;
	for (int i = 0; i < n; i++)
	{
		cin >> T[i].data >> left >> right;
		if (left == '-')
			T[i].left = Null;
		else
		{
			T[i].left = left - '0';
			root -= T[i].left;
		}
		if (right == '-')
			T[i].right = Null;
		else
		{
			T[i].right = right - '0';
			root -= T[i].right;
		}
		// 0 累加到 n-1
		root += i;
	}
	return root;
}


// 判断是否同构
bool Isomorphic(int R1, int R2)
{
	if (R1 == Null && R2 == Null)   // 都为空
		return true;
	if (R1 == Null && R2 != Null || R1 != Null && R2 == Null)    // 一个为空，一个不为空
		return false;
	if (T1[R1].data != T2[R2].data)   // 值不同
		return false;
	if ((T1[R1].left == Null) && (T2[R2].left == Null))  //左儿子均为空
	{
		return Isomorphic(T1[R1].right, T2[R2].right);
	}
	if ((T1[R1].left != Null && T2[R2].left != Null) && (T1[T1[R1].left].data == T2[T2[R2].left].data))  // 左儿子不为空且值相等
		return Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right);
	else   // 左儿子不为空且值不等  或者 某一个左儿子为空（有可能左边和右边同构，右边和左边同构）
		return Isomorphic(T1[R1].right, T2[R2].left) && Isomorphic(T1[R1].left, T2[R2].right);
}

int main() {
	Tree R1, R2;
	R1 = BuildTree2(T1);
	R2 = BuildTree1(T2);
	cout << "是否同构？" << endl;
	if (Isomorphic(R1, R2))
		cout << "是" << endl;
	else
		cout << "否" << endl;

	system("pause");

	return 0;
}