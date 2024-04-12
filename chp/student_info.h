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
};//세미클론을 잊지 않도록 주의

bool compare(const student_info&, const student_info&);

istream& read(istream&, student_info&);
istream& read_hw(istream& , vector<double>& );


#endif // !GUARD_student_info
