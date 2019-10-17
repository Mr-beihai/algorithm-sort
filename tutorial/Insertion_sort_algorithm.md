# Insertion_sort_algorithm

## 插入排序
插入排序（Insertion sort）是一种简单直观且稳定的排序算法。如果有一个已经有序的数据序列，要求在这个已经排好的数据序列中插入一个数，但要求插入后此数据序列仍然有序，这个时候就要用到一种新的排序方法——插入排序法,插入排序的基本操作就是将一个数据插入到已经排好序的有序数据中，从而得到一个新的、个数加一的有序数据，算法适用于少量数据的排序，
时间复杂度为**O(n^2)**。是稳定的排序方法。
插入算法把要排序的数组分成两部分：
- 第一部分包含了这个数组的所有元素，但将最后一个元素除外（让数组多一个空间才有插入的位置），
- 而第二部分就只包含这一个元素（即待插入元素）。在第一部分排序完成后，再将这个最后元素插入到已排好序的第一部分中。

插入排序的基本思想是：每步将一个待排序的记录，按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。
``` c++
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
```
```c
original data :
 0 7 49 73 58 30 72 44 78 23
begin sort data :
**** Insertion sort ****
loop hit the target, index = 4, L[i].key = 58 move into temp
Moving :73, move the big element to right
 0 7 49 73 73 30 72 44 78 23
Move over :58 move to index 3
 0 7 49 58 73 30 72 44 78 23
loop hit the target, index = 5, L[i].key = 30 move into temp
Moving :73, move the big element to right
 0 7 49 58 73 73 72 44 78 23
Moving :58, move the big element to right
 0 7 49 58 58 73 72 44 78 23
Moving :49, move the big element to right
 0 7 49 49 58 73 72 44 78 23
Move over :30 move to index 2
 0 7 30 49 58 73 72 44 78 23
loop hit the target, index = 6, L[i].key = 72 move into temp
Moving :73, move the big element to right
 0 7 30 49 58 73 73 44 78 23
Move over :72 move to index 5
 0 7 30 49 58 72 73 44 78 23
loop hit the target, index = 7, L[i].key = 44 move into temp
Moving :73, move the big element to right
 0 7 30 49 58 72 73 73 78 23
Moving :72, move the big element to right
 0 7 30 49 58 72 72 73 78 23
Moving :58, move the big element to right
 0 7 30 49 58 58 72 73 78 23
Moving :49, move the big element to right
 0 7 30 49 49 58 72 73 78 23
Move over :44 move to index 3
 0 7 30 44 49 58 72 73 78 23
loop hit the target, index = 9, L[i].key = 23 move into temp
Moving :78, move the big element to right
 0 7 30 44 49 58 72 73 78 78
Moving :73, move the big element to right
 0 7 30 44 49 58 72 73 73 78
Moving :72, move the big element to right
 0 7 30 44 49 58 72 72 73 78
Moving :58, move the big element to right
 0 7 30 44 49 58 58 72 73 78
Moving :49, move the big element to right
 0 7 30 44 49 49 58 72 73 78
Moving :44, move the big element to right
 0 7 30 44 44 49 58 72 73 78
Moving :30, move the big element to right
 0 7 30 30 44 49 58 72 73 78
Move over :23 move to index 2
 0 7 23 30 44 49 58 72 73 78
 0 7 23 30 44 49 58 72 73 78

```
## 折半插入排序
因为考虑到左侧的数字其实已经是按顺序排列的，所以使用折半排序以找到插入点就是顺理成章的事情了。

