#include "Administrator.h"
#include<iostream>
#include"daikuanguanli.h"
#include"Query.h"
#include<string>
#include"kaihu.h"
using namespace std;

 Administrator::Administrator()
{

}

 
void Administrator::show()
{
	cout << "��ӭ��������Աģʽ" << endl;
	cout<<"��ѡ����Ҫ�����ҵ��"<<endl;
	cout << "********** 1.������������ **********" << endl;
	cout << "********** 2.���������� **********" << endl;
	cout << "********** 3.�������  **********" << endl;
	cout << "********** 4.��ѯ���Ҫ���ڵ��û� **********" << endl;
	cout << "********** 5.�°�  **********" << endl;
	cout << "********** 6.�˳����� *********" << endl;
	cout << "********** 7.�л����û�ģʽ *********" << endl;
	int n;
	cin >> n;
	system("cls");
	switch (n)
    {
	case 1:
	  {
		kaihu S;
		S.show();
		int v;
		cin >> v;
		system("cls");
		if (v == 1)
		{
			int id; string name; string phone; double Cun; string mima;
			double dingqi;int dingqi_time;
			cout << "��ֱ�����ID����������ϵ��ʽ��������" << endl;
			cin >> id;
			cin.get();
			getline(cin, name);
			getline(cin, phone);
			cout << "��ѡ����ķ�ʽ�� 1����           2����" << endl;
			int iii;
			cin >> iii;
			if (iii == 1)
			{
				cout << "��������Ҫ����Ľ��" << endl;
				cin >> Cun;
				dingqi = 0;
				dingqi_time = 0;
			}
			else if (iii == 2)
			{
				Cun = 0;
				cout << "��������Ҫ����Ľ��ʹ�ȡ��ʱ��" << endl;
				cin >> dingqi >> dingqi_time;
			}
			cout << "������������룬����˻��Ŀ�������"<<endl;
			cin.get();
			getline(cin, mima);
			kaihu a(id, name, phone, Cun,dingqi,dingqi_time, mima);
			a.GetDate();
			a.Account();
		}
		else if (v == 2)
		{
			int id; string name; string phone; double Dai; string mima; int year;
			cout << "��ֱ�����ID����������ϵ��ʽ��������������ޡ�����" << endl;
			cin >> id;
			cin.get();
			getline(cin, name);
			getline(cin, phone);
			cin >> Dai;
			cin >> year;
			cin.get();
			getline(cin, mima);
			kaihu a(id, name, phone, Dai,year, mima);
			a.GetDate();
			a.DK_account();
		}
		else if (v == 3)
		{
			int id; string mima;
			cout << "������Ҫ������id������" << endl;
			cin >> id;
			cin.get();
			getline(cin, mima);
			system("cls");
			Query AP(id, mima);
			AP.Account_cancellation();

		}
		else
		{
			Administrator LL;
			LL.show();
		}break; 
	   }
	case 2:
	  {
		int id0;
		string mI;
		cout << "��ӭ�����������" << endl;
		cout << "����������id������" << endl;
		cin >> id0;
		cin.get();
		getline(cin, mI);
		system("cls");
		daikuanguanli G(id0, mI);
		G.MIMA();
		break; 
	   }
	case 3:
	  {
		cout << "������ܲ�ѯ" << endl;
		Query LLL;
		LLL.Statistical();
		break;
	   }
	case 4:
	   {
		daikuanguanli AAA;
		AAA.search();
		break;
	    }
	case 5:
	   {
		Query JJJ;
		JJJ.Timing();
		break;
	    }
	case 6:
	   {
		cout << "�����˳��ó���" << endl;
		exit(0);
     	}
	case 7:
		Customer PO;
		PO.Customer_interface();
		break;
	}

}
