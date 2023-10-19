// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               crop_Image.cpp
// Last Modification Date:      11/10/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     This filter allows entering an x, y position and cutting a square of length and width l, w to keep and removing the rest.
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int w, l, wcut, lcut;
void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    cout << "enter x and y position to crop the image :";
    cin >> w >> l;
    wcut = (SIZE - w) / 2; // to make the program start take pixels in rows from it
    lcut = (SIZE - l) / 2; // to make the program start take pixels in columns from it
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
    // to make the second image white
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i][j] = 255;
        }
    }
    for (int i = lcut; i < SIZE - lcut; i++)
    {
        for (int j = wcut; j < SIZE - wcut; j++)
        {
            image2[i][j] = image[i][j];
        }
    }
}
