#include "modelo.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;



FUNÇÃO OBJETIVO
///////////////////////////////////////////
 	for (int p=0; p<professor;p++){
		for(int r=0;r<room<r++){
		obj += y[p][r];
		}
	}
	model.add(IloMinimize(env,obj));


RESTRIÇÃO (14)
/////////////////////////////////////////////////////
// precisa do for ???
	for (int c=0; c< classes; c++){
		for (int d=0; d<dias;d++){
			for(int s=0; s<slots; s++){
				for (int r=0; r< room; r++){
				x[c][d][s][r] <= y[c][r];
		}
	}
]



