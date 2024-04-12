#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <list>
#include <vector>
#include <stdexcept>

bool fgrade(const student_info& s)
{
    return grade(s) < 60;
}
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}
double grade(double mt, double ft, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");


    return grade(mt, ft, median(hw));
}

double grade(const student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

//세번째 버젼:
//인덱스 대신 반복자를 사용하지만 여전히
//성능 저하가 우려됨
list<student_info> extract_fails(list<student_info>& students) {
    list<student_info> fail;
    list<student_info>::iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else {
            ++iter;

        }
    }

    return fail;
}