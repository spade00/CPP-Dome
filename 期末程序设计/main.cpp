#include <windows.h>
#include<iostream>
#include <stdio.h> 
#include"kaihu.h"
#include"virtaul.h"
#include<string>
#include"Query.h"
#include"Customer.h"
#include"Administrator.h"
#include"daikuanguanli.h"
using namespace std;
void search1()
{
	ifstream fin("贷款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("贷款账户.txt");
	DK* dai = new DK[n];
	int a, f, Y, M, D;
	double c;
	string b, e, d;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> e >> c >> f >> d >> Y >> M >> D;
		dai[i].ID = a;
		dai[i].Name = b;
		dai[i].Phone = e;
		dai[i].Daikuan = c;
		dai[i].Dai_time = f;
		dai[i].Mima = d;
		dai[i].Year = Y;
		dai[i].Month = M;
		dai[i].Day = D;
	}
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	for (int i = 0; i < n; i++)
	{
		if (dai[i].Daikuan != 0)
		{
			if (YYY >= dai[i].Year + dai[i].Dai_time && MMM >= dai[i].Month)
			{
				if (YYY > dai[i].Year + dai[i].Dai_time)
				{
					cout << "这个用户已经逾期" << endl;
					cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
				}
				else
				{
					if (MMM > dai[i].Month)
					{
						cout << "这个用户已经逾期" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
					}
					else
					{
						cout << "这个用户的贷款日期剩余不足个月，请注意联系其进行反还贷款" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						if (DDD == dai[i].Day)
						{
							cout << "这个用户已经到达还款日期" << endl;//开户时超过28号，不予办理；
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
						else if (DDD > dai[i].Day)
						{
							cout << "该用户以及逾期" << endl;
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
					}
				}
			}
			else
				cout << "暂未有快到期的用户" << endl;

		}
	}
	system("pause");
	system("cls");
}
int main()
{
	search1();
	int n;
	cout << "欢迎来到“天地黑心”银行管理系统" << endl;
	cout << "请选择程序运行模式" << endl;
	cout << "*********1.管理员模式**********" << endl;
	cout << "*********2.用户模式**********" << endl;
	cin >> n;
	system("cls");
	switch (n) 
	{
	case 1:
	{
		string M;
		cout << "请输入管理员验证码" << endl;
		cin.get();
		getline(cin, M);
		virtaul B(M);
		B.verify111();
		break;
	}
	case 2:
	{
		Customer I;
		I.Customer_interface();
		break;
	}
	}
}