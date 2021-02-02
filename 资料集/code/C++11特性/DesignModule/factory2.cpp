#include<bits/stdc++.h>
using namespace std;

typedef enum ProductTypeTag
{
    TypeA,
    TypeB,
    TypeC
} PRODUCTTYPE;

class Product {
    public : 
    virtual void show() = 0;
};

class ProductA : public Product {
    public :
    void show() { cout << "I am Product A." << endl; }
};

class ProductB : public Product {
    public :
    void show() { cout << "I am product B. " << endl; }
};

class ProductC : public Product {
    public : 
    void show() { cout << "I am Product C. " << endl; }
};

class Factory {
    public :
    virtual Product * CreateProduct() = 0;
};

class FactortA : public Factory {
    public : 
    Product * CreateProduct() {
        return new ProductA();
    }
};

class FactortB : public Factory {
    public : 
    Product * CreateProduct() {
        return new ProductB();
    }
};

class FactortC : public Factory {
    public : 
    Product * CreateProduct() {
        return new ProductC();
    }
};

int main() {
    Factory* facA = new FactortA();
    Product* proA = facA->CreateProduct();
    proA->show();
    Factory* facB = new FactortB();
    Product* proB = facB->CreateProduct();
    proB->show();
    return 0;
}