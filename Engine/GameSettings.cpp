#include "GameSettings.h"
#include <fstream>
#include <cassert>

GameSettings::GameSettings(const std::string filename)
{
	std::ifstream file(filename);
	assert(file);
	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		if (!line.empty())
		{
			if (line == "[Ball radius]")
			{
				file >> ballRadius;
			}
			else if (line == "[Ball speed]")
			{
				file >> ballSpeed;
			}
			else if (line == "[Ball starting speed]")
			{
				file >> ballStartingSpeed;
			}
			else if (line == "[Paddle speed]")
			{
				file >> paddleSpeed;
			}
			else if (line == "[Paddle width]")
			{
				float t;
				file >> t;
				paddleHalfWidth = t / 2;
			}
			else if (line == "[Paddle height]")
			{
				float t;
				file >> t;
				paddleHalfHeight = t / 2;
			}
		}
	}
}

float GameSettings::GetBallRadius() const
{
	return ballRadius;
}

float GameSettings::GetBallSpeed() const
{
	return ballSpeed;
}

float GameSettings::GetBallStartingSpeed() const
{
	return ballStartingSpeed;
}

float GameSettings::GetPaddleSpeed() const
{
	return paddleSpeed;
}

float GameSettings::GetPaddleHalfWidth() const
{
	return paddleHalfWidth;
}

float GameSettings::GetPaddleHalfHeight() const
{
	return paddleHalfHeight;
}
