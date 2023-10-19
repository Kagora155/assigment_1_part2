// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               darker_and_lighter_image.cpp
// Last Modification Date:      07/09/2023
// Author1 and ID and Group:    Nour El-dien Mohamed Rabie - 20220364
// Author2 and ID and Group:    ahmed mahmoud hasaneen - 20220039
// Author3 and ID and Group:    mohamed mostafa shaheen - 20221131
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                     it makes the image lighter or darker as the user chooses
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
string filter;
void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    cout << "would you make the photo lighter or darker :";

    cin >> filter;
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
            // it checks hwo the user want the image
            if (filter == "darker")
            {
                // if darker it reduces the pixel level to the half
                image[i][j] *= 0.5;
            }
            else
            {
                // else it checks if the pixel level is over 180 it makes it 230 (not to make it over the range of pixel level)
                if (image[i][j] > 180)
                {
                    image[i][j] = 230;
                    continue;
                }
                // if the pixel level is less than 180 it raises it by 50
                image[i][j] += 50;
            }
        }
    }
}
