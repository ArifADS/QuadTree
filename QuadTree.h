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
        {
            this->hijo[i] = reconstruir(preorden);
        }
        
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
        int nNegros = 0;
        for (int i = 0; i<4; i++)
        {
            if (this->hijo[i]->nodoColor == Negro)
                nNegros +=4;
            
            
            if (this->hijo[i]->nodoColor == Gris)
            {
                for (int j = 0; j<4; j++)
                {
                    if (this->hijo[i]->hijo[j]->nodoColor == Negro)
                        nNegros++;
                }
            }
            
        }
        
        return nNegros;
        
    }
    

    
    
private:
    
    
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
    
    int negros(QuadTree * qt){
        
        return qt->nodoColor == Negro;
    }
    
};



#endif /* defined(__QuadTree__QuadTree__) */
