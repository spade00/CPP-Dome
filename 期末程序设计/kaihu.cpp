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
	cout << "��ѡ����Ҫ����������" << endl;
	cout << "********** 1.����˻� **********" << endl;
	cout << "********** 2.�����˻� **********" << endl;
	cout << "********** 3.���� **********" << endl;
	cout << "********** 4.������һ�� **********" << endl;
}
void kaihu::Account()
{
		ofstream fout("����˻�.txt", ios::app);
		if (!fout)

		{
			cout << "�ļ��򿪴��󣬳������" << endl;
			exit(0);
		}
		fout << ID << " " << Name << " " << Phone << " " << Cunkuan << " " <<Dingqi<<" "<<Dingqi_Time<<" "<< Mima << " " << 0  << " " << Year << " " << Month << " " << Day << "\n";
		fout.clear();
		fout.close();
		cout << "�˻�¼�����" << endl;
		system("pause");
		system("cls");
		Administrator JJJ;
		JJJ.show();
}


void kaihu::DK_account()
{
	ofstream fout("�����˻�.txt", ios::app);
	if (!fout)
	{
		cout << "�ļ��򿪴��󣬳������" << endl;
		exit(0);
	}
	if (Day > 28)
	{
		cout << "���³���28�Ų�������������¸���1������" << endl;
	}
	else
	{
		fout << ID << " " << Name << " " << Phone << " " << Daikuan << " " << DKYear << " " << Mima <<" "<< Year << " " << Month << " " << Day << "\n";
		cout << "�˻�¼�����" << endl;
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