/*
 * QSort.h
 *
 *  Created on: Oct 18, 2019
 *      Author: chenjie
 */

#ifndef QSORT_H_
#define QSORT_H_

#include <stdio.h>
#include "../data/DataList.h"

/**
 *  递归快速排序法
 */
template<class T>
void QuickSort(DataList<T> &L, const int left, const int right) {
	if (left < right) {
		int pivotpos = L.Partition(left, right);
		QuickSort(L, left, pivotpos - 1);
		QuickSort(L, pivotpos + 1, right);
	}
}

#endif /* QSORT_H_ */
