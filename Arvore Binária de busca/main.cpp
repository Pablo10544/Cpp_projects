#include <iostream>
#include "ArvBin.h"
int main()
{  
    ArvBin *a = new ArvBin();
    a->montaArvore();
    cout<<endl<<"preordem:";
    a->preOrdem();
    cout<<"fila:";
     a->PercursoComFila();
}