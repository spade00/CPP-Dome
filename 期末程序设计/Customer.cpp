#include "Customer.h"
#include<iostream>
#include"Query.h"
#include<string>
using namespace std;

void Customer::Customer_interface()
{
	int id;
	string mima;
	cout << "�װ����û�����ӭ��������غ��ġ����й���ϵͳ" << endl;
	cout << "�밴�������ʾѡ������Ҫ�����ҵ��" << endl;
	cout << "���������ID������" << endl;
	cin >> id;
	cin.get();
	getline(cin, mima);
	system("cls");
	Query A(id, mima);
	A.verify();
}
