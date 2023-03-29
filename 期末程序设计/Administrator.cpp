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
	cout << "欢迎来到管理员模式" << endl;
	cout<<"请选择需要办理的业务"<<endl;
	cout << "********** 1.开户或者销户 **********" << endl;
	cout << "********** 2.管理贷款服务 **********" << endl;
	cout << "********** 3.收入汇总  **********" << endl;
	cout << "********** 4.查询贷款将要到期的用户 **********" << endl;
	cout << "********** 5.下班  **********" << endl;
	cout << "********** 6.退出程序 *********" << endl;
	cout << "********** 7.切换至用户模式 *********" << endl;
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
			cout << "请分别输入ID、姓名、联系方式、存款、密码" << endl;
			cin >> id;
			cin.get();
			getline(cin, name);
			getline(cin, phone);
			cout << "请选择存款的方式： 1活期           2定期" << endl;
			int iii;
			cin >> iii;
			if (iii == 1)
			{
				cout << "请输入需要存入的金额" << endl;
				cin >> Cun;
				dingqi = 0;
				dingqi_time = 0;
			}
			else if (iii == 2)
			{
				Cun = 0;
				cout << "请输入需要存入的金额和存取的时间" << endl;
				cin >> dingqi >> dingqi_time;
			}
			cout << "请继续输入密码，完成账户的开户工作"<<endl;
			cin.get();
			getline(cin, mima);
			kaihu a(id, name, phone, Cun,dingqi,dingqi_time, mima);
			a.GetDate();
			a.Account();
		}
		else if (v == 2)
		{
			int id; string name; string phone; double Dai; string mima; int year;
			cout << "请分别输入ID、姓名、联系方式、贷款金额、贷款年限、密码" << endl;
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
			cout << "请输入要销户的id和密码" << endl;
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
		cout << "欢迎来到贷款管理" << endl;
		cout << "请输入您的id和密码" << endl;
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
		cout << "收入汇总查询" << endl;
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
		cout << "即将退出该程序" << endl;
		exit(0);
     	}
	case 7:
		Customer PO;
		PO.Customer_interface();
		break;
	}

}
