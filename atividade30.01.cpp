#include <iostream>

using namespace std;
// Selection sort Iv
void troca( int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void selection (int *v, int n){
 int i, j, maior;
 for (i = n - 1; i > 0; i--){
    maior = i;
    for (j = i-2; j >= 0; j--){
        if (v[j] > v[maior])
            maior = j;
    }
    if (v[maior] != v[i]){
        troca (&v[maior], &v[i]);
    }
 }
}
// Bubble sort Iv
void bubble (int *v, int n){
   
    for(int j = 0; j < n - 1; j++){
        if(v[j] > v[j+1]){
            troca(&v[j], &v[j+1]);
        }
    }
    if(n > 0){
        bubble(v, n-1); 
    }   
}


int main(){
    int v[3] = {3, 2, 1};
    bubble(v, 3);
    for(int i = 0; i < 3; i++){
        cout << v[i];
    }
}