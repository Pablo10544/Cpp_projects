#include "NoArv.h"
class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    int MaiorElemento();
    int MenorElemento(){
         return NoMenorElemento(raiz)->getInfo();  
    }
    void RemoveMaior();
    int Altura();
        bool ArvoreBalanceada();

private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
    NoArv* NoMaiorElemento(NoArv *p);
    NoArv* NoMenorElemento(NoArv *p);
    NoArv* MenorSubArvoreEsquerda(NoArv *p);
    int AuxAltura(NoArv * p);
    int percusoPre(NoArv *N);
};
#include <iostream>
#include <cmath>

using namespace std;
int ArvBinBusca::Altura(){
    return AuxAltura(raiz);
}
int ArvBinBusca::percusoPre(NoArv* n){
    if(n!=NULL){
        int a= percusoPre(n->getEsq());
       int b=  percusoPre(n->getDir());
         return 1+a+b;
    }
    return 0;
}
int ArvBinBusca::MaiorElemento()
{
 return NoMaiorElemento(raiz)->getInfo();  
}
bool ArvBinBusca::ArvoreBalanceada(){
    int nos = percusoPre(raiz);
    int alt = Altura();
    cout<<"numero de nos:"<<nos<<"Altura:"<< alt<<endl;
    if(alt<log2(nos) +1){
        cout<<"balanceada";
        return true;
    }else{
        cout<<"não balanceada";
        return false;
    }
}
int ArvBinBusca::AuxAltura(NoArv*p)
{
    if(p!=NULL){
        int he = AuxAltura(p->getEsq());
        int hd = AuxAltura(p->getDir());
        return 1+(he>=hd?he:hd);
    }
    return -1;


}
NoArv* ArvBinBusca::NoMenorElemento(NoArv *p){
    if(p->getEsq()==NULL){

       return p; 
    }
    return NoMenorElemento(p->getEsq());
}
NoArv* ArvBinBusca::NoMaiorElemento(NoArv *p){
    if(p->getDir()==NULL){
        return p;
    }
   return NoMaiorElemento(p->getDir());

}
void ArvBinBusca::RemoveMaior(){
    remove(NoMaiorElemento(raiz)->getInfo());

}
ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{cout<<"removendo:"<<val;
    raiz = auxRemove(raiz, val);
    
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            // NoArv *aux = menorSubArvDireita(p);
            NoArv *aux = MenorSubArvoreEsquerda(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setEsq(auxRemove(p->getEsq(), val));
        }
    }
    return p;
}
NoArv * ArvBinBusca::MenorSubArvoreEsquerda(NoArv *p){

    NoArv *n = p->getEsq();
    while(n->getDir()!=NULL){
        n = n->getDir();
    }
    return n;

}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}
