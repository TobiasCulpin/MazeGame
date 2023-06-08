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
		
	public:
		void Parse(GameData* gameData);
		ConfigParser(std::string fileName);
	};
}
