#include <iostream>
#include <math.h>

using namespace std;

void regua(int v[], int n, int x, int tam, int tam2){
    int pon, k;
    pon = tam / 2;
    x = pon;
    k = pon * 2;
    if(n > 1){
        regua(v, n-1, x, k/2, tam2);  
    }
    while(x <= tam2){
        if(v[x] == 0){
            v[x] = n;
        }
        x += k;
    }
    if(v[x] == 0){
            v[x] = n;
        }
}



int main(){
    int n, tam, x = 1;
    cin >> n;
    tam = pow(2, n);
    int v[tam];
    for(int i = 0; i < tam; i++){
        v[i] = 0;
    }
    regua(v, n, x, tam, tam);
    cout << endl;
    for(int i = 0; i < tam; i++){
        if(v[i] == 0){
            cout << " ";
        } else{
        for(int j = 0; j < v[i]; j++){
            cout << "-";
        }
        }
        cout << endl;
    }
}