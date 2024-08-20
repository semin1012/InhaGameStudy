#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StopWatch.h"
using namespace std;

/*
Q2. 단순 삽입 정렬 구현
	p.227 Q8처럼 정렬 과정을 표현하라.

*/

// 16-17
/*
template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) { }
	bool operator() (const T& v) { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	cout << "원래의 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(f100);
	etcetera.remove_if(TooBig<int>(200));
	cout << "정비된 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}
*/
/*
// 16-18
void Show(int);
const int LIM = 10;
int main()
{
	using namespace std;
	int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);
	cout << "오리지널 리스트의 내용:\n\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	la.remove(4);
	cout << "remove() 메서드를 사용한 후:\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show);
	cout << endl;
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "remove() 함수를 사용한 후:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	lb.erase(last, lb.end());
	cout << "erase() 메서드를 사용한 후:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << endl;
	return 0;
}

void Show(int v)
{
	std::cout << v << ' ';
}
*/

/**/
// 16-19
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

char toLower(char ch) { return tolower(ch); }
string& ToLower(string& st);
void display(const string& s);

int main()
{
	vector<string> words;
	cout << "단어들을 입력하십시오 (끝내려면 quit):\n";
	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);

	cout << "다음과 같은 단어들을 입력하셨습니다.\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
	cout << "\n단어들의 알파벳순 리스트:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);

	cout << "\n단어별 빈도:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;

	return 0;
}

string& ToLower(string& st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}
