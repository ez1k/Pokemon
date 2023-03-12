#pragma once
#include "Skill.h"
#include <fstream>
using namespace std;

class Pokemon 
{
private:
    /*
    * statystyki i w�a�ciwo�ci pokemona
    */
    int strength;
    int dexterity;
    int hp;
    int maxHP;
    string element;
    string name;
    int Xp;
    int XP_to_next;
    Skill skill;
    bool alive;
    int id;
vector<string> ElementType = {
    "Water",
    "Ground",
    "Wind",
    "Fire",
    "Ice",
    "Steel"
};

public:
    Pokemon();
    virtual ~Pokemon() {};
    Pokemon (const Pokemon& copy);
    Pokemon(
        int id,
        int strength,
        int dexterity,
        int hp,
        int maxHp,
        int XP_to_next,
        string name, 
        string element 
        ,Skill skill,
        bool alive
        );


    void PrintPokemon();

    void Attack(Pokemon& player, Pokemon& Enemy, int type);
    /*
    Metoda Attack s�u�y do ataku pokemona wyznaczonym pokemonem,
    na zasadzie przyj�tego inta type jest wybierany atak na 1 lub super atak na 2
    w przypadku ataku przeciwka jest to bardzo pomocne, bo losowana jest warto�� od 1 do 2
    Atak jest wykonywany wg. logiki ataku, damage zale�y od �ywio�u pokemona
    */
    void Evolute();
    /*
    Metoda Evloute ewoluje pokemona podnosz�c jego statystyki wg. mno�nika
    , kt�ry wynosi 0.1 w przypadku statystyk, w przypadku XP do nastepnej ewolucji jest to 
    1.5 Metoda wy�wietla pokemona przed ewolucja i po 
    */
    int FightLogic(Pokemon& player, Pokemon& Enemy);
    /*
    * metoda FightLogic logika wed�ug kt�rej wykonywany jest atak metoda zwraca damage, kt�ry jest pomniejszony 
    * w zale�no�ci od �ywio�u pokemona atakuj�cego i atakowanego
    */
    void restart();
    /*
    * metoda restart przywraca hp do pierwotnego stanu, czyli np. przed walk�
    */
    void BoostPokemon(float level);
    /*
    Metoda BoostPokemon podnosi statystyki pokemon�w przeciwnika w zale�no�ci od wybranego poziomu
    trudno�ci
    */
    
    
    //Modifiers
    void SetDexterity(int dexterity){this->dexterity = dexterity;}
    void SetStrength(int strength){this->strength = strength;}
    void SetHp(int hp){this->hp = hp;}
    void SetAlive(bool alive) { this->alive = alive; }
    void XP(int XP) { this->Xp = XP + Xp; }
    void SetId(int id) { this->id = id; }
    void SetSkill(Skill skill) { this->skill = skill; }
    void SetMaxHP(int maxHP) { this->maxHP = maxHP; }
    void SetName(string name) { this->name = name; }
    void SetElement(string element) { this->element = element; }
    void SetMaxXP(int XP_to_next) { this->XP_to_next = XP_to_next; }
    void SetXP(int xp) { this->Xp = xp; }

    //Accessors
    inline const string& GetName(){return name;}
    inline const string& GetElement() { return element; }
    inline const int& GetDexterity(){return dexterity;}
    inline const int& GetHP(){return hp;}
    inline const int& GetMaxHP() { return maxHP; }
    inline const int& GetStrength(){return strength;}
    inline const bool& GetAlive() { return alive; }
    inline const string& GetType() { return skill.GetType(); }
    inline const int& GetXP() { return Xp; }
    inline const int& GetMaXP() { return XP_to_next; }
    inline const int& GetID(){return id;}
    inline Skill& GetSkill() { return skill; }
    
};


