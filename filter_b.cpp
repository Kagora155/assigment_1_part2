// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:               Shuffle_image.cpp
// Last Modification Date:     12/10/2023
// Author1 and ID and Group:   Nour El-dien Mohamed Rabie - 20220364
// Teaching Assistant:         Dr.Mohamed El-Ramly
// Purpose:                    This filter allows the user to enter a new order of quarters then it rearrange the image according to new order
//_________________________________________
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int start_l, start_w, end_l, end_w, start_row, start_col;
string quarters;
void loadImage();
void saveImage();
void doSomethingForImage();

int main()
{
    loadImage();
    cout << "enter the order of the new image :";
    cin >> quarters;
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
    for (int k = 0; k < 4; k++)
    {
        // to check the quarter it's going to copy
        if (quarters[k] == '1')
        {
            start_w = 0;
            start_l = 0;
            end_w = 128;
            end_l = 128;
        }
        else if (quarters[k] == '2')
        {
            start_w = 128;
            start_l = 0;
            end_w = SIZE;
            end_l = 128;
        }
        else if (quarters[k] == '4')
        {
            start_w = 128;
            start_l = 128;
            end_w = SIZE;
            end_l = SIZE;
        }
        else if (quarters[k] == '3')
        {
            start_w = 0;
            start_l = 128;
            end_w = 128;
            end_l = SIZE;
        }
        // to make the new quarter be copied in the right place
        if (k == 0)
        {
            start_row = 0;
            start_col = 0;
        }
        else if (k == 1)
        {
            start_row = 128;
            start_col = 0;
        }
        else if (k == 2)
        {
            start_row = 0;
            start_col = 128;
        }
        else if (k == 3)
        {
            start_row = 128;
            start_col = 128;
        }
        int col = start_col;
        for (int i = start_l; i < end_l; i++)
        {
            int row = start_row;
            for (int j = start_w; j < end_w; j++)
            {
                // the program takes every pixel in the quarter and copy it in the other image
                image2[col][row] = image[i][j];
                row++;
            }
            col++;
        }
    }
}
