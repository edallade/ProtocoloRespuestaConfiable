#include <stdlib.h>
#include <iostream>
#include "Solicitud.h"

using namespace  std;

int main (int argc, char*argv[]){
    cout<<"Modo de uso: ./cliente NumDepositos ip\n";
    int cantidad;
    int puerto = 7500;
    long int NumDepositos;
    NumDepositos= atoi(argv[1]);
    int c =0, cuenta_serv;
    Solicitud cliente;
    for(int i = 0;i<NumDepositos;i++){     
    cantidad= rand()%10+1;
    c = c +cantidad;
    cuenta_serv =  cliente.doOperation(argv[2],puerto,1,(char *)&cantidad, cantidad);
        if(c != cuenta_serv){
            cout << "cuenta local "<<c <<" cuenta en el servidor "<<endl;
            exit(0);
        }
        if(cuenta_serv==-1){
            cout<<"no se envio el deposito al servidor"<<cuenta_serv<<endl;
            exit(0);
        }
    }
    cout<<"Cuenta local final del cliente "<<c<<endl;

}

