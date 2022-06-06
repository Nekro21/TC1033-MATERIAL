//
//  Fracciones.cpp
//  Revision
//
//  Created by Ma. Guadalupe Roque Díaz de León on 5/27/20.
//  Copyright © 2020 Invitado. All rights reserved.
//

#include "Fracciones.hpp"

#include <iostream>
#include <string>
using namespace std;

// Constructor default : 0/1  2/4 debe ser 1/2
Fracciones::Fracciones(){
    iNum = 0;
    iDen = 1;
}

// Constructor con parámetros :todos positivos
Fracciones::Fracciones(int num,int den){
    if (num >= 0 )
        iNum = num;
    else
        iNum = - num;
    if (den > 0)
        iDen = den;
    if (den < 0)
        iDen = - den;
}

void Fracciones::setNum(int num){
    iNum = num;
}

int Fracciones::getNum(){
    return iNum;
}

void Fracciones::setDen(int den){
    iDen = den;
}

int Fracciones::getDen(){
    return iDen;
}

string Fracciones::str()
{
    //std::cout << iNum << "/" << iDen << std::endl;
    return (to_string(iNum) + " / " + to_string(iDen));
}

double  Fracciones::strFlotante(){
    return  double(iNum) / iDen;
}

// Lee una fraccion
void Fracciones::input(){
    cout << "Ingresa el numerador:";
    cin >> iNum;
   cout << "Ingresa el denominador:";
    cin >> iDen;
}

// despliega la fraccion en la pantalla
void Fracciones::output(){
    std::cout << iNum << " / " << iDen ;
}


ostream & operator << (ostream &out, const Fracciones &f)
{
    out << f.iNum << " / " << f.iDen << endl;
    return out;
}





















