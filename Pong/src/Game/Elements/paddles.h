#ifndef PADDLES_H
#define PADDLES_H

#include "raylib.h"

#include "Game/Elements/arrows.h"
#include "Game/Elements/power_ups.h"

namespace Game
{
const int paddleSpeed = 1000;
const int paddleWidth = 20;
const int paddleHeight = 100;

struct Paddle
{
	Arrow leftArrow;
	Arrow rightArrow;
	Color color;
	Rectangle rec;

	int colorCode;
	int score;

	float ballAndCenterDiference;
	float center;
	float speed;

	bool up;
	bool right;
};

extern Paddle paddle1;
extern Paddle paddle2;

extern bool paddle1LastToHit;

//----------------------------------------------------------------

Paddle InitPaddle();

void InitArrows(Paddle &paddle);
void GeneratePaddleArrows(Paddle &paddle);

void ApplyPowerUp(Paddle &positivePaddle, Paddle &negativePaddle);
void RemovePowerUp(Paddle &positivePaddle, Paddle &negativePaddle);
}

#endif