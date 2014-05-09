//
//  main.cpp
//  QuadTree
//
//  Created by Arif De Sousa on 2/5/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#include <iostream>
#include "QuadTree.h"



/* Ya que no consegui como compilar por entrada estandar de bla bla bla bla
 * defino "cin" como "fin" y asi cuando tu lo metas por istd no te de error y te funcione igual, ves? y ya está.*/
#ifdef DEBUG
    #include <fstream>
    #define cin fin
    ifstream fin("/Users/ADS/Documents/QuadTree/QuadTree/entrada.in");
#else
    #define DEBUG 0
#endif



List<Color>& poListaDeString(string myString);
void printMuchosQt();
void recPrint(int i);



int main(int argc, char * argv[])
{
    //cout <<"Debug mode: "<<  DEBUG << endl;
    //main2(); return 0;

    int nCasosPrueba,npxT=0,npx;
    string line1,line2;
    List<Color> prepo1,prepo2;
    QuadTree qt1,qt2;
    
    
    cin >> nCasosPrueba;
    getline(cin, line1);
    
    for (int i = 0; i<nCasosPrueba; i++)
    {
        //toma las lineas del archivo/stream.
        getline(cin, line1);
        getline(cin, line2);
        
        //convierte de string a List<Color>.
        prepo1 = poListaDeString(line1);
        prepo2 = poListaDeString(line2);
        
        //crea los QuadTree a partir de una Lista de color.
        qt1.crear(prepo1);
        qt2.crear(prepo2);
        
        npx = qt1.unionQt(qt2).pxNegros();
        
        npxT += npx;
        
        cout << "Hay "<< npx << " pixels negros."<<endl;
    }
    
    
    //cout de prueba
    //cout << "De "        << nCasosPrueba << " QuadTrees" << endl;
    //cout << "Hay "       << npxT << " pixeles negros"    << endl;
    //cout << "Promedio: " << npxT/nCasosPrueba            << endl;
    
    
    return 0;
}

// funciones para testear, ignorar
int main2()
{
    int j = 100000;
    cout<<j<<endl;
    for (int i = 1; i<=j*2; i++)
        printMuchosQt();
    return 0;
}


void recPrint(int i)
{
    srand ((unsigned int)time(NULL)*rand());
    int j = rand()%(3-i);
    
    switch (j) {
        case 0:
            cout<< 'f';
            break;
        case 1:
            cout<< 'e';
            break;
        case 2:
        case 3:
            cout<< 'p';
            recPrint(i+1);
            recPrint(i+1);
            recPrint(i+1);
            recPrint(i+1);
            break;
            
        default:
            cout << endl<< "WTF? "<<j<<endl;
            break;
    }
}

void printMuchosQt()
{
    int i = -1;
    cout<<'p';
    recPrint(i);
    recPrint(i);
    recPrint(i);
    recPrint(i);
    cout<< endl;
}

List<Color>& poListaDeString(string myString){
    List<Color>* myList = new List<Color>;
    
    for (int i = 0; i<myString.length(); i++) {
        myList->addInfoAtPos((Color)myString[i],i);
    }
    
    return *myList;
    
}

