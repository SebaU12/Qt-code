#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

#include "Block.h"
#include "BlockChain.h"
#include "TRANSACTION.h"

void Menu(Blockchain *heiderCoin) {
    int cantidad, block;
    char rpta;
    string emisor, receptor;

    do {
        cout << endl
             << "---------------------------" << endl;
        cout << "    HeiderCoin Main Menu" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Crear Bloque" << endl;
        cout << "2. Imprimir Blockchain" << endl;
        cout << "3. Proof Of Work Test" << endl;
        cout << "4. Arreglar Blockchain" << endl;
        cout << "5. Exportar Blockchain" << endl;
        cout << "6. Salir" << endl;

        cout << endl
             << "Ingrese una opcion: ";
        cin >> rpta;
        cout << endl;

    } while (rpta != '1' && rpta != '2' && rpta != '3' && rpta != '4' && rpta != '5' && rpta != '6');

    if (rpta == '1') {  // Creamos y a;adimos el bloque a la blockchain

        cout << "---------------------------" << endl;
        cout << endl
             << "Ingrese Emisor: ";
        cin >> emisor;
        cout << "Ingrese Receptor: ";
        cin >> receptor;
        cout << "Ingrese cantidad de HCoins a enviar: ";
        cin >> cantidad;
        cout << endl;
        time_t dataTime;
        TRANSACTION *data = new TRANSACTION(cantidad, emisor, receptor, time(&dataTime));
        heiderCoin->addBlock(data);
        cout << endl
             << "Bloque creado satisfactoriamente." << endl;
        Menu(heiderCoin);
    } else if (rpta == '2') {
        heiderCoin->show_blockchain();
        Menu(heiderCoin);

    } else if (rpta == '3') {
        cout << "---------------------------" << endl;
        cout << endl
             << "Ingrese Bloque: ";
        cin >> block;
        heiderCoin->test_proof_work(block);
        Menu(heiderCoin);

    } else if (rpta == '4') {
        cout << "---------------------------" << endl;
        cout << "Arreglando Blockchain..." << endl;
        cout << "---------------------------" << endl;

        heiderCoin->fix_all();
        cout << endl
             << "Blockchain Arreglada Satisfactoriamente." << endl;
        Menu(heiderCoin);

    }

    else if (rpta == '5') {
        string file;
        cout << "Ingrese nombre del archivo: " << endl;
        cin >> file;
        file = file + ".txt";
        heiderCoin->import_blockchain(file);
    }

    else if (rpta == '6') {
        cout << endl
             << "Gracias por usar la plataforma. " << endl;
        cout << endl
             << " " << endl;
    }
}
