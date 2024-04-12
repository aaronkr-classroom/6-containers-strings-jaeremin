//student_info.cpp
#include "student_info.h"
#include <iostream>
bool compare(const student_info& x, const student_info& y)
{
    return x.name < y.name;
}


    istream& read(istream & is, student_info & s){
        //�л��� �̸�, �߰���� ����, �⸻��� ���� �о� ����
        is >> s.name >> s.midterm >> s.final;
        // ���� ������ ����
        read_hw(is, s.homework);
        return is;
    }
    istream& read_hw(istream& in, vector<double>& hw){
        if (in) {
            // ���� ������ ����
            hw.clear();

            // �Է��� ���� ����
            double x; // cin���� ����ϱ� 

            // �Һ���: ���ݱ��� count�� ������ �Է¹޾�����
            // �Է¹��� ������ ���� sum
            while (in >> x) {
                hw.push_back(x);
            }

            // ���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
            in.clear();

            return in;
        }
    }
