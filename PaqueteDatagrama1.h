class PaqueteDatagrama1
{
private:
    char *datos;
    char ip[16];
    unsigned int longitud;
    int puerto;
public:
    PaqueteDatagrama1(char *,unsigned int , char*,int);
    PaqueteDatagrama1(unsigned int );
    ~PaqueteDatagrama1();
    char *getAddress();
    unsigned int getLen();
    int getPort();
    char *getData();
    void setPort(int );
    void setIp(char *);
    void setData(char *);

    
};

