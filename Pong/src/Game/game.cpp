#include "game.h"

#include "Game/States/game_over.h"
#include "Game/States/gameplay.h"
#include "Game/States/main_menu.h"
#include "Game/States/selection_menu.h"
#include "Game/Elements/buttons.h"
#include "Game/Elements/paddles.h"

namespace Game
{
GameState currentState;
GameState selectedGameMode;

Music music;

Sound buttonSFX;
Sound hitSFX;

Vector2 cursor;

float deltaTime;
bool enterPressed;

//----------------------------------------------------------------

static void Init();
static void InitSounds();

static void Close();
static void UnloadSounds();

void Execute()
{
	Init();

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		switch (currentState)
		{
		case GameState::MainMenu:
		{
			Main_Menu::Execute();
		}
		case GameState::SelectionMenu:
		{
			Selection_Menu::Execute();
		}
		case GameState::PvP:
		case GameState::PvAI:
		{
			Gameplay::Execute();
		}
		case GameState::GameOver:
		{
			Game_Over::Execute();
		}
		}

		EndDrawing();
	}

	Close();
}

static void Init()
{
	currentState = GameState::MainMenu;

	deltaTime = 0;

	pauseActive = false;
	enterPressed = false;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
	InitAudioDevice();
	InitSounds();
	InitMainMenuButtons(jugadorVsIA, playerVsPlayer, fullScreen_, exit);
	InitSelectionMenuButtons(jugar, return_);
	InitGameplayAndGameOverButtons(continue_, pause, pauseMenu, returnToSelectionMenu, returnToMainMenu);
}

static void InitSounds()
{
	music = LoadMusicStream("audio/music/music.ogg");

	buttonSFX = LoadSound("audio/SFX/buttonSFX.ogg");
	hitSFX = LoadSound("audio/SFX/hitSFX.ogg");
}

static void Close()
{
	UnloadSounds();
	CloseAudioDevice();
	CloseWindow();
}

static void UnloadSounds()
{
	UnloadMusicStream(music);

	UnloadSound(buttonSFX);
	UnloadSound(hitSFX);
}
}