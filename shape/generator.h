#pragma once
#include "shape.h"

class ShapeGenerator{
protected:
    string m_shapeName;
public:
    virtual Shape* createShape()=0;
    const string& getShapeName(){
        return m_shapeName;
    }
};

class RectangleGenerator : public ShapeGenerator{
public:
    RectangleGenerator() {
        m_shapeName = "Rectangle";
    }
    virtual Shape* createShape(){
        float width, height;
        cout << "Enter width and height of rectangle: ";
        cin >> width >> height;

        return new Rectangle(width, height);
    }
};

class CircleGenerator : public ShapeGenerator{
public:
    CircleGenerator() {
        m_shapeName = "Circle";
    }
    virtual Shape* createShape(){
        float radius;
        cout << "Enter radius of circle: ";
        cin >> radius;

        return new Circle(radius);
    }
};

class TriangleGenerator : public ShapeGenerator{
public:
    TriangleGenerator() {
        m_shapeName = "Triangle";
    }
    virtual Shape* createShape(){
        float a,b,c;
        cout << "Enter sides a, b, c of triangle: ";
        cin >> a >> b >> c;
        return new Triangle(a, b, c);
    }
};