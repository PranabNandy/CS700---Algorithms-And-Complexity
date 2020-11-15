

/*-------- Analysis of Quick Sort Algorithm --------- */


#include<bits/stdc++.h>
#include <chrono> 
#include <sys/resource.h>
#include <sys/time.h>
using namespace std;

class QuickSort{
	private:
		vector<long int> arr;
	public:
		QuickSort(int n){
			//arr.resize(n);
			srand((unsigned) time(0));
			ofstream inputFile ("input.txt");
			if (inputFile.is_open()){
				for(int i=0;i<=n;i++){
					long int x=rand()%100000;
					inputFile<<x<<"\n";    //Storing data into input file
					
				}
			
			}
			inputFile.close();

			fstream readingInput("input.txt", ios_base::in);
		    long int x;
		    int i=0;
		    while(readingInput>>x){
		    	arr.push_back(x);         //Reading data from input file
		    }

			readingInput.close();
			
		}
		void swap(long int &a,long int &b){
			long int temp=a;
			a=b;
			b=temp;
		}
		int findPivotIndex(int pivot,int st,int end){
			int ele=arr[pivot];
			int i=1+st, j=st;
			while(i<=end){
				if(ele<=arr[i]) i++;
				else{
					j++;
					swap(arr[j],arr[i]);
					i++;
				}			
				
			}
			swap(arr[j],arr[pivot]);
			return j;
		}
		
		void qsort(int st,int end){
			if(st>=end) return;
			int pivot=st+0;
			int index=findPivotIndex(pivot,st,end);
			qsort(st,index-1);
			qsort(index+1,end);
		}
		void print(){
			l1: ofstream outputFile ("output.txt");
			if(outputFile.is_open()==false)
				 goto l1;
		
			for(long int i:arr)
				outputFile<<i<<"\n";        //Storing output into output file from array
		
			outputFile.close();
		}
		

};
int main() {

	auto start =std::chrono::high_resolution_clock::now(); 
	
	
	int n=100111;
	QuickSort *ob=new QuickSort(n);
	ob->qsort(0,n);
	ob->print();
	
   	auto stop = std::chrono::high_resolution_clock::now(); 
   	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
   	cout<<"--------------------------------------------------------------------------------------"<<endl;      
    double ans=duration.count();
   	ans=ans/1000000;
   	cout.precision(6);
    cout << "Time taken to perform the Quick Sort over "<<n+1<<" elements considering 0th element as Pivot is "
         <<fixed<< ans <<" seconds"<< endl;
   	cout<<endl;
   	cout<<"The amount of space is used during running the program = Maximum resident set size (kbytes) [ ===> 26th line ]"<<endl;
   	cout<<endl;
   	cout<<"Large size input data is handled by \'Array\' Data Structure of Long Int type where data is read from input file and output is written back to output file"<<endl;
   	cout<<endl;

    cout<<"Memory release statement is present from 41th line onwards "<<endl;
    cout<<endl;
    
   
    cout<<"--------------------------------------------------------------------------------------"<<endl;      
   	cout<<endl;
         
    return 0;
}
