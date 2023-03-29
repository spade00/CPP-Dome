#include "Query.h"

Query::Query()
{
	
}
Query::Query(int id,string mima,double k,double Q)
{
	iD = id;
	mi = mima;
	CunK = k;
	QvK = Q;
}


Query::Query(int id, string mima,double k, int Q)
{
	iD = id;
	mi = mima;
	CunK = 0;
	DING = k;
	DING_TIME = Q;
}


Query::~Query(void)
{
}
void Query::show(int a,string b)
{
	int n;
	cout << "请选择您需要办理的业务" << endl;
	cout << "*********1.查询余额**********" << endl;
	cout << "*********2.取款**********" << endl;
	cout << "*********3.存款**********" << endl;
	cout << "*********4.修改银行密码**********" << endl;
	cout << "*********5.退出程序**********" << endl;
	cout << "*********6.退出登录**********" << endl;
	cout << "*********7.切换至管理员模式**********" << endl;
	cin >> n;
	system("cls");
	if (n == 1)
	{
		Query A(a, b);
		A.search();
		system("pause");
		system("cls");
	}
	else if (n == 2)
	{
		double j;
		cout << "请输入需要取款的金额" << endl;
		cin >> j;
		system("cls");
		Query B(a, b, 0, j);
		B.QVKUAN();
		system("pause");
		system("cls");
	}
	else if (n == 3)
	{
		int M;
		cout << "请选择存款的方式" << endl;
		cout << "1.活期" << endl;
		cout << "2.定期" << endl;
		cin >> M;
		if (M == 1)
		{
			double j;
			cout << "请输入存款的金额" << endl;
			cin >> j;
			system("cls");
			Query B(a, b, j);
			B.CUNKUAN();
		}
		else
		{
			double j1; int J2;
			cout << "请输入定期的金额和时间" << endl;
			cin >> j1>>J2;
			system("cls");
			Query B(a, b,j1,J2);
			B.CUNKUAN();
		}
		system("pause");
		system("cls");
	}
	else if (n == 4)
	{
		string d;
		cin.get();
		cout << "请输入新密码" << endl;
		getline(cin, d);
		system("cls");
		Query D(a, d);
		D.Change_password();
		system("pause");
		system("cls");
	}
	else if (n == 5)
		exit(0);
	else if(n==6)
	{
		Customer PPP;
		PPP.Customer_interface();
	}
	else
	{
		string M;
		cout << "请输入管理员的验证码" << endl;
		cin.get();
		getline(cin, M);
		virtaul B(M);
		B.verify111();
	}
	cout << "按0结束" << endl;
	cout << "按1返回上一层" << endl;
	cout << "按其他退出登录" << endl;
	int y;
	cin >> y;
	system("cls");
	if (y == 0)
	{
		exit(0);
	}
	else if(y==1)
	{
		Query U(a, b);
		U.show(a,b);
	}
	else
	{
		Customer P;
		P.Customer_interface();
	}
}


void Query::verify()//验证密码
{
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e,d;
	double s; int y;int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e>>timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	for (int j = 0; j < n; j++)
	{
		if (iD == q[j].ID)
		{
			if (mi == q[j].Mima)
			{
				cout << "密码正确" << endl;
				Query l;
				l.show(iD,mi);
				break;
			}
			else if (mi != q[j].Mima)
			{
				int i; string m;
				int pa;
				cout << "密码错误" << endl;
				cout << "退出请按1，继续尝试登录请按其他" << endl;
				cin >> pa;
				system("cls");
				if (pa == 1)
				{
					exit(0);
				}
				else
				{
					cout << "请重新请输入ID和密码" << endl;
					cin >> i;
					cin.get();
					getline(cin, m);
					system("cls");
					Query a(i, m);
					a.verify();
				}
				break;
			}
		}
		else
			if (j == n - 1)
			{
				int I; string M;
				int pa1;
				cout << "未查询到该账户" << endl;
				cout << "退出请按1，继续尝试登录请按其他" << endl;
				cin >> pa1;
				system("cls");
				if (pa1 == 1)
				{
					exit(0);
				}
				else
				{
					cout << "请输入ID和密码" << endl;
					cin >> I;
					cin.get();
					getline(cin, M);
					system("cls");
					Query B(I, M);
					B.verify();
				}
			}
	}
	fin1.clear();
	fin1.close();
	delete[]q;
}


void Query::search()//查询余额
{
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	for (int j = 0; j < n; j++)
	{
		if (iD == q[j].ID)
		{
			cout << "您的余额为：" << q[j].Cunkuan << endl;
			cout << "您的定期信息为：" << q[j].ding << "定期时间为：" << q[j].ding_time << "年" << endl;
			cout << "定期开始时间" << q[j].Year << "/" << q[j].Month << "/" << q[j].Day << endl;
			break;
		}
	}
	fin1.clear();
	fin1.close();
	delete[]q;
}

