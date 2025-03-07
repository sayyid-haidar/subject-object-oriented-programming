#include <string>;
#include <iostream>;

using namespace std;

class Mahasiswa {
    private:
        string nama;
        string nim;
        string jurusan;
        float IPK;
    
    public:
        Mahasiswa(string n, string id) {
            this->nama = n;
            this->nim = id;
        }

        void setIPK(float v) {
            if (v > 4 || v < 0) {
                cout << "IPK Melewati Range Nilai" << endl;
            }

            this->IPK = v;
        }
};