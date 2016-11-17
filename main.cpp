#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int SIZE = 50000;
const int SIZE2 = 1000;

int main()
{
        clock_t start, stop;
        float diff;
        float sec, sec2, sec3, sec4, sec5, sec6, sec7;
	
/*
        start = clock();
        //alkjfvkljabf
        stop = clock();
        diff = ((float)stop - (float)start);
        sec = diff/CLOCKS_PER_SEC;
*/
	int shell_sort(int[], int);
	int getLargest(int[], int);
	void countSort(int[], int, int);
	void copy(int*, int*&);
        void display(int[]);
	int bubble_sort(int[]);
	int quick_sort(int[], int, int);
	int radix_sort(int[], int);
        int select_sort(int*);
	int insert_sort(int*);
	int merge(int*, int, int, int);
	int merge_sort(int*, int, int);

        srand(time(NULL));
        int j = 0;
        int * list;
	int * list2;
	int * list3;
	int * list4;
	int * list5;
	int * list6;
	int * list7;
        int num;
        int length = SIZE;

        list = new int[SIZE];
	list2 = new int[SIZE];
	list3 = new int[SIZE];
	list4 = new int[SIZE];
	list5 = new int[SIZE];
	list6 = new int[SIZE];
	list7 = new int[SIZE];

        for(j = 0; j < SIZE; ++j)
        {
                num = rand() % SIZE2;
                list[j] = num;
        }

	copy(list, list2);
	copy(list, list3);
	copy(list, list4);
	copy(list, list5);
	copy(list, list6);
	copy(list6, list7);
        
/*	cout << "\nHere is unsorted list1 >> ";
        display(list);
	cout << "\nHere is unsorted list2 >> ";
	display(list2);
	cout << "\nHere is unsorted list3 >> ";
	display(list3);
	cout << "\nHere is unsorted list4 >> ";
	display(list4);
	cout << "\nHere is unsorted list5 >> ";
	display(list5);
*/

	cout << "\nHere is unsorted list6 >> ";
	display(list6);
	cout << "\nHere is unseroted list7 >> ";
	display(list7);
	

	start = clock();
        select_sort(list);
        stop = clock();
        diff = ((float)stop - (float)start);
        sec = diff/CLOCKS_PER_SEC;

        start = clock();
        insert_sort(list2);
        stop = clock();
        diff = ((float)stop - (float)start);
        sec2 = diff/CLOCKS_PER_SEC;

	start = clock();
        merge_sort(list3,0,(SIZE-1));
        stop = clock();
        diff = ((float)stop - (float)start);
        sec3 = diff/CLOCKS_PER_SEC;

	start = clock();
        radix_sort(list4, SIZE);
        stop = clock();
        diff = ((float)stop - (float)start);
        sec4 = diff/CLOCKS_PER_SEC;

	start = clock();
        quick_sort(list5, 0, (SIZE-1));
        stop = clock();
        diff = ((float)stop - (float)start);
        sec5 = diff/CLOCKS_PER_SEC;

	start = clock();
        bubble_sort(list6);
        stop = clock();
        diff = ((float)stop - (float)start);
        sec6 = diff/CLOCKS_PER_SEC;

	start = clock();
        shell_sort(list7, (SIZE-1));
        stop = clock();
        diff = ((float)stop - (float)start);
        sec7 = diff/CLOCKS_PER_SEC;


	cout << "\nHere is sorted list1 from selection sort >> ";
        display(list);
	cout << "\nHere is sorted list2 from insertion sort >> ";
	display(list2);
	cout << "\nHere is sorted list3 from merge sort >> ";
	display(list3);
	cout << "\nHere is sorted list4 from radix sort >> ";
	display(list4);
	cout << "\nHere is sorted list5 from quick sort >> ";
	display(list5);
	cout << "\nHere is sorted list6 from bubble sort >> ";
	display(list6);
	cout << "\nHere is sorted list7 from shell sort >> ";
	display(list7);



	cout << "\nBUBBLE SORT took " << sec6 << " seconds to run." << endl;
	cout << "\nINSERTION SORT took " << sec2 << " seconds to run." << endl;
	cout << "\nSELECTION SORT took " << sec << " seconds to run." << endl;
	cout << "\nMERGE SORT took " << sec3 << " seconds to run." << endl;
	cout << "\nQUICK SORT took " << sec5 << " seconds to run." << endl;
	cout << "\nSHELL SORT took " << sec7 << " seconds to run." << endl;
	cout << "\nRADIX SORT took " << sec4 << " seconds to run." << endl;
	

        return 0;
}



void copy(int * source, int * & dest)
{
	int j = 0;

	if(!source)
		return;
	
	for(j = 0; j < SIZE; ++j)
		dest[j] = source[j];
}	


void display(int list[])
{
        int j = 0;

        if(!list)
                return;

        for(j = 0; j < SIZE; ++j)
                cout << list[j] << "|";

        cout << endl;
}

int shell_sort(int array[], int size)
{
	int j = 0;
	int gap = 0;
	int i = 0;
	int temp = 0;

	for(gap = (size/2); gap > 0; gap = gap/2)
	{
		for(i = gap; i < size; ++i)
		{
			temp = array[i];

			for(j = i; j >= gap && temp < array[j - gap]; j = j - gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
	}

	return 1;
}	





int select_sort(int * array)
{

        int j = 0;
        int k = 0;
        int * curMin;
        int temp;

        if(!array)//if empty
                return 0;

        for(j = 0; j < SIZE; ++j)
        {//for all items 0...N-1
                curMin = &array[j];//set the minimum ptr to the first element

                for(k = j+1; k < SIZE; ++k)//for the second element onward
                {
                        if(array[k] < *curMin)//if an element is less than the current minimum
                                curMin = &array[k];//set THAT item as the new current minimum
                }

                temp = array[j];
                array[j] = *curMin;
                *curMin = temp;
        }

        return 1;
}



int insert_sort(int * array)
{
	int lastSortedIndex, j, k, extracted;
	int * open;
	bool done;

	if(!array)
		return 0;

	lastSortedIndex = 0;//mark the first element as 'sorted'
	for(j = 1; j < SIZE; ++j)//for each unsorted element
	{
		extracted = array[j];//'extract' the element
		open = &array[j];		
		for(k = lastSortedIndex; k >= 0; --k)
		{
			if(array[k] > extracted)
			{
				*open = array[k];//move to the right by 1
				open = &array[k];
				if(k == 0)
					done = true;	
			}
			else
			{
				*open = extracted;
				lastSortedIndex = j;
			}
			if(done)
				*open = extracted;
		}
	}

	return 1;
}


int merge(int array[], int low, int mid, int high)
{
	int * subArray = new int[high-low+1]; 
	int h, i, j, k;

	h = low;
	j = mid + 1;
	i = 0;

	while((h <= mid) && (j <= high))
	{
		if(array[h] <= array[j])
		{
			subArray[i] = array[h];
			h++;
		}
		else
		{
			subArray[i] = array[j];
			j++;
		}
		i++;
	}

	if(h > mid)
	{
		for(k = j; k <= high; k++)
		{
			subArray[i] = array[k];
			i++;
		}
	}
	else
	{
		for(k = h; k <= mid; k++)
		{
			subArray[i] = array[k];
			i++;
		}
	}

	for(k = 0; k <= high-low; k++)
		array[k+low] = subArray[k];

	delete []subArray;

	return 1;
}





int merge_sort(int array[], int low, int high)
{
	int mid;

	if(low < high)
	{
		mid = (low+high)/2;
		merge_sort(array, low, mid);
		merge_sort(array, mid+1, high);
		merge(array, low, mid, high);
	}

	return 1;
}


int getLargest(int array[], int n)
{
	int max = array[0];
	int i = 0;	
	
	for(i = 1; i < n; ++i)
	{
		if(array[i] > max)
			max = array[i];
	}

	return max;
}



void countSort(int array[], int n, int exp)
{
	int output[n];
	
	int i, count[10] = {0};

	for(i = 0; i < n; i++)
		count[(array[i]/exp) % 10]++;

	for(i = 1; i < 10; i++)
		count[i] += count[i -1];

	for(i = n -1; i >= 0; i--)
	{
		output[count[(array[i]/exp) % 10] - 1] = array[i];
		count[(array[i]/exp) % 10]--;
	}

	for(i = 0; i < n; i++)
		array[i] = output[i];
}


int radix_sort(int array[], int n)
{
	int exp;
	int m = getLargest(array, n);

	for(exp = 1; (m/exp) > 0; exp *= 10)
		countSort(array, n, exp);

	return 1;
}



int quick_sort(int array[], int left, int right)
{
	int i = left;
	int j = right; 
	int temp = 0;
	srand(time(NULL));
	int piv = array[rand() % (right-left) + left];
	//int piv = array[(left+right) / 2];

	while( i <= j)
	{
		while(array[i] < piv)
			i++;
		while(array[j] > piv)
			j--;

		if(i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}

	if(left < j)
		quick_sort(array, left, j);

	if(i < right)
		quick_sort(array, i, right);


	return 1;
}


int bubble_sort(int array[])
{
	int unsorted = SIZE-1;
	bool swapped;
	int j = 0;
	int temp;

	do
	{
		swapped = false;
		for(j = 1; j <= unsorted; ++j)
		{
			if(array[j-1] > array[j])//if left bigger than right, swap
			{
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
				swapped = true;
			}			
		}
	}while(swapped);

	return 1;
}


















