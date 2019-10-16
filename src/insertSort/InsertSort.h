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

void InsertSort(dataList<T>& L,const int left,const int right){
    Element<T> temp;
    int i,j;
    for(i = left+1; i < right; i++){
        if(L[i] < L[i-1]){
            temp = L[i];
            j=i-1;
            do{
                L[j+1] = L[j];
                j--;
            }while (j >= left && temp < L[j]);
            L[j+1] = temp;
        }
    }
}

#endif /* INSERTSORT_H_ */
