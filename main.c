/*******************************************************************************************
*        Art by Joan Stark
*                           _ |\_
*                           \` ..\
*                      __,.-" =__Y=
*                    ."        )
*              _    /   ,    \/\_
*             ((____|    )_-\ \_-`
*        jgs  `-----'`-----` `--`
********************************************************************************************/

/*******************************************************************************************
 * JAKIM THE UNTOUCHABLE! by Daniel Motilla Monreal
 *******************************************************************************************/

#include "raylib.h"

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "JAKIM THE UNTOUCHABLE");

    // NOTE: Textures MUST be loaded after window initialization (OpenGL context is required)
    Texture2D jakim = LoadTexture("C:\\Users\\Danie\\Documents\\Github\\HAKIM_CAT\\Assets\\Meow Knight\\Meow-Knight_Idle.png");
    Texture2D MAP = LoadTexture("C:\\Users\\Danie\\Documents\\Github\\HAKIM_CAT\\Assets\\Maps\\MAP_9.png");

    Vector2 playerPosition = {400.0f, 225.0f };
    float playerRotation = 0.0f;

    Rectangle frameRec = { 0.0f, 0.0f, (float)jakim.width, (float)jakim.height/6 };


    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 8;                 // Number of sprite sheet frames shown by second

    Camera2D camera = { 0 };
    camera.target = (Vector2){ playerPosition.x + 20.0f, playerPosition.y + 20.0f };
    camera.offset = (Vector2){ (float)screenWidth/2.0f, (float)screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    float rotationAmount = 1.0f;

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 origin = {(float)jakim.width/2.0f, (float)jakim.height/6.0f};
    //Rectangle frameRecMapEnd = { 0.0f, 0.0f, (float)MAP.width, (float)MAP.height };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here

        // Player movement
        if (IsKeyDown(KEY_D)) playerPosition.x += 2;
        else if (IsKeyDown(KEY_A)) playerPosition.x -= 2;
        else if (IsKeyDown(KEY_S)) playerPosition.y += 2;
        else if (IsKeyDown(KEY_W)) playerPosition.y -= 2;

        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            frameRec.y = (float)currentFrame*(float)jakim.height/6;
        }
        // Control frames speed
        if (IsKeyPressed(KEY_RIGHT)) framesSpeed++;
        else if (IsKeyPressed(KEY_LEFT)) framesSpeed--;

        if (framesSpeed > MAX_FRAME_SPEED) framesSpeed = MAX_FRAME_SPEED;
        else if (framesSpeed < MIN_FRAME_SPEED) framesSpeed = MIN_FRAME_SPEED;

        // Camera target follows player
        camera.target = (Vector2){ playerPosition.x + 8, playerPosition.y + 8 };

        // Camera rotation controls
        if (IsKeyDown(KEY_Q)) {
            //camera.rotation -= rotationAmount;
            playerRotation -= rotationAmount;
        }
        else if (IsKeyDown(KEY_E)) {
            //camera.rotation += rotationAmount;
            playerRotation += rotationAmount;
        }

        // Ensure rotation is between 0 and 360 degrees
        if (playerRotation >= 360.0f) playerRotation -= 360.0f;
        else if (playerRotation < 0.0f) playerRotation += 360.0f;

        // Synchronize the camera's rotation with the player's rotation
        camera.rotation = playerRotation;

        // Limit camera rotation to 80 degrees (-40 to 40)
        //if (camera.rotation > 40) camera.rotation = 40;
        //else if (camera.rotation < -40) camera.rotation = -40;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
            playerRotation = 0.0f;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);

        DrawTexturePro(MAP,
                       (Rectangle){ playerPosition.x, playerPosition.y, (float)MAP.width, (float)MAP.height },
                         (Rectangle){ playerPosition.x, playerPosition.y, (float)MAP.width, (float)MAP.height },
                        (Vector2){playerPosition.x - camera.target.x + (float)MAP.width/2 + origin.x, playerPosition.y - camera.target.y + (float)MAP.height/2 + origin.y},
                        -playerRotation, WHITE);

        DrawTexturePro(jakim,
                       frameRec,
                         (Rectangle){ camera.target.x, camera.target.y, (float)jakim.width, (float)jakim.height/6 },origin,
                         playerRotation, WHITE);


        DrawLine((int)camera.target.x, -screenHeight*10, (int)camera.target.x, screenHeight*10, GREEN);
        DrawLine(-screenWidth*10, (int)camera.target.y, screenWidth*10, (int)camera.target.y, RED);

        EndMode2D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(jakim);
    UnloadTexture(MAP);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}