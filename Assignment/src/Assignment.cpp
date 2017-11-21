#include "modelo/modelo.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char * argv[]) {

	// arquivo de entrada
	char *input = "monitoria.input";

	// vetor de custos
	std::vector<std::vector<int> > custos; //matriz?

	// parametro m e t
	int m, t;

	ifstream infile; //como funciona?
	infile.open(input, ios::in);

	infile >> m;
	infile >> t;

	custos.resize(m);

	for(int i=0; i < m; ++i){
		for(int j=0; j < t; ++j){
			int aux;
			infile >> aux;
			custos[i].push_back(aux);
		}
	}


	// cria objeto que ira resolver a instancia
	CG *cg = new CG(t, m, custos);
	// seta parametros
	cg->set_parameters(); //??
	// executa
	cg->solve();
	// obtem o valor objetivo
	cout << "valor otimo: " << cg->objective_value() << endl;
	cout<< "Todos os custos: "<<endl;
	for (int i=0;i<m;i++){
		for(int j=0;j<t;j++){
			cout<<custos[i][j]<<endl;

		}
	}

	delete cg;

	return 0;
}
