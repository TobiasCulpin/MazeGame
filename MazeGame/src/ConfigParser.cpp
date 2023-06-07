#include "ConfigParser.h"
#include "Globals.h"

#include <fstream>
#include <list>
#include <string>

namespace MazeGame
{
	ConfigParser::ConfigParser(std::string fileName)
	{
		this->m_fileName = fileName;
		this->Parse();
	}

	void ConfigParser::InvalidConfig()
	{
		//TODO throw errors
	}

	void ConfigParser::Parse()
	{
		std::list<std::string> lines;
		std::string tempLine;
		std::ifstream configFile;
		configFile.open(CONFIG_PATH + this->m_fileName + std::string(".config"));
		while (std::getline(configFile, tempLine))
		{
			lines.push_back(tempLine);
		}



	}
}