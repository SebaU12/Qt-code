#include <iostream>
#include "list.h"

template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int nodes;
    public:
        DoubleList() : List<T>() {
          head = nullptr;
          tail = nullptr;
        }

        ~DoubleList(){
            for (auto it = head; it->next != nullptr; it = it->next){
                delete it;
            }
            delete head;
            delete tail;
        }
        typedef ListIterator<T> Iterator;

        Iterator begin(){
        return Iterator(this, this->head);
        }
    
        Iterator end(){
            return Iterator(this, nullptr);
        }

        T front(){
            return head->data;
            //throw ("sin definir");
        }

        T back(){
            if(tail != nullptr) return tail->data;
            return nullptr;
            //throw ("sin definir");
        }

        bool is_empty(){
          if(head == nullptr && tail == nullptr)
            return true;
          else
            return false;
            //throw ("sin definir");
        }

        void push_front(T data){
            auto nuevo = new Node<T>(data);
            if(is_empty()){
                head = nuevo;
                tail = nuevo;
            }
            else {
                nuevo->next = head;
                head->prev = nuevo;
                head = nuevo;
                //throw ("sin definir");
            }
        }

        void push_back(T data){
            auto nuevo = new Node<T>(data);
            if(is_empty()){
                head = nuevo;
                tail = nuevo;
            }
            else{
                nuevo->next = nullptr;
                nuevo->prev = tail;
                tail->next = nuevo;
                tail = nuevo;
            }
            //throw ("sin definir");
        }

        T pop_front(){
            if(is_empty()){
                return head->data;
            }
            else{
                T val = head->data;
                head = head->next;
                delete head->prev;
                head -> prev = nullptr;
                return val;
            }
            //throw ("sin definir");
        }

        T pop_back(){
            if(is_empty()){
                return head->data;
            }
            else {
                T val = tail->data;
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
                return val;
            }
            //throw ("sin definir");
        }

        T insert(T data, int pos){
            auto nuevo = new Node<T>(data);
            int size = this->size();
            if(is_empty()){
                head = nuevo;
                tail = nuevo;
            }
            else if(pos == 0){
                nuevo->next = head;
                head->prev = nuevo;
                head = nuevo;
            }
            else if(pos == size){
                nuevo->next = nullptr;
                nuevo->prev = tail;
                tail->next = nuevo;
                tail = nuevo;
            }
            else if(pos>0 && pos<size){
                auto temp = head;
                for(int i = 0; i < pos - 1; i++)
                    temp = temp->next;
                nuevo->next = temp->next;
                nuevo->prev = temp;
                temp->next->prev = nuevo;
                temp->next = nuevo;
            }
            //else
                //throw exception ("posicion no valida");
            return nuevo->data;
        }

        void remove(int pos){
            int size = this->size();
            if(is_empty()){
                return;
            }
            else if(pos == 0){
                head = head -> next;
                delete head->prev;
                head -> prev = nullptr;
            }
            else if(pos == size){
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
            else if(pos>0 && pos<size){
                auto temp = head;
                for (int i = 0; i < pos; ++i){
                    temp = temp->next;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
            //else
                //throw exception ("posicion no valida");
        }

        T& operator[](int pos){
            auto temp = head;
            int size = this->size();
            if(is_empty()){
                return head->data;
            }
            else if(pos == 0){
                return head->data;
            }
            else if(pos == size){
                return tail->data;
            }
            else if(pos>0 && pos<size){
                for (int i = 0; i < pos; ++i) {
                    temp = temp->next;
                }
                return temp->data;
            }
            //else
                //throw exception ("posicion no valida");
        }

        int size(){
            int cont = 0;
            for (auto it = head; it != nullptr; it = it->next){
                cont++;
            }
            return cont;
            //throw ("sin definir");
        }

        void clear(){
            if(is_empty()){
                return;
            }
            else{
              Node<T>* curr = head;
              
              Node<T>* poorGuy = curr;
              
              while (curr != nullptr) {
              
                  curr = curr->next;
              
                  delete poorGuy;
              
                  poorGuy = curr;
              
              }
            }
            
            head = tail = nullptr;
            //throw ("sin definir");
        }
/*
        void sort(){
            if (is_empty() || size()==1){
                return;
            }
            else{
                // Get first node
            		Node<T>* front = head;
            		Node<T>* back = nullptr;
            		while (front != nullptr)
            		{
            			// Get next node
            			back = front->next;
            			// Update node value when consecutive nodes are not sort
            			while (back != nullptr && back->prev != nullptr && back->data < back->prev->data){
            				// Modified node data
            				//this->swapData(back, back->prev);
                    T value = back->data;
                		back->data = back->prev->data;
                		back->prev->data = value;
            				// Visit to previous node
            				back = back->prev;
            			}
            			// Visit to next node
            			front = front->next;
            		}
            }
            //throw ("sin definir");
        }

        bool is_sorted(){
            int cont = 0;
            for (auto it = head; it->next != nullptr; it = it->next){
                if(it < it->next)
                    cont++;
            }
            return cont == size()-1;
            //throw ("sin definir");
        }
*/
        void reverse(){
            auto it = head;
            Node<T>* temp = nullptr;

            while (it != nullptr) {
                temp = it->prev;
                it->prev = it->next;
                it->next = temp;
                it = it->prev;
            }
            if(temp != nullptr)
                head = temp->prev;
            //throw ("sin definir");
        }

        string name(){
            return "DoubleList";
        }/*
        void display(){
          for (auto it = head; it != nullptr; it = it->next){
                cout << it->data << " ";
            }
          cout << endl;
        }*/

};
