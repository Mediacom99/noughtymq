#include <raylib/raylib.h>
#include <stdio.h>

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	//Main event loop
	while(!WindowShouldClose())
	{
		BeginDrawing();
		
		ClearBackground(BLACK);

		DrawText("H4CK3D", 190, 200, 20, RED);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
