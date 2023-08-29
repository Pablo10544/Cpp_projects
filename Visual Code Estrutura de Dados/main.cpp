#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"
using namespace std;

void ChangeValue(int *i){
    *i =10;

}
int main()
{   int j =0;
    int *i = &j;
    *i=0;
    cout<< *i<<endl;
    cout<<* i<<endl;

    ChangeValue(i);
    cout<<*i<<endl;
        cout<<j<<endl;
}
