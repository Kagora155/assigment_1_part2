// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                Shrink_Image.cpp
// Last Modification Date:      17/10/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:          Dr.Mohamed El-Ramly
// Purpose:                     This filter allows the user to shrink the image dimensions to 50%, 33.3% or 25% the original dimensions.
// _________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <bits/stdc++.h>
#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
int m, sh;
void loadImage();
void saveImage();
void doSomethingForImage();
int main()
{
    loadImage();
    cout << "how much you want to shrink the image \n 50        66             75:";
    cin >> sh;
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
    readRGBBMP(imageFileName, image);
}

//________________________________________

void saveImage()
{
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}

//_________________________________________
void doSomethingForImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image2[i][j][k] = 255;
            }
        }
    }
    // to specify how much you want to shrink the photo
    if (sh == 50)
        m = 2;
    else if (sh == 66)
        m = 3;
    else if (sh == 75)
        m = 4;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                // to take the average of (m) pixels and store it in the other photo
                image2[i / m][j / m][k] = (image[i][j][k] + image2[i / m][j / m][k]) / 2;
            }
        }
    }
}
