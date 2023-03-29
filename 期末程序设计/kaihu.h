#pragma once
#include<string>
#include<Windows.h>
#include"Administrator.h"
#include<fstream>
#include "virtaul.h"
using namespace std;
class kaihu :
	public virtaul
{
 protected:
	int ID;
	string Name;
	int Year;
	int Month;
	int Day;
	double Cunkuan;//存款金额
	double Daikuan;//贷款金额
	double Dingqi;//定期
	int Dingqi_Time;//定期的时间
	string Phone;//电话号码
	string Mima;//密码
	int DKYear;//贷款年限
 public:
	void Account();
	void DK_account();
	kaihu(int,string,string,double,double ,int,string);
	kaihu(int, string, string, double, int, string);
	kaihu();
	void GetDate();
	void show();
};

