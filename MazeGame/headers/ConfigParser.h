#pragma once
#include <string>

namespace MazeGame
{
	class ConfigParser
	{
	private:
		std::string m_fileName;

		void InvalidConfig();
		void Parse();
	public:
		ConfigParser(std::string fileName);
	};
}
