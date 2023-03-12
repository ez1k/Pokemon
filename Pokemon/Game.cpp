#include "Game.h"
using namespace std;



vector<Pokemon> Game::Generate(vector<Pokemon>& pokemons)
{
    pokemons.clear();
    for (int i = 0; i < 4; i++)
    {
        int losowa = (rand() % (AllPokemons.size()));
        Pokemon c = AllPokemons[losowa];
        c.BoostPokemon(level);
        pokemons.push_back(c);
    }
    Enemies++;
    return pokemons;
}


Game::Game()
{
    
    skills = {
    Skill("Fire", "Attack", "fire ball", 10, 0, 5, 5),
    Skill("Water", "Attack", "water ball", 10, 0, 5, 5),
    Skill("Steel", "Attack", "Magnet punch", 40, 0, 5, 5),
    Skill("Ground", "Defensive", "Rock head", 0, 50, 5, 5),
    Skill("Ice", "Attack", "Ice arrow", 2, 0, 5, 5),
    Skill("Wind", "Attack", "Wind shuriken", 2, 0, 5, 5),
    Skill("Fire", "Attack", "Flash Fire", 10, 0, 3, 3),
    Skill("Ice","Attack", "Inner Focus", 35, 0, 2, 2),
    Skill("Steel","Attack", "Hyper Cutter", 55, 0, 2, 2)
    };

    AllPokemons={
         Pokemon(0, 55, 55, 105, 105, 5, "Hajzu", "Fire", skills[0], 1),
         Pokemon(1, 75, 75, 135, 135, 5, "grom", "Ground", skills[3], 1),
         Pokemon(2, 51, 40, 104, 104, 5, "Pilap", "Water", skills[1], 1),
         Pokemon(3, 60, 20, 140, 140, 10, "Geodude", "Ground", skills[3], 1),
         Pokemon(4, 58, 61, 88, 88, 10, "Chimchar", "Fire", skills[0], 1),
         Pokemon(5, 35, 45, 105, 105, 10, "Magnemite", "Steel",skills[2], 1),
         Pokemon(6, 55, 60, 70, 70, 10,"Starly","Wind", skills[5], 1),
         Pokemon(7, 41, 65, 78, 78, 10, "Vulpix", "Fire", skills[0], 1),
         Pokemon(8, 55, 95, 35, 35, 10, "Diglet", "Ground", skills[3], 1),
         Pokemon(9, 50, 90, 80, 80, 10, "Poliwag", "Water", skills[1], 1),
         Pokemon(10, 85, 90, 105, 105, 20, "Ponyta", "Fire", skills[6], 1),
         Pokemon(11, 85, 85, 190, 190, 20, "Articuno", "Wind", skills[5], 1),
         Pokemon(12, 85, 30, 285, 285, 20, "Steelix", "Ground", skills[3], 1),
         Pokemon(13, 95, 115, 110, 110, 20, "Sneasel", "Ice", skills[7], 1),
         Pokemon(14, 85, 50, 135, 135, 20, "Mawile", "Steel", skills[8], 1)
    };

    choice = 0;
    playing = true;
}
Game::~Game()
{

}


