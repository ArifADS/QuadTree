#ifndef _H_Lista_
#define _H_Lista_
#include "Node.h"
using namespace std;

template <class T>
class List
{
	private:
		int longitud;
		Node<T> *header,*trailer;

		
	public:
		List() {
			longitud = 0;
			header = NULL;
            trailer = NULL;
		}
    
		void setInfoAtPos(T nInfo,int pos){
			Node<T>* nodeAux;
            Node<T>* nNode;
			if (pos < 0 || pos>getLenght()) return;
			if (pos == 0){
                if (header == NULL) {
                    nNode = new Node<T>;
                    header = trailer = nNode;
                }
				header->setInfo(nInfo);
			}
			else if (pos == getLenght()-1){
				return trailer->setInfo(nInfo);
			}
			else {
				nodeAux = header;
				for (int i=1; i<pos; i++){
					nodeAux = nodeAux->getNext();
				}
				nodeAux->setInfo(nInfo);
			}
		}

		void setLenght(int l){
			longitud = l;
		}

		
		int getLenght(){
			return longitud;
		}

		
		bool isEmpty(){
			return getLenght() == 0;
		}

		void addInfoAtPos(T nInfo,int pos){
			Node<T>* nodeAux, *nNode;
			
			if (pos < 0 || pos>getLenght()) return;
			
			nNode = new Node<T>;
            
            if (getLenght()==0) {
                trailer = header = nNode;
            }
			if (pos == 0 )
            {
                nNode->setPrev(trailer); // en caso de ser circular, sino NULL
                nNode->setNext(header);
                
                trailer->setNext(nNode);
                header->setPrev (nNode);
                
                header = nNode;
            
                setLenght(getLenght() + 1);
                
            }
			else if (pos == getLenght())
            {
				nNode->setPrev(trailer);
				nNode->setNext(header); // circular
                
                trailer->setNext(nNode);
                header->setPrev (nNode);
                
                trailer = nNode;
				
				setLenght(getLenght() + 1);
			}
			else {
				nodeAux = header;
				for (int i=1; i<pos; i++){
					nodeAux = nodeAux->getNext();
				}
				nNode->setPrev(nodeAux);
				nNode->setNext(nodeAux->getNext());
                
                nodeAux->getNext()->setPrev(nNode);
				nodeAux->setNext(nNode);
				setLenght(getLenght() + 1);
				
			}
			nNode->setInfo(nInfo);
		}

		void deleteAtPos(int pos){
			Node<T>* nodeAux;
						
			if (pos < 0 || pos>=getLenght()) return;
			
			if (pos == 0)
            {
                nodeAux = header;
                header = header->getNext();
                trailer->setNext(header);
                
                header->setPrev(trailer); //circular
				
				
			}
			else if (pos == getLenght()-1)
            {
                
				nodeAux = trailer;
                trailer = trailer->getPrev();
                header->setPrev(trailer);
                
                trailer->setNext(header); //circular
			}
			else {
				nodeAux = header;
				for (int i=1; i<=pos; i++){
					nodeAux = nodeAux->getNext();
				}
				nodeAux->getPrev()->setNext(nodeAux->getNext());
				nodeAux->getNext()->setPrev(nodeAux->getPrev());
				
			}
            setLenght(getLenght() - 1);
			delete(nodeAux);
		}

		int getPosWithInfo(T info){
			Node<T> *nodeAux = header;
			for (int i=1; i<=getLenght();i++){
				if (nodeAux->getInfo() == info){
					return i;
				}
				nodeAux = nodeAux->getNext();
			}
			return (int) NULL;
		}

		T& getInfoWithPos(int pos){
			Node<T>* nodeAux;
			//if (pos < 0 || pos>=getLenght()) return NULL;
			if (pos == 0){
				return header->getInfo();
			}
			else if (pos == getLenght()-1){
				return trailer->getInfo();
			}
			else {
				nodeAux = header;
				for (int i=1; i<=pos; i++){
					nodeAux = nodeAux->getNext();
				}
				return nodeAux->getInfo();
			}
			//return  NULL;
		}

		void deleteAll(){
			Node<T>* nodeAux = header ,*next ;
            while (getLenght()) {
                next = nodeAux->getNext();
                delete(nodeAux);
                nodeAux = next;
                setLenght(getLenght() - 1);
            }
            header = NULL;
            
            
        }


		void imprimirLog(){
			Node<T> *nodeAux = header;
			if (isEmpty()) {
				cout << "lista está vacia" <<endl;
			}
			for (int i=0; i<getLenght();i++){
				cout << i<< ". " << nodeAux->getInfo() <<endl;
				nodeAux = nodeAux->getNext();
			}
            cout<<endl;
		}

		List<T> operator=(List<T>& asignador){
			if (&asignador != this){
				this->deleteAll();
				for (int i=0; i<asignador.getLenght();i++){
					this->addInfoAtPos(asignador.getInfoWithPos(i),i);
				}
			}
			return *this;
		}
    
    
        T& operator[](int i)
        {
            return this->getInfoWithPos(i);;
        }
    
    
    
        void invertir()
        {
            Node<T> *nodo0 = header,*nodo1;
            
            do{
                nodo1 = nodo0->getNext();
                nodo0->setNext(nodo0->getPrev());
                nodo0->setPrev(nodo1);
                nodo0 = nodo1;
                
            }while (nodo0!=header);
            header = trailer;
            trailer = nodo0;
        }
};
#endif