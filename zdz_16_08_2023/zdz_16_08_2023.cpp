// zdz_16_08_2023.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include "operacje.h"

using namespace std;

#define SIZE 10


void macierz_mnoz(double **a, double *b, double *c, int start = 0, int stop = SIZE) {
    //cout << "TUTAJ WĄTEK o start " << start << "\n";
    
    for (int i = start; i < stop; i++) {
        for (int j = 0; j < SIZE; j++) {
            c[i] += a[i][j] * b[j];
        }
        
    }
}

int main()
{
    //cout << sizeof(double) << "\n";

   srand(time(NULL));
    double **a = new double*[SIZE];
    double* b = new double[SIZE];
    double* c = new double[SIZE];
    for (int i = 0; i < SIZE; i++) {
        a[i] = new double[SIZE];
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = (rand() * 1.) / (rand() * 1.);
            //cout << a[i][j] << " ";
        }
       // cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        b[i] = (rand() * 1.) / (rand() * 1.);
        //cout << b[i] << " ";
        c[i] = 0;
    }
    //cout << "\n\n";
    cout << "START LICZENIA\n\n\n";
    thread* threads = new thread[4];

    int s = SIZE/ 4;
    for (int i = 0; i < 4; i++) {
        threads[i] = thread(macierz_mnoz, a, b, c, s * i, s * i + s);
        //threads[i].join();
        //threads[i] = w;

    }
    for (int i = 0; i < 4; i++) threads[i].join();

    //thread watek(macierz_mnoz, a, b, c, 0, SIZE);
    //thread watek2(macierz_mnoz, a, b, c, 2500, 4999);

    //watek.join();
    //watek2.join();

    for (int i = 0; i < SIZE; i++) {
        cout << c[i] << " ";
    }
    cout << "\n\n";




    /*Operacje<int, char, string, int> op;

    cout << op.wieksze('z', 'a');
    cout << op.wieksze(14, 15);
    cout << op.wieksze(true, false);
    //cout << op.wieksze("Bartek", "Ala");
    A a;
    A b;
    cout << Operacje<A>::wieksze(a, b);

    cout << Operacje<A>::rowne("Polska", "Polska");

    std::cout << "Hello World!\n";*/
}


