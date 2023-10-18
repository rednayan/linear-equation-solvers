#include <raylib.h>
#include <stdio.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui/src/raygui.h"

#define N 3
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400
#define INPUTHEIGHT 20
#define INPUTWIDTH 100
#define INPUTLIMIT 2000000000

int SolveUsingGaussElimination(int matrix[N][N],int result[N]);

int main(void) {

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Solving Linear Equation");
  SetTargetFPS(60);

  int matrix[N + 1][N] = {0};
  int editMode[N + 1][N] = {0};

  bool resultsVisible = false;
  int result[N] = {0};

  char params[] = "XYZR";

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int i = 0; i < N + 1; i++) {
      char param = params[i];
      DrawText(&param, 100 * (i + 1) + 50, 5, 14, BLACK);
    }

    for (int i = 0; i < N + 1; i++) {
      for (int j = 0; j < N; j++) {
        if (GuiValueBox((Rectangle){100 * (i + 1),
                                    (10 + INPUTHEIGHT / 2.0f) * (j + 1),
                                    INPUTWIDTH, INPUTHEIGHT},
                        NULL, &matrix[i][j], -(INPUTLIMIT), INPUTLIMIT,
                        editMode[i][j])) {
          editMode[i][j] = !editMode[i][j];
        }
      }
    }

    if (GuiButton((Rectangle){100, INPUTHEIGHT * (N + 2), 100, INPUTHEIGHT},
                  "Compute")) {
      SolveUsingGaussElimination(matrix, result);
      resultsVisible = true;
    }

    if (resultsVisible) {
      for (int i = 0; i < N; i++) {
        GuiValueBox((Rectangle){100 * (i + 1), INPUTHEIGHT * (N + 4),
                                INPUTWIDTH, INPUTHEIGHT},
                    NULL, &result[i], -(INPUTLIMIT), INPUTLIMIT, false);
      }
    }

    EndDrawing();
  }
  return 0;
}

int SolveUsingGaussElimination(int matrix[N][N], int result[N]) { return 0; }
