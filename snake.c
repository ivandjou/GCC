#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CELL_SIZE 20
#define MAX_SNAKE_LENGTH 100

typedef struct {
    int x;
    int y;
} Vector2Int;

typedef enum { MENU, GAME, PAUSE } GameState;

typedef enum { SHAPE_CIRCLE, SHAPE_TRIANGLE, SHAPE_SQUARE } FoodShape;

typedef struct {
    Vector2Int position;
    FoodShape shape;
} Food;

void DrawFood(Food food);

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    SetTargetFPS(10);
    InitAudioDevice();
    srand(time(NULL));

    GameState state = MENU;
    int menuOption = 0;
    int maxMenuOptions = 3;
    float volume = 1.0f;

    Vector2Int direction = {1, 0};
    Vector2Int snake[MAX_SNAKE_LENGTH];
    int snakeLength = 3;
    for (int i = 0; i < snakeLength; i++) {
        snake[i].x = 10 - i;
        snake[i].y = 10;
    }
    Food fruit = {
        .position = {rand() % (SCREEN_WIDTH / CELL_SIZE), rand() % (SCREEN_HEIGHT / CELL_SIZE)},
        .shape = rand() % 3
    };
    int score = 0;
    bool pause = false;
    bool isMultiplayer = false;
    while (!WindowShouldClose()) {
        if (state == MENU) {
            if (IsKeyPressed(KEY_DOWN)) menuOption = (menuOption + 1) % maxMenuOptions;
            if (IsKeyPressed(KEY_UP)) menuOption = (menuOption - 1 + maxMenuOptions) % maxMenuOptions;
            if (IsKeyPressed(KEY_ENTER)) {
                if (menuOption == 0) state = GAME;
                if (menuOption == 1) volume = (volume < 1.0f) ? volume + 0.1f : 0.0f;
                if (menuOption == 2) isMultiplayer = !isMultiplayer;
            }
        } else if (state == GAME) {
            if (IsKeyPressed(KEY_V)) {
                state = MENU;
                continue;
            }
            if (IsKeyPressed(KEY_F)) {
                pause = !pause;
            }
            if (!pause) {
                if (IsKeyPressed(KEY_UP) && direction.y != 1) direction = (Vector2Int){0, -1};
                else if (IsKeyPressed(KEY_DOWN) && direction.y != -1) direction = (Vector2Int){0, 1};
                else if (IsKeyPressed(KEY_LEFT) && direction.x != 1) direction = (Vector2Int){-1, 0};
                else if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) direction = (Vector2Int){1, 0};
                for (int i = snakeLength; i > 0; i--) {
                    snake[i] = snake[i - 1];
                }
                snake[0].x = (snake[0].x + direction.x + SCREEN_WIDTH / CELL_SIZE) % (SCREEN_WIDTH / CELL_SIZE);
                snake[0].y = (snake[0].y + direction.y + SCREEN_HEIGHT / CELL_SIZE) % (SCREEN_HEIGHT / CELL_SIZE);

                for (int i = 1; i < snakeLength; i++) {
                    if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                        state = MENU;
                    }
                }
                if (snake[0].x == fruit.position.x && snake[0].y == fruit.position.y) {
                    snakeLength++;
                    score += 10;
                    fruit.position.x = rand() % (SCREEN_WIDTH / CELL_SIZE);
                    fruit.position.y = rand() % (SCREEN_HEIGHT / CELL_SIZE);
                    fruit.shape = rand() % 3;
                }
            }
        }
        BeginDrawing();
        ClearBackground((Color){20, 40, 80, 255});  // Bleu foncé

        if (state == MENU) {
            DrawText("SNAKE GAME", SCREEN_WIDTH / 2 - 150, 50, 40, RAYWHITE);

            const char* options[] = {"Start", TextFormat("Sound: %.0f%%", volume * 100), isMultiplayer ? "Multiplayer: ON" : "Multiplayer: OFF"};

            for (int i = 0; i < maxMenuOptions; i++) {
                Color color = (i == menuOption) ? YELLOW : WHITE;
                DrawText(options[i], SCREEN_WIDTH / 2 - 100, 150 + i * 50, 30, color);
            }
            DrawText("Use arrows + ENTER to select. Press ESC to quit.", 100, SCREEN_HEIGHT - 40, 20, GRAY);
        } else if (state == GAME) {
            for (int i = 0; i < snakeLength; i++) {
                DrawRectangle(snake[i].x * CELL_SIZE, snake[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE, DARKGREEN);
            }
            DrawFood(fruit);
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);
            if (pause) DrawText("PAUSED (Press F to resume)", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2, 20, ORANGE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
void DrawFood(Food food) {
    int px = food.position.x * CELL_SIZE + CELL_SIZE / 2;
    int py = food.position.y * CELL_SIZE + CELL_SIZE / 2;
    int size = CELL_SIZE / 2;

    switch (food.shape) {
        case SHAPE_CIRCLE:
            DrawCircle(px, py, size, BLACK);
            break;
        case SHAPE_TRIANGLE:
            DrawTriangle(
                (Vector2){px, py - size},
                (Vector2){px - size, py + size},
                (Vector2){px + size, py + size},
                BLACK
            );
            break;
        case SHAPE_SQUARE:
            DrawRectangle(food.position.x * CELL_SIZE, food.position.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, BLACK);
            break;
    }
}
