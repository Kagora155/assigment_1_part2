// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               invert_image.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     it produces another version of the image that is the negative version of the image
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    doSomethingForImage();
    saveImage();
    return 0;
}

//_________________________________________
void loadImage()
{
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage()
{
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void doSomethingForImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // it substracts the pixel level from the highest possible pixel level
            image[i][j] = 255 - image[i][j];
        }
    }
}
