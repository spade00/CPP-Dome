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
	int timing;//���ڼ�ʱ
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
	double CunK;//���
	double DING;//����
	int DING_TIME;//����ʱ��
	double QvK;//ȡ��
public:
	Query(int,string,double=0,double=0);
	Query(int, string, double , int);
	Query();
	~Query(void);
	void show(int,string);//��ʾ����
	void search();//��ѯ
	void verify();//��֤����
	void CUNKUAN();//���
	void QVKUAN();//ȡ��
	void Change_password();//��������
	void Account_cancellation();//����
	void Statistical();//ͳ������
	void Timing();//��ʱ
};

