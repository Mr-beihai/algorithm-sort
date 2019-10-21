/*
 * SelectionSort.h
 *
 *  Created on: Oct 21, 2019
 *      Author: chenjie
 */

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "dataList.h"

class SelectionSort {
public:
	SelectionSort();
};

template<class T>
void SelectSort(DataList<T>& L,const int left,const int right){
	for(int i = left;i<right;i++){
		int k = i;
		for(int j=i+1;j<right;j++){
			if(L[j]<L[k])
				k=j;
		}
		if(k != i)
			Swap(L[i] = L[k]);
	}
}

#endif /* SELECTIONSORT_H_ */
