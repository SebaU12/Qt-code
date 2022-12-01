// Clase Blockchain
#ifndef BLOCKCHAIN_H 
#define BLOCKCHAIN_H


#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <string>
#include "Block.h"
#include "double.h"
using namespace std;


class Blockchain
{
private:
    List<Block*> *chain = new DoubleList<Block*>();
    unsigned int size_chain = 0;
public:
    // Constructor
    Blockchain(){}

    // Public Functions
    void addBlock(TRANSACTION *data){
        if(this->chain->back() != nullptr){
            Block *prev_block = this->chain->back();
            Block *new_block = new Block(data);
            string prev_hash = prev_block->get_hash();
            new_block->set_id(this->size_chain+1, prev_hash);
            new_block->mine();
            this->chain->push_back(new_block);
            this->size_chain = this->chain->size();
        } else {
            Block *new_block = new Block(data);
            new_block->set_id(this->size_chain+1, "");
            new_block->mine();
            this->chain->push_back(new_block);
            this->size_chain = this->chain->size();
        }
    }
    void show_blockchain(){
        ListIterator<Block*> it;
        for (it = this->chain->begin(); it != this->chain->end(); ++it)
        {
            Block *currentBlock = *it;
            currentBlock->show_block_info();
        }
    }
    void test_proof_work(int id){
        int cont = 1;
        ListIterator<Block*> it;
        string hash_tmp;
        bool flag1 = false;
        bool flag2 = false;
        for (it = this->chain->begin(); it != this->chain->end(); ++it)
        {
            Block *currentBlock = *it;
            if(flag2 == true){
                currentBlock->set_hash_prev(hash_tmp);
                currentBlock->mine();
            }
            if(flag1 == true){
                currentBlock->set_hash_prev(hash_tmp);
            }
            if(cont == id){
                currentBlock->modify("Soy modificacion");
                flag1 = true;
            }
            hash_tmp = currentBlock->get_hash();
            cont++;
        }
    }
    void fix_all(){
        ListIterator<Block*> it;
        string hash_tmp;
        for (it = this->chain->begin(); it != this->chain->end(); ++it)
        {
            Block *currentBlock = *it;
            if(currentBlock->get_validation() == false){
                currentBlock->set_hash_prev(hash_tmp);
                currentBlock->mine();
            }
            hash_tmp = currentBlock->get_hash();
        }
    }
    int get_size(){return size_chain;}
};





#endif
