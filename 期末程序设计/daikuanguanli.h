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
	void show(int,string);//��ʾ����
	void search();//��ѯ�����Ƿ���
	void loans();//����
	void Loan();//������
	void MIMA();//������֤
private:
	double D;//������
	double id;
	string password;
};

