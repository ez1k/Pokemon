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
	Metoda mainMenu wywo�uje menu do wywo�ania innych metod*/

	void Play();
	/*
	metoda Play otwiera menu gdzie mo�emy wywo�a� inne metody w tej metodzie tak�e zaczyna
	si� p�tla gry, kt�ra zostaje przerwana przez u�ytkowanika albo w momencie, gdy 
	gracz pokona 4 przeciwnik�w*/
	void PokemonMenu();
	/*
	Metoda PokemonMenu pozwala u�ytkownikowi wybra� 6 pokemon�w z tablicy AllPokemons do 
	PlayersPokemons*/
	void Fight();
	/*
	* Metoda fight rozpoczyna p�tla walki z tablica pokemon�w przeciwnika wylosowanych 
	* metoda generate z walki mo�na si� wycofa�, wtedy ponownie losowane s� pokemony przeciwnika
	* w ka�dym ruchu p�tli sprawdzane s� pokemony gracza oraz przeciwnika
	* , nastepnie jest wywo�ywana metoda battle w kt�rej jest pojedynek
	* obu pokemon�w po sko�czonej bitwie sprawdzane s� tablice pokemon�w czy 
	* jeszcze jest jaki� �ywy pokemon, je�li nie walka si� ko�czy i wraca do menu
	* 
	*/
	void Load();
	/*
	* Metoda load wczytuje dane z pliku i na ich podstawie tworzy 
	* pokemony oraz skille ��czy je ze sob� i wczytuje je do 
	* tablicy gracza, pozosta�e dane inicjalizuj� wszystkie podstawowe
	* parametry gry czyli poziom trudno�ci
	*/
	void save();
	/*
	Metoda save zapisuje statystki pokemon�w oraz ich skilli oraz 
	poziom trudno�ci
	*/
	void Battle();
	/*
	* Wy�wietla menu do pojedynku w p�tli dop�ki jeden z pokemon�w
	* nie bedzie mia� hp poni�ej 0, w case mo�na wywo�a� metody
	* do ataku oraz w jednym case wymieniony jest numer wyboru pokemona
	* przez co pokemon zmienia si� w bitwie
	*/
	void PlayerPokemon(int &Pokemonchoosen);
	/*
	metoda PlayerPokemon sprawdza w p�tli czy wybrany pokemon jest
	�ywy, je�li nie to u�ytkownik musi wprowadzi� warto�c int do zmiany
	*/
	void EnemyPokemon(int &random);
	/*
	metoda EnemyPokemon sprwadza w p�tli czy pokemon przeciwnika �yje
	jesli nie losuje innego �ywego pokemona*/
	void Choose(float &level);
	/*
	Metoda Choose wy�wietla menu do wyboru poziomu trundo�ci 
	gdzie wybierany jest mno�nik do zwi�kszenia statystyk przeciwnika*/
	vector<Pokemon> Generate(vector <Pokemon> &pokemons);
	/*
	* Wype�nia tablice pokemon�w przeciwnika losowywmi pokemonami z
	* AllPokemons
	*/
	bool Check(vector<Pokemon> v1);
	/*
	Metoda Check Sprawdza tablice pokemon�w wprowadzony w metodzie, je�li wszystkie 
	pokemony s� martwe zwraca false, je�li chod� jeden jest �ywy
	zwraca true*/
	bool CheckPokemon(Pokemon& p);
	/*
	Sprawdza wprowadzonego pokemona, je�li jego hp jest poni�ej lub r�wne 0
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

