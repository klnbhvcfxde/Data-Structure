#include<iostream>
using namespace std;
#include<map>
#include<string>

int main() 
{
	int N;
	char command;
	string qq;
	string ps;
	map<string, string> m;
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		getchar();
		cin >> command >> qq >> ps;
		if (command == 'N')     // ���û�
		{  
			if (m.find(qq) != m.end())    // qq���Ѿ�����(map�������ҵ�key�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����m.end()) 
				cout << "ERROR: Exist";
			else  // ע��ɹ�
			{     
				cout << "New: OK";
				m[qq] = ps;
			}
		}
		else if (command == 'L')   // ���û� 
		{
			if (m.find(qq) == m.end())  // û�ҵ� 
				cout << "ERROR: Not Exist";
			else if (m[qq] == ps)   // ������ȷ 
				cout << "Login: OK";
			else
				cout << "ERROR: Wrong PW";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
