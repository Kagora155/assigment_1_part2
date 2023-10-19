// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               flip_image.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     it flips the image ether horizontal or vertical
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
string t;
void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    cout << "enter the flip type ";

    cin >> t;
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
    writeGSBMP(imageFileName, image2);
}

//_________________________________________
void doSomethingForImage()
{
    // it checks if the flip type is horizontal or vertical
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (t == "horizontal")
            {
                // if horizontal it rearranges the rows in reverse
                image2[i][j] = image[i][255 - j];
            }
            else
            {
                // else it rearranges the columns in reverse
                image2[i][j] = image[255 - i][j];
            }
        }
    }
}
