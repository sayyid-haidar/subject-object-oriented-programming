#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Product {
    public:
        int id;
        string name;
        string category;
        int stock = 0;
        float price = 0;
        float discount = 0;
        float priceAfterDiscount = 0;

        void updatePriceAfterDiscount() {
            this->priceAfterDiscount = this->price - (this->price - this->discount / 100);
        }
    
    private:
        Product(int id, string name, string category, float price, int stock) {
            if (price < 0) {
                throw invalid_argument("Harga tidak boleh kurang dari 0");
            }
            if (discount < 0 || discount > 100) {
                throw invalid_argument("Discount tidak boleh kurang dari 0 atau lebih dari 100");
            }
            if (stock < 0) {
                throw invalid_argument("Stock tidak boleh kurang dari 0");
            }

            this->id = id;
            this->name = name;
            this->category = category;
            this->price = price;
            this->stock = stock;
            this->discount = discount;

            this->updatePriceAfterDiscount();
        }

        void updatePrice(float price) {
            if (price < 0) {
                throw invalid_argument("Harga tidak boleh kurang dari 0");
            }

            this->price = price;
            this->updatePriceAfterDiscount();
        }

        void updateDiscount(float price, float discount) {
            if (discount < 0 || discount > 100) {
                throw invalid_argument("Discount tidak boleh kurang dari 0 atau lebih dari 100");
            }
            this->updatePriceAfterDiscount();
        }

        void updateStock(int stock) {
            if (stock < 0) {
                throw invalid_argument("Stock tidak boleh kurang dari 0");
            }
            this->stock = stock;
        }

        void displayInfo() {
            cout << "Name       : " << this->name << endl;
            cout << "Category   : " << this->category << endl;
            cout << "Stock      : " << this->stock << endl;
            cout << "Price      : " << this->price << endl;
            cout << "Discount   : " << this->discount << endl;
            cout << "Price After Discount   : " << this->priceAfterDiscount << endl;
        }
};