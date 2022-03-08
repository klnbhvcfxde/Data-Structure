#include<iostream>
using namespace std;
#define MaxSize 1000
typedef int ElementType;
typedef struct {
	ElementType Data; // 锟斤拷值
	int Parent;  // 指锟津父斤拷锟� 
}SetType;

// 锟斤拷锟斤拷 
int Find(SetType S[], ElementType X) 
{
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);  // 锟揭碉拷锟斤拷锟斤拷锟叫革拷值锟斤拷应锟斤拷锟铰憋拷 
	if (MaxSize <= i) // 锟斤拷锟矫伙拷锟斤拷业锟斤拷锟斤拷锟斤拷锟� -1 
		return -1;
	for (; S[i].Parent >= 0; i = S[i].Parent); 	// 锟揭碉拷锟矫斤拷锟侥革拷锟斤拷锟� 
	return i; // 锟斤拷锟截革拷锟斤拷锟斤拷锟斤拷锟斤拷锟絊锟叫碉拷锟铰憋拷 
}

// 锟斤拷 
void Union(SetType S[], ElementType X1, ElementType X2) 
{
	int root1 = Find(S, X1);  // 锟揭碉拷 X1 锟侥革拷锟斤拷锟斤拷卤锟� 
	int root2 = Find(S, X2);  // 锟揭碉拷 X2 锟侥革拷锟斤拷锟斤拷卤锟� 
	// 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷卤瓴煌�锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷
	if (root1 != root2) 
	{
		S[root1].Parent = root2;   // 锟斤拷X1锟揭碉拷X2锟侥硷拷锟斤拷 
	}
}

int main() 
{
	SetType S[MaxSize];
	// 锟斤拷始锟斤拷锟斤拷锟介，锟斤拷锟斤拷锟饺�锟斤拷指锟斤拷-1 
	for (int i = 0; i < MaxSize; i++) 
	{
		S[i].Data = i + 1;
		S[i].Parent = -1;
	}
	cout << Find(S, 5) << endl;
	Union(S, 3, 5);
	cout << Find(S, 4) << endl;
	cout << Find(S, 3) << endl;
	Union(S, 1, 3);
	Union(S, 2, 4);
	Union(S, 8, 6);
	cout << Find(S, 6) << endl;
	cout << Find(S, 8) << endl;
	return 0;
}