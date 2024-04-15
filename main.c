#include "raylib.h"


int main(){

    int window_width = 800;
    int window_height = 600;
    int ball_velocity = 4;


    float ball_size = 40.0;
    int ball_x = window_width / 2;
    int ball_y = window_height / 2;
    int gravity = 2;

    InitWindow(window_width, window_height, "My Game");
    SetTargetFPS( 60 );

    while(! WindowShouldClose()){
        BeginDrawing();

        int ball_bottom = ball_y + ball_size; 
        if ( ball_bottom >= window_height){
            ball_velocity = 0;
            ball_y = window_height - ball_size;
        }

        if (IsKeyDown ( KEY_SPACE ) ) {
            ball_velocity = -30;
        }

        if (IsKeyDown ( KEY_RIGHT ) ) {
            ball_x += 20;
        }

        if (IsKeyDown ( KEY_LEFT ) ) {
            ball_x -= 20;
        }

        ball_y += ball_velocity;
        ball_velocity += gravity;

        ClearBackground(WHITE);

        DrawCircle(ball_x, ball_y, ball_size, RED);

        EndDrawing();
    }

    return 0;
}