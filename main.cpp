#include <iostream>
#include <string.h>

#include "pilePuntatori.h"
#include "pileVettori.h"
#include "pileMultiple.h"

void catchNewVariable(char *);

int main()
{
    linkedStack<float> homer;
    vectorStack<int> marge;

    marge.push(10);
    marge.push(20);
    marge.push(30);
    marge.push(40);
    marge.push(50);
    marge.push(60);
    marge.push(70);
    marge.push(80);

    marge.pop();
    marge.pop();

    cout << "valore in testa: " << marge.top() << endl;

    marge.print();

    homer.push(100);
    homer.push(200);
    homer.push(300);
    homer.push(400);
    homer.push(500);
    homer.push(600);
    homer.push(700);
    homer.push(800);

    homer.pop();
    homer.pop();

    cout << "valore in testa: " << homer.top() << endl;

    homer.print();


    multipleStack<int> apu(10);

    return 0;
}
/*
template <class S, class T>
void catchNewVariable(char *sequenza, linkedStack<S> codaVariabili, linkedStack<T> codaValori) {

    bool assegnazione = false;
    bool valoreAttuale = false;
    int moltiplicatore = 1;
    T sommaAttuale = 0;
    T valoreFinale = 0;
    T valorePrelevato;

    for (int i = 0; i < strlen(sequenza); i++) {
        if(sequenza[i] >= 'a' && sequenza[i] <= 'z') {
            if(assegnazione == false) {
                codaVariabili.push(sequenza[i]);
            } else if(assegnazione == true) {
                int prof = codaVariabili.calcolaProfondita(sequenza[i]);
                if(valoreFinale == 0) {
                    valoreFinale = codaValori.prendiDaProfondita(prof);
                } else valorePrelevato = codaValori.prendiDaProfondita(prof);
            }
        } else if(sequenza[i] == '=') {
            assegnazione = true;
        } else if(sequenza[i] == '+' || sequenza[i] == '-' || sequenza[i] == '*' || sequenza[i] == '/') {
            //operatore
        } else if(sequenza[i] >= '1' && sequenza[i] <= '9') {
            valoreAttuale = true;
            sommaAttuale = sommaAttuale + ((sequenza[i] - '0') * moltiplicatore);
            moltiplicatore = moltiplicatore * 10;
        } else {
            if(valoreAttuale == true) {
                //valore da salvare
            }

            valoreAttuale = false;
            moltiplicatore = 1;
            sommaAttuale = 0;
        }
    }

}

*/
