#pragma once
#include "virtaul.h"
#include"kaihu.h"
#include<windows.h>
#include<iostream>
#include<string>
#include"Query.h"
using namespace std;
struct DK
{
	int ID;
	string Name;
	string Phone;
	double Daikuan;
	int Dai_time;
	int Year;
	int Month;
	int Day;
	string Mima;
};
class daikuanguanli :
	public virtaul,kaihu 
{
public:
	daikuanguanli(int,string);
	daikuanguanli();
	~daikuanguanli(void);
	void show(int,string);//显示界面
	void search();//查询贷款是否到期
	void loans();//贷款
	void Loan();//还贷款
	void MIMA();//密码验证
private:
	double D;//贷款金额
	double id;
	string password;
};

