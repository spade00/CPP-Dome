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
	ifstream fin("�����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("�����˻�.txt");
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
					cout << "����û��Ѿ�����" << endl;
					cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
				}
				else
				{
					if (MMM > dai[i].Month)
					{
						cout << "����û��Ѿ�����" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
					}
					else
					{
						cout << "����û��Ĵ�������ʣ�಻����£���ע����ϵ����з�������" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						if (DDD == dai[i].Day)
						{
							cout << "����û��Ѿ����ﻹ������" << endl;//����ʱ����28�ţ��������
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
						else if (DDD > dai[i].Day)
						{
							cout << "���û��Լ�����" << endl;
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
					}
				}
			}
			else
				cout << "��δ�п쵽�ڵ��û�" << endl;

		}
	}
	system("pause");
	system("cls");
}
int main()
{
	search1();
	int n;
	cout << "��ӭ��������غ��ġ����й���ϵͳ" << endl;
	cout << "��ѡ���������ģʽ" << endl;
	cout << "*********1.����Աģʽ**********" << endl;
	cout << "*********2.�û�ģʽ**********" << endl;
	cin >> n;
	system("cls");
	switch (n) 
	{
	case 1:
	{
		string M;
		cout << "���������Ա��֤��" << endl;
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