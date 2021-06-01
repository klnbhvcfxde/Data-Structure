#include<iostream>
using namespace std;

// �㷨1��ȷ�����е��ײ���β�����ٱ����ۼӣ�ʱ�临�Ӷ�ΪO(n^3)
int MaxSubseqSum1(int a[], int n)
{
	int ThisSum, MaxSum = 0;
	for (int i = 0; i < n; i++)  //iΪ�������λ��
	{
		for (int j = 0; j < n; j++)  //j�������Ҷ�λ��
		{
			ThisSum = 0;  //ThisSum�Ǵ�a[i]��a[j]�����к�
			for (int k = i; k <= j; k++)
			{
				ThisSum += a[k];
			}
			if (ThisSum > MaxSum)  //����յõ���������к͸�������½��
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}

//�㷨2��ȷ�����е��ײ�������ۼӣ�ʱ�临�Ӷ�ΪO(n^2)
int MaxSubseqSum2(int a[], int n)
{
	int ThisSum, MaxSum = 0;
	for (int i = 0; i < n; i++)  //iΪ�������λ��
	{
		ThisSum = 0;  //ThisSum�Ǵ�a[i]��a[j]�����к�
		for (int j = i; j < n; j++)  //j�������Ҷ�λ��
		{
			ThisSum += a[j];
			if (ThisSum > MaxSum)  //����յõ���������к͸�������½��
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}

//�㷨3���ֶ���֮���ݹ�ֳ����ݣ��ֱ���ÿ���ָ��������кͣ�ʱ�临�Ӷ�ΪO(nlogn)
//�������������к͡��ұ�������к͡���绮�ֱ߽��������к����������ֵ
int MaxSum(int A, int B, int C)
{
	return (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
}
//����
int DivideAndConquer(int a[], int left, int right)
{
	if (left == right) 	//�ݹ��������������ֻ��һ������
	{
		if (a[left] > 0)  // ������Ϊ����ʱ��������к�Ϊ�䱾��
		{
			return a[left];
		}
		return 0;	// ������Ϊ����ʱ��������к�Ϊ 0
	}

	//�ֱ�ݹ��ҵ�����������к�
	int mid = left + (right - left) / 2;  //����left+(right - left)/2��mid��Ϊ�˷�ֹ�����������
	int MaxLeftSum = DivideAndConquer(a, left, mid);
	int MaxRightSum = DivideAndConquer(a, mid + 1, right);

	//�ٷֱ������ҿ��������к�
	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for (int i = mid; i >= left; i--)  //Ӧ�ôӱ߽�����������
	{
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	int MaXRightBorderSum = 0;
	int RightBorderSum = 0;
	for (int i = mid + 1; i <= right; i++)  // �ӱ߽�������ұ���
	{
		RightBorderSum += a[i];
		if (RightBorderSum > MaXRightBorderSum)
			MaXRightBorderSum = RightBorderSum;
	}

	//��󷵻طֽ�����������кͣ��ұ�������кͣ��Ϳ��������к�������������
	return MaxSum(MaxLeftSum, MaxRightSum, MaXRightBorderSum + MaxLeftBorderSum);
}
int MaxSubseqSum3(int a[], int n)
{
	return DivideAndConquer(a, 0, n - 1);
}

//�㷨4�����ߴ���ֱ���ۼӣ�����ۼӵ���ǰ�ĺ�Ϊ�������õ�ǰֵ��0��ʱ�临�Ӷ�Ϊ O(n)
int MaxSubseqSum4(int a[], int n)
{
	int ThisSum = 0;
	int MaxSum = 0;
	for (int i = 0; i < n; i++)
	{
		ThisSum += a[i];  //�����ۼ�
		if (ThisSum < 0)  //����յõ���������к�Ϊ��������ʹ����Ĳ��ֺ���������
		{
			ThisSum = 0;
		}
		else if (ThisSum > MaxSum)  //����յõ���������к͸�������½��
		{
			MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int main() {
	int n;
	int a[100000 + 5];
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//�㷨1
	//int MaxSum1 = MaxSubseqSum1(a, n);
	//cout << MaxSum1 << endl;

	//�㷨2
	//int MaxSum2 = MaxSubseqSum2(a, n);
	//cout << MaxSum2 << endl;

	//�㷨3
	//int MaxSum3 = MaxSubseqSum3(a, n);
	//cout << MaxSum3 << endl;

	//�㷨4
	int MaxSum4 = MaxSubseqSum4(a, n);
	cout << MaxSum4 << endl;

	system("pause");

	return 0;
}