//
//  main.cpp
//  Revision
//
//  Created by Ma. Guadalupe Roque Díaz de León on 6/05/22.
//  Copyright © 2022 Invitado. All rights reserved.
//

#include <stdio.h>
// Example program
#include <iostream>
#include "Fracciones.hpp"

using namespace std;

int menu(){
    int iOpcion;
    cout << "\n1. Ingresa la Fraccion1:";
    cout << "\n2. Ingresa la fraccion2:";
    cout << "\n3. f1 + f2 ";
    cout << "\n4. f1 - f2 ";
    cout << "\n5. f1 * f2 ";
    cout << "\n6. f1 / f2 ";
    cout << "\n7. f1 < f2 ";
     cout << "\n8. f1++ ";
     cout << "\n9. ++f1 ";
     cout << "\n10. cout << fraccion f1";
    cout << "\n11. cout << fraccion f2";
     cout << "\n12. funcion amiga suma(f1,f2)";
    cout << "\n0. Salir";
    cout << "\nTeclea la opcion:";
    cin >> iOpcion;
    return iOpcion;
}

int main() {
    Fracciones f1(3,5), f2(1,4);
    Fracciones f3(3,5), f4(2,6);
    Fracciones resultado;
    int iOpcion;
    
    f1.input();
    cout << f1;
    
    f2.input();
    cout << f2;
    
    
    // usando la sobrecarga del operador +
    cout << "f1 + 5 = " << f1 + 5 << endl;
    cout << "f1 + 2.5  = " << f1 + 2.5 << endl;
    cout << f1 << '+' << 2.5 << '=' << (f1 + 2.5) << endl;
    /*
    //  🚨 cout << 5 + f1; lo tengo que sobrecargar dentro de int + Fracciones
    cout << "f1 - f2 =\n " << f1 << '-' << f2 <<  f1 - f2 << endl;
    cout << "f1 * f2 =\n " << f1 * f2 << endl;
    cout << "f1 / f2 =\n " << f1 / f2 << endl;
    cout << "f1 + f2 =\n " << f1 + f2 << endl;
    cout << suma(f1,f2) << endl; // f1.suma(f2)
     
    cout << f1.str() << " + " << f2.str() << " = " << resultado.str() << endl;
    
    resultado = f3 + f4;
    cout << f3.str() << " + " << f4.str() << " = " << resultado.str() << endl;
*/
    // Inicializar la vcc antes del ciclo
    iOpcion = menu();
    while (iOpcion != 0) {
        switch (iOpcion) {
            case 1:
                f1.input();
                cout << f1 << endl;
                break;
                
            case 2:
                f2.input();
                f2.output();
                break;
                
                
            case 3: // +
                resultado = f1 + f2;
                cout << f1.str() << " + " << f2.str() << "= " << resultado.str() <<  " = " << resultado.strFlotante() << endl;
                break;
            case 4: // -
                resultado = f1 - f2;
                cout << f1.str() << " - " << f2.str() << "= " << resultado.str() <<  " = " << resultado.strFlotante() << endl;
                break;
            case 5: // *8
                resultado = f1 * f2;
                cout << f1.str() << " * " << f2.str() << "= " << resultado.str() <<  " = " << resultado.strFlotante() << endl;
                break;
            case 6: // /
                resultado = f1 / f2;
                cout << f1.str() << " / " << f2.str() << "= " << resultado.str() <<  " = " << resultado.strFlotante() << endl;
                break;
             case 7: // <
                // Probando la sobrecarga del operador relacional <
                if (f1 == f2){
                    cout <<f2.str() <<  " <  " << f1.str() << endl;
                }
                else
                    cout << f1 <<  " > " << f2  << endl;
                break;
            case 8: // sobrecarga ++ posfijo
                cout << f1++ ;
                // ver el valor actualizado de f1
                cout << f1 ;
                break;
            case 9:// ++ prefijo
                 cout << ++f1;
                break;
            case 10: // sobrecarga del operador << sobre f1
                cout << f1;
                 break;
            case 11:// sobrecarga del operador << sobre f2
                cout << f2;
                 break;
            case 12:
                
                cout << f1 + f2 << endl;
                cout << f1 + 5 << endl;
                cout << f1 + 6.5 << endl;
                break;
            default:
                cout << "Opcion Incorrecta!! Adios!!\n";
                break;
        }
        // Actualizar la vcc dentro del ciclo
        iOpcion = menu();
    }// fin while
   
    return 0;
}


