#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
    private:
		string nome;
		int idade;
		string telefone;
    public:
	    Pessoa(string); //contrutor que recebe so o nome
	    Pessoa(string, int, string); //contrutor que recebe o nome, idade e telefone
	    ~Pessoa();
		void setNome(string);
		void setIdade(int);
		void setTelefone(string);
		string getNome();
		int getIdade();
		string getTelefone();
};							

class CadastroDePessoas
{
public:
	CadastroDePessoas();
	~CadastroDePessoas();
	
};

Pessoa::Pessoa(string nome)
{
	this->nome = nome;
	idade = 0;
	telefone = "";
}

Pessoa::Pessoa(string nome, int idade, string telefone)
{
	this->nome = nome;
	this->idade = idade;
	this->telefone = telefone;
}

void Pessoa::setNome(string nome)
{
	this->nome = nome;
}

void Pessoa::setIdade(int idade)
{
	this->idade = idade;
}

void Pessoa::setTelefone(string telefone)
{
	this->telefone = telefone;
}

string Pessoa::getNome()
{
	return nome;
}
 int Pessoa::getIdade()
 {
 	return idade;
 }

string Pessoa::getTelefone()
{
	return telefone;
}

int main(int argc, char const *argv[])
{
	Pessoa *p1 = new Pessoa("Cloud");
	Pessoa *p2 = new Pessoa("Jozy", 25, "22 22222 2222");

	cout << "Nome p1: " << p1->getNome() << endl;
	cout << "Idade p1: " << p1->getIdade() << endl;
	cout << "Telefone p1: " << p1->getTelefone() << endl;

	p1->setNome("Cloud Souza");
	p1->setIdade(32);
	p1->setTelefone("11 11111 1111");

	cout << "Nome p1: " << p1->getNome() << endl;
	cout << "Idade p1: " << p1->getIdade() << endl;
	cout << "Telefone p1: " << p1->getTelefone() << endl;

	cout << "Nome p2: " << p2->getNome() << endl;
	cout << "Idade p2: " << p2->getIdade() << endl;
	cout << "Telefone p2: " << p2->getTelefone() << endl;

	return 0;
}