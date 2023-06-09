#include "ConfigParser.h"
#include "Globals.h"
#include "MazeData.h"

#include <fstream>
#include <vector>
#include <string>

namespace MazeGame
{
	ConfigParser::ConfigParser(std::string fileName)
	{
		this->m_fileName = fileName;
	}

	void ConfigParser::InvalidConfig()
	{
		//TODO throw errors
	}

	void ConfigParser::Parse(GameData* gameData)
	{
		std::vector<std::string> lines;
		std::string tempLine;
		std::ifstream configFile;
		configFile.open(MG_CONFIG_PATH + this->m_fileName + std::string(".dwdwconfig"));
		while (std::getline(configFile, tempLine))
		{
			lines.push_back(tempLine);
		}

		for (int i = 0; i < 3; i++)//17 rows in config file per maze  3 mazes
		{
			for (int j = 0; j < 9; j++)//tiles
			{
				for (int k = 0; k < 9; k++)
				{
					gameData->m_mazes[i].m_tiles[j][k] = std::stoi(lines[(17*i)+j].substr(k,1));
				}
			}
			for (int j = 0; j < 3; j++)//treasure
			{
				std::string pos = lines[(17 * i) + 9 + j].substr(0, 2);
				if (pos != std::string("!!"))
				{
					gameData->m_mazes[i].m_treasure[j][0] = std::stoi(pos);
					gameData->m_mazes[i].m_treasure[j][1] = std::stoi(lines[(17 * i) + 9 + j].substr(2, 2));
				}
				else { continue; }//TODO throw error
			}
			for (int j = 0; j < 3; j++)//threats
			{
				std::string pos = lines[(17 * i) + 12 + j].substr(0, 2);
				if (pos != std::string("!!"))
				{
					gameData->m_mazes[i].m_threats[j][0] = std::stoi(pos);
					gameData->m_mazes[i].m_threats[j][1] = std::stoi(lines[(17 * i) + 12 + j].substr(2, 1));
					gameData->m_mazes[i].m_threats[j][2] = std::stoi(lines[(17 * i) + 12 + j].substr(3, 1));
				}
				else { continue; }//TODO throw error
			}
			for (int j = 0; j < 4; j++)//passages
			{
				std::string passage = lines[(17 * i) + 15].substr(j, 1);
				gameData->m_mazes[i].m_passages[j] = passage == std::string("!") ? -1 : std::stoi(passage);
			}
			//exit
			std::string exit = lines[(17 * i) + 16].substr(0, 1);
			gameData->m_mazes[i].m_exit = exit == std::string("!") ? -1 : std::stoi(exit);
			//index
			gameData->m_mazes[i].m_index = i;
		}
	}
}