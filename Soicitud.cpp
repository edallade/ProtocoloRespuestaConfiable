#include "Solicitud.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <cstdlib>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <iostream>
using namespace std;
Solicitud::Solicitud(){
    socketLocal = new SocketDatagrama(0);
    
}


int Solicitud::doOperation(char * ip,int puerto,int operId,char * arg, int suma){
    struct mensaje msj,replay_msj;
    int random;
    int i;  
   int r;
    random = rand()%100+1;//id de operación 
    memcpy(msj.arguments,arg,sizeof(arg));
    msj.operationId=operId;//id = 1 = suma si no , error
    msj.messageType=0;//0= solicitud 1 = respuesta
    msj.requestId=random;//
    PaqueteDatagrama1 pd((char *)&msj,sizeof(msj),ip,puerto);//se llena el datagram package a enviar
    PaqueteDatagrama1 respuesta(sizeof(msj));//como argumento ssolo el tamaño de un mensaje(datagrampackage)
    

    for(i = 0;i<7;i++){//se intentara hasta 7 veces el envio de cada paquerte 
        socketLocal->envia(pd);
        //se espera respuesta del servidor
        if(socketLocal->SetDatagramTimeout(respuesta,2,500000) != -1){
        memcpy(&replay_msj,respuesta.getData(),sizeof (replay_msj));//se guardan datos del mensaje recibdo en una instancia msj local
       memcpy(&r,&replay_msj.arguments,sizeof(r));//se obtiene numero del msj recibido en un a variable local
        
       return r;
             
        }else{
                    cout << "no se envio el paquete en el intento "<<i+1<<endl;
            }
      }
        
        return -1;
    
    }
        
    


