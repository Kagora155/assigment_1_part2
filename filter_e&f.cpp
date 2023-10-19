// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               darker_and_lighter_image.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     getting the skew of the iamge depend to the user index "the degree" horizentally and verticaly
//_________________________________________
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();
void skew();

int main()
{
    loadImage();
    skew();
    saveImage();
    return 0;
}

void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    ;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void skew_horizontal(double angletochange)
{
    // converting the degree to radin by this low
    int anss;
    double lenght = tan((angletochange * 22) / (7 * 180));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            anss[i][j] = 255;
        }
    }
    // getting the base of the image to make it forbidden to change at the base
    double ans3 = SIZE / (SIZE - (256 * lenght));
    for (int i = 0; i < SIZE; i++)
    {
        int cnt = 1;
        for (int j = 0; j < SIZE && cnt <= (SIZE - (256 * lenght)); j++)
        {
            int sum = 0, num = 0;
            for (; j <= (ans3 * cnt) && j < SIZE; j++)
            {
                sum += image[i][j];
                num++;
                if (j + 1 > (ans3 * cnt))
                {
                    break;
                }
            }
            image[i][cnt - 1] = sum / num;
            cnt++;
        }
    }
    double step = (lenght * 256);
    double move = step / SIZE;
    anss = SIZE;
    for (int i = 0; i < SIZE; i++)
    {
        anss = SIZE - ((SIZE * lenght) - step);
        for (int j = step; j < anss; j++)
        {
            anss[i][j] = image[i][int(j - step)];
        }
        step -= move;
    } // arrange the pexciels into skew mode and vertical mode to make the right skew depended on the radin degree which is the user has
    // gave it.
}