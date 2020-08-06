#include "../Logging/Logging.h"
#include"Board.h"
#include"QuixoGame.h"
#include <fstream>

int main()
{
	std::ofstream of("syslog.log", std::ios::app);
	Logger logger(of);

	logger.log("Quixo game started...", Logger::Level::Info);

	QuixoGame quixoGame;
	quixoGame.RunGame();

	system("pause");
	logger.log("Quixo game stopped...", Logger::Level::Info);
	return 0;
}