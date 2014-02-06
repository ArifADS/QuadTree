#include <iostream>

#ifndef _H_NODE_
#define _H_NODE_
template <class T>
class Node{
	private:
		T info;
		Node<T>* next;
		Node<T>* prev;
		
	public:
		Node(){
			next = NULL;
			prev = NULL;
		}

		T getInfo(){
			return info;
		}

		void setInfo(T nInfo){
			info = nInfo;
		}
		Node<T>* getNext(){
			return next;
		}
		void setNext(Node<T>* nNext){
			next = nNext;
		}
		Node<T>* getPrev(){
			return prev;
		}
		void setPrev(Node<T>* nPrev){
			prev = nPrev;
		}
};
#endif