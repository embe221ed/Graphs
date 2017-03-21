#include "connectionmatrix.h"
#ifndef IncidenceMatrix_h
#define IncidenceMatrix_h

	//podstawia wpisana wartosc pod int tylko wtedy gdy strumien jest dobry
	//zaleta1: nie stanie si� nic czego sie nie bedziemy spodziewac
	//zaleta2: bez dodatkowych bibliotek (tylko <iostream> potrzebny)
	//jesli wpiszesz tekst ustawi -2137
	//jesli wpiszesz "123xxx..." to ustawi integer z poczatku strumienia
	//zwraca 1 gdy sie udalo, 0 gdy sie nie udalo (ustawiono -2137)
bool cinSelectedInt(int& selectedInt);


//template <typename Type> class ConnectionMatrix;

	//Macierz Indcydencji
class IncidenceMatrix
{
public:
		//tworzy macierz pytajac o ilosc wierzcholkow i krawedzi, wypelnia zerami
	IncidenceMatrix();
		//tworzy macierz o podanym rozmiarze, wypelnia zerami
	IncidenceMatrix(int numberOfTops, int numberOfEdges); 
		//ustawia elementy calej macierzy wpisanymi wartosciami
		//wpisujesz po kolei pola do ca�ej macierzy, wiersz po wierszu
		//zwraca 0 gdy jest poprawnie, 1 gdy jest niepoprawnie wpisana
		//bledy w reprezentacji sa eliminowane; wypisywane jest co zostalo usuniete
	IncidenceMatrix(const ConnectionMatrix<int> &conn);
	bool setEntireMatrixByRows();
		//ustawia elementy calej macierzy wpisanymi wartosciami
		//wpisujesz po kolei pola do ca�ej macierzy, kolumna po kolumnie
		//zwraca 0 gdy jest poprawnie, 1 gdy jest niepoprawnie wpisana
		//bledy w reprezentacji sa eliminowane; wypisywane jest co zostalo usuniete
	bool setEntireMatrixByColumns();
		//ustawia elementy calej macierzy wartosciami wczytanymi z pliku 'Filename'
		//zwraca 0 gdy wczyta poprawnie, 1 gdy wystapil jakis blad i wypisuje komunikat bledu
		//bledy w reprezentacji sa eliminowane; wypisywane jest co zostalo usuniete
	bool setEntireMatrixFromFile(std::string Filename, int numberOfTops, int numberOfEdges);
		//usuwa bledy w reprezentacji macierzy incydencji, takie jak
		//krawedzie z bledna liczba wierzcholkow lub zmultiplikowane krawedzie
		//zwraca 1 gdy wystapily jakiekolwiek bledy (na pewno je naprawiono)
		//zwraca 0 gdy w nie bylo bledow w reprezentacji
		//gdy bledow nie uda sie naprawic (jakims cudem) to wczesniej wysypie sie program
	bool eliminateAllMistakes();
		//usuwa krawedzie ktore sie powtarzaja
		//zwraca 0 gdy nie bylo zmultiplikowanych krawedzi
		//nie wywoluj gdy moga istniec bledne krawedzie, nie usunie wtedy wszystkich
	bool eliminateDuplicates();
		//usuwa krawedzie z bledna liczba wierzcholkow lub liczbami wiekszymi niz 1
		//zwraca 0 gdy nie bylo blednych krawedzi; zwraca 1 gdy usunieto bledne i wypisuje komunikat
	bool eliminateInvalidEdges();
		//inforumuje o istnieniu indeksu krawedzi (gdy istnieje zwraca 1)
	bool edgeIndexExist(int questionedEdge);
		//informuje o mozliwosci istnienia/stworzenia krawedzi (poprawnosc indeksow wierzcholkow)
		//zwraca 0 gdy nie moze istniec taka krawedz
		//zwraca 1 gdy taka krawedz moze istniec
	bool possibleEdge(int firstTop, int secondTop);
		//informuje o mozliwosci dodania krawedzi o zadanych indeksach wierzcholkow
		//zwraca 0 gdy nie ma takiej krawedzi (mozna taka dodac)
		//zwraca 1 gdy taka krawedz istnieje lub podano zle indeksy etc. (NIE mozna takiej dodac)
	bool isThisEdgeFree(int firstTop, int secondTop);
		//wypisuje na ekran cala macierz
	void printEntireMatrix() const;
		//ustala(badz zmienia) wierzcho�ki do kt�rych nale�y zadana kraw�d�
		//gdy ktorekolwiek indeksy sa bledne zwraca 1 i wypisuje komunikat bledu 
		//gdy taka krawedz juz istnieje zwraca 1 i wypisuje komunikat bledu
		//gdy operacja sie udaje zwraca 0
	bool setTopsOfEdge(int selectedEdge, int newOwner1, int newOwner2);
		//funckja zwraca indeksy wybranej krawedzi poprzez zmiane waratosci referowanych integerow
		//gdy indeksy wierzcholkow zostana poprawnie pobrane i wpisane pod referowane zmienne: zwraca 0
		//gdy indeks krawedzi jest bledny zwraca 1, a pod referowane zmienne podstawia -2137
	bool getTopsOfEdge(int selectedEdge, int& storageInt1, int& storageInt2);
	//dodaje nowa krawedz nalezaca do zadanych wierzcholkow (realokacja pamieci)
		//gdy uzyjesz zlych nieporawnych indeksow lub taka krawedz juz istnieje: zwraca 1 i wypisuje blad
		//gdy pomyslnie doda krawedz zwraca 0
	bool addNewEdge(int newOwner1, int newOwner2);
		//gdy krawedz nie istnieje zwraca 1
		//gdy usunie pomyslnie zwraca 0
	bool deleteEdge(int selectedEdge);
		//alokuje pamiec na macierz incydencji o 'top' wierzcholkach i 'edge' krawedziach
		//zwraca wskaznik na stworzona macierz
	static int** IncidenceMatrix::allocateMatrix(int top, int edge);
		//powoduje destrukcje wszechswiata oraz usuniecie macierzy
	~IncidenceMatrix();
		//zwraca liczbe wierzcholkow
	const int getTop() const { return top; }
		//zwraca liczbe krawedzi
	const int getEdge() const { return edge; }
private:
		//wierzcholki
	int top;  
		//krawedzie
	int	edge;	
		//macierz incydencji
	int** matrix;	
};




#endif // IncidenceMatrix_h