void Query::CUNKUAN()//存款
{
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	double III = 0;
	ifstream finn("收入.txt");
	double RR;
	finn >> RR;
	finn.clear();
	finn.close();
	for (int j = 0; j < n; j++)
	{
		if (iD == q[j].ID)
		{
			if (CunK != 0)
			{
				III = q[j].Cunkuan * (0.4 / 360) * q[j].timing;
				q[j].Cunkuan = q[j].Cunkuan + CunK + III;
				q[j].timing = 0;
			}
			else if(q[j].ding==0)
			{
				q[j].ding = DING;
				q[j].ding_time = DING_TIME;
			}
			else
			{
				cout << "暂时无法存入" << endl;
			}
		}
	}
	RR = RR - III;
	ofstream income("收入.txt");
	income << RR;//统计利息
	ofstream fout("存款账户.txt");
	for (int i = 0; i < n; i++)
	{
		fout << q[i].ID << " " << q[i].Name << " " << q[i].Phone << " " << q[i].Cunkuan << " "<<q[i].ding<<" "<<q[i].ding_time<<" " << q[i].Mima << " " <<q[i].timing<<" "<< q[i].Year << " " << q[i].Month << " " << q[i].Day << "\n";
	}
	income.clear();
	income.close();
	fout.clear();
	fout.close();
	fin1.clear();
	fin1.close();
	delete[]q;
}

void Query::QVKUAN()//取款
{
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	double II = 0;
	ifstream finn("收入.txt");
	double RR;
	finn >> RR;
	finn.clear();
	finn.close();
	for (int j = 0; j < n; j++)
	{
		if (iD == q[j].ID)
		{
			if (QvK <= q[j].Cunkuan)
			{
				II = q[j].Cunkuan * (0.4 / 360) * q[j].timing;
				q[j].Cunkuan = q[j].Cunkuan - QvK + II;
				q[j].timing = 0;
			}
			else
				cout << "取款失败,余额不足" << endl;
		}
	}
	RR = RR - II;
	ofstream income("收入.txt");
	income << RR;//统计利息
	ofstream fout("存款账户.txt");
	for (int i = 0; i < n; i++)
	{
		fout << q[i].ID << " " << q[i].Name << " " << q[i].Phone << " " << q[i].Cunkuan << " " << q[i].ding << " " << q[i].ding_time << " " << q[i].Mima << " " << q[i].timing << " " << q[i].Year << " " << q[i].Month << " " << q[i].Day << "\n";
	}
	income.clear();
	income.close();
	fout.clear();
	fout.close();
	fin1.clear();
	fin1.close();
	delete[]q;
}

void Query::Change_password()//修改密码
{
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	for (int j = 0; j < n; j++)
	{
		if (iD == q[j].ID)
		{
			q[j].Mima = mi;
		}
	}
	ofstream fout("存款账户.txt");
	for (int i = 0; i < n; i++)
	{
		fout << q[i].ID << " " << q[i].Name << " " << q[i].Phone << " " << q[i].Cunkuan << " " << q[i].ding << " " << q[i].ding_time << " " << q[i].Mima << " " << q[i].timing << " " << q[i].Year << " " << q[i].Month << " " << q[i].Day << "\n";
	}
	fout.clear();
	fout.close();
	fin1.clear();
	fin1.close();
	delete[]q;
}

void Query::Account_cancellation()//销户
{
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	int j;
	for (j = 0; j < n; j++)
	{
		if (iD == q[j].ID)
		{
			if (mi == q[j].Mima)
			{
				cout << "重要的事情说三遍，此操作会删除您的所有信息，请小心操作" << endl;
				cout << "重要的事情说三遍，此操作会删除您的所有信息，请小心操作" << endl;
				cout << "重要的事情说三遍，此操作会删除您的所有信息，请小心操作" << endl;
				Query B(iD, mi);
				cout << "密码正确" << endl;
				B.search();
				cout << endl;
				cout << "请您将其全部取出" << endl;
				int c;
				cout << "请输入取出的金额" << endl;
				cin >> c;
				system("cls");
				Query C(iD, mi, 0, c);
				C.QVKUAN();
				break;
			}
			else if (mi != q[j].Mima)
			{
				int O; string M;
				cout << "密码错误，请重新输入" << endl;
				cout << "请输入ID和密码" << endl;
				cin >> O;
				cin.get();
				getline(cin, M);
				system("cls");
				Query A(O,M);
				A.Account_cancellation();
				break;
			}
		}
		else
			if (j == n - 1)
			{
				int I; string M;
				cout << "未查询到该账户,请重新输入" << endl;
				cout << "请输入ID和密码" << endl;
				cin >> I;
				cin.get();
				getline(cin, M);
				system("cls");
				Query C(I, M);
				C.Account_cancellation();
				break;
			}	
	}

	ofstream fout("存款账户.txt");
	for (int i = 0; i < n; i++)
	{ 
		if (i == j)
		{
			cout << "销户成功" << endl;
		}
		else
		{
			fout << q[i].ID << " " << q[i].Name << " " << q[i].Phone << " " << q[i].Cunkuan << " " << q[i].ding << " " << q[i].ding_time << " " << q[i].Mima << " " << q[i].timing << " " << q[i].Year << " " << q[i].Month << " " << q[i].Day << "\n";
		}
	}
	fout.clear();
	fout.close();
	fin1.clear();
	fin1.close();
	delete[]q;
	system("pause");
	system("cls");
	Query LLP;
	LLP.show(iD, mi);
}

