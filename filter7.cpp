// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                Detect_Image_Image.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Teaching Assistant:          Dr.Mohamed El-Ramly
// Purpose:                     This function finds the edges of the drawings in the image and turns the image into a skeleton version of the original
// _________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
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
    writeGSBMP(imageFileName, image2);
}

//_________________________________________
void doSomethingForImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // the program checks if pixel level is above average or not to make all pixels ether 0 or 255
            if (image[i][j] > 110)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // if above the pixel doesn't equal it's under ,or it's right doesn't equal it's left the pixel is edge
            if (image[i - 1][j] != image[i + 1][j] || image[i][j + 1] != image[i][j - 1])
                image2[i][j] = 0;
            else
                image2[i][j] = 255;
        }
    }
}
