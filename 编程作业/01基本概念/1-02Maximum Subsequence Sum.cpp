#include<iostream>
using namespace std;

void MaxSubseqSum(int a[], int n)
{
	int ThisSum = 0;
	int MaxSum = -1;
	int Head = 0, Tail = 0, TempHead = 0; // ������е�ͷ��β���±� 
	for (int i = 0; i < n; i++) 
	{
		ThisSum += a[i]; // �����ۼ�
		if (ThisSum < 0)  //�����ǰ����С��0 
		{
		    ThisSum = 0; //�򲻿���ʹ����Ĳ�����������֮ 
	 	    TempHead = i + 1; //ע����ʱ���ܸı�������ͷ��ֻ�з��ָ���ĺ͸�������ʱ�Ż�ı�ͷ��β 
		}
		else if (ThisSum > MaxSum)  //����յõ���������к͸�������½��
		{
			MaxSum = ThisSum; // ���ָ���ĺ�����µ�ǰ���
			Tail = i;
			Head = TempHead;
		}
	}
	if (MaxSum < 0) //ȫ�Ǹ��������0��ԭ������β�� 
		cout << 0 << " " << a[0] << " " << a[n - 1] << endl;
	else
		cout << MaxSum << " " << a[Head] << " " << a[Tail] << endl;
}

int main()
{
	int n;
	int a[100000 + 5];
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	MaxSubseqSum(a, n);

	system("pause");

	return 0;
}