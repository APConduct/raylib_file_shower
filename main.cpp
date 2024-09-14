#include <iostream>
#include <fstream>

#include <raylib.h>


int main () {

    InitWindow(800, 600, "test");
    SetTargetFPS(1000);




    std::string fileName = "readtest.txt";
    std::string file_string;
    if (std::ifstream myfile (fileName); myfile.is_open())
    {
        std::string line;

        while(std::getline(myfile, line)) {

            //cout << line << endl;
            file_string.append(line);
            file_string.append("\n");
            std::cout << line << '\n';
            std::cout << file_string << '\n';
        }
        myfile.close();
    }else { std::cout << "Unable to open file";}
    std::cout << file_string << '\n';



    while (!WindowShouldClose())
    {


        BeginDrawing();
        ClearBackground(BLACK);


        //DrawText(file_string.c_str(), 50, 50, 20, WHITE);
        const char *fileName = "readtest.txt";
        DrawText(LoadFileText(fileName), 50, 50, 20, WHITE);


        EndDrawing();
    }


    return 0;
}