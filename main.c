#include "raylib.h"

typedef struct {
    int x;
    int y;
    float size; 
    int velocity;
} Ball;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Platform;


int ball_on_platform( Ball ball, Platform platforms[] ){
    int count = 3;
    for ( int i = 0; i < count; i++){
        Platform platform = platforms[i];
        Rectangle platform_rec = {
            .x = platforms[i].x, 
            .y = platforms[i].y,
            .width = platforms[i].width,
            .height = platforms[i].height};
        Vector2 ball_position = {.x = ball.x, .y = ball.y};
        int ball_botton = ball.y + ball.size;

        if( CheckCollisionCircleRec(ball_position, ball.size, platform_rec)){
            return 1;
        }
    }

    return 0;
}

int main(){

    int window_width = 800;
    int window_height = 600;

    Ball ball = { 
        .x = window_width/2 , 
        .y = window_height/2, 
        .size = 40.0,
        .velocity = 4};

    int gravity = 2;

    Platform platforms[3];

    platforms[0].x = 0;
    platforms[0].y = window_height - 10;
    platforms[0].width = window_width;
    platforms[0].height = 10;

    platforms[1].x = (int) window_width * 0.1;
    platforms[1].y = (int) window_width * 0.7;
    platforms[1].width = (int) window_width * 0.3;
    platforms[1].height = (int)  window_height *0.05;

    platforms[2].x = (int) window_width * 0.3;
    platforms[2].y = (int) window_width * 0.5;
    platforms[2].width = (int) window_width * 0.3;
    platforms[2].height = (int)  window_height *0.05;

    InitWindow(window_width, window_height, "My Game");
    SetTargetFPS( 60 );

    while(! WindowShouldClose()){
        BeginDrawing();

        if ( ball_on_platform( ball, platforms)){
            ball.velocity = 0;
            //ball.y = window_height - ball.size;

            if (IsKeyDown ( KEY_SPACE ) ) {
                ball.velocity = -30;
            }
        }

        if (IsKeyDown ( KEY_RIGHT ) ) {
            ball.x += 20;
        }

        if (IsKeyDown ( KEY_LEFT ) ) {
            ball.x -= 20;
        }

        ball.y += ball.velocity;
        ball.velocity += gravity;

        ClearBackground(WHITE);

        int count = sizeof(platforms) / sizeof( Platform);
        for ( int i = 0; i < count; i++){
            DrawRectangle(
                platforms[i].x,
                platforms[i].y,
                platforms[i].width,
                platforms[i].height,
                BLUE
                );
        }

        DrawCircle(ball.x, ball.y, ball.size, RED);


        EndDrawing();
    }

    return 0;
}