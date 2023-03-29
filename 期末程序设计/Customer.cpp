#include "Customer.h"
#include<iostream>
#include"Query.h"
#include<string>
using namespace std;

void Customer::Customer_interface()
{
	int id;
	string mima;
	cout << "亲爱的用户，欢迎来到“天地黑心”银行管理系统" << endl;
	cout << "请按界面的提示选择您需要办理的业务" << endl;
	cout << "请输入你的ID和密码" << endl;
	cin >> id;
	cin.get();
	getline(cin, mima);
	system("cls");
	Query A(id, mima);
	A.verify();
}
