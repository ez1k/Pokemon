#include "Pokemon.h"
#include "Skill.h"



int help = 0;
Pokemon::Pokemon( int id, int strength, int dexterity, int hp , int maxHp, int XP_to_next, string name, string element, Skill skill, bool alive)
{
    
        int element_choice = 0;
        for (int i = 0; i < ElementType.size(); i++)
        {
            if (element == ElementType[i])
            {
                element_choice = i;
                break;
            }
        }
        this->id = id;
        this->hp = hp;
        this->maxHP = maxHp;
        this->dexterity = dexterity;
        this->element = ElementType[element_choice];
        this->strength = strength;
        this->name = name;
        this->Xp = 0;
        this->XP_to_next = XP_to_next;
        this->alive = alive;
        this->skill = skill;
        
    
}
Pokemon::Pokemon()
{
    this->id = 0;
    this->strength = 0;
    this->dexterity = 0;
    this->hp = 0;
    this->element = "";
    this->name = "";
    this->Xp = 0;
    this->XP_to_next = 0;
    this->alive = false;
    this->maxHP = 0;
    this->skill = Skill();
}
Pokemon::Pokemon(const Pokemon& copy)
{
    this->id = copy.id + help;
    this->strength = copy.strength;
    this->dexterity = copy.dexterity;
    this->hp = copy.hp;
    this->maxHP = copy.maxHP;
    this->element = copy.element;
    this->name = copy.name;
    this->Xp = copy.Xp;
    this->XP_to_next = copy.XP_to_next;
    this->alive = copy.alive;
    this->skill = copy.skill;
    help++;
    
}
void Pokemon::PrintPokemon()
{
    cout << " \nName: " << this->name;
    cout << " Element:" << this->element;
    cout << " Strength: " << this->strength;
    cout << " dexterity: " << this->dexterity;
    cout << " HP: " << this->hp;
    cout << " Xp: " << this->Xp;
    cout << " Skill: " << this->skill.GetskillName();
    cout << " Xp to next evolution: " << this->XP_to_next << endl;
}
void Pokemon::Evolute()
{
    PrintPokemon();
    cout << "\nnew stats:"<<endl;
    this->Xp = Pokemon::GetXP()-Pokemon::GetMaXP();
    this->maxHP = (maxHP * 0.1) + maxHP;
    this->hp = maxHP;
    this->dexterity = (dexterity * 0.1) + dexterity;
    this->strength = (strength * 0.1) + strength;
    this->XP_to_next = (XP_to_next * 1.5) + XP_to_next;
    cout << "\nYour Pokemon is evoluting..."<<endl;
    PrintPokemon();
    
}
int Pokemon::FightLogic(Pokemon& player, Pokemon& Enemy)
{
    int dmg = rand() % player.strength + (player.strength*0.1);
    if (player.element == "Water")
    {
        if (Enemy.element == "Water")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Fire")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Ground")
        {
            dmg += 5;
            return dmg;
        }

    }
    if (player.element == "Ground")
    {
        if (Enemy.element == "Wind")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Fire")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Ice")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Steel")
        {
            dmg += 5;
            return dmg;
        }
    }
    if (player.element == "Wind")
    {
        if (Enemy.element == "Ground")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Steel")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Ice")
        {
            dmg += 5;
            return dmg;
        }
    }
    if (player.element == "Fire")
    {
        if (Enemy.element == "Ice")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Steel")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Water")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Ground")
        {
            dmg -= 5;
            return dmg;
        }
    }
    if (player.element == "Ice")
    {
        if (Enemy.element == "Water")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Ice")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Fire")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Ground")
        {
            dmg += 5;
            return dmg;
        }
    }
    if (player.element == "Steel")
    {
        if (Enemy.element == "Water")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Wind")
        {
            dmg += 5;
            return dmg;
        }
        if (Enemy.element == "Fire")
        {
            dmg -= 5;
            return dmg;
        }
        if (Enemy.element == "Steel")
        {
            dmg -= 5;
            return dmg;
        }
    }
    return dmg;
}
void Pokemon::restart()
{
    this->hp = maxHP;
}
void Pokemon::BoostPokemon(float level)
{
    this->maxHP = (maxHP * level) + maxHP;
    this->hp = maxHP;
    this->dexterity = (dexterity * level) + dexterity;
    this->strength = (strength * level) + strength;
}


void Pokemon::Attack(Pokemon& player, Pokemon& Enemy, int type)
{

    int dodge = rand() % Enemy.dexterity;
    int dmg = 0;




if(type == 1)
{ 
    if(dodge<=player.dexterity)
    { 
        dmg = player.FightLogic(player, Enemy);
        cout << player.name << " Deals " << dmg << " Damage " << endl;
        Sleep(1000);
    }
    else {
        dmg = 0;
        cout << player.name << " missed " << endl;
        Sleep(1000);
    }
    Enemy.hp = Enemy.GetHP() - dmg;
}

if (type == 2)
{ 
    if(player.skill.GetUsesCounter()>0)
    { 
    if (player.skill.GetType()=="Attack")
    {
        dmg = player.skill.UseAttackSkill();
        if (dodge <= player.dexterity)
        {
            dmg += player.FightLogic(player, Enemy);
            cout << player.name <<" Uses: " <<player.skill.GetskillName()<< " that Deals " << dmg << " Damage " << endl;
            Sleep(1000);
        }
        else
        {
            dmg = 0;
            cout << player.name << " Uses: " << player.skill.GetskillName() << " that misses"<< endl;
            Sleep(1000);
        }
        Enemy.hp = Enemy.GetHP() - dmg;
    }
    else if (player.GetSkill().GetType() =="Defensive")
    {
        int AddictHP = player.skill.UseDefendSkill();
        player.hp = player.GetHP() + AddictHP;
        cout << player.name << " Uses: " << player.skill.GetskillName() << " that gives him " << AddictHP <<" hp" << endl;
        Sleep(1000);
    }
    }
    else {
        cout << "You cannot use your special attack" << endl;
        
    }
}
}