void Query::Statistical()//统计收入
{
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	if (DDD == 1)
	{
		ifstream fin("存款账户.txt");
		char str[100];
		int n = -1;
		while (!fin.eof())
		{
			fin.getline(str, sizeof(str));
			n++;
		}
		fin.clear();
		fin.close();
		ifstream fin1("存款账户.txt", ios::in);
		CU* q = new CU[n];
		int a, Y, M, D;
		double c;
		string b, e, d;
		double s; int y; int timing;
		for (int i = 0; i < n; i++)
		{
			fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
			q[i].ID = a;
			q[i].Name = b;
			q[i].Phone = d;
			q[i].Cunkuan = c;
			q[i].ding = s;
			q[i].ding_time = y;
			q[i].Mima = e;
			q[i].timing = timing;
			q[i].Year = Y;
			q[i].Month = M;
			q[i].Day = D;
		}
		double III, RR;
		ifstream finn("收入.txt");
		finn >> RR;
		finn.clear();
		finn.close();
		for (int j = 0; j < n; j++)
		{
				III = q[j].Cunkuan * (0.4 / 360) * q[j].timing;
				q[j].Cunkuan = q[j].Cunkuan + III;
				q[j].timing = 0;
				RR = RR - III;
		}
		ofstream fout2("每月收入统计.txt",ios::app);
		ofstream income("收入.txt");
		cout << "本月收入为" << RR << endl;
		fout2 << MMM-1 << "月收入为:" << RR<<"\n";
		RR = 0;
		income << RR;//统计利息
		ofstream fout("存款账户.txt");
		for (int i = 0; i < n; i++)
		{
			fout << q[i].ID << " " << q[i].Name << " " << q[i].Phone << " " << q[i].Cunkuan << " " << q[i].ding << " " << q[i].ding_time << " " << q[i].Mima << " " << q[i].timing << " " << q[i].Year << " " << q[i].Month << " " << q[i].Day << "\n";
		}
		income.clear();   
		income.close();
		fout.clear();
		fout.close();
		fin1.clear();
		fin1.close();
		delete[]q;
		system("pause");
		system("cls");
		Administrator WWW;
		WWW.show();
	
	}
	else
	{
		cout << "本月账单暂未出账，请下个月一号再次进行查询" << endl;
		cout << "按1可查看1号到当前的的账单，按其他则返回上一层" << endl;
		int JJ;
		double YYYY;
		cin >> JJ;
		system("cls");
		if (JJ == 1)
		{
			ifstream d("收入.txt");
			d >> YYYY;
			cout << "本月收入为" << YYYY <<"元"<< endl;
			system("pause");
			system("cls");
			d.clear();
			d.close();
			Administrator WWW;
			WWW.show();
		}
		else
		{
			Administrator WWW;
			WWW.show();
		}

	}
}

void Query::Timing()//计时
{
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	ifstream fin("存款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("存款账户.txt", ios::in);
	CU* q = new CU[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
	double s; int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> s >> y >> e >> timing >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Cunkuan = c;
		q[i].ding = s;
		q[i].ding_time = y;
		q[i].Mima = e;
		q[i].timing = timing;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	for (int i = 0; i < n; i++)
	{
		if (YYY == q[i].Year + q[i].ding_time)
		{
			if (MMM == q[i].Month)
			{
				if (DDD == 1)
				{
					double RRR;
					RRR = q[i].ding * 0.3 * q[i].ding_time;
					cout << "该用户的定期时间已经快到了，明天就可以领取，定期的金额将于明日自动转入活期账户中" << endl;
					cout << "本次定期产生的利息为" << RRR << endl;
					Query B(q[i].ID, q[i].Mima, q[i].ding+RRR);
					B.CUNKUAN();
					q[i].ding = 0;
					q[i].ding_time = 0;
				}

			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		q[j].timing = q[j].timing+1;
	}
	ofstream fout("存款账户.txt");
	for (int i = 0; i < n; i++)
	{
		fout << q[i].ID << " " << q[i].Name << " " << q[i].Phone << " " << q[i].Cunkuan << " " << q[i].ding << " " << q[i].ding_time << " " << q[i].Mima << " " << q[i].timing << " " << q[i].Year << " " << q[i].Month << " " << q[i].Day << "\n";
	}
	fout.clear();
	fout.close();
	fin1.clear();
	fin1.close();
	delete[]q;
}