void Game::PokemonMenu()
{
    PlayersPokemons.clear();
    int counter = 1;
    system("cls");
    cout << "\nWelcome in Pokemons" << endl;
    Sleep(500);
    system("cls");
    cout << "\nYou can pick 6 pokemons"<<endl;
    cout << endl;
    for (int i = 0; i < AllPokemons.size(); i++)
    {
        cout << "Enter: " << i << " to get:";
        AllPokemons[i].PrintPokemon();
        cout << "\n";
    }
    
    while(counter!=7)
    { 
      
        cout <<"\n"<< counter << " Choice: ";
        cin >> choice;  
        if(choice <= AllPokemons.size()-1 )
        { 
            PlayersPokemons.push_back(AllPokemons[choice]);
            counter++;
        }
        else 
        {
            cout << "\nWrong choice";
        }
    }
}
void Game::Load()
{
    
    file.open(fileName, ios::in);
    PlayersPokemons.clear();
    
    
    if (file.good())
    {
        
        file >> Enemies;
        file >> level;
        
      

        for (int i = 0; i <= 5; i++)
        {
            int zm = 0;
            string wyraz = "";
            string wyraz2;
            file >> wyraz;
            file >> wyraz2;
            wyraz.append(" "+wyraz2);
            for (int k = 0; k < skills.size(); k++)
            {
                if (wyraz == skills[k].GetskillName())
                {
                    zm = k;
                }
            }
            Skill skill = skills[zm];
            Pokemon *poko = new Pokemon();
            poko->SetSkill(skill);
            file >> zm;
            poko->SetId(zm);
            file >> zm;
            poko->SetStrength(zm);
            file >> zm;
            poko->SetDexterity(zm);
            file >> zm;
            poko->SetHp(zm);
            file >> zm;
            poko->SetMaxHP(zm);
            file >> zm;
            poko->XP(zm);
            file >> wyraz;
            poko->SetName(wyraz);
            file >> wyraz;
            poko->SetElement(wyraz);
            file >> zm;
            poko->SetAlive(zm);
            file >> zm;
            poko->SetMaxXP(zm);
            PlayersPokemons.push_back(*poko);
            delete poko;
            
        }



        
        file.close();
    }
}
void Game::save()
{
    file.open(fileName, ios::out, ios::trunc);
    if (file.good())
    {
        file << level <<" ";
        file << Enemies <<" ";
        
           
            for (int i = 0; i <= 5; i++)
            {
                file << PlayersPokemons[i].GetSkill().GetskillName() << " ";
                file << PlayersPokemons[i].GetID() << " ";
                file << PlayersPokemons[i].GetStrength() << " ";
                file << PlayersPokemons[i].GetDexterity() << " ";
                file << PlayersPokemons[i].GetHP() << " "; 
                file << PlayersPokemons[i].GetMaxHP() << " ";
                file << PlayersPokemons[i].GetXP() << " ";
                file << PlayersPokemons[i].GetName() << " ";
                file << PlayersPokemons[i].GetElement() << " ";
                file << PlayersPokemons[i].GetAlive() << " ";
                file << PlayersPokemons[i].GetMaXP() << " ";
                
            }
        
        
        
        file.close();
    }
    
}

void Game::mainMenu()
{
    
    cout << "Menu" << endl;
    cout << "1. Play" << endl;
    cout << "2. Load" << endl;
    cout << "3. Quit" << endl;

    cout << "choice: ";
    
    cin >> choice;
    switch (choice)
    {
    case 1:
        Choose(level);
        PokemonMenu();
        Play();
        break;
    case 2:
        system("cls");
        Load();
        Play();
        break;
    case 3:
        playing = false;
        break;
    default:
        cout << "\nWrong key";
        Sleep(500);
        system("cls");

        break;
    }
   
    
}
bool Game::Check(vector<Pokemon>v1)
{
    bool value = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (!v1[i].GetAlive())
        {
            value = false;
        }
        else 
        {
            value =  true;
            break;
        }
    }
    return value;
}
bool Game::CheckPokemon(Pokemon &p)
{
    if(p.GetHP() <= 0)
    {   
        p.SetHp(0);
        p.SetAlive(false);
        return false;
    }
    else {
        return true;
    }
}

