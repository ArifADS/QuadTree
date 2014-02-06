//
//  main.cpp
//  QuadTree
//
//  Created by Arif De Sousa on 2/5/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#include <iostream>
#include "QuadTree.h"

#ifdef DEBUG
    #include <fstream>
    #define cin fin
    ifstream fin("/Users/ADS/Documents/QuadTree/QuadTree/entrada.in");
#else
    #define DEBUG 0
#endif



List<Color>& poListaDeString(string myString);

/* Ya que no consegui como compilar por entrada estandar de bla bla bla bla
 * defino "cin" como "fin" y asi cuando tu lo metas por istd no te de error y te funcione igual, ves? y ya está.*/

int main(int argc, char * argv[])
{
    cout <<"Debug mode: "<<  DEBUG << endl;
    int nCasosPrueba;
    string line1,line2;
    
    List<Color> prepo,prepo2;
    
    
    cin >> nCasosPrueba;
    getline(cin, line1);
    
    for (int i = 0; i<nCasosPrueba; i++)
    {
        getline(cin, line1);
        
        getline(cin, line2);
        
        QuadTree qt1(poListaDeString(line1)),qt2(poListaDeString(line2));
        
        qt1.preorden();
        qt2.preorden();
        

    }
    
    return 0;
    
    
    //ppeeefpffeefe
    int i = 0;
    prepo.addInfoAtPos(Gris, i++);
    prepo.addInfoAtPos(Gris, i++);
    prepo.addInfoAtPos(Blanco, i++);
    prepo.addInfoAtPos(Blanco, i++);
    prepo.addInfoAtPos(Blanco, i++);
    prepo.addInfoAtPos(Negro, i++);
    prepo.addInfoAtPos(Gris, i++);
    prepo.addInfoAtPos(Negro, i++);
    prepo.addInfoAtPos(Negro, i++);
    prepo.addInfoAtPos(Blanco, i++);
    prepo.addInfoAtPos(Blanco, i++);
    prepo.addInfoAtPos(Negro, i++);
    prepo.addInfoAtPos(Blanco, i++);
    
    i =0;
    prepo2.addInfoAtPos(Gris, i++);
    prepo2.addInfoAtPos(Blanco, i++);
    prepo2.addInfoAtPos(Negro, i++);
    prepo2.addInfoAtPos(Blanco, i++);
    prepo2.addInfoAtPos(Gris, i++);
    prepo2.addInfoAtPos(Blanco, i++);
    prepo2.addInfoAtPos(Blanco, i++);
    prepo2.addInfoAtPos(Negro, i++);
    prepo2.addInfoAtPos(Blanco, i++);
    
    QuadTree Qt(prepo),qtnulo,Qt2(prepo2);
    
    
    if  (Qt.esNulo()){
        cout << "Es nulo\n";
    }
    else
        cout << "No es nulo\n";
    
    
    cout << "Numero de negros Qt: " <<    Qt.numeroDeNegros()*4 << endl;
    cout << "Numero de negros Qt2: " <<  Qt2.numeroDeNegros()*4 << endl;
    
    Qt.preorden();
    Qt2.preorden();
    
    
    
    
    
    return 0;
}

List<Color>& poListaDeString(string myString){
    List<Color>* myList = new List<Color>;
    
    for (int i = 0; i<myString.length(); i++) {
        myList->addInfoAtPos((Color)myString[i],i);
    }
    
    return *myList;
    
}

