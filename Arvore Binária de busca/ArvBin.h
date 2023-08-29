#include "NoArv.h"
#include <iostream>
using namespace std;

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    void nNos(){ if(raiz==NULL)cout<<0;
    else cout<< AuxNos(raiz);};
    void nFolhas(){
        if(vazia())
        cout<<0;
     cout<<auxNFolhas(raiz);//
    } bool cheia();
    void PercursoComFila();

  private:
    int auxNFolhas(NoArv * n);
    NoArv *raiz; // ponteiro para o No raiz da árvore
    int AuxNos(NoArv *n);
    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    int auxAltura(NoArv *p);
    NoArv* auxInsere(NoArv *p, int x);
   
};
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "FilaEncad.h"
#include "FilaEncad.cpp"
#include "cmath"
using namespace std;
bool ArvBin::cheia(){
    if(AuxNos(raiz)==pow(2,auxAltura(raiz)+1)-1)
    cout<<"cheia";
    return true;
}
int ArvBin::auxAltura(NoArv *p)
{
//he e hd armazenam, respectivamente, as alturas
//das sub-árvores da esquerda e da direita de p
int he, hd;
if (p == NULL)
return -1;
else
{
he = auxAltura(p->getEsq());
hd = auxAltura(p->getDir());
return 1 + (he>=hd?he:hd); //maior de 2 inteiros
}
}
void ArvBin::PercursoComFila(){
    FilaEncad p;
    NoArv *n = raiz;
    p.enfileira(raiz);
    while (!p.vazia())
    {n = p.getInicio();
        if(n->getEsq()!=NULL){
            p.enfileira(n->getEsq());
        }
        if(n->getDir()!=NULL){
             p.enfileira(n->getDir());
        }
        p.desenfileira();
        
    }
    

}
int ArvBin::auxNFolhas(NoArv *n){
    if(n==NULL){
return 0;
    }
    else if(n->getDir()==NULL&& n->getEsq()==NULL){
        return 1;
    }else{
          int i = auxNFolhas(n->getDir());
       int j= auxNFolhas(n->getEsq());
    return i+j;

    }


}
int ArvBin::AuxNos(NoArv *n){
    if(n==NULL){
        return 0;
    }
    if(n->getDir()==NULL &&n->getEsq()==NULL)
    {
        return 1;
    }else{
     int i = AuxNos(n->getDir());
       int j= AuxNos(n->getEsq());
    return 1+i+j;
    }

}
ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