void Game::Fight()
{
    fight = true;
    system("cls");
    Generate(Enemy1);
    cout << "opponent's pokemons" << endl;
    for (int i = 0; i < Enemy1.size(); i++)
    {
        Enemy1[i].PrintPokemon();//wyœwietla pokemony wroga
    }
    cout << "\nFight /1, RUN /2";
    cout << "\nchoice: ";
    cin >> choice;
    if (choice == 1)//rozpoczyna siê walka
    {
        random = (rand() % (Enemy1.size()));
        system("cls");
        cout << "Your Enemy pick: ";
        Enemy1[random].PrintPokemon();
        cout << "\n";
        system("pause");
        system("cls");

        for (int i = 0; i < PlayersPokemons.size(); i++)
        {
            cout << "Enter: " << i << " to get:";
            PlayersPokemons[i].PrintPokemon();
            cout << "\n";
        }
        cout << "\nChoose your Pokemon: ";
        cin >> choice;
        Pokemonchoosen = choice;
        
        system("cls");


        while (fight)
        {
            PlayerPokemon(Pokemonchoosen);
            EnemyPokemon(random);
        

            system("cls");
            cout<<Enemy1[random].GetName()<<endl;
            cout << "______________VS_______________";
            cout<<PlayersPokemons[Pokemonchoosen].GetName()<<endl;
            cout << endl;
            system("pause");
            system("cls");
            battle = true;
            Round = 0;
            Battle();
            if (!Check(PlayersPokemons))
            {
                cout << "\nyou lost" << endl;
                fight = false;
                system("pause");
                break;
            }
            if (!Check(Enemy1))
            {
                cout << "\nyou won" << endl;

                system("pause");
                fight = false;
                Enemy1.clear();
                Play();

            }

        }
    }
    else if (choice == 2)
    {
        fight = false;
    }
    else {
        system("cls");
        cout << "\nWrong key";
        Sleep(500);
    }
}
void Game::Battle()
{
    while (battle)
    {
        system("cls");
        cout << "\nHP: " << PlayersPokemons[Pokemonchoosen].GetHP();
        cout << "\nEnemy HP: " << Enemy1[random].GetHP();
        cout << "\nRound: " << Round;
        cout << "\n1. Attack" << endl;
        cout << "\n2. SuperAttack" << endl;
        cout << "\n3. Exchange" << endl;
        cout << "\nChoice: ";
        cin >> choice;




        switch (choice)
        {
        case 1:
            PlayersPokemons[choice].Attack(PlayersPokemons[Pokemonchoosen], Enemy1[random], choice);

            if (!CheckPokemon(Enemy1[random]))
            {
                system("cls");
                cout << "\nYour defated Enemy" << endl;
                PlayersPokemons[Pokemonchoosen].XP(5);
                if (PlayersPokemons[Pokemonchoosen].GetXP() >= PlayersPokemons[Pokemonchoosen].GetMaXP())
                {
                    PlayersPokemons[Pokemonchoosen].Evolute();
                }
                battle = false;
                system("pause");
                break;
            }
            if(Enemy1[random].GetSkill().GetUsesCounter()>0)
            { 
                enemyCh = rand() % 2 + 1;
            }
            else {
                enemyCh = 1;
            }
            choice = enemyCh;
            Enemy1[random].Attack(Enemy1[random], PlayersPokemons[Pokemonchoosen], enemyCh);

            if (!CheckPokemon(PlayersPokemons[Pokemonchoosen]))
            {
                system("cls");
                cout << "\nYour pokemon lost" << endl;
                battle = false;
                system("pause");
                break;
            }

            Round++;
            break;
        case 2:
            PlayersPokemons[choice].Attack(PlayersPokemons[Pokemonchoosen], Enemy1[random], choice);
            if (!CheckPokemon(Enemy1[random]))
            {
                system("cls");
                cout << "\nYour defated Enemy" << endl;
                PlayersPokemons[Pokemonchoosen].XP(5);
                if (PlayersPokemons[Pokemonchoosen].GetXP() >= PlayersPokemons[Pokemonchoosen].GetMaXP())
                {
                    PlayersPokemons[Pokemonchoosen].Evolute();
                }
                battle = false;
                system("pause");
                break;
            }
            if (Enemy1[random].GetSkill().GetUsesCounter() > 0)
            {
                enemyCh = rand() % 2 + 1;
            }
            else {
                enemyCh = 1;
            }
            choice = enemyCh;
            Enemy1[random].Attack(Enemy1[random], PlayersPokemons[Pokemonchoosen], enemyCh);

            if (!CheckPokemon(PlayersPokemons[Pokemonchoosen]))
            {
                system("cls");
                cout << "\nYour pokemon lost" << endl;
                battle = false;
                system("pause");
                break;
            }
            Round++;
            break;
        case 3:
            system("cls");
            for (int i = 0; i < PlayersPokemons.size(); i++)
            {
                cout << "Enter: " << i << " to get:";
                PlayersPokemons[i].PrintPokemon();
                cout << endl;
            }
            cout << "\nChoose your Pokemon: ";
            cin >> choice;
            Pokemonchoosen = choice;
            break;
        default:
            system("cls");
            cout << "\nWrong key";
            Sleep(500);
            break;
        }




    }
}
void Game::PlayerPokemon(int& Pokemonchoosen)
{
    while (!PlayersPokemons[Pokemonchoosen].GetAlive())
    {
        system("cls");
        cout << "this pokemon is unable to fight, choose another one ";
        Sleep(1000);
        system("cls");
        Enemy1[random].PrintPokemon();
        for (int i = 0; i < PlayersPokemons.size(); i++)
        {
            cout << "Enter: " << i << " to get:";
            PlayersPokemons[i].PrintPokemon();
            cout << endl;
        }
        cout << "\nChoose your Pokemon: ";
        cin >> choice;
        if (choice <= PlayersPokemons.size() - 1)
        {
            Pokemonchoosen = choice;
        }
        else
        {
            cout << "\nWrong choice";
            Sleep(500);
        }


    }
}
void Game::EnemyPokemon(int& random)
{
    while (!Enemy1[random].GetAlive())
    {
        random = (rand() % (Enemy1.size()));
    }
}
void Game::Choose(float& level)
{
   while(level == 1)
   { 
    system("cls");
    cout << "Choose level of difficulty" << endl;
    cout << "1. low" << endl;
    cout << "2. medium" << endl;
    cout << "3. High" << endl;

    cout << "choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        level = 0;
        break;
    case 2:
        level = 0.1;
        break;
    case 3:
        level = 0.3;
        break;
    default:
        cout << "\nWrong key";
        Sleep(500);
        system("cls");

        break;
    }
   }
}
void Game::Play()
{
    
    if(Enemies<=3)
    { 
    system("cls");
    PlayMenu = true;
    while (PlayMenu)
    {
       
        if(fight == false)
        { 
        cout << "1. Fight" << endl;
        cout << "2. Show your Pokemons" << endl;
        cout << "3. Save" << endl;
        cout << "4. Load" << endl;
        cout << "5. Quit" << endl;


        cout << "choice: ";
        cin >> choice;
        }
        switch (choice)
        {
        case 1:
        {
            if(Check(PlayersPokemons))
            { 
            Fight();
            break;
            }
            else {
                system("cls");
                cout << "Your Pokemons are dead"<<endl;
                system("pause");
                break;
            }
            
        }
        case 2:
        {
            system("cls");
            for (int i = 0; i < PlayersPokemons.size(); i++)
            {
                
                PlayersPokemons[i].PrintPokemon();
                cout << endl;
            }
            system("pause");
            
            break;
        }
        case 3:
        {
            save();
            break;
        }
        case 4:
        {
            Load();
            break;
        }
        case 5:
        {
            system("cls");
            PlayMenu = false;
            break;
        }
        default: {
            system("cls");
            Sleep(500);
            cout << "\nWrong key";
            break;
        }

        }
        Sleep(500);
        system("cls");
    }
    }
    else {
        cout << "Congratulations you passed the game" << endl;
        system("pause");

        
        playing = false;
    }
    
}


