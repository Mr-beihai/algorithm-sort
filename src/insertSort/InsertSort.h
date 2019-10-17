/*
 * InsertSort.h
 *
 *  Created on: Oct 15, 2019
 *      Author: chenjie
 */

#ifndef INSERTSORT_H_
#define INSERTSORT_H_

#include <stdio.h>
#include "../data/DataList.h"

template<class T>

void InsertSort(DataList<T>& L,const int left,const int right){
    Element<T> temp;
    int i,j;
    for(i = left+1; i < right; i++){
        if(L[i]<L[i-1]){
        	cout<< "loop hit the target, index = " << i;
        	cout<< ", L[i].key = "<< L[i].key <<" move into temp"<<endl;
            temp = L[i];//move into temp
            j=i-1;
            do{
            	cout<< "Moving :"<< L[j].key <<", move the big element to right"<<endl;
                L[j+1] = L[j];
                j--;
                L.printInfo();
            }while (j >= left && temp < L[j]);
            cout<< "Move over :"<< temp.key <<" move to index "<<(j+1)<< endl;
            L[j+1] = temp;
            L.printInfo();
        }
    }

}

#endif /* INSERTSORT_H_ */
