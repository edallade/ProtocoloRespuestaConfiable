#include "SocketDatagrama.h"
#include "mensaje.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class Solicitud
{
private:
    SocketDatagrama * socketLocal,*socketDestino;
    int  checksum;

public:
    Solicitud();
    int  doOperation(char * ip,int puerto,int operId,char * arguments,int suma);
   

};


