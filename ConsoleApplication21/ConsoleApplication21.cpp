#include "pch.h"
#include <iostream>
#include <time.h>

using namespace System;
using namespace std;

const int cols = 200;
const int rows = 45;

void initialSettings() {
    Console::SetWindowSize(cols, rows);
    Console::SetBufferSize(cols, rows);
    Console::CursorVisible = false;
}

void goToXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}

//[65,90]
int getRandomNumber(int a, int b) {
    return a + rand() % (b - a + 1);
}

void print(int x, int y, int n) {
    for (int i = x; i <= x+(n-1); i++){
        goToXY(i, y);
        cout << char(getRandomNumber(65,90));
    }
    for (int i = x; i <= x + (n - 1); i++) {
        goToXY(i, y + (n-1));
        cout << char(getRandomNumber(65, 90));
    }
    for (int j = y +1; j <= y + (n - 2); j++) {
        goToXY(x,j);
        cout << char(getRandomNumber(65, 90));

    }
    for (int j = y + 1; j <= y + (n - 2); j++) {
        goToXY(x + (n - 1), j);
        cout << char(getRandomNumber(65, 90));

    }
}

void deleteF(int x, int y, int n) {
    for (int i = x; i <= x + (n - 1); i++) {
        goToXY(i, y);
        cout << " ";
    }
    for (int i = x; i <= x + (n - 1); i++) {
        goToXY(i, y + (n - 1));
        cout << " ";
    }
    for (int j = y + 1; j <= y + (n - 2); j++) {
        goToXY(x, j);
        cout << " ";

    }
    for (int j = y + 1; j <= y + (n - 2); j++) {
        goToXY(x + (n - 1), j);
        cout << " ";

    }
}

int main()
{

    initialSettings();

    int n;
    cout << "Ingrese cantidad de figuras: ";
    cin >> n;

    int xi = (200 - n) / 2;
    int dx = 1;


    while (1) {
        //BORRAR
        int yi = 1;
        for (int i = 0; i < n; i++)
        {
            deleteF(xi, yi, n);
            yi += (n + 1);
        }

        //CAMBIAR COORDENDAS

        if (xi + dx >= cols - n) {
            dx = -1;
        }
        if (xi + dx <= 0) {
            dx = 1;
        }
        xi += dx;

        //PINTAR
        yi = 1;
        for (int i = 0; i < n; i++)
        {
            print(xi, yi, n);
            yi += (n + 1);
        }

        _sleep(1);
    }

    

    cin.get();
    cin.ignore();
    return 0;
}
