#include<iostream>
using namespace std;

/*
	��Ŀ�����ڲ�ͬ���������У��ж��Ƿ�Ϊͬһ��������������
	���˼·��
			1����������ʾ��
			2����������T��
			3���ж�һ�����Ƿ���������Tһ�¡�
*/

//��������ʾ
typedef struct TreeNode *Tree;
struct TreeNode
{
	int v;  //��v��ʾ������Ϣ
	Tree Left, Right;  //��������ʽ��ʾ��
	int flag;  //flagΪĳ������Ƿ񱻷��ʹ��ı�־�������б�һ�������Ƿ�����һ�������ĳ�����δ�����ʣ�flag=0������flag=1
};

Tree MakeTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);

//�����ܴ
int main()
{
	int N, L;  // N����㣬L������
	Tree T;

	cin >> N;
	while (N)
	{
		cin >> L;
		T = MakeTree(N);  //���ݵ�һ�����н�N��������T
		for (int i = 0; i < L; i++)  //������T�ֱ��б�����L�������Ƿ�����T�γ�ͬһ��������������
		{
			if (Judge(T, N))
				cout << "��" << endl;
			else
				cout << "��" << endl;
			ResetT(T); //���T�еı��flag
		}
		FreeTree(T);
		cin >> N;
	}


	return 0;
}

//��ι���������
Tree MakeTree(int N)
{
	Tree T;
	int V;

	cin >> V;  //���ȶ����һ��Ԫ�ط���V��
	T = NewNode(V);  //ΪT�����½��
	for (int i = 1; i < N; i++)
	{
		cin >> V;  //���ζ������к����Ԫ��
		T = Insert(T, V);  //����ĺ���Ԫ�����β�����T
	}
	return T;
}

//���½�㣨һ��Ϊ��һ����㣩
Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

//�������Ĳ���
Tree Insert(Tree T, int V)
{
	if (!T)  //TΪ��
	{
		T = NewNode(V);  //ͨ��NewNode(V)ΪT�����һ�����
	}
	else  //T��Ϊ��
	{
		if (V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}
	return T;
}

//����б��Ѿ����ʹ��Ľ��Ҫ���б�ǣ�ʹflag=1��
//����T�а�˳�����������е�ÿ���������ÿ�������������Ľ����ǰ������ֹ�����һ�£�
//                                 �������ĳ������������ǰ��δ���ֵĽ�㣬��һ�¡�
int check(Tree T, int V)
{
	if (T->flag)  //ĳ����㱻���ʹ�(��Ϊ֮ǰ��V == T->v����ʹ��flag =1)
	{
		if (V < T->v)
			return check(T->Left, V);
		else if (V > T->v)
			return check(T->Right, V);
		else  //���V == T->v����ζ�����������������Ԫ�س������������ϣ����ظ����֣���Ϊ��һ��
			return 0;
	}
	else  //ĳ�����δ�����ʹ�
	{
		if (V == T->v)  //���δ�����ʹ��Ľ��պ����������ģ�ʹflag=1
		{
			T->flag = 1;
			return 1;
		}
		else  //����δ�����ʹ��Ľ�㲻���������ģ�������ǰ��δ���ֵĽ�㣬ʹflag=0
			return 0;
	}
}

int Judge(Tree T, int N)
{
	int V, same = 1;
	//same��1����Ŀǰ��һ�£�0�����Ѿ���һ��

	cin >> V;

	if (V != T->v)  //���е�һ��Ԫ����T�ĸ���㲻һ��
		same = 0;  //�������Ѿ���һ��
	else
		T->flag = 1;

	for (int i = 1; i < N; i++)
	{
		cin >> V;
		if ((same) && (!check(T, V)))
			same = 0;
	}

	if (!same)
		return 0;
	else
		return 1;
}

//���T�и������ı��
void ResetT(Tree T)
{
	if (T->Left)
		ResetT(T->Left);
	if (T->Right)
		ResetT(T->Right);
	T->flag = 0;
}

//�ͷ�T�Ŀռ�
void FreeTree(Tree T)
{
	if (T->Left)
		FreeTree(T->Left);
	if (T->Right)
		FreeTree(T->Right);
	free(T);
}