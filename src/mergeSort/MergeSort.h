/*
 * MergeSort.h
 *
 *  Created on: Oct 25, 2019
 *      Author: chenjie
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <stdio.h>
#include "../data/DataList.h"

template<class T>
void merge(DataList<T>& L1,DataList<T>& L2,const int left,const int mid,const int right){
	for(int k= left;k<=right;k++){
		L2[k] = L1[k];
	}
	int s1=left,s2=mid+1,t=left;
	while(s1<mid && s2<right){
		if(L2[s1]<=L2[s2]){
			L1[t++] = L2[s1++];
		}else{
			L1[t++]=L2[s2++];
		}
	}

	while(s1<mid){
		L1[t++] = L2[s1++];
	}

	while(s1<right){
		L1[t++] = L2[s1++];
	}

}

template<class T>
void mergeSort(DataList<T>& L,DataList<T>& L2,int left,int right){
	if(left >= right){
		return;
	}
	int mid = (left + right)/2;
	mergeSort(L,L2,left,mid);
	mergeSort(L,L2,mid+1,right);
	merge(L,L2,left,mid,right);
}


#endif /* MERGESORT_H_ */
