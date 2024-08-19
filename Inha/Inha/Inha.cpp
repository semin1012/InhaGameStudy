#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include "StopWatch.h"
using namespace std;

/*
// 예제 16.12
void outint(int n) { std::cout << n << " "; }

int main()
{
	using namespace std;
	list<int> one(5, 2);
	int stuff[5] = { 1, 2, 4, 8, 6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6, 4, 2, 4, 6, 5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "리스트 one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "리스트 two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << endl << "리스트 three에서 2들을 삭제: ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "접목 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "리스트 one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();
	cout << endl << "단일화 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "정렬과 단일화 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "정렬된 리스트 two를 리스트 three에 합병: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	return 0;
}
*/

/*
// 예제 16.13
#include <string>
#include <set>

int main()
{
	using namespace std;
	const int N = 6;
	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	ostream_iterator<string, char> out(cout, " ");
	cout << "집합 A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "집합 B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;
	cout << "A와 B의 합집합:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 교집합:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 차집합:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string> C;
	cout << "집합 C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "삽입한 후의 집합 C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "특정한 범위를 표시:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;

	return 0;
}
*/

/*
#include <map>
#include <string>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
	using namespace std;
	MapCode codes;

	codes.insert(Pair(415, "샌프란시스코"));
	codes.insert(Pair(510, "오클랜드"));
	codes.insert(Pair(718, "브루클린"));
	codes.insert(Pair(415, "샌라파엘"));
	codes.insert(Pair(510, "버클리"));

	cout << "지역 코드가 415인 도시 수: " << codes.count(415) << endl;
	cout << "지역 코드가 718인 도시 수: " << codes.count(718) << endl;
	cout << "지역 코드가 510인 도시 수: " << codes.count(510) << endl;
	cout << "지역 코드 도시\n";
	MapCode::iterator it;
}
*/