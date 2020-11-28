
/*
SUBMIITED BY GROUP NO 12
Himanshu Kashyap 202CS012 (Group Leader)
Pranab Nandy 202CS019
Rakeshwar Verma 202CS021
Ankush Ravindra Dhamanwar 202CS002
Satyam Prakash 202CS027
*/



#include<bits/stdc++.h>
using namespace std;
std:: ofstream input;
std:: ofstream output;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int* arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergesort(int* arr, int l, int r){
    if (l>=r) return;
    int m = (l + r - 1) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
}
void merge2(int* arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergesort2(int* arr, int n){
    int curr_size;
    int left_start;

    for(curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size){
        for(left_start = 0; left_start < n - 1; left_start += 2 * curr_size){
            int mid = min(left_start + curr_size - 1, n-1);
            int right_end = min(left_start + 2 * curr_size - 1, n-1);
            merge(arr, left_start, mid, right_end);
        }
    }
}
void print(int *arr,int n){
	output.open("output.txt", std::ios_base::app);
	for(int i=0;i<n;i++){
		output<<arr[i];
		output<<" ";
	}
	output<<"\n";
}
int main(){
	input.open("input.txt", std::ios_base::app);
    int t = 4;
    while(t--){
        if(t == 3){
            int n = 10000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
                input<<(arr[i]);
                input<<" ";
            }
            input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Recursive) with 10^4 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Recursive) with 10^4 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Recursive) with 10^4 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }

        if(t == 2){
            int n = 100000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
                input<<(arr[i]);
                input<<" ";
            }
            input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Recursive) with 10^5 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Recursive) with 10^5 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Recursive) with 10^5 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }

        if(t == 1){
            int n = 1000000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
                input<<(arr[i]);
                input<<" ";
            }
             input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Recursive) with 10^6 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Recursive) with 10^6 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Recursive) with 10^6 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }

        if(t == 0){
            int n = 10000000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
                input<<(arr[i]);
                input<<" ";
            }
            input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Recursive) with 10^7 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Recursive) with 10^7 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort(arr, 0, n - 1);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Recursive) with 10^7 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }
        
    }
    
    
    
    
    
   t = 4;
    while(t--){
        if(t == 3){
            int n = 10000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
              	input<<(arr[i]);
                input<<" ";
            }
             input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Iterative) with 10^4 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Iterative) with 10^4 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Iterative) with 10^4 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }

        if(t == 2){
            int n = 100000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
                input<<(arr[i]);
                input<<" ";
            }
             input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Iterative) with 10^5 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Iterative) with 10^5 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Iterative) with 10^5 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }

        if(t == 1){
            int n = 1000000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
               	input<<(arr[i]);
                input<<" ";
            }
             input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Iterative) with 10^6 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Iterative) with 10^6 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Iterative) with 10^6 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
        }

        if(t == 0){
            int n = 10000000;
            int *arr = new int[n];
            srand((unsigned) time(0));
            for(int i=0; i<n; i++){
                arr[i] = (rand()%10000000);
                input<<(arr[i]);
                input<<" ";
            }
             input<<"\n";
            const clock_t begin_random_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort random arr using MergeSort(Iterative) with 10^7 elements: "<< float( clock () - begin_random_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            
            const clock_t begin_sorted_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort sorted arr using MergeSort(Iterative) with 10^7 elements: "<< float( clock () - begin_sorted_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;

            int p = n / 1000;
            for (int k = 0; k < p; k++){
                int x = rand() % n;
                int y = rand() % n;
                swap(&arr[x], &arr[y]);
            }

            const clock_t begin_swapped_time = clock();
            mergesort2(arr, n);
            print(arr,n);
            cout <<"Time required to sort swapped arr using MergeSort(Iterative) with 10^7 elements: "<< float( clock () - begin_swapped_time ) /  CLOCKS_PER_SEC<<" sec"<<endl;
            cout<<endl;
            
            cout << "The amount of space is used during running the program = Maximum resident set size (kbytes) [ ===> 57th line ]" << endl;
	cout << endl;
	
	cout << "Large size input data is handled by \'Array\' Data Structure of int type where data is read from input file and output is written back to output file" << endl;
	cout << endl;


	cout << "Memory release statement is present from 71th line onwards " << endl;
	cout << endl;
	
	cout << "MergeSort takes O(nlogn) time to perfrom sorting operation in all cases as working of Merge sort is independent of distribution of data " << endl;
	cout << endl;
	
	cout << "Disadvantage of Merge sort implemented either recursively or non-recursively is that it requires an extra space of O(n) " << endl;
	cout << endl;
        }
        
    }
  
}
