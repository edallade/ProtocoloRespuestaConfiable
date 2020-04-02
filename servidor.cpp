#include "Respuesta.h"

int main(){
    Respuesta servidor(7500);
    struct mensaje * replay;
   while (1)
   {    
     replay =  servidor.getRequest();
     servidor.sendReply(replay);
   }
  
    
} 