#include <iostream>
#include "Client.h"
#include <cstring>

using namespace std;

Client::Client(){
    nume = NULL;
    strcpy(CNP,"000...0");
    sold = 0;
}

Client::Client(char* nume2, char CNP2[], double sold2){
    if(nume2 != NULL){
        nume  = new char[strlen(nume2)+1];
        strcpy(nume,nume2);
    }
    strcpy(CNP,CNP2);

    sold = sold2;
}

Client::Client(const Client& client){
    if(nume != NULL) delete[]nume;
    nume = new char[strlen(client.nume)+1];
    strcpy(nume, client.nume);

    for(int i=0;i<14;i++) CNP[i] = client.CNP[i];

    sold = client.sold;
}


void Client::afisare()const{
    if(nume !=NULL){
        cout<<nume<<" ";

        for(int i=0;i<14;i++) cout<<CNP[i];
        cout<<" ";
        cout<<sold;
    }
}
void Client::modificare(const Client& clientmodif){
    if(nume != NULL) delete[]nume;
    nume = new char[strlen(clientmodif.nume)+1];
    strcpy(nume, clientmodif.nume);

    for(int i=0;i<14;i++) CNP[i] = clientmodif.CNP[i];

    sold = clientmodif.sold;
}

char* Client::getCNP() const{
    return (char*)CNP;
}

double Client::getSold() const{
    return sold;
}

char* Client::getName()const{
    return nume;
}

Client::~Client(){
    if(nume !=NULL) delete[]nume;
}

