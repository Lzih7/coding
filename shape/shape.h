#pragma once

#include<cmath>
using namespace std;
#define PI 3.1415926
class Shape
{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual ~Shape() {};
};

class Rectangle : public Shape
{
private:
    float m_width;
    float m_height;

public:
    virtual float area()
    {
        return m_width * m_height;
    }
    virtual float perimeter()
    {
        return 2 * (m_width + m_height);
    }
    Rectangle(float width, float height) : m_width(width), m_height(height) {}
};

class Circle : public Shape
{
private:
    float m_r;

public:
    virtual float area()
    {
        return PI * m_r * m_r;
    }
    virtual float perimeter()
    {
        return 2 * PI * m_r;
    }
    Circle(float r):m_r(r){}
};

class Triangle:public Shape{
private:
    float m_a;
    float m_b;
    float m_c;
public:
    virtual float area(){
        float p= (m_a + m_b + m_c)/2;
        return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
    }
    virtual float perimeter(){
        return m_a + m_b + m_c;
    }
    Triangle(float a, float b, float c) : m_a(a), m_b(b), m_c(c) {}
};