// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               merge_of_two_images.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     it takes two images from and merge them into one image
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void loadImage();
void loadImage2();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    loadImage2();

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
void loadImage2()
{
    char image2FileName[100];
    cout << "Enter the source image file name: ";
    cin >> image2FileName;
    strcat(image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
}
//_________________________________________
void saveImage()
{
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image3);
}

//_________________________________________
void doSomethingForImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // it calculates the average of each pixel in the two images and store the result in third image
            image3[i][j] = (image2[i][j] + image[i][j]) / 2;
        }
    }
}
