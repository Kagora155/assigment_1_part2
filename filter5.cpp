// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               rotate_image.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     it rotates the image clockwise by 90º, 180º or 270º as the user chooses
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
string degree;
void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    cout << "enter the rotate degree :";

    cin >> degree;
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
            // it checks what degree the user want
            if (degree == "270")
            {
                // it makes the columns rows and rows columns then rearrange the rows in revers
                image2[i][j] = image[j][255 - i];
            }
            else if (degree == "90")
            {
                // it makes the columns rows and rows columns then rearrange the columns in revers
                image2[i][j] = image[255 - j][i];
            }
            else if (degree == "180")
            {
                // it rearranges the rows and the columns in revers
                image2[i][j] = image[255 - i][255 - j];
            }
        }
    }
}
