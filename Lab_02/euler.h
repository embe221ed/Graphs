#pragma once

#include <iostream>
#include <vector>
#include "IncidenceMatrix.h"
#include "connected_components.h"
#include "randomization.h"


IncidenceMatrix* createEulerGraph() {
	srand(static_cast<unsigned int>(time(NULL)));
	int a, b;
	bool status = true;
	std::vector<int> sequence;
	IncidenceMatrix* seq;
	IncidenceMatrix* rewrited;
	std::vector<int> largestComp;



	do {
		b = randomint(10, 12);


		while (sequence.size()) sequence.erase(sequence.begin());
		for (int i = 0; i < b; i++) {
			a = randomint(1, 4);
			a = a * 2;
			sequence.push_back(a);
		}
		

		if (checkIfSequenceIsGraphic(sequence)) {
			seq = new IncidenceMatrix(sequence);
			largestComp = findTheLargestConnectedComponent(IncidenceMatrix(sequence));
			for (int i = 0; i < static_cast<int>(largestComp.size()); i++)
				std::cout << largestComp[i] << ", ";
			std::cout << std::endl;

			rewrited = new IncidenceMatrix(b, largestComp.size());
			int x, y;
			for (unsigned int i = 0; i < largestComp.size(); i++) {
				seq->getTopsOfEdge(largestComp[i], x, y);
				rewrited->setTopsOfEdge(i, x, y);
			}
			delete seq;
			for (int j = 0; j < rewrited->getTop(); j++) {
				std::vector<int> temp = rewrited->adjForTop(j);
				if (temp.size()%2==1) {
					status = true;
					delete rewrited;
					break;
				}
				else status = false;
			}
			
		}
		else status = true;

	} while (status);
	
	rewrited->printEntireMatrix();

	std::vector<int> toDelete;
	for (int i = 0; i < rewrited->getTop(); i++) {
		std::vector<int> temp = rewrited->adjForTop(i);
		if (temp.size() == 0) {
			toDelete.push_back(i);
		}
	}
	//std::cout <<"size "<< toDelete.size() << std::endl;
	for (int i = toDelete.size() - 1; i >= 0; i--) {
		//std::cout << "usuwam numer " << toDelete[i] << std::endl;
		rewrited->deleteTop(toDelete[i]);
	}

	rewrited->printEntireMatrix();
	return rewrited;
}


/*
0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0
0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1
0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0
0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0
1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0
1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1
0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0
*/


/*
0  0  0  0  1  0  1  0  0  0  0
0  1  0  0  0  0  0  1  0  0  0
0  0  0  0  0  0  0  0  0  1  1
1  1  0  1  0  0  1  0  1  0  1
0  0  0  1  0  1  0  0  0  0  0
1  0  1  0  1  1  0  1  0  1  0
0  0  1  0  0  0  0  0  1  0  0
*/


/*
0  0  1  0  0  1  0  0  0  0  0
0  0  0  0  0  0  1  0  0  1  0
0  0  0  1  0  0  0  1  0  0  0
0  1  0  0  1  0  0  0  0  0  0
1  1  0  0  0  1  0  1  1  1  0
1  0  1  1  1  0  1  0  0  0  1
0  0  0  0  0  0  0  0  1  0  1
*/