/*
 * DataList.h
 *
 *  Created on: Oct 15, 2019
 *      Author: chenjie
 */

#ifndef DATALIST_H_
#define DATALIST_H_

#include <stdio.h>
#include <iostream>

using namespace std;

const int DefaultSize = 100;

template<class T>
class Element{
public:
    T key;
    Element<T>& operator= (Element<T>& x){
        key = x.key;
        return *this;
    }
    bool operator == (Element<T>& x){
        return key == x.key;
    }
    bool operator <= (Element<T>& x){
        return key <= x.key;
    }
    bool operator > (Element<T>& x){
        return key > x.key;
    }
    bool operator < (Element<T>& x){
        return key < x.key;
    }
};

template<class T>
class DataList{
public:
	DataList(int maxSz = DefaultSize):maxSize(maxSz),currentSize(0){
        Vector = new Element<T>[maxSize];
    }
    void Swap(Element<T>& x,Element<T>& y){
        Element<T> temp = x;
        x = y;
        y = temp;
    }
    int Length(){return currentSize;}
    Element<T>& operator[](int i){
        return Vector[i];
    };

    int Partition(const int low,const int higth);

    bool addEle(Element<T>& x){
    	if(currentSize < maxSize){
    		currentSize = currentSize + 1;
    		Vector[currentSize] = x;
    		return true;
    	}
    	std::cout<<" The number of currentSize equally maxSize,so you cannot add an element! "<<endl;
    	return false;
    }
    void printInfo(){
    	for(int i = 0;i<currentSize;i++){
    		cout<<" "<<Vector[i].key;
    	}
    	cout<<endl;
    }
private:
    Element<T>* Vector;
    int maxSize;
    int currentSize;
};


#endif /* DATALIST_H_ */
