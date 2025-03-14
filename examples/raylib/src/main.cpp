#include "raylib.h"


int main() {
    InitWindow(800, 600, "Hello from qbs");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RED);
        EndDrawing();
    }

    CloseWindow();
}
