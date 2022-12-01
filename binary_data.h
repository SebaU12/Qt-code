#ifndef BINARY_DATA_H
#define BINARY_DATA_H
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Index {
  int pos;
  int total;
  int size_amount;
  int size_sender;
  int size_reciever;
  int size_timestamp;
};

struct Transaction {
  string amount;
  string sender;
  string reciever;
  string timestamp;
};

class VariableRecord {
private:
  string file;
  string index_file;

public:
  VariableRecord() {}
  VariableRecord(string _file);
  void add(Transaction record);
  vector<Transaction> load();
  Transaction readRecord(int pos);
};

VariableRecord::VariableRecord(string _file) {
  this->file = _file + ".dat";
  this->index_file = _file + "_index.dat";
  ofstream inFile;
  inFile.open(this->file, ios::binary | ios::app);
  inFile.close();

  ofstream inFile_index;
  inFile_index.open(this->index_file, ios::binary | ios::app);
  inFile_index.close();
}

void VariableRecord::add(Transaction record) {
  int size_amount = record.amount.size();
  int size_sender = record.sender.size();
  int size_reciever = record.reciever.size();
  int size_timestamp= record.timestamp.size();
  int cant_bytes =
      size_amount + size_sender + size_reciever + size_timestamp;  
  ofstream file;
  int scant_bytes = cant_bytes;
  Index getInd;
  int pos_total = 0;
  file.open(this->file, ios::binary | ios::app);
  if (file.is_open()) {
    file.write(&record.amount[0], record.amount.size());
    file.write(&record.sender[0], record.sender.size());
    file.write(&record.reciever[0], record.reciever.size());
    file.write(&record.timestamp[0], record.timestamp.size());
    file.close();
  } else {
    throw "No se pudo abrir el archivo";
  }
  ifstream file_ind;
  file_ind.open(this->index_file, ios::binary);
  if (file_ind.is_open()) {
    if (file_ind.peek() != EOF) {
      if (!file_ind.eof()) {
        file_ind.seekg(0, file_ind.beg);
        while (!file_ind.eof()) {
          file_ind.read((char *)&getInd, sizeof(Index));
          if (file_ind.eof()) {
            break;
          }
          pos_total += getInd.total;
        }
      }
    }
    file_ind.close();
  } else {
    throw "No se pudo abrir el archivo";
  }
  ofstream file_save;
  file_save.open(this->index_file, ios::binary | ios::app);
  if (file_save.is_open()) {
    Index ind = {pos_total, cant_bytes, size_amount, size_sender, size_reciever, size_timestamp};
    file_save.write((char *)&ind, sizeof(Index));
    file.close();
  } else {
    throw "No se pudo abrir el archivo";
  }
}

vector<Transaction> VariableRecord::load() {
  vector<Transaction> result;
  Transaction dataTransaction;
  Index dataIndex;
  ifstream file_ind;
  ifstream file;
  file_ind.open(this->index_file, ios::binary);
  if (file_ind.is_open() != true)
    throw "No se pudo abrir el archivo";
  file.open(this->file, ios::binary);
  if (file.is_open()) {
    while (true) {
    file_ind.read((char *)&dataIndex, sizeof(Index));
    dataTransaction.amount.resize(dataIndex.size_amount);
    dataTransaction.sender.resize(dataIndex.size_sender);
    dataTransaction.reciever.resize(dataIndex.size_reciever);
    dataTransaction.timestamp.resize(dataIndex.size_timestamp);
    file.read(&dataTransaction.amount[0], dataIndex.size_amount);
    file.read(&dataTransaction.sender[0], dataIndex.size_sender);
    file.read(&dataTransaction.reciever[0], dataIndex.size_reciever);
    file.read(&dataTransaction.timestamp[0], dataIndex.size_timestamp);
      if (file.eof()){
        break;
      }
        result.push_back(dataTransaction);
    }
    file.close();
    file_ind.close();
  } else {
    throw "No se pudo abrir el archivo";
  }
  return result;
}

Transaction VariableRecord::readRecord(int pos) {
  Transaction result;
  Index index;
  ifstream file;
  ifstream file_index;
  pos -= 1;
  file_index.open(this->index_file, ios::binary);
  file.open(this->file, ios::binary);
  if (file_index.is_open()) {
    file_index.seekg(pos * sizeof(Index), ios::beg);
    file_index.read((char *)&index, sizeof(Index));
    file_index.close();
  } else {
    throw "No se pudo abrir el archivo";
  }
  int npos = index.pos;
  if (file.is_open()) {
    file.seekg(npos, ios::beg);
    result.amount.resize(index.size_amount);
    result.sender.resize(index.size_sender);
    result.reciever.resize(index.size_reciever);
    result.timestamp.resize(index.size_timestamp);
    file.read(&result.amount[0], index.size_amount);
    file.read(&result.sender[0], index.size_sender);
    file.read(&result.reciever[0], index.size_reciever);
    file.read(&result.timestamp[0], index.size_timestamp);
    file.close();
  } else {
    throw "No se pudo abrir el archivo";
  }
  return result;
}
#endif
