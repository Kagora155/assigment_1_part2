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
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            // Calculate the average of the surrounding pixels (including the current pixel)
            int sum = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    sum += image[i + x][j + y];
                }
            }
            image[i][j] = sum / 9; // Divide by 9 to get the average

            // Set the boundary pixels to the original image values
            image[0][j] = image[0][j];
            image[i - 255][j] = image[i - 255][j];
            image[i][0] = image[i][0];
            image[i][j - 255] = image[i][j - 255];
        }
    }
}