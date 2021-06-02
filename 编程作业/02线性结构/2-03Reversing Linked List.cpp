#include <iostream>
#include<iomanip>
using namespace std;
#define MAXSIZE 100005

typedef int ElementType;
typedef struct node {
	ElementType data;
	ElementType next;
} Node;

//��ת��������ÿK����㣬��תһ�� 
int reverList(Node list[], int K, int head, int N)
{
	int flag = 1;
	int last_head;	//���ڼ�¼��һ�η�ת���������������ַ
					//������һ�η�ת���������ͷ������ 
	int rev_head = head;//��һ�δ���ת�������ͷ����ַ 
	int mid_head = head;//��ת�����е��м����ַ 
	int mid_next;		//��ת�����е��м����ַ 

	while (N - K >= 0)//��ʣ���㲻��K��ʱ�����ٷ�ת 
	{
		N -= K;

		//��ת������ 
		for (int i = 0; i < K - 1; i++) 
		{
			mid_next = list[rev_head].next;
			list[rev_head].next = list[mid_next].next;
			list[mid_next].next = mid_head;
			mid_head = mid_next;
		}//��ת������ 

		//�ӵڶ��ο�ʼ����Ҫ����η�ת����������ͷ������ӵ���һ�ε�β�� 
		if (flag == 0) 
{
			list[last_head].next = mid_head;
		}

		//��¼��һ�η�ת���ͷ��㣬��Ϊ����List��ͷ��㲢���� 
		if (flag) 
		{
			head = mid_head;
			flag = 0;
		}

		last_head = rev_head;
		rev_head = list[rev_head].next;//�´ο�ʼ��ͷ����ַ 
		mid_head = rev_head;
	}
	return head;
}

void printList(Node list[], int head)
{
	int next = head;
	while (list[next].next != -1) 
	{
		cout << setw(5) << setfill('0') << next << " " << list[next].data << " " << setw(5) << setfill('0') << list[next].next << endl;
		next = list[next].next;
	}
	cout << setw(5) << setfill('0') << next << " " << list[next].data << " " << list[next].next << endl;
}

int main()
{
	int Head, N, K;  //HeadΪ��һ�����ĵ�ַ,NΪ����������KΪҪ��ת�����б�ĳ���
	cin >> Head >> N >> K;
	Node list[MAXSIZE];
	int i, Address, Data, Next;  //Address�ǽ���λ�ã�Data��һ��������Next����һ������λ��
	for (i = 0; i < N; i++) 
	{
		cin >> Address >> Data >> Next;
		list[Address].data = Data;
		list[Address].next = Next;
	}
	int next = Head;
	int num = 1;//�������ݽ�㲢�����������еĽ�㣬���ڼ��������Ľ����� 
	while (list[next].next != -1) {
		num++;
		next = list[next].next;
	}
	if (K > 1)	//�����1������Ҫ��ת��ԭ����� 
		Head = reverList(list, K, Head, num);
	printList(list, Head);

	system("pause");
	return 0;
}