#pragma once
#include <string>
#include "GameData.h"

namespace MazeGame
{

	class ConfigParser
	{
	private:
		std::string m_fileName;

		void InvalidConfig();
		void Parse();
	public:
		GameData m_gameData;
		ConfigParser(std::string fileName);
	};
}
