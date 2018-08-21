#include <iostream>
#include <string>


using namespace std;

class Pagamento
{
	private:
		double valorPagamento;
		string nomeDoFuncionario;
	public:
		Pagamento();
		~Pagamento();
		void setValorPagamento(double);
		void setNomeDoFuncionario(string);
		double getValorPagamento();
		string getNomeDoFuncionario();

};
class ControleDePagamentos
{
private: 
	Pagamento pagamentos[99];
	int index;
public:
	ControleDePagamentos();
	~ControleDePagamentos();
	void setPagamentos(string, double);
	double calculaTotalDePagamentos(); //total dos pagamentos do sistema
	bool existePagamentoParaFuncionario(string);
};

Pagamento::Pagamento(){}
Pagamento::~Pagamento(){}

void Pagamento::setValorPagamento(double valorPagamento)
{
	this->valorPagamento = valorPagamento;
}

void Pagamento::setNomeDoFuncionario(string nomeDoFuncionario)
{
	this->nomeDoFuncionario = nomeDoFuncionario;
}

double Pagamento::getValorPagamento()
{
	return valorPagamento;
}

string Pagamento::getNomeDoFuncionario()
{
	return nomeDoFuncionario;
}

ControleDePagamentos::ControleDePagamentos()
{
	index = 0;
	for (int a = 0; a < 99; a++)
	{
		pagamentos[a].setValorPagamento(0);
		pagamentos[a].setNomeDoFuncionario("");
	}
}
ControleDePagamentos::~ControleDePagamentos(){}

void ControleDePagamentos::setPagamentos(string nomeDoFuncionario, double valorPagamento)
{
	if(index != 99){
		pagamentos[index].setNomeDoFuncionario(nomeDoFuncionario);
		pagamentos[index].setValorPagamento(valorPagamento);
		index++;
	}else
	{
		cout << "Não é possível cadastrar mais pagamentos." << endl;
	}
}

double ControleDePagamentos::calculaTotalDePagamentos()
{
	double soma=0;

	for (int i = 0; i < 99; ++i)
	{
		soma += pagamentos[i].getValorPagamento();
	}
	return soma;
}

bool ControleDePagamentos::existePagamentoParaFuncionario(string nomeDoFuncionario)
{
	for (int i = 0; i < 99; ++i)
	{
		if(!pagamentos[i].getNomeDoFuncionario().compare(nomeDoFuncionario))
			return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	
 	ControleDePagamentos c;

 	c.setPagamentos("Cloud", 200);
 	c.setPagamentos("Jozy", 450);

 	cout << "Total de pagamentos = " << c.calculaTotalDePagamentos() << endl;
 	cout << "Verificando se existe uma Jozy no cadastro" << endl;
 	if(c.existePagamentoParaFuncionario("Jozy"))
 		cout << "Existe sim!!!" << endl;

	return 0;
}