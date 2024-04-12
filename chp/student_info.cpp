//student_info.cpp
#include "student_info.h"
#include <iostream>
bool compare(const student_info& x, const student_info& y)
{
    return x.name < y.name;
}


    istream& read(istream & is, student_info & s){
        //학생의 이름, 중간고사 점수, 기말고사 점수 읽어 저장
        is >> s.name >> s.midterm >> s.final;
        // 과제 점수를 일음
        read_hw(is, s.homework);
        return is;
    }
    istream& read_hw(istream& in, vector<double>& hw){
        if (in) {
            // 이전 내용을 제거
            hw.clear();

            // 입력을 위한 변수
            double x; // cin에서 사용하기 

            // 불변성: 지금까지 count개 점수를 입력받았으며
            // 입력받은 점수의 합은 sum
            while (in >> x) {
                hw.push_back(x);
            }

            // 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
            in.clear();

            return in;
        }
    }
