#include "Game.h"

void Game::run()
{
	InputListener input;
	Logic logic;
	Player player;
	Field field;
	Menu menu;
	FieldView fieldView;
	int gameover = 1;
	menu.start(field);
	while (gameover) {
		fieldView.DrawField(field, player);
		input.listen(gameover);
		logic.start(input.getDir(), field, player, gameover);
	}
}
