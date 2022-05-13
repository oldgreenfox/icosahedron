#include <iostream>
#include "math.h"
#include <array>

class Point{

    double x;
    double y;
    double z;
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0):x(x),y(y),z(z){

    }
    Point(Point *p):x(p->X()),y(p->Y()),z(p->Z()){

    }
    void print(){
        std::cout << "(" << this->x << ";" << this->y << ";" << this->z << ")" << std::endl;
//        std::cout << "Distance to the center of coord: " << sqrt(this->distance()) << std::endl;
    }

    void set_point(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double X() const{
        return this->x;
    };

    double Y() const{
        return this->y;
    }

    double Z() const{
        return this->y;
    }

    double Distance() const{
        return this->x*this->x + this->y*this->y + this->z*this->z;
    }
    void Normalize(const double r = 1){
        double dist = this->Distance();
        if (!dist){ //Якщо точка співпадає з центром координат - виносимо її на коло
            this->x = r;
            this->y = r;
            this->z = r;
            return;
        }
        double coeff = sqrt((r*r)/dist);
        this->x *= coeff;
        this->y *= coeff;
        this->z *= coeff;
    }
};

class Triangle{
    std::array<Point, 3> points;
public:
    Triangle(Point p1, Point p2, Point p3){
        points[0]=p1;
        points[1]=p2;
        points[2]=p3;
    }

    void Print(){
        for(auto &element: this->points){
            element.print();
        }
    }

};

int main() {
    Point p1 (1,1,1);
    Point p2 (2,2,2);
    Point p3 (3,3,3);

    Triangle t(p1, p2, p3);
    t.Print();
    return 0;
}
