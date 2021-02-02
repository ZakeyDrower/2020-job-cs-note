#include "header.h"

class Graph
{
protected:
    double x;
    double y;
public:
    Graph(double x,double y)
    {    
        this->x=x;
        this->y=y;
    }
    virtual void showArea()
    {
        cout<<"计算图形面积"<<endl;
    }
};


class Rectangle:public Graph
{
public:
    Rectangle(double x,double y):Graph(x,y){};
    virtual void showArea()
    {
        cout<<"Rectangle Area: "<<x*y<<endl;
    }
};


class Triangle:public Graph
{
public:
    Triangle(double d,double h):Graph(d,h){};
    virtual void showArea()
    {
        cout<<"Triangle Area: "<<x*y*0.5<<endl;
    }
};


class Circle:public Graph
{
public:
    Circle(double r):Graph(r,r){};
    virtual void showArea()
    {
        cout<<"Circle Area: "<<3.14*x*y<<endl;
    }
};


int main(int argc, char* argv[])
{
    Graph *graph;

    Rectangle rectangle(10,5);
    graph=&rectangle;
    graph->showArea();

    Triangle triangle(5,2.4);
    graph=&triangle;
    graph->showArea();

    Circle circle(2);
    graph=&circle;
    graph->showArea();   

    Graph* gArray[3];
    gArray[0] = &rectangle;
    gArray[1] = &triangle;
    gArray[2] = &circle;
    for (int i = 0;i < 3;i++)
    {
        gArray[i]->showArea();
    }

    return 0;
}