#include "modelo.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

CG::CG(int num_tarefas, int num_maquinas,
		std::vector<std::vector<int> > & custos) :
		model(env), obj(env)  {   //modelo e funcao objetivo no ambiente que gerencia memoria e identificadores???
	t = num_tarefas;
	m = num_maquinas;
	c = custos; // c é uma matriz de inteiros  e armazena os valores da matriz de custos?
	create_model();
	cplex = new IloCplex(model);  //incia o cplex com o modelo a ser proposto?
}

CG::~CG() {
	try {        //identifica excecoes, nesse caso se x ou o modelo estiver no final??
		x.end();
		model.end();

		delete cplex;
		env.end();

	} catch (IloException& e) {    //cath : manipulador
		std::cerr << "ERROR: " << e.getMessage() << std::endl;
	} catch (...) {
		std::cerr << "Error" << std::endl;
	}
}

void CG::solve() {

	// imprime o modelo
	cplex->exportModel("master_restrito.lp"); //?

	// resolve o modelo
	cplex->solve();

	// TODO: 
	// exercicio: montar solucao encontrada na matriz solucao
}

void CG::create_model() {
	create_variables();
	create_objective_function();
	create_constraints();
}

void CG::create_variables() {

	char buffer[20];

	// instancia dimensao das maquinas
	x = IloArray<IloBoolVarArray>(env, m);  // como funciona?
	for (int i = 0; i < m; ++i) {
		// instancia dimensao das tarefas
		x[i] = IloBoolVarArray(env, t);     // como funciona?
		for (int j = 0; j < t; j++) {
			sprintf(buffer, "x_%d,%d", i, j);  // armazena maquinas e tarefas em buffer???
			// atribui nome a variavel
			x[i][j].setName(buffer);
		}
	}
}
                          // ...
void CG::create_objective_function() {

	// cria funcao objetivo
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < t; j++) {
			obj += c[i][j] * x[i][j];
		}
	}
	// indica que o problema e de minimizacao e passa a funcao objetivo obj
	model.add(IloMinimize(env, obj));
}

void CG::create_constraints() {

	char buffer[20];

	// instancia pool de restricoes com tamanho t
	constraints_1 = IloRangeArray(env, t);
	for (int j = 0; j < t; ++j) {
		IloExpr constraint(env);

		// monta restricao
		for (int i = 0; i < m; i++) {
			constraint += x[i][j];
		}

		// monta restricao + rhs no pool
		constraints_1[j] = constraint == 1;

		// atribui nome a restricao
		sprintf(buffer, "rest_t_%d", j);
		constraints_1[j].setName(buffer);

		// adiciona restricao ao modelo
		model.add(constraints_1[j]);
		constraint.end();

	}
}

double CG::objective_value() {
	return cplex->getValue(obj);
}

void CG::set_parameters() {

	cplex->setParam(IloCplex::PreInd, 0);  //preciso saber?

	cplex->setParam(IloCplex::AggInd, 0);
	cplex->setParam(IloCplex::HeurFreq, -1);

	cplex->setParam(IloCplex::FracCuts, -1);
	cplex->setParam(IloCplex::FlowCovers, -1);
	cplex->setParam(IloCplex::GUBCovers, -1);
	cplex->setParam(IloCplex::Covers, -1);

	cplex->setParam(IloCplex::ImplBd, -1);
	cplex->setParam(IloCplex::Cliques, -1);
	cplex->setParam(IloCplex::DisjCuts, -1);
	cplex->setParam(IloCplex::FlowPaths, -1);
	cplex->setParam(IloCplex::MIRCuts, -1);
	//versao 12
	cplex->setParam(IloCplex::ZeroHalfCuts, -1);
}
