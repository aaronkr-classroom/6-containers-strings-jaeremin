//border.cpp

#include <iostream>
#include <cctype>
#include <vector>
#include <string>


#include"split.h"

using namespace std;

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;

	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, 'x');

	ret.push_back(border);

	for (vector<string> ::size_type i = 0; i != v.size(); i++)
	{
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}
	//하단 테두리를 추가
	ret.push_back(border);
	return ret;
}

//수직 결합 = vertical concat
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{ 
	//위쪽 문자 그림을 복사
	vector<string> ret = top;

	//아래쪽 문자 그림을 복사
    for (vector<string> :: const_iterator it =bottom.begin();
		it != bottom.end(); ++it)
	{
		ret.push_back(*it);
	}
	return ret;
} 

//수평 결합 = horizental
vector<string> hcat(const vector<string>& left,const vector<string>& right)
{
	vector<string> ret;

	string::size_type width1 = width(left) + 1;

	//왼쪽 문자 그림과 오른쪽 문자 그림에 요소를 살펴보는 인덱스
	vector<string>::size_type i = 0, j = 0;

	//두 문자 그림의 모든 행을 살펴봄

	while (i != left.size() || j != right.size())
	{
		//두 문자 그림의 문자들을 저장할 새로운 문자열을 생성
		string s;

		//왼쪽 문자 그림에서 행 하나를 복사
		if (i != left.size())
		{
			s = left[i++];
		}

		//공백을 포함하여 문자열을 적절한 너비까지 채움
		s += string(width1 - s.size(), ' ');

		//오른쪽 문자 그림에서 행 하나를 복사
		if (j != right.size())
		{
			s += right[j++];
		}
		//새로운 문자 그림에 문자열 s를 추가
		ret.push_back(s);
	}
	return ret;
}
/*과제
* 1.split()가져오고 사용하기
* 2.vcat() 사용하기
* 3.hcat() 사용하기
* 4.out.txt 파일에서 모든 출력 저장해 주세요.
*/

/*
int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> v = split(s);
		frame(v);

	}
	return 0;
}
*/