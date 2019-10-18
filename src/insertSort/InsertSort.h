/*
 * InsertSort.h
 * 包含3种插入排序：直接插入，折半插入，希尔插入
 *  Created on: Oct 15, 2019
 *      Author: chenjie
 */

#ifndef INSERTSORT_H_
#define INSERTSORT_H_

#include <stdio.h>
#include "../data/DataList.h"

/**
 *  直接插入排序法
 */
template<class T>
void InsertSort(DataList<T> &L, const int left, const int right) {
	Element<T> temp;
	int i, j;
	for (i = left + 1; i < right; i++) {
		if (L[i] < L[i - 1]) {
			cout << "loop hit the target, index = " << i;
			cout << ", L[i].key = " << L[i].key << " move into temp" << endl;
			temp = L[i]; //move into temp
			j = i - 1;
			do {
				cout << "Moving :" << L[j].key
						<< ", move the big element to right" << endl;
				L[j + 1] = L[j];
				j--;
				L.printInfo();
			} while (j >= left && temp < L[j]);
			cout << "Move over :" << temp.key << " move to index " << (j + 1)
					<< endl;
			L[j + 1] = temp;
			L.printInfo();
		}
	}

}

/**
 * 折半插入排序法
 */
template<class T>
void BinaryInsertSort(DataList<T> &L, const int left, const int right) {
	Element<T> temp;
	int i, low, high, middle, k;
	for (i = left + 1; i < right; i++) {
		temp = L[i];
		low = left;
		high = i - 1;
		if (L[i] < L[i - 1]) {
			cout << "loop hit the target, index = " << i;
			cout << ", L[i].key = " << L[i].key
					<< " move into temp，begin binary search ..." << endl;
			temp = L[i]; //move into temp
			while (low <= high) {
				middle = (low + high) / 2;
				if (temp < L[middle]) {
					high = middle - 1;
				} else {
					low = middle + 1;
				}
			}
			cout << "find the key = " << low << " & moving." << endl;

			for (k = i - 1; k >= low; k--) {
				L[k + 1] = L[k];
			}

			L[low] = temp;
			L.printInfo();
		}
	}
}

/**
 * 希尔插入排序法
 */
template<class T>
void ShellInsertSort(DataList<T> &L, const int left, const int right) {
	Element<T> temp;
	int i, j, gap = right - left + 1; //size add 1
	do {
		gap = gap / 3 + 1;
		cout << "This loop gap is = " << gap << endl;
		for (i = left + gap; i < right; i++) { //反向计算避免边界值
			if (L[i] < L[i - gap]) {
				cout << "loop hit the target,index i-gap=" << i - gap << " ,i ="
						<< i << endl;
				cout << L[i].key << " exchange " << L[i - gap].key << endl;
				temp = L[i];
				j = i - gap;
				do {
					//同一组向后继续比较替换
					L[j + gap] = L[j];
					j = j - gap;
				} while (j >= left && temp < L[j]);
				L[j + gap] = temp;
				L.printInfo();
			}
		}
	} while (gap > 1);
	L.printInfo();
}

#endif /* INSERTSORT_H_ */
