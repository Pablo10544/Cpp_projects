#include <iostream>
#include <cstdlib>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    cout << "Criando FilaEncad" << endl;
    inicio = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    cout << "Destruindo FilaEncad" << endl;
    No* p = inicio;
    while(inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
    fim = NULL;
}

bool FilaEncad::vazia()
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

void FilaEncad::enfileira(NoArv* val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

NoArv* FilaEncad::getInicio()
{
    if(inicio != NULL)
         return inicio->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

int FilaEncad::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        cout<<p->getInfo()->getInfo();
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        delete p;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
       
    }
}
