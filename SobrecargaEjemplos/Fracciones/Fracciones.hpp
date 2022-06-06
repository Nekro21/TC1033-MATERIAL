//
//  Fracciones.hpp
//  Revision
//
//  Created by Ma. Guadalupe Roque on 5/27/20.
//  Copyright © 2020 Invitado. All rights reserved.
//
// TEMA - SOBRECARGA DE OPERADORES
#ifndef Fracciones_hpp
#define Fracciones_hpp
#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
class Fracciones{
    
private:
    int iNum, iDen;
    
public:
    // Constructor default : 0/1  2/4 debe ser 1/2
    Fracciones();
    
    // Constructor con parámetros :todos positivos
    Fracciones(int _num,int _den);
    
    // método set cambia el valor del numerador
    void setNum(int _num);
    
    // get retorna el valor del numerador
    int getNum();
    
    // set cambia el valor del denominador
    void setDen(int _den);
    
    // get retorna el valor del denominador
    int getDen();
    
    // str retorna iNum/iDen
    string str();
    
    // strPtoFlotante la forma en punto flotante
    double strFlotante();
    // Lee una fraccion
    
    void input();
    // despliega la fraccion
    void output();
    
    
     
    // - Sobrecarga de operadores aritméticos usando operator simbolo-
    // Sobrecargar el operador  + :Suma de dos Fracciones
    Fracciones operator + (Fracciones f2){
        Fracciones resp;
        // Si son iguales los denominadores -// 1/2 + 1/2
        if (iDen == f2.iDen){
            resp.iNum = iNum + f2.iNum;
            resp.iDen = iDen;
        }
        else{
            resp.iNum = (iNum * f2.iDen + iDen * f2.iNum);
            resp.iDen = (iDen * f2.iDen);
        }
        return resp;
    }
    
    // valor de retorno
    Fracciones   operator + (int f2){
        return Fracciones(iNum + iDen * f2, iDen);
    }
    
    double operator + (double f2){
        return  (iNum  + iDen * f2)/ double(iDen);
    }
    
    
    // Sobrecargar el operador con operator - : Resta de dos Fracciones
    Fracciones operator -(Fracciones f2){
        Fracciones resp;
        if (iDen == f2.iDen){
            resp.iNum = (iNum - f2.iNum);
            resp.iDen = iDen ;
        }
        else{
            resp.iNum = (iNum * f2.iDen - iDen * f2.iNum);
            resp.iDen = (iDen * f2.iDen);
        }
        return resp;
    }
    
    // Sobrecargar el operador  * : multiplica dos Fracciones
    Fracciones operator *(Fracciones f2){
        Fracciones resp;
        // f1.numerador X f2.numerador
        resp.iNum = (iNum * f2.iNum);
        // f1.denominador X f2.denominador
        resp.iDen = iDen * f2.iDen;
        
        return resp;
    }
    
    // Sobrecargar el operador  / : divide dos Fracciones
    Fracciones operator/(Fracciones f2){
        Fracciones resp;
        // f1.numerador X f2.denominador
        resp.iNum = (iNum * f2.iDen);
        // f1.denominador X f2.numerador
        resp.iDen = (iDen * f2.iNum);
        
        return resp;
    }
    
    // Sobrecargar el operador  < :overloaded < operator
    bool operator <(Fracciones f2) {
        
        if( ( double(iNum) / f2.iNum) < ( double(iDen) / f2.iDen) ) {
            // si hace este return termina la ejecucion de la funcion
            return true;
        }
        return false;
    }
    
    // Sobrecargar el operador  > :overloaded < operator
    bool operator >(Fracciones f2) {
        
        if(iNum > f2.iNum && iDen > f2.iDen) {
            return true;
        }
        
        return false;
    }
    
     // Sobrecargar el operador  == :overloaded == operator
    bool operator ==(Fracciones f2) {
        
        if(iNum == f2.iNum && iDen == f2.iDen) {
            return true;
        }
        
        return false;
    }
    
    Fracciones operator ++(){
        Fracciones temp;
        cout << "++Prefix : " << endl;
        temp.iNum = iNum++;
        temp.iDen = iDen++;
        return  temp;
    }

    
    Fracciones operator ++(int){
    Fracciones temp;
    cout << "++Posfix : " << endl;
    temp.iNum = ++iNum;
    temp.iDen = ++iDen;
    return  temp;
}

   
    friend ostream & operator << (ostream &out, const Fracciones &f);

};


#endif /* Fracciones_hpp */





































