// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                enlarge_image.cpp
// Last Modification Date:      17/10/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:          Dr.Mohamed El-Ramly
// Purpose:                     This filter allows the user to enlarge one of the four quarters of the image into a separate new image
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
int q, qx, qy;
void loadImage();
void saveImage();
void doSomethingForImage();
int main()
{
    loadImage();
    cout << "What quarter you want to enlarge :";
    cin >> q;
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
    // to specify from which column and row the zooming will begin
    if (q == 1)
    {
        qx = 0;
        qy = 0;
    }
    else if (q == 2)
    {
        qx = 127;
        qy = 0;
    }
    else if (q == 4)
    {
        qx = 127;
        qy = 127;
    }
    else if (q == 3)
    {
        qx = 0;
        qy = 127;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                // the program every pixel in the quarter and copy it in the pixel under and next
                image2[i][j][k] = image[(i / 2) + qy][(j / 2) + qx][k];
            }
        }
    }
}
