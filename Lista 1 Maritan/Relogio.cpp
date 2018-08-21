#include <iostream>

using namespace std;

class Relogio
{
private:
    int hora;
    int minutos;
    int segundos;
public:
    Relogio();
    Relogio(int, int, int);
    virtual ~Relogio();
    void setHorario(int, int, int);
    int getHora();
    int getMinuto();
    int getSegundo();
    void avancarHorario();
};

Relogio::Relogio()
{
    hora = 0;
    minutos = 0;
    segundos = 0;        
}

Relogio::Relogio(int hora, int minutos, int segundos) : hora(hora),minutos(minutos),segundos(segundos)
{
    if(hora < 0 || hora > 23)
        hora = 0;
    if(minutos < 0 || minutos > 59)
        minutos = 0;
    if(segundos < 0 || segundos > 59)
        segundos = 0;
}

Relogio::~Relogio(){}

void Relogio::setHorario(int hora, int minutos, int segundos)
{
    if(hora < 0 || hora > 23)
    {
        hora = 0;
    }
    else if(minutos < 0 || minutos > 59)
    {
        minutos = 0;
    }
    else if(segundos < 0 || segundos > 59)
    {
        segundos = 0;
    }
    else
    {    
        this->hora = hora;
        this->minutos = minutos;
        this->segundos = segundos;
    }    
}

void Relogio::avancarHorario()
{    
    if(segundos == 59)
    {
        segundos = 0;
        minutos++;
        if(minutos = 60)
        {
            minutos = 0;
            hora++;
            if(hora == 24)
            {
                hora = 0;
            }
        }        
    } 
    else
    {
        segundos++;
    } 
}


int Relogio::getHora()
{
    return hora;
}

int Relogio::getMinuto()
{
    return minutos;
}

int Relogio::getSegundo()
{
    return segundos;
}




int main(int argc, char const *argv[])
{
    Relogio r1 = Relogio(22, 10, 5);
    Relogio r2 = Relogio(23, 59, 59);
    

    cout << "R1 - " << r1.getHora() << ":" << r1.getMinuto() << ":" << r1.getSegundo() << endl;
    
    r1.avancarHorario();
    
    cout << "R1 - " << "segundos++: "<< r1.getSegundo() << endl;

    r1.setHorario(23,59,02);
        
    cout << "R1 - " << r1.getHora() << ":" << r1.getMinuto() << ":" << r1.getSegundo() << endl;


    cout << "R2 - " << r2.getHora() << ":" << r2.getMinuto() << ":" << r2.getSegundo() << endl;

    r2.avancarHorario();  
    
    cout << "R2 - " << r2.getHora() << ":" << r2.getMinuto() << ":" << r2.getSegundo() << endl;                                                      
                               
    return 0;
}