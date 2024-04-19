
#pragma once
#ifndef GUARD_border_h
#define GUARD_border_h

#include <string>
#include <vector>

using namespace std;

string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);

//수직 결합 = vertical concat
vector<string> vcat(const vector<string>& top,
	const vector<string>& bottom);
//수평 결합 = horizental
vector<string> hcat(const vector<string>& left,
	const vector<string>& right);
#endif