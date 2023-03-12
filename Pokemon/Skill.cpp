#pragma once
#include "Skill.h"

Skill::Skill()
{
	this->name = "";
	this->damage = 0;
	this->BonusHP = 0;
	this->element = "";
	this->type = "";
	this->uses_Counter = 0;
	this->max_uses = max_uses;
}
Skill::~Skill()
{
}
Skill::Skill(const Skill& copy)
{
	
	this->BonusHP = copy.BonusHP;
	this->type = copy.type;
	this->damage = copy.damage;
	this->element = copy.element;
	this->name = copy.name;
	this->uses_Counter = copy.uses_Counter;
	this->max_uses = copy.max_uses;
}
Skill::Skill(string element, string type, string name, int damage, int BonusHP, int uses_Counter, int max_uses)
{

	this->name = name;
	this->damage = damage;
	this->element = element;
	this->type = type;
	this->BonusHP = BonusHP;
	this->uses_Counter = uses_Counter;
	this->max_uses = max_uses;

}
