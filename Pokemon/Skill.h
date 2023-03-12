#pragma once

#include <iostream>
#include <vector>
#include <windows.h>


using namespace std;
class Skill
{
private:
	string element;
	string name;
	string type;
	int damage;
	int BonusHP;
	int uses_Counter;
	int max_uses;
public:
	
	Skill();
	virtual ~Skill();
	Skill(const Skill& copy);
	
	Skill(string element, string type, string name, int damage, int BonusHP, int uses_Counter, int max_uses);



	//Modifiers
	void ResetUses() {
		this->uses_Counter = max_uses;
	}
	/*
	* metoda ResetUses przywraca poprzedni stan u¿yæ umiejêtnoœci dzieje siê to po walce
	* 
	*/
	void SetElement(string element) { this->element = element; }
	void SetName(string name) { this->name = name; }
	void SetType(string type) { this->type = type; }
	void SetDamage(int damage) { this->damage = damage; }
	void SetBonusHP(int BonusHP) { this->BonusHP = BonusHP; }
	void SetUsesCounter(int uses_Counter) { this->uses_Counter = uses_Counter; }
	void SetMaxUses(int max_uses) { this->max_uses = max_uses; }
	


	//Accessors
	inline const int UseAttackSkill() { uses_Counter--; return damage; }
	inline const int UseDefendSkill() { uses_Counter--; return BonusHP; }
	inline const string& GetType() { return type; }
	inline const string& GetskillName() { return name; }
	inline const string& GetElement() { return element; }
	inline const int GetUsesCounter() { return uses_Counter; }
	inline const int GetDamage() { return damage; }
	inline const int GetBonusHP() { return BonusHP; }
	inline const int GetMaxUses() { return max_uses; }
};

