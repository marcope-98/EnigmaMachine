#ifndef ENIGMA_ALPHABET_H
#define ENIGMA_ALPHABET_H

#include <iostream>
/**
    Alphabet -> classe base di Rotor and Reflector
    */


class Alphabet
{
protected:
    int size;      // dimensione dei dati del rotore 
    int* data;     // dati del rotore
    int initIndex; // primo elemento per l'inizializzazione del rotore (non rilvante)

    explicit Alphabet(int size);            // costruttore 1
    Alphabet(int size, int* data);          // costruttore 2
    int reset(int& val, const int& val_);   // reset se esce dal range di data

public:
    // getter
    int getSize() const { return size; }
    
    // costruttore di copia
    Alphabet(const Alphabet& other);

    // overloading degli operatori
    virtual Alphabet &operator<<=(int val); // inizializzazione successiva (usa InitIndex)
    virtual Alphabet &operator,(int val);   // inizializzazione successiva (usa InitIndex)
    virtual int operator()(int& i) const;   // operatore di accesso (sola lettura)
    virtual int &operator()(int& i);         // operatore di accesso (lettura + scrittura)
    virtual int operator>>=(int& i);        // operatore di step
    virtual int operator+(int i);           // operatore di step


    void setAllValuesAt(int value);         // setter di default (inizializza tutti i dati a @param value)

    ~Alphabet() { delete[] data; }          // distruttore

};



#endif //ENIGMA_ALPHABET_H
