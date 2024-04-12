#pragma once
//student_info.h

#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};//����Ŭ���� ���� �ʵ��� ����

bool compare(const student_info&, const student_info&);

istream& read(istream&, student_info&);
istream& read_hw(istream& , vector<double>& );


#endif // !GUARD_student_info
