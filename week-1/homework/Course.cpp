#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Student.cpp"

using namespace std;

class Course {
    private:
        int id;
        string title;
        vector<Student> students;
        int maxiumumRegistration;

    public:
        Course(int id, string title, int maxiumumRegistration) {
            if (title.size() <= 0) {
                throw invalid_argument("Title tidak boleh kosong");
            }
            if (maxiumumRegistration <= 0) {
                throw invalid_argument("Maximum registration tidak boleh dan kurang dari 0");
            }

            this->id = id;
            this->title = title;
            this->maxiumumRegistration = maxiumumRegistration;
        }

        void enroll(Student student) {
            if (this->students.size() >= this->maxiumumRegistration) {
                throw invalid_argument("Course ini sudah mencapai batas pendaftar");
            }

            this->students.push_back(student);
        }

        void drop() {
            if (this->students.empty()) {
                throw invalid_argument("Course belum memiliki students");
            }

            this->students.clear();
        }

        void getEnrolledStudents() {
            if (this->students.empty()) {
                throw invalid_argument("Course belum memiliki students");
            }

            for (const Student &s: this->students) {
                cout << "Name : " << s.getName() << endl;
            }
        }
};