//
//  Alimento.cpp
//  ClasesAbstractasPuras
//
//  Created by Ma. Guadalupe Roque  on 5/20/20.
//  Copyright © 2020 Invitado. All rights reserved.
//

#include "Alimento.hpp"
#include <iostream>


Alimento::Alimento(){
    ingrediente1 = "Queso";
    ingrediente2 = "Salami";
    precio = 200;
}

Alimento::~Alimento(){
    cout << "Se destruyo un alimento\n";
}

// no se hace la codificación del método dibuja -
