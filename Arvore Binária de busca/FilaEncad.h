#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED
#include "No.h"
#include "NoArv.h"

using namespace std;

class FilaEncad
{
private:
    No *inicio;
    No *fim;      /// ponteiros para os No's extremos
public:
    FilaEncad();
    ~FilaEncad();
    NoArv* getInicio();           /// retorna valor do primeiro No
    void enfileira(NoArv* val);   /// insere No no fim
    int desenfileira();        /// elimina No do inicio
    bool vazia();              /// verifica se fila esta vazia
};

#endif // FILAENCAD_H_INCLUDED
