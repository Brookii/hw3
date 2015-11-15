#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;


void random(double* pointer, int N){
	for(int i=0;i<N;i++){
		*pointer = rand()/(double)RAND_MAX;
		pointer = pointer+1;	
	}
}

void Mittelwert(double& mean, int N, double* pointer){
		for(int i = 0; i < N ; i++){
		mean += *(pointer+i); 
		}
		mean /= N;
}

void Varianz(double& var,double& mean, int N, double* pointer){
		for(int i = 0; i < N ; i++){
			var += (*(pointer+i)-mean) * (*(pointer+i)-mean ); 
		}
		var /= N;
}

int main(){
   const int N = 100;
   double p[N];
   double mean, var;
   double* pointer = &p[0];
   double* helferling = pointer;
   
   random(pointer,N);
   pointer = helferling;
   Mittelwert(mean,N,pointer);
   pointer = helferling;
   Varianz(var,mean,N,pointer);

	cout << "Mean = " << mean << endl;
	cout << "Variance = " << var << endl;

   return 0;
}
