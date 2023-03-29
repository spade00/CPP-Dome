#pragma once
#include "virtaul.h"
#include "kaihu.h"
#include<iostream>
#include<string>
#include"Customer.h"
#include"Administrator.h"
using namespace std;
struct CU
{
	int ID;
	string Name;
	string Phone;
	double Cunkuan;
	double ding;
	int ding_time;
	int timing;//活期计时
	int Year;
	int Month;
	int Day;
	string Mima;
};
class Query :
	public virtaul,kaihu
{
	string mi;
	int iD;
	double CunK;//存款
	double DING;//定期
	int DING_TIME;//定期时间
	double QvK;//取款
public:
	Query(int,string,double=0,double=0);
	Query(int, string, double , int);
	Query();
	~Query(void);
	void show(int,string);//显示界面
	void search();//查询
	void verify();//验证密码
	void CUNKUAN();//存款
	void QVKUAN();//取款
	void Change_password();//更改密码
	void Account_cancellation();//销户
	void Statistical();//统计收入
	void Timing();//计时
};

