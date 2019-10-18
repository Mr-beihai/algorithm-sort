/*
 * DataList.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: chenjie
 */

#include "DataList.h"

template<class T>
int DataList<T>::Partition(const int low, const int high) {
	int pivotpos = low;
	Element<T> pivot = Vector[low];
	for (int i = low + 1; i <= high; i++) {
		if (Vector[i] < pivot) {
			pivotpos++;
			if (pivotpos != i) {
				Swap(Vector[pivotpos], Vector[i]);
			}
		}
	}
	Vector[low] = Vector[pivotpos];
	Vector[pivotpos] = pivot;
	return pivotpos;
}
