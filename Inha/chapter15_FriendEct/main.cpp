#include <iostream>


/*
*/
#include "tv.h"
int main()
{
	using std::cout;
	Tv s42;
	cout << "42\" Tv�� �ʱ� ������:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);

	cout << "\n���� �������� ";
	grey.print_listen_mode();
	cout << "\n42�� ������ ��ȭ��� ����\n";
	s42.set_listen_mode(grey);
	grey.print_listen_mode();

	cout << "\n\n42 Tv ���� ON:\n";
	s42.onoff();
	cout << "42\" Tv�� ������:\n";
	s42.settings();

	cout << "\n42�� ������ ��ȭ��� �ٽ� ����\n";
	s42.set_listen_mode(grey);
	cout << "\n���� �������� ";
	grey.print_listen_mode();
	return 0;
}

/*
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "�� ���� �Է��Ͻʽÿ�: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << x << ", " << y << "�� ��ȭ����� " << z << "�Դϴ�.\n";
			cout << x << ", " << y << "�� ��������� " << gmean(x, y) << "�Դϴ�.\n";
			cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
		}
		catch (bad_hmean& bg)
		{
			bg.mesg();
			cout << "�ٽ� �Ͻʽÿ�.\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
			break;
		}
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
*/