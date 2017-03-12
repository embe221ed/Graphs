#include <iostream>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(){}
/******************************************************************/
void AdjacencyList::initList(){
	int number;

	std::cout << "Podaj liczbę wierchołków: ";
	std::cin >> number;
	for( int vert = 1; vert <= number; ++vert ){
		_vertTable.push_back( std::vector< int >() );
		_vertTable[ vert - 1 ].push_back( vert );
		std::cout << "Stworzyłem kolejną listę dla wierzchołka: " << _vertTable[ vert - 1 ][0] << std::endl;
	}
	getList();
}
/******************************************************************/
void AdjacencyList::getGraph( int counter ){
	int temp;
	std::cin.clear();
	std::cin.ignore();

	std::cout << "Wpisz sąsiadów wierzchołka: " << _vertTable[ counter ][0] << std::endl;

	std::cout << "Wypisz jego sąsiadów: ";
	while( std::cin >> temp ){
		if( temp != _vertTable[ counter ][0] && temp <= ( int )_vertTable.size() && temp > 0 )
			_vertTable[ counter ].push_back( temp );
	}
	
	if( _vertTable[ counter ].size() > 1 ){	
		std::cout << "Dodano następujących sąsiadów do wierzchołka nr " << _vertTable[ counter ][0] << ": " << std::endl;
		for( int i = 1; i < ( int )_vertTable[ counter ].size(); ++i ){
			std::cout << _vertTable[ counter ][i] << "  " << std::endl;
		}
	}
	else
		std::cout << "Nie dodano żadnych sąsiadów do wierzchołka nr " << _vertTable[ counter ][0] << std::endl;
}
/*******************************************************************/
void AdjacencyList::getList(){

	for( int i = 0; i < ( int )_vertTable.size(); ++i ){
		getGraph(i);
	}
	int temp;
	for( int j = 0; j < ( int )_vertTable.size(); ++j ){
		temp = ( int )_vertTable[j].size();
		for( int k = 1; k < temp; ++k ){
			/*UWAGA isThisVal pobiera wartość czyli np.
			2 jako sąsiada, a wartość
			!= indeks w tablicy*/
			if( isThisVal( _vertTable[j][k], _vertTable[j][0] ) )
				_vertTable[ _vertTable[j][k] - 1 ].push_back( j + 1 );
		}
	}
}
/******************************************************************/
void AdjacencyList::showList(){
	for( int i = 0; i < ( int )_vertTable.size(); ++i ){
		std::cout << "Wierzchołek nr: " << _vertTable[i][0] << std::endl;
		std::cout << "Sąsiedzi: ";
		for( int j = 1; j < ( int )_vertTable[i].size(); ++j ){
			std::cout << _vertTable[i][j];
			std::cout << std::endl;
		}
	}
}
/******************************************************************/
std::vector< std::vector< int > > AdjacencyList::retAdjacencyList(){
	if( _vertTable.size() )
		return _vertTable;
	else
		std::cout << "Aby zwrócić listę należy najpierw ją utworzyć" << std::endl;
	return _vertTable;
}	
/******************************************************************/
bool AdjacencyList::isThisVal( int vert, int val ){
	for( int i = 0; i < ( int )_vertTable[ vert - 1 ].size(); ++i ){
		if( _vertTable[ vert - 1 ][i] == val )
			return 0;
	}
	return 1;
}
/******************************************************************/