```
/**
 * 折半插入排序法
 */
template<class T>
void BinaryInsertSort(DataList<T>& L,const int left,const int right){
    Element<T> temp;
    int i,low,high,middle,k;
    for(i = left+1; i < right; i++){
    	temp = L[i];
    	low = left;
    	high=i-1;
        if(L[i]<L[i-1]){
        	cout<< "loop hit the target, index = " << i;
        	cout<< ", L[i].key = "<< L[i].key <<" move into temp，begin binary search ..."<<endl;
            temp = L[i];//move into temp
            while(low <= high){
            	middle = (low + high)/2;
            	if(temp < L[middle]){
            		high = middle - 1;
            	}else{
            		low = middle + 1;
            	}
            }
            cout<< "find the key = "<< low <<" & moving."<<endl;

            for(k = i-1;k>=low;k--){
            	L[k+1] = L[k];
            }

            L[low] = temp;
            L.printInfo();
        }
    }
}
```

```c
original data :
 0 7 49 73 58 30 72 44 78 23
begin sort data :
**** Binary Insertion sort ****
loop hit the target, index = 4, L[i].key = 58 move into temp，begin binary search ...
find the key = 3 & moving.
 0 7 49 58 73 30 72 44 78 23
loop hit the target, index = 5, L[i].key = 30 move into temp，begin binary search ...
find the key = 2 & moving.
 0 7 30 49 58 73 72 44 78 23
loop hit the target, index = 6, L[i].key = 72 move into temp，begin binary search ...
find the key = 5 & moving.
 0 7 30 49 58 72 73 44 78 23
loop hit the target, index = 7, L[i].key = 44 move into temp，begin binary search ...
find the key = 3 & moving.
 0 7 30 44 49 58 72 73 78 23
loop hit the target, index = 9, L[i].key = 23 move into temp，begin binary search ...
find the key = 2 & moving.
 0 7 23 30 44 49 58 72 73 78
```

## 希尔排序

```c
/**
 * 希尔插入排序法
 */
template<class T>
void ShellInsertSort(DataList<T>& L,const int left,const int right){
    Element<T> temp;
    int i,j,gap = right-left+1;//size add 1
    do{
    	gap = gap/3 + 1;
    	cout<< "This loop gap is = "<< gap <<endl;
    	for(i = left + gap; i < right; i++){//反向计算避免边界值
    		if(L[i]<L[i-gap]){
    			cout<< "loop hit the target,index i-gap="<<i-gap<<" ,i ="<<i<<endl ;
    			cout<<L[i].key<<" exchange "<<L[i-gap].key<<endl;
    			temp = L[i];
    			j = i - gap;
    			do{
    				//同一组向后继续比较替换
    				L[j+gap] = L[j];
    				j = j-gap;
    			}while(j>=left && temp<L[j]);
    			L[j+gap]=temp;
    			L.printInfo();
    		}
    	}
    }while(gap > 1);
    L.printInfo();
}

```

```c
original data :
 0 7 49 73 58 30 72 44 78 23
begin sort data :
**** Shell Insertion sort ****
This loop gap is = 4
loop hit the target,index i-gap=3 ,i =7
44 exchange 73
 0 7 49 44 58 30 72 73 78 23
loop hit the target,index i-gap=5 ,i =9
23 exchange 30
 0 7 49 44 58 23 72 73 78 30
This loop gap is = 2
loop hit the target,index i-gap=3 ,i =5
23 exchange 44
 0 7 49 23 58 44 72 73 78 30
loop hit the target,index i-gap=7 ,i =9
30 exchange 73
 0 7 49 23 58 30 72 44 78 73
This loop gap is = 1
loop hit the target,index i-gap=2 ,i =3
23 exchange 49
 0 7 23 49 58 30 72 44 78 73
loop hit the target,index i-gap=4 ,i =5
30 exchange 58
 0 7 23 30 49 58 72 44 78 73
loop hit the target,index i-gap=6 ,i =7
44 exchange 72
 0 7 23 30 44 49 58 72 78 73
loop hit the target,index i-gap=8 ,i =9
73 exchange 78
 0 7 23 30 44 49 58 72 73 78
 0 7 23 30 44 49 58 72 73 78
```
Insertion_sort_algorithm.md
 Created on: Oct 16, 2019
     Author: chenjie
