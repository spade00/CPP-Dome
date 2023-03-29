#include "virtaul.h"

virtaul::virtaul()
{
	
}


virtaul::virtaul(string V)
{
	pass = V;
}

void virtaul::verify111()
{
	ifstream fin("管理员账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("管理员账户.txt");
	string* T = new string[100];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> T[i];
	}
	for (int j = 0; j < n; j++)
	{
		if (pass == T[j])
		{
				cout << "验证成功" << endl;
				Administrator l;
				system("pause");
				system("cls");
				l.show();
				break;
		}
		else
			if (j == n -1)
			{
				string M; int PA;
				cout << "未查询到该管理员" << endl;
				cout << "退出程序请按1，继续尝试认证请按其他" << endl;
				cin >> PA;
				system("cls");
				if (PA == 1)
				{
					exit(0);
				}
				else
				{
					cout << "请再次输入验证码" << endl;
					cin.get();
					getline(cin, M);
					virtaul B(M);
					system("cls");
					B.verify111();
					break;
				}
			}
	}
	fin1.clear();
	fin1.close();
	delete[]T;
}
