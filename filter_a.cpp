#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
string s;
string t;
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    cout << "which side for the miorror up_down or left_right?";
    cin >> s;
    if (s == "up_down")
    {
        cout << "which side for the mirror up or down?";
        cin >> t;
    }
    else if (s == "left_right")
    {
        cout << "which side for the mirror left or right?";
        cin >> t;
    }
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
    if (s == "left_right")
    {

        int mid = SIZE / 2;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = mid; j < SIZE; j++)
            {
                if (t == "right")
                {
                    image[i][SIZE - 255 - j] = image[i][j];
                }
                else if (t == "left")
                {
                    image[i][j] = image[i][SIZE - 255 - j];
                }
            }
        }
    }
    else if (s == "up_down")
    {
        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (t == "down")
                {
                    image[i][j] = image[SIZE - i - 1][j];
                }
                else if (t == "up")
                {
                    image[SIZE - i - 1][j] = image[i][j];
                }
            }
        }
    }
}
// image[i][j] = image[i][SIZE - 255 - j];