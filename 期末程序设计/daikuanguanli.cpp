#include "daikuanguanli.h"



daikuanguanli::daikuanguanli()
{

}


daikuanguanli::daikuanguanli(int i,string MI)
{
	id = i;
	password = MI;
}


daikuanguanli::~daikuanguanli(void)
{
}

void daikuanguanli::show(int a,string b)
{
	int n;
	cout << "请选择您需要办理的业务" << endl;
	cout << "*********1.贷款**********" << endl;
	cout << "*********2.还款**********" << endl;
	cout << "*********其他.返回上一层**********" << endl;
	cin >> n;
	system("cls");
	if (n == 1)
	{
		daikuanguanli A(a,b);
		A.loans();
	}
	else if (n == 2)
	{
		daikuanguanli B(a,b);
		B.Loan();
	}
	else
	{
			Administrator P;
			P.show();
	}
	cout << "按0结束" << endl;
	cout << "按1返回上一层" << endl;
	cout << "按其他返回主菜单" << endl;
	int y;
	cin >> y;
	system("cls");
	if (y == 0)
	{
		exit(0);
	}
	else if (y == 1)
	{
		daikuanguanli U(a, b);
		U.show(a, b);
	}
	else
	{
		Administrator P;
		P.show();
	}
}


void daikuanguanli::MIMA()
{
	ifstream fin("贷款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("贷款账户.txt");
	DK* q = new DK[n];
	int a, Y, M, D;
	double c;
	string b, e, d;
    int y; int timing;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> d >> c >> y >> e >> Y >> M >> D;
		q[i].ID = a;
		q[i].Name = b;
		q[i].Phone = d;
		q[i].Daikuan = c;
		q[i].Dai_time = y;
		q[i].Mima = e;
		q[i].Year = Y;
		q[i].Month = M;
		q[i].Day = D;
	}
	for (int j = 0; j < n; j++)
	{
		if (id == q[j].ID)
		{
			if ( password== q[j].Mima)
			{
				cout << "密码正确" << endl;
				daikuanguanli L;
				L.show(id, password);
				break;
			}
			else if (password != q[j].Mima)
			{
				int i; string m;
				cout << "密码错误，请重新输入" << endl;
				cout << "请输入ID和密码" << endl;
				cin >> i;
				cin.get();
				getline(cin, m);
				system("cls");
				daikuanguanli a(i, m);
				a.MIMA();
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
				daikuanguanli B(I, M);
				B.MIMA();
			}
	}
	fin1.clear();
	fin1.close();
	delete[]q;
}

void daikuanguanli::loans()//贷款
{
	cout<<"注意！！！本月超过28号不予办理贷款" << endl;
	ifstream fin("贷款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("贷款账户.txt");
	DK* dai = new DK[n];
	int a,f, Y, M, D;
	double c;
	string b,e,d;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> e >> c >> f >> d >> Y >> M >> D;
		dai[i].ID = a;
		dai[i].Name = b;
		dai[i].Phone = e;
		dai[i].Daikuan = c;
		dai[i].Dai_time = f;
		dai[i].Mima = d;
		dai[i].Year = Y;
		dai[i].Month = M;
		dai[i].Day = D;
	}
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	for (int j = 0; j < n; j++)
	{
		if (id == dai[j].ID)
		{
			if (DDD <= 28)
			{
				if (dai[j].Daikuan == 0)
				{
					cout << "请输入需要的贷款的金额和贷款时间" << endl;
					double Y;
					int N;
					cin >> Y>>N;
					dai[j].Daikuan = Y;
					dai[j].Dai_time = N;
					system("cls");
					break;
				}
				else
				{
					cout << "您的账户正处于借款之中，请先偿还贷款，才可进行新一次的贷款" << endl;
					break;
				}
			}
			else
			{
				cout << "本月超过28号不予办理贷款，请于下个月1号再来" << endl;
				break;
			}
		}
		
	}
	ofstream fout("贷款账户.txt");
	for (int i = 0; i < n; i++)
	{
		fout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << " " << dai[i].Dai_time << " " <<dai[i].Mima<<" "<< dai[i].Year << " " << dai[i].Month << " " << dai[i].Day << "\n";
	}
	fin1.clear();
	fin1.close();
	fout.clear();
	fout.close();
}

void daikuanguanli::Loan()//还款
{
	ifstream fin("贷款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("贷款账户.txt");
	DK* dai = new DK[n];
	int a, f, Y, M, D;
	double c;
	string b, e,d;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> e >> c >> f >> d >> Y >> M >> D;
		dai[i].ID = a;
		dai[i].Name = b;
		dai[i].Phone = e;
		dai[i].Daikuan = c;
		dai[i].Dai_time = f;
		dai[i].Mima = d;
		dai[i].Year = Y;
		dai[i].Month = M;
		dai[i].Day = D;
	}
	ifstream finn("收入.txt");
	double RR=0,III=0;
	finn >> RR;
	for (int i = 0; i < n; i++)
	{
		if (id == dai[i].ID)
		{
			cout << "请注意，如果提前还款，利息将按照之前的时常计算" << endl;
			cout << "您的贷款开始时间为" << dai[i].Year << "/" << dai[i].Month << "/" << dai[i].Day << endl;
			cout << "您的贷款时间为" << dai[i].Dai_time << "年" << endl;
			cout << "还款请按1，暂时不换请按其他" << endl;
			int G;
			cin >> G;
			system("cls");
			if (G == 1)
			{
				III= dai[i].Daikuan* 0.0475 * dai[i].Dai_time;
				cout << "您需要还款的金额为" << dai[i].Daikuan + III;
				cout << "请再次确认是否还款,确定请按1" << endl;
				int r;
				cin >> r;
				system("cls");
				if (r == 1)
				{
					dai[i].Daikuan = 0;
					dai[i].Dai_time = 0;
					RR = RR + III;
					break;
				}
				else
					break;//（返回主菜单）
			}
			else
			{
				break;//返回上一层
			}
		}

	}
	ofstream income("收入.txt");
	income << RR;
	ofstream fout("贷款账户.txt");
	for (int i = 0; i < n; i++)
	{
		fout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << " " << dai[i].Dai_time << " " << dai[i].Mima << " " << dai[i].Year << " " << dai[i].Month << " " << dai[i].Day << "\n";
	}
	finn.clear();
	finn.close();
	income.clear();
	income.close();
	fout.clear();
	fout.close();
}


void daikuanguanli::search()//查询贷款时间快到的用户
{
	ifstream fin("贷款账户.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("贷款账户.txt");
	DK* dai = new DK[n];
	int a, f, Y, M, D;
	double c;
	string b, e, d;
	for (int i = 0; i < n; i++)
	{
		fin1 >> a >> b >> e >> c >> f >> d >> Y >> M >> D;
		dai[i].ID = a;
		dai[i].Name = b;
		dai[i].Phone = e;
		dai[i].Daikuan = c;
		dai[i].Dai_time = f;
		dai[i].Mima = d;
		dai[i].Year = Y;
		dai[i].Month = M;
		dai[i].Day = D;
	}
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	for (int i = 0; i < n; i++)
	{
		if (dai[i].Daikuan != 0)
		{
			if (YYY >= dai[i].Year + dai[i].Dai_time && MMM >= dai[i].Month)
			{
				if (YYY > dai[i].Year + dai[i].Dai_time)
				{
					cout << "这个用户已经逾期" << endl;
					cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
				}
				else
				{
					if (MMM > dai[i].Month)
					{
						cout << "这个用户已经逾期" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
					}
					else
					{
						cout << "这个用户的贷款日期剩余不足个月，请注意联系其进行反还贷款" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						if (DDD == dai[i].Day)
						{
							cout << "这个用户已经到达还款日期" << endl;//开户时超过28号，不予办理；
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
						else if (DDD > dai[i].Day)
						{
							cout << "该用户以及逾期" << endl;
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
					}
				}
			}
			else
				cout << "暂未有快到期的用户" << endl;
		
		}
	}
	system("pause");
	system("cls");
	Administrator II;
	II.show();
}