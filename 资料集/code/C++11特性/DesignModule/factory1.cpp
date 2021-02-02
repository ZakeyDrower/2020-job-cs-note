#include <bits/stdc++.h>
using namespace std;

typedef enum ProductTypeTag
{
    TypeA,
    TypeB,
    TypeC
} PRODUCTTYPE;

class Product // product abstract base class
{
    public :
    virtual void show() = 0;
};

class ProductA : public Product
{
    public : 
    void show() { cout << "I am Product A." << endl; }
};

class ProductB : public Product
{
    public : 
    void show() { cout << "I am Product B." << endl; }
};

class ProductC : public Product
{
    public : 
    void show() { cout << "I am Product C. " << endl; }
};

class Factory 
{
    public : 
    Product* CreateProduct(PRODUCTTYPE type) {
        switch(type){
            case TypeA:
            return new ProductA();
            case TypeB:
            return new ProductB();
            case TypeC:
            return new ProductC();
            default : 
            return nullptr;
        }
    }
};

int main()
{
    Factory productCreater;
    Product *productA = productCreater.CreateProduct(TypeA);
    Product *productB = productCreater.CreateProduct(TypeB);
    Product *productC = productCreater.CreateProduct(TypeC);
    productA->show();
    productB->show();
    productC->show();
    delete productA;
    delete productB;
    delete productC;
    productA = nullptr;
    productB = nullptr;
    productC = nullptr;
    return 0;
}