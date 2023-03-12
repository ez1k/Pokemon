#include "Functions.h"
#include "Pokemon.h"
#include "Game.h"
#include "Skill.h"

int main()
{
	

	Game game;
	while (game.getPlaying())
	{
		game.mainMenu();
	}
}