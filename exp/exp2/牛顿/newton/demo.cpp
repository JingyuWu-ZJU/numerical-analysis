#include <iostream>
#include "cmath"
#include <iomanip>
using namespace std;

double max;//�Ͻ�
double min;//�½�
double precis;//����
double x0;//ţ�ٳ�ʼֵ

double f(double x)
{
	return x*x*x-x-1;
	//return 1/x-3;
}

double p(double x)
{
	return 3*x*x-1;
	//return log(x);
}

void Binary(double min,double max,double precis)
{

	double mid = 0;
	int i = 0;
	cout<<"���ַ��������£�"<<endl;
	cout<<" ����     ֵ"<<endl;

	for(i=1;precis<fabs((max-min));i++)
	{
		mid = (min + max)/2.0;
		if(f(min)*f(mid)<0)
			max = mid;
		else if(f(mid) == 0.00)
			break;
		else 
			min = mid;
		cout<<setw(2)<<i<<""<<setw(10)<<mid<<endl;

	}
	cout<<"�ܹ�������"<<i<<"�ε�����"<<endl;
}



void Newton(double x0,double precis)
{
	int flag;
	double x1 = 0;
	int k = 1;
	cout<<"ţ�ٷ��������£�"<<endl;
	cout<<" ����     ֵ"<<endl;
	while(1)
	{

		if(p(x0) == 0)
		{
			flag = 1;
			break;
		}
		x1 = x0 - f(x0)/p(x0);
		if(fabs(x1-x0)<precis)
			break;
		else
		{
			cout<<setw(2)<<k<<""<<setw(10)<<x0<<endl;
		}
		k++;
		x0 = x1;
		if(k>1000)	break;
		
	}
	if(k<1000)
		cout<<"�ܹ�������"<<k-1<<"�ε�����"<<endl;
	else	
		cout<<"ţ�����з�ɢ��"<<endl;
}

int main()
{
	cout<<"�����뺯������������";
	cin>>min;
	cout<<endl;
	cout<<"�����뺯������������";
	cin>>max;
	cout<<endl;
	cout<<"�����þ���";
	cin>>precis;
	cout<<endl;
	Binary(min,max,precis);
	cout<<endl;
	cout<<"������ţ�ٵĳ�ʼֵ��";
	cin>>x0;
	Newton(x0,precis);
	return 0;
}
