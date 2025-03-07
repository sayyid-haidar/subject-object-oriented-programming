#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Student {
    private:
        int id;
        string name;

    public:
        Student(int id, string name) {
            this->id = id;
            this->name = name;
        }

        string getName() {
            return this->name;
        }
};