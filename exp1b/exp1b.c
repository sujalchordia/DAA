#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int*a , int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selSort(int* arr , int size){
	for(int i=0;i<size-1;i++){
		int minId = i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[minId]){
				minId = j;
			}
		}
		if(i!=minId){
			swap(&arr[i],&arr[minId]);
		}
	}
}

void insertSort(int *arr, int n){
	int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
} 

void quickSort(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quickSort(a, start, p - 1);  
        quickSort(a, p + 1, end);  
    }  
}  

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  

int main(){
	for(int i=1;i<=100;i++){
		int j=0;
		int numberArray[100000];
		FILE *f;
		f = fopen("new.txt","r");
		for (j = 0; j < 100000; j++){
       	 	fscanf(f, "%d,", &numberArray[j] );
    		}
    	fclose(f);
		clock_t t;
    	t = clock();
		//mergeSort(numberArray,0,i*100);
		selSort(numberArray,i*100);
		t = clock() - t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    	printf("%f\n",time_taken);
    }
}
