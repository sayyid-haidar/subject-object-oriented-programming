#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class BankAccount {
    private: 
        string accountNumber;
        string holderName;
        int balance = 0;

    public:
        void deposit(int amount) {
            if (amount <= 0) {
                throw invalid_argument("Niali yang diinput tidak boleh kurang atau sama dengan 0");
            }
            balance += amount;
        }

        void withdraw(int amount) {
            if (amount <= 0) {
                throw invalid_argument("Niali yang diinput tidak boleh kurang atau sama dengan 0");
            }
            if (balance < amount) {
                throw invalid_argument("Saldo tidak mencukupi");
            }

            this->balance -= amount;
        }

        void transfer(int amount, BankAccount &destination) {
            if (amount <= 0) {
                throw invalid_argument("Niali yang diinput tidak boleh kurang atau sama dengan 0");
            }
            if (balance < amount) {
                throw invalid_argument("Saldo tidak mencukupi");
            }

            this->balance -= amount;
            destination.deposit(amount);
        }  
};