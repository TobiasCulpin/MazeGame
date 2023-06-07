#pragma once
#include <string>
#include "GameData.h"

namespace MazeGame
{
	class ConfigParser
	{
	private:
		GameData m_gameData;
		std::string m_fileName;

		void InvalidConfig();
		void Parse();
	public:
		ConfigParser(std::string fileName);
	};
}
