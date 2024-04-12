// main.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>//cin, cout�� ����ϱ� ����
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>//������ ����ϱ� ����
#include "grade.h"
#include "student_info.h"

using namespace std;




int main() {
    //���� ��Ʈ�� ����� "txt" ������ �б�
    ifstream student_file("grades.txt");

    vector<student_info> students;
    student_info record;
    string::size_type maxlen = 0;

    //�л� �̸���  ��� ������ �о� �����ϰ�
    //���� �� �̸��� ã��
    while (read(student_file, record))
    {//cin = ���� ����ڶ� �Է¸� ����
     //student_file = ifstream�̿��� ������ �� ����
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

   //�л� ������ ���ĺ������� ����
    sort(students.begin(), students.end(), compare);

    for (vector<student_info>::size_type i = 0;
        i != students.size(); i++)
    {
        //�̸��� ������ ������ �����Ͽ� maxlen + 1����
        //���ڸ� ���
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');


        // ���� ������ ����� ����
        try {
            double final_grade = grade(students[i]);
            // ����� ���
            streamsize prec = cout.precision(); // ���� cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();
        }
    }// for ��

    return 0;
} // main ��
