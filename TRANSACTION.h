//
//  TRANSACION.h
//  BlockChain Proyect
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std; // Evita poner std:: en el codigo.


struct TRANSACTION{
  string amount; // almacena la cantidad de la transaccion.
  string senderKey; // Almacena la llave del emisor en la transaccion.
  string recieverKey; // Almacena la llave del receptor en la transaccion.
  string timestamp; // time_t Almacena valores de tiempo en la transaccion.

  TRANSACTION(){}

  //Aqui Se usa valores como "amt" en lugar de amount, para poder diferenciar. si     esto no fuera asi, abajo pondriamos amount = amount, lo que podria ser confuso.

  TRANSACTION(double amt, string sender, string reciever, time_t time){
    amount = to_string(amt);
    senderKey = sender;
    recieverKey = reciever;
    timestamp = ctime(&time);
  }
  TRANSACTION(string amt, string sender, string reciever, string time){
    amount = amt;
    senderKey = sender;
    recieverKey = reciever;
    timestamp = time;
  }
  string get_data(){
      string result = ""; 
      result += this->amount; 
      result += this->senderKey; 
      result += this->recieverKey; 
      result += this->timestamp; 
      return result; 
    }
};

#endif
