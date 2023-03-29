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
	cout << "��ѡ������Ҫ�����ҵ��" << endl;
	cout << "*********1.����**********" << endl;
	cout << "*********2.����**********" << endl;
	cout << "*********����.������һ��**********" << endl;
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
	cout << "��0����" << endl;
	cout << "��1������һ��" << endl;
	cout << "�������������˵�" << endl;
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
	ifstream fin("�����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("�����˻�.txt");
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
				cout << "������ȷ" << endl;
				daikuanguanli L;
				L.show(id, password);
				break;
			}
			else if (password != q[j].Mima)
			{
				int i; string m;
				cout << "�����������������" << endl;
				cout << "������ID������" << endl;
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
				cout << "δ��ѯ�����˻�,����������" << endl;
				cout << "������ID������" << endl;
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

void daikuanguanli::loans()//����
{
	cout<<"ע�⣡�������³���28�Ų���������" << endl;
	ifstream fin("�����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("�����˻�.txt");
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
					cout << "��������Ҫ�Ĵ���Ľ��ʹ���ʱ��" << endl;
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
					cout << "�����˻������ڽ��֮�У����ȳ�������ſɽ�����һ�εĴ���" << endl;
					break;
				}
			}
			else
			{
				cout << "���³���28�Ų�������������¸���1������" << endl;
				break;
			}
		}
		
	}
	ofstream fout("�����˻�.txt");
	for (int i = 0; i < n; i++)
	{
		fout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << " " << dai[i].Dai_time << " " <<dai[i].Mima<<" "<< dai[i].Year << " " << dai[i].Month << " " << dai[i].Day << "\n";
	}
	fin1.clear();
	fin1.close();
	fout.clear();
	fout.close();
}

void daikuanguanli::Loan()//����
{
	ifstream fin("�����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("�����˻�.txt");
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
	ifstream finn("����.txt");
	double RR=0,III=0;
	finn >> RR;
	for (int i = 0; i < n; i++)
	{
		if (id == dai[i].ID)
		{
			cout << "��ע�⣬�����ǰ�����Ϣ������֮ǰ��ʱ������" << endl;
			cout << "���Ĵ��ʼʱ��Ϊ" << dai[i].Year << "/" << dai[i].Month << "/" << dai[i].Day << endl;
			cout << "���Ĵ���ʱ��Ϊ" << dai[i].Dai_time << "��" << endl;
			cout << "�����밴1����ʱ�����밴����" << endl;
			int G;
			cin >> G;
			system("cls");
			if (G == 1)
			{
				III= dai[i].Daikuan* 0.0475 * dai[i].Dai_time;
				cout << "����Ҫ����Ľ��Ϊ" << dai[i].Daikuan + III;
				cout << "���ٴ�ȷ���Ƿ񻹿�,ȷ���밴1" << endl;
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
					break;//���������˵���
			}
			else
			{
				break;//������һ��
			}
		}

	}
	ofstream income("����.txt");
	income << RR;
	ofstream fout("�����˻�.txt");
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


void daikuanguanli::search()//��ѯ����ʱ��쵽���û�
{
	ifstream fin("�����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("�����˻�.txt");
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
					cout << "����û��Ѿ�����" << endl;
					cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
				}
				else
				{
					if (MMM > dai[i].Month)
					{
						cout << "����û��Ѿ�����" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
					}
					else
					{
						cout << "����û��Ĵ�������ʣ�಻����£���ע����ϵ����з�������" << endl;
						cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						if (DDD == dai[i].Day)
						{
							cout << "����û��Ѿ����ﻹ������" << endl;//����ʱ����28�ţ��������
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
						else if (DDD > dai[i].Day)
						{
							cout << "���û��Լ�����" << endl;
							cout << dai[i].ID << " " << dai[i].Name << " " << dai[i].Phone << " " << dai[i].Daikuan << endl;
						}
					}
				}
			}
			else
				cout << "��δ�п쵽�ڵ��û�" << endl;
		
		}
	}
	system("pause");
	system("cls");
	Administrator II;
	II.show();
}