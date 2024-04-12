#pragma once
//grade.h

#ifndef GUARD_grade
#define GUARD_grade

#include <list>
#include <vector>
#include "student_info.h"

bool fgrade(const student_info&);
double grade(double , double, double);
double grade(double, double, vector<double>&);
double grade(const student_info&);
list<student_info> extract_fails(list<student_info>&);

#endif // !GUARD_grade.h
