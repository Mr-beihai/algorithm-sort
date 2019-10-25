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
#include "../insertSort/InsertSort.h"

#define M 16

template<class T>
void improveMerge(DataList<T>& L1,DataList<T>& L2,const int left,const int mid,const int right){
	int s1=left,s2=right,t=left,k;
	for(k=left;k<=mid;k++){
		L2[k] = L1[k];
	}
	for(k=mid+1;k<=right;k++){
		L2[right+mid+1-k]=L1[k];
	}
	while(t<=right){
		if(L2[s1]<=L2[s2]){
			L1[t++] = L2[s1++];
		}else{
			L1[t++] = L2[s2--];
		}
	}

}

template<class T>
void doSort(DataList<T>& L,DataList<T>& L2,int left,int right){
	if(left >= right){
		return;
	}
	if(right-left+1<M){
			return;
	}
	int mid = (left + right)/2;
	doSort(L,L2,left,mid);
	doSort(L,L2,mid+1,right);
	improveMerge(L,L2,left,mid,right);
}

template<class T>
void mergeSort(DataList<T>& L,DataList<T>& L2,int left,int right){
	doSort(L,L2,left,right);
	InsertSort(L.left,right);
}

#endif /* MERGESORT_H_ */
