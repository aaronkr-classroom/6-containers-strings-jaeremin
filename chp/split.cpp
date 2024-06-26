//split.cpp

#include<cctype>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	//불변성: 지금까지 [원래의 i, 현재의 i) 범위에 있는
	//문자들을 처리
	while (i != s.size())
	{
		//불변성: 지금까지 [원래의 i, 현재의 i) 범위에 있는
		//문자들을 처리
		while (i != s.size() && isspace(s[i]))
		{
			++i;
		}
		//순서상 다음 단어의 끝을 찾음
		string_size j = i;
		//불변성: 지금까지 [원래의 j, 현재의 j) 범위에 있는
		//문자들은 공백이 아님
		while (j != s.size() && isspace(s[j]))
		{
			++j;

		}
		if (i != j)
		{
			//i에서부터  j-1개의 문자들을 s에 복사
			ret.push_back(s.substr(i, j - i));
			i = j;
		}

	}
	return ret;
}

int main()
{
	string s;

	while (getline(cin, s))
	{
		vector<string> v = split(s);

		//벡터 v에 저장한 단어를 각각 출력
		for (vector<string>::size_type i = 0;
			i != v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}
	return 0;
}