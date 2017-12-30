#ifndef GAME_H_
#define GAME_H_

// The head class. Manages the whole game.
class Game
{
private:
	void init();
	void clear();
	void update();
	void render();
	void initGl();
public:
	Game();
	~Game();
	void run();
};

#endif