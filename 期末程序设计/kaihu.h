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
	double Cunkuan;//�����
	double Daikuan;//������
	double Dingqi;//����
	int Dingqi_Time;//���ڵ�ʱ��
	string Phone;//�绰����
	string Mima;//����
	int DKYear;//��������
 public:
	void Account();
	void DK_account();
	kaihu(int,string,string,double,double ,int,string);
	kaihu(int, string, string, double, int, string);
	kaihu();
	void GetDate();
	void show();
};

