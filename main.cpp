/*
 * mainai.cpp
 *
 *  Created on: 2011.09.03
 *      Author: adomas
 */

#include <fstream>

#define INPUT "U1.txt"
#define OUTPUT "U1rez.txt"

using namespace std;

//kintamuju apsirasymas
int n_gil, n_egl; //monetu nominalu kiekiai
int *p_gil_nom, *p_egl_nom; //rodykles i nominalu masyvus
int *p_gil_n, *p_egl_n; //rodykles i monetu masyvus
int gaus_gil, gaus_egl; //kiek gaus

void skaitymas() {
    ifstream f;
    f.open(INPUT);
    f >> n_gil;
    p_gil_nom = new int[n_gil];
    p_gil_n = new int[n_gil];
    int i;
    for(i=0; i<n_gil; i++) {
        f >> p_gil_nom[i];
    }
    for(i=0; i<n_gil; i++) {
        f >> p_gil_n[i];
    }
    f >> n_egl;
    p_egl_nom = new int[n_egl];
    p_egl_n = new int[n_egl];
    for(i=0; i<n_egl; i++) {
        f >> p_egl_nom[i];
    }
    for(i=0; i<n_gil; i++) {
        f >> p_egl_n[i];
    }
}

void suma(const int n, const int* p_nom, const int* p_n, int &gaus) {
    gaus = 0;
    for (int i = 0; i < n; i++) {
        gaus += p_nom[i] * p_n[i];
    }
}

void rasymas() {
    ofstream f;
    f.open(OUTPUT);

    int monetu_viso;
    int monetu;
    int gaus;
    int i;

    gaus = gaus_gil;
    monetu_viso = 0;
    for (i=0; i<n_egl; i++) {
        monetu = gaus / p_egl_nom[i];
        gaus -= monetu * p_egl_nom[i];
        monetu_viso += monetu;
        f << p_egl_nom[i] << ' ' << monetu << endl;
    }
    f << monetu_viso << endl;

    gaus = gaus_egl;
    monetu_viso = 0;
    for (i=0; i<n_gil; i++) {
        monetu = gaus / p_gil_nom[i];
        gaus -= monetu * p_gil_nom[i];
        monetu_viso += monetu;
        f << p_gil_nom[i] << ' ' << monetu << endl;
    }
    f << monetu_viso << endl;

}

int main() {
    skaitymas();
    suma(n_gil, p_gil_nom, p_gil_n, gaus_gil);
    suma(n_egl, p_egl_nom, p_egl_n, gaus_egl);
    rasymas();
    delete[] p_egl_n;
    delete[] p_egl_nom;
    delete[] p_gil_n;
    delete[] p_gil_nom;

    return 0;
}
