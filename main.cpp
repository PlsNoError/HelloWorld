/*
Sa se descompuna un nr nat (unsingned long long) in factori primi, folosind un algoritm cat mai eficient!
*/

#include <iostream>
#include <math.h>
using namespace std;

int is_prime(int x);

#define DIM 32

int main()
{
    unsigned long long x, aux;
    int i, e, k, gasit;

    int prim[DIM]; // sirul factorilor primi
    int exp[DIM]; //sirul puterior la care apar factorii primi in descompunerea lui x
    for (i=0; i<DIM; i++)
        exp[i] = 0;
    x = 1;


    cout << "x=";
    cin >>x;
    aux = x;
    i = 0;
    e = 0;
    k = 2;
    while (aux!=1){
        while (((aux%k)==0)&&(is_prime(k)==1)) {
            aux = aux / k;
            e++;
            gasit = 1;
        }
        if (gasit==1){

            exp[i] = e;
            prim[i] = k;
            e = 0;
            i++;
        }
        gasit = 0;
        k++;
   }
   for (i=0; i<DIM; i++)
        if (exp[i]!=0){
            cout << prim[i] << "^" << exp[i] << endl;
        }

    return 0;
}

int is_prime(int x){
   int i, prim;
   prim = 1;
   for (i=2; i<=sqrt(x); i++)
        if (x%i==0)
            prim = 0;
   return prim;

}
