#include "kaihu.h"
#include<iostream>
using namespace std;

kaihu::kaihu(int id,string name,string phone,double cun,double Di,int Di_time,string mima)
{
	ID = id; Name = name;
	Cunkuan = cun;
	Phone = phone;
	Mima = mima;
	Dingqi = Di;
	Dingqi_Time = Di_time;
}

kaihu::kaihu(int id, string name, string phone, double dai, int dai_time, string mima)
{
	ID = id; Name = name;
	Daikuan = dai;
	Phone = phone;
	Mima = mima;
	DKYear = dai_time;
}

kaihu::kaihu()
{

}

void kaihu::show()
{
	cout << "请选择需要开户的类型" << endl;
	cout << "********** 1.存款账户 **********" << endl;
	cout << "********** 2.贷款账户 **********" << endl;
	cout << "********** 3.销户 **********" << endl;
	cout << "********** 4.返回上一层 **********" << endl;
}
void kaihu::Account()
{
		ofstream fout("存款账户.txt", ios::app);
		if (!fout)

		{
			cout << "文件打开错误，程序结束" << endl;
			exit(0);
		}
		fout << ID << " " << Name << " " << Phone << " " << Cunkuan << " " <<Dingqi<<" "<<Dingqi_Time<<" "<< Mima << " " << 0  << " " << Year << " " << Month << " " << Day << "\n";
		fout.clear();
		fout.close();
		cout << "账户录入完成" << endl;
		system("pause");
		system("cls");
		Administrator JJJ;
		JJJ.show();
}


void kaihu::DK_account()
{
	ofstream fout("贷款账户.txt", ios::app);
	if (!fout)
	{
		cout << "文件打开错误，程序结束" << endl;
		exit(0);
	}
	if (Day > 28)
	{
		cout << "本月超过28号不予办理贷款，请于下个月1号再来" << endl;
	}
	else
	{
		fout << ID << " " << Name << " " << Phone << " " << Daikuan << " " << DKYear << " " << Mima <<" "<< Year << " " << Month << " " << Day << "\n";
		cout << "账户录入完成" << endl;
	}
	fout.clear();
	fout.close();
	system("pause");
	system("cls");
	Administrator JJJ;
	JJJ.show();
}
 

void kaihu::GetDate()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	Year = sys.wYear;
	Month = sys.wMonth;
	Day = sys.wDay;
}