//============================================================================
// Name        : algo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "data/DataList.h"
#include "insertSort/InsertSort.h"

using namespace std;

int main() {
	DataList<int> *list = new DataList<int>();
	Element<int> *ele;
	for(int i = 0;i<10;i++){
		ele = new Element<int>();
		ele->key = rand()%100;
		list->addEle(*ele);
	}
	cout << "original data : " << endl;
	list->printInfo();

//  Test the refs type.
//	cout << typeid(list).name() << endl;
//	cout << typeid(*list).name() << endl;
//	cout << typeid(list->Vector).name() << endl;
//	cout << typeid(list->Vector[1]).name() << endl;
//	cout << typeid((list->Vector[1]).key).name() << endl;
//	cout << typeid((*list)[1]).name() << endl;
//	cout << typeid(list->getEle(1)).name() << endl;

	cout << "begin sort data : " << endl;
	cout << "**** Insertion sort ****" << endl;
	InsertSort(*list,0,list->Length());
	list->printInfo();
	return 0;
}
