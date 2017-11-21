#ifndef CG_H
#define CG_H

#include <ilcplex/ilocplex.h>

#include <vector>

struct CG {

	// ambiente - gerencia memoria e identificadores para os objetos
	IloEnv env;

	// modelo - representa o modelo a ser otimizado
	IloModel model;

	// representa o CPLEX. motor que faz tudo acontecer
	IloCplex * cplex;

	// funcao objetivo
	IloExpr obj;

	// variavel maquina x tarefas
	IloArray<IloBoolVarArray> x; // como funciona???

	// restricoes
	IloRangeArray constraints_1;
	IloRangeArray constraints_2;

	// numero de maquinas
	int m;
	// numero de tarefas
	int t;

	// matriz de custos maquina x tarefa
	std::vector<std::vector<int> > c;  //matriz de vetors de inteiros?

	// matriz de solucao maquina x tarefa
	std::vector< std::vector<int> > solucao; //matriz de vetors de inteiros?

	// construtores
	CG(int num_tarefas, int num_maquinas, std::vector<std::vector<int> > & c); //O que é CG? recebendo os valores de maquinas e tarefas na matriz de custos ????
	virtual ~CG(); //?

	// resolve o problema
	void solve();

	// seta os parametros
	void set_parameters();

	// cria modelo
	void create_model();

	// cria variaveis
	void create_variables();

	// cria funcao objetivo
	void create_objective_function();

	// cria restricoes
	void create_constraints();

	// retorna valor da funcao objetivo
	double objective_value();
};

#endif // CG_H
