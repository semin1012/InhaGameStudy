#include <iostream>


/*
*/
#include "tv.h"
int main()
{
	using std::cout;
	Tv s42;
	cout << "42\" Tv의 초기 설정값:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);

	cout << "\n현재 리모콘의 ";
	grey.print_listen_mode();
	cout << "\n42로 리모콘 대화모드 설정\n";
	s42.set_listen_mode(grey);
	grey.print_listen_mode();

	cout << "\n\n42 Tv 전원 ON:\n";
	s42.onoff();
	cout << "42\" Tv의 설정값:\n";
	s42.settings();

	cout << "\n42로 리모콘 대화모드 다시 설정\n";
	s42.set_listen_mode(grey);
	cout << "\n현재 리모콘의 ";
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

	cout << "두 수를 입력하십시오: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << x << ", " << y << "의 조화평균은 " << z << "입니다.\n";
			cout << x << ", " << y << "의 기하평균은 " << gmean(x, y) << "입니다.\n";
			cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
		}
		catch (bad_hmean& bg)
		{
			bg.mesg();
			cout << "다시 하십시오.\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
			break;
		}
	}
	cout << "프로그램을 종료합니다.\n";
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