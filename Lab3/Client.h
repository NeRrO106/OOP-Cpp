#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
class Client {
    char *nume;
    char CNP[14];
    double sold;
public:
    Client();
    Client(char*, char[], double);
    Client(const Client&);

    ~Client();

    void afisare() const;
    void modificare(const Client &);
    char* getCNP() const;
    double getSold() const;
    char* getName()const;
};


#endif // CLIENT_H_INCLUDED
