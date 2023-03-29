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
	cout << "��ѡ������Ҫ�����ҵ��" << endl;
	cout << "*********1.��ѯ���**********" << endl;
	cout << "*********2.ȡ��**********" << endl;
	cout << "*********3.���**********" << endl;
	cout << "*********4.�޸���������**********" << endl;
	cout << "*********5.�˳�����**********" << endl;
	cout << "*********6.�˳���¼**********" << endl;
	cout << "*********7.�л�������Աģʽ**********" << endl;
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
		cout << "��������Ҫȡ��Ľ��" << endl;
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
		cout << "��ѡ����ķ�ʽ" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cin >> M;
		if (M == 1)
		{
			double j;
			cout << "��������Ľ��" << endl;
			cin >> j;
			system("cls");
			Query B(a, b, j);
			B.CUNKUAN();
		}
		else
		{
			double j1; int J2;
			cout << "�����붨�ڵĽ���ʱ��" << endl;
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
		cout << "������������" << endl;
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
		cout << "���������Ա����֤��" << endl;
		cin.get();
		getline(cin, M);
		virtaul B(M);
		B.verify111();
	}
	cout << "��0����" << endl;
	cout << "��1������һ��" << endl;
	cout << "�������˳���¼" << endl;
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


void Query::verify()//��֤����
{
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
				cout << "������ȷ" << endl;
				Query l;
				l.show(iD,mi);
				break;
			}
			else if (mi != q[j].Mima)
			{
				int i; string m;
				int pa;
				cout << "�������" << endl;
				cout << "�˳��밴1���������Ե�¼�밴����" << endl;
				cin >> pa;
				system("cls");
				if (pa == 1)
				{
					exit(0);
				}
				else
				{
					cout << "������������ID������" << endl;
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
				cout << "δ��ѯ�����˻�" << endl;
				cout << "�˳��밴1���������Ե�¼�밴����" << endl;
				cin >> pa1;
				system("cls");
				if (pa1 == 1)
				{
					exit(0);
				}
				else
				{
					cout << "������ID������" << endl;
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


void Query::search()//��ѯ���
{
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
			cout << "�������Ϊ��" << q[j].Cunkuan << endl;
			cout << "���Ķ�����ϢΪ��" << q[j].ding << "����ʱ��Ϊ��" << q[j].ding_time << "��" << endl;
			cout << "���ڿ�ʼʱ��" << q[j].Year << "/" << q[j].Month << "/" << q[j].Day << endl;
			break;
		}
	}
	fin1.clear();
	fin1.close();
	delete[]q;
}

void Query::CUNKUAN()//���
{
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
	ifstream finn("����.txt");
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
				cout << "��ʱ�޷�����" << endl;
			}
		}
	}
	RR = RR - III;
	ofstream income("����.txt");
	income << RR;//ͳ����Ϣ
	ofstream fout("����˻�.txt");
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

void Query::QVKUAN()//ȡ��
{
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
	ifstream finn("����.txt");
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
				cout << "ȡ��ʧ��,����" << endl;
		}
	}
	RR = RR - II;
	ofstream income("����.txt");
	income << RR;//ͳ����Ϣ
	ofstream fout("����˻�.txt");
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

void Query::Change_password()//�޸�����
{
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
	ofstream fout("����˻�.txt");
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

void Query::Account_cancellation()//����
{
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
				cout << "��Ҫ������˵���飬�˲�����ɾ������������Ϣ����С�Ĳ���" << endl;
				cout << "��Ҫ������˵���飬�˲�����ɾ������������Ϣ����С�Ĳ���" << endl;
				cout << "��Ҫ������˵���飬�˲�����ɾ������������Ϣ����С�Ĳ���" << endl;
				Query B(iD, mi);
				cout << "������ȷ" << endl;
				B.search();
				cout << endl;
				cout << "��������ȫ��ȡ��" << endl;
				int c;
				cout << "������ȡ���Ľ��" << endl;
				cin >> c;
				system("cls");
				Query C(iD, mi, 0, c);
				C.QVKUAN();
				break;
			}
			else if (mi != q[j].Mima)
			{
				int O; string M;
				cout << "�����������������" << endl;
				cout << "������ID������" << endl;
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
				cout << "δ��ѯ�����˻�,����������" << endl;
				cout << "������ID������" << endl;
				cin >> I;
				cin.get();
				getline(cin, M);
				system("cls");
				Query C(I, M);
				C.Account_cancellation();
				break;
			}	
	}

	ofstream fout("����˻�.txt");
	for (int i = 0; i < n; i++)
	{ 
		if (i == j)
		{
			cout << "�����ɹ�" << endl;
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

void Query::Statistical()//ͳ������
{
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	if (DDD == 1)
	{
		ifstream fin("����˻�.txt");
		char str[100];
		int n = -1;
		while (!fin.eof())
		{
			fin.getline(str, sizeof(str));
			n++;
		}
		fin.clear();
		fin.close();
		ifstream fin1("����˻�.txt", ios::in);
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
		ifstream finn("����.txt");
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
		ofstream fout2("ÿ������ͳ��.txt",ios::app);
		ofstream income("����.txt");
		cout << "��������Ϊ" << RR << endl;
		fout2 << MMM-1 << "������Ϊ:" << RR<<"\n";
		RR = 0;
		income << RR;//ͳ����Ϣ
		ofstream fout("����˻�.txt");
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
		cout << "�����˵���δ���ˣ����¸���һ���ٴν��в�ѯ" << endl;
		cout << "��1�ɲ鿴1�ŵ���ǰ�ĵ��˵����������򷵻���һ��" << endl;
		int JJ;
		double YYYY;
		cin >> JJ;
		system("cls");
		if (JJ == 1)
		{
			ifstream d("����.txt");
			d >> YYYY;
			cout << "��������Ϊ" << YYYY <<"Ԫ"<< endl;
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

void Query::Timing()//��ʱ
{
	int YYY, MMM, DDD;
	SYSTEMTIME syst;
	GetLocalTime(&syst);
	YYY = syst.wYear;
	MMM = syst.wMonth;
	DDD = syst.wDay;
	ifstream fin("����˻�.txt");
	char str[100];
	int n = -1;
	while (!fin.eof())
	{
		fin.getline(str, sizeof(str));
		n++;
	}
	fin.clear();
	fin.close();
	ifstream fin1("����˻�.txt", ios::in);
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
					cout << "���û��Ķ���ʱ���Ѿ��쵽�ˣ�����Ϳ�����ȡ�����ڵĽ��������Զ�ת������˻���" << endl;
					cout << "���ζ��ڲ�������ϢΪ" << RRR << endl;
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
	ofstream fout("����˻�.txt");
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

