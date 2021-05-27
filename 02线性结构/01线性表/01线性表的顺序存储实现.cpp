#include<iostream>
using namespace std;
#define MAXSIZE 100  // MAXSIZE ����Ϊ Data ����Ĵ�С
typedef int ElementType;  // ElementType �ɶ���Ϊ�������ͣ�typedefΪ�������ʹ���һ���µ�����
typedef struct LNode *List;  //typedef��Ԥ����ؼ��֣��൱������������������򵥵����֣����������List��ʾstruct LNode�ṹ��ָ��
struct LNode
{
	ElementType Data[MAXSIZE];
	int Last;  // Last �������Ա�����һ��Ԫ��
};
List L;
//�����±�Ϊ i ��Ԫ�أ�L->Data[i]���±�� 0 ��ʼ
//���Ա�ĳ��ȣ�L->Last+1

List MakeEmpty(); //��ʼ��˳��� 
int Find(ElementType X, List L); //���� X ��һ�γ��ֵ��±� 
void Insert(ElementType X, int i, List L); //���±�Ϊ i �ĵط����� X 
void Delete(int i, List L);   //ɾ���±�Ϊ i �ĵ�ǰֵ 
ElementType FindKth(int K, List L);  //�����±�Ϊ K �ĵ�ǰֵ
int Length(List L);  //����˳���ĳ��� 

//��ʼ�� 
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));  //malloc�ķ���ֵ��һ��ָ�룬ָ��һ�ο����ڴ����ʼ��ַ
	L->Last = -1;
	return L;
}

// ����
void Insert(ElementType X, int i, List L)
{
	if (L->Last == MAXSIZE - 1)  //λ������
	{
		cout << "����" << endl;
		return;
	}
	if (i < 0 || L->Last + 1 < i)  //λ��Խ�磬����������� L->Data[L->Last+1]�����涼������λ����
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	for (int j = L->Last; j >= i; j--)   // �Ӻ���ǰ�������Ųһ������ a[i]�ڳ�λ��     
		L->Data[j + 1] = L->Data[j];
	L->Data[i] = X;    //��Ԫ�ز���
	L->Last++;    // Last��Ȼָ�����Ԫ��
	return;
}

//ɾ��
void Delete(int i, List L)
{
	if (i < 0 || L->Last < i)  //λ��Խ�磬��ɾ����ൽ L->Data[L->Last]
	{
		cout << "L->Data[" << i << "]������Ԫ��" << endl;
		return;
	}
	for (int j = i; j <= L->Last; j++)   // ��ǰ����������ǰŲһ������ a[i] ������ 
		L->Data[j] = L->Data[j + 1];
	L->Last--;  // Last��Ȼָ�����Ԫ��
	return;
}

// ��ֵ���� 
int Find(ElementType X, List L)
{
	int i = 0;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (L->Last < i)  //���û�ҵ������� -1
		return -1;
	else    // �ҵ��󷵻��±� 
		return i;
}

// �������
ElementType FindKth(int K, List L)
{
	if (K < 0 || L->Last < K)  //λ��Խ��
	{
		cout << "L->Data[" << K << "]������Ԫ��" << endl;
		return NULL;
	}
	return L->Data[K];
}

//��
int Length(List L)
{
	return L->Last + 1;
}

int main() 
{
	L = MakeEmpty();  //MakeEmpty()��ն�������ݽṹ

	//����
	Insert(11, 0, L); 
	cout << "�����Ա�L->Data[0]����11" << endl;
	Insert(25, 0, L);
	cout << "�����Ա�L->Data[0]����25" << endl;
	Insert(33, 0, L);
	cout << "�����Ա�L-Data[0]����33" << endl;
	Insert(77, 0, L);
	cout << "�����Ա�L-Data[0]����77" << endl;

	cout << "��ʱ�����Ա�Ϊ��";
	for (int i = 0; i < Length(L); i++)
		cout << L->Data[i] << " ";
	cout << endl;

	//����
	cout << "����ֵΪ12���±��ǣ�" << Find(12, L) << endl;
	cout << "����ֵΪ33���±��ǣ�" << Find(33, L) << endl;
	cout << "�������Ա����±�Ϊ3��ֵ�ǣ�" << FindKth(3, L) << endl;
	cout << "�������Ա����±�Ϊ5��ֵ�ǣ�" << FindKth(5, L) << endl;

	//ɾ��
	Delete(2, L);
	cout << "ɾ�����Ա����±�Ϊ2��Ԫ��" << endl;
	Delete(2, L);
	cout << "ɾ�����Ա����±�Ϊ2��Ԫ��" << endl;

	cout << "��ʱ�����Ա�Ϊ��";
	for (int i = 0; i < Length(L); i++)
		cout << L->Data[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}