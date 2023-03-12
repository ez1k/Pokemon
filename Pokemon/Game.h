#pragma once
#include <vector>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "Pokemon.h"
#include "Skill.h"
using namespace std;

class Game
{

public:
	Game();
	virtual ~Game();





	

	//Functions 
	void mainMenu();
	/*
	Metoda mainMenu wywo³uje menu do wywo³ania innych metod*/

	void Play();
	/*
	metoda Play otwiera menu gdzie mo¿emy wywo³aæ inne metody w tej metodzie tak¿e zaczyna
	siê pêtla gry, która zostaje przerwana przez u¿ytkowanika albo w momencie, gdy 
	gracz pokona 4 przeciwników*/
	void PokemonMenu();
	/*
	Metoda PokemonMenu pozwala u¿ytkownikowi wybraæ 6 pokemonów z tablicy AllPokemons do 
	PlayersPokemons*/
	void Fight();
	/*
	* Metoda fight rozpoczyna pêtla walki z tablica pokemonów przeciwnika wylosowanych 
	* metoda generate z walki mo¿na siê wycofaæ, wtedy ponownie losowane s¹ pokemony przeciwnika
	* w ka¿dym ruchu pêtli sprawdzane s¹ pokemony gracza oraz przeciwnika
	* , nastepnie jest wywo³ywana metoda battle w której jest pojedynek
	* obu pokemonów po skoñczonej bitwie sprawdzane s¹ tablice pokemonów czy 
	* jeszcze jest jakiœ ¿ywy pokemon, jeœli nie walka siê koñczy i wraca do menu
	* 
	*/
	void Load();
	/*
	* Metoda load wczytuje dane z pliku i na ich podstawie tworzy 
	* pokemony oraz skille ³¹czy je ze sob¹ i wczytuje je do 
	* tablicy gracza, pozosta³e dane inicjalizuj¹ wszystkie podstawowe
	* parametry gry czyli poziom trudnoœci
	*/
	void save();
	/*
	Metoda save zapisuje statystki pokemonów oraz ich skilli oraz 
	poziom trudnoœci
	*/
	void Battle();
	/*
	* Wyœwietla menu do pojedynku w pêtli dopóki jeden z pokemonów
	* nie bedzie mia³ hp poni¿ej 0, w case mo¿na wywo³aæ metody
	* do ataku oraz w jednym case wymieniony jest numer wyboru pokemona
	* przez co pokemon zmienia siê w bitwie
	*/
	void PlayerPokemon(int &Pokemonchoosen);
	/*
	metoda PlayerPokemon sprawdza w pêtli czy wybrany pokemon jest
	¿ywy, jeœli nie to u¿ytkownik musi wprowadziæ wartoœc int do zmiany
	*/
	void EnemyPokemon(int &random);
	/*
	metoda EnemyPokemon sprwadza w pêtli czy pokemon przeciwnika ¿yje
	jesli nie losuje innego ¿ywego pokemona*/
	void Choose(float &level);
	/*
	Metoda Choose wyœwietla menu do wyboru poziomu trundoœci 
	gdzie wybierany jest mno¿nik do zwiêkszenia statystyk przeciwnika*/
	vector<Pokemon> Generate(vector <Pokemon> &pokemons);
	/*
	* Wype³nia tablice pokemonów przeciwnika losowywmi pokemonami z
	* AllPokemons
	*/
	bool Check(vector<Pokemon> v1);
	/*
	Metoda Check Sprawdza tablice pokemonów wprowadzony w metodzie, jeœli wszystkie 
	pokemony s¹ martwe zwraca false, jeœli chodŸ jeden jest ¿ywy
	zwraca true*/
	bool CheckPokemon(Pokemon& p);
	/*
	Sprawdza wprowadzonego pokemona, jeœli jego hp jest poni¿ej lub równe 0
	to wtedy zwraca false i ustawia bool pokemon alive na false*/
	
	//Accessors
	inline bool getPlaying()const { return this->playing; }
	inline int getChoice() { return this->choice; };
	


private:
	int choice;
	bool playing;
	string fileName = "PokemonSave.txt";
	fstream file;
	vector <Skill>skills;
	vector <Pokemon> AllPokemons;
	vector <Pokemon> PlayersPokemons;
	vector <Pokemon> Enemy1;
	bool fight = false;
	bool battle = true;
	int Round = 0;
	int Enemies = 0;
	int Pokemonchoosen=0;
	int random = 0;
	float level = 1;
	int enemyCh = 0;
	bool PlayMenu = false;
};

