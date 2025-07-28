#include <iostream>
#include<vector>
#include "shape.h"
#include "generator.h"
int main(){
    vector<ShapeGenerator*> genlist{
        new RectangleGenerator(),
        new CircleGenerator(),
        new TriangleGenerator()
    };
    while(true){
        cout << "Choose a shape to create:";
        int i;
        for(i=0;i<genlist.size();i++){
            cout << i << ":";
            cout << genlist[i]->getShapeName();
            cout << ", ";
        }
        cout << i <<":" << "Exit";

        unsigned int choice;
        cin >> choice;
        if(choice ==i){
            return 0;
        }
        if(choice > i){
            cout << "Invalid choice";
        }
        
        Shape* pShape=genlist[choice]->createShape();
        float area=pShape->area();
        float perimeter=pShape->perimeter();
        cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
    }
    
}