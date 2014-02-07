//
//  QuadTree.h
//  QuadTree
//
//  Created by Arif De Sousa on 2/5/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//




#ifndef __QuadTree__QuadTree__
#define __QuadTree__QuadTree__

#include <iostream>
#include "List.h"

typedef enum
{
    Blanco='e',
    Negro ='f',
    Gris  ='p'
}Color;



class QuadTree
{
    Color nodoColor;
    QuadTree *hijo[4];
    
    
public:
    QuadTree()
    {
        nodoColor = (Color) 0;
    }
    
    QuadTree(List<Color> &preorden)
    {
        this->nodoColor = preorden[0];
        preorden.deleteAtPos(0);
        
        for (int i = 0; i<4; i++)
            this->hijo[i] = reconstruir(preorden);
        
    }
    
    
    
    
    bool esNulo(){
        return nodoColor == 0;
        
    }
    
    Color color(){
        return nodoColor;
    }
    
    //QuadTree& unionQT;
    
    void preorden(){
        cout<< "PREORDEN:\t";
        recorridoPreorden(this);
        cout<< endl;
    }
    
    int numeroDeNegros()
    {
        return cuantosNegros(this,64);
        
    }
    
    
    
    
    
    
private:
    
    int cuantosNegros(QuadTree* qt,int i)
    {
        int nNegros = 0;
        if (qt->nodoColor == Negro)
            nNegros+= i;
        
        else if (qt->nodoColor == Gris)
        {
            for (int j=0; j<4; j++) {
                nNegros += cuantosNegros(qt->hijo[j], i/4);
            }
        }
        return nNegros;
    }
    
    QuadTree& unionQt(const QuadTree& qt2)
    {
        return *unionDeQuadTree(this, &qt2);
    }
    
    QuadTree* unionDeQuadTree(const QuadTree* qt1,const QuadTree* qt2)
    {
        QuadTree* qt3 = new QuadTree;
        
        if (qt1->nodoColor == Negro || qt2->nodoColor == Negro)
            qt3->nodoColor = Negro;
        
        else if (qt1->nodoColor == Blanco && qt2->nodoColor == Blanco)
            qt3->nodoColor = Blanco;
        
        else if (qt1->nodoColor == Blanco && qt2->nodoColor == Gris)
        {
            qt3->nodoColor = Gris;
            for (int i = 0; i<4; i++) {
                qt3->hijo[i] = qt2->hijo[i]; // no es copia formal sino de apuntadores :(
            }
        }
        
        else if (qt1->nodoColor == Gris && qt2->nodoColor == Blanco)
        {
            qt3->nodoColor = Gris;
            for (int i = 0; i<4; i++) {
                qt3->hijo[i] = qt1->hijo[i]; // no es copia formal sino de apuntadores :(
            }
        }
        
        else
        {
            qt3->nodoColor = Gris;
            for (int i = 0; i<4; i++)
            {
                qt3->hijo[i] = unionDeQuadTree(qt1->hijo[i], qt2->hijo[i]);
            }
        }
        
        return qt3;
    }
    
    
    QuadTree* reconstruir(List<Color> &preorden)
    {//ppeeefpffeefe
        
        
        if (preorden.isEmpty()) return NULL;
            
            
        Color auxColor = preorden[0];
        QuadTree* auxQt;
        
        preorden.deleteAtPos(0);
        
        auxQt = new QuadTree(auxColor);

        if (auxColor == Gris)
        {
            for (int i = 0; i<4; i++)
            {
                auxQt->hijo[i] = reconstruir(preorden);
            }
        }

        return auxQt;
    }
    
    
    QuadTree(Color myColor){
        this->nodoColor = myColor;
        for (int i = 0; i<4; i++)
            this->hijo[i] = NULL;
    }
    
    void recorridoPreorden(QuadTree* qt)
    {
        if (qt != NULL)
        {
            cout << (char) qt->nodoColor << " ";
            
            if (qt->nodoColor == Gris)
            {
                for (int i=0; i<4; i++)
                    recorridoPreorden(qt->hijo[i]);
            }
            
            
        }
    }
    
};



#endif /* defined(__QuadTree__QuadTree__) */
