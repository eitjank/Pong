#pragma once

#include <string>

class GameSettings
{
public:
	GameSettings(const std::string filename);
	float GetBallRadius()const;
	float GetBallSpeed()const;
	float GetBallStartingSpeed()const;
	float GetPaddleSpeed()const;
	float GetPaddleHalfWidth()const;
	float GetPaddleHalfHeight()const;
private:
	float ballRadius;
	float ballSpeed;
	float ballStartingSpeed;
	float paddleSpeed;
	float paddleHalfWidth;
	float paddleHalfHeight;
};