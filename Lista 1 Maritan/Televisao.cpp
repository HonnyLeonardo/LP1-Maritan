#include <iostream>

using namespace std;

class Televisao
{
private:
    int volume;
    int canal;
public:
    Televisao();
    virtual ~Televisao();
    void setCanal(int);
    int getCanal();
    int getVolume();
    void aumentarVolume();
    void abaixarVolume();
    void avancarCanal();
    void diminuirCanal();
};

Televisao::Televisao()
{
    canal = 1;
    volume = 10;       
}

Televisao::~Televisao(){}

void Televisao::setCanal(int canal)
{
    if(canal > 0 || canal < 60)         //60 eh o numero de canais existentes
    {
        this->canal = canal;
    }  
}

void Televisao::aumentarVolume()
{    
    if(volume == 59)
        volume = 59;
    
    else
    {
        volume++;
    }  
}

void Televisao::abaixarVolume()
{    
    if(volume == 0)
        volume = 0;
    
    else
    {
        volume--;
    }   
}

void Televisao::avancarCanal()
{
    if(canal == 60)
        canal = 1;
    else
        canal++;
}

void Televisao::diminuirCanal()
{
    if(canal == 1)
        canal = 60;
    else
        canal--;
}

int Televisao::getVolume()
{
    return volume;
}

int Televisao::getCanal()
{
    return canal;
}


int main(int argc, char const *argv[])
{                                                     
    Televisao t1 = Televisao();
    Televisao t2 = Televisao();

    cout << "Canal atual do t1: " << t1.getCanal() << endl;
    cout << "Volume atual do t1: " << t1.getVolume() << endl;

    t1.aumentarVolume();
    t1.avancarCanal();

    cout << "Canal atual do t1: " << t1.getCanal() << endl;
    cout << "Volume atual do t1: " << t1.getVolume() << endl;

    t1.setCanal(1);
    t1.abaixarVolume();

    cout << "Canal atual do t1: " << t1.getCanal() << endl;
    cout << "Volume atual do t1: " << t1.getVolume() << endl;

    t1.diminuirCanal();
    t1.abaixarVolume();

    cout << "Canal atual do t1: " << t1.getCanal() << endl;
    cout << "Volume atual do t1: " << t1.getVolume() << endl;

    t2.setCanal(60);
    cout << "Canal atual do t2: " << t2.getCanal() << endl;
    cout << "Volume atual do t2: " << t2.getVolume() << endl;

    t2.avancarCanal();
    t2.aumentarVolume();

    cout << "Canal atual do t2: " << t2.getCanal() << endl;
    cout << "Volume atual do t2: " << t2.getVolume() << endl;

    return 0;
}