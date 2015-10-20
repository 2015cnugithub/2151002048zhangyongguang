using namespace std;
#include <iostream>
class worker
{
public:
	char *name;
	int age;
	char sex;
	int pay_per_hour;
	char hs;//类别
	virtual double compute_pay(double hours)=0;
	worker (char hs1, char *name1, int age1, char sex1, int pay_per_hour1)
	{
		hs = hs1;
		name = name1;
		age = age1;
		sex = sex1;
		pay_per_hour = pay_per_hour1;
	}
	~worker() {};
};
class hourlyworker :public worker
{
public:
	double compute_pay(double hours)
   {
	double salary;
	if (hours <= 40)
		salary = pay_per_hour*hours;
	else
		salary = pay_per_hour * 40 + 1.5*pay_per_hour*(hours - 40);
	return salary;
	}
	hourlyworker(char *name1, int age1, char sex1, int pay_per_hour1)
	{
		name = name1;
		age = age1;
		sex = sex1;
		pay_per_hour = pay_per_hour1;
	}
	~hourlyworker(){}
};
class salariedworker :public worker
{
public:
	double compute_pay(double hours)
	{
		double salary;
		if (hours >= 35)
			salary = pay_per_hour * 40;
		else
			salary = pay_per_hour*hours + 0.5*pay_per_hour*(35 - hours);
		return salary;
	}
	salariedworker(char *name1, int age1, char sex1, int pay_per_hour1)
	{
		name = name1;
		age = age1;
		sex = sex1;
		pay_per_hour = pay_per_hour1;
	}
	~salariedworker(){}
};
void main()
{
	char hs[5];
	char *name;
	int age[5];
	char sex[5];
	int pay_per_hour[5];
	int i=0,hour;
	double salary;
	for (i = 0; i < 5; i++)
	{
		cout << "请依次输入工人信息：类型h/s，姓名，年龄，性别m/f，小时工资额。";
		cin >> hs[i];
		cin >> name;
		cin >> age[i];
		cin >> sex[i];
		cin >> pay_per_hour[i];
		 worker worker[i](hs[i],name[i],age[i],sex[i],pay_per_hour[i]);
	}
	for (i = 0; i < 5; i++)
	{
		cout << worker[i].name << "\n";
	}
	while (0)
	{
		cout << "输入选定的标号,输入0终止";
		cin >> i;
		if (i == 0)
			break;
		else
		{
			if (worker[i].hs =='h')
			{
				hourlyworker ahourlyworker(worker[i].name, worker[i].age, worker[i].sex, worker[i].pay_per_hour);
				cout << worker[i].name << worker[i].age << worker[i].sex << worker[i].pay_per_hour << "请输入工作时间";
				cin >> hour;
				salary = ahourlyworker.compute_pay(hour);
				cout << "salary=" << salary;
			};
			if (worker[i].hs == 's')
			{
				salariedworker asalariedworker(worker[i].name, worker[i].age, worker[i].sex, worker[i].pay_per_hour);
				cout << worker[i].name << worker[i].age << worker[i].sex << worker[i].pay_per_hour << "请输入工作时间";
				cin >> hour;
				salary = asalariedworker.compute_pay(hour);
				cout << "salary=" << salary;
			}
		}
	}
}