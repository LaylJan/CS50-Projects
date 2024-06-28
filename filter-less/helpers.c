#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int rows = height;
    int columns = width;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int average = round((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int rows = height;
    int columns = width;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int rows = height;
    int columns = width;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][columns - 1 - j];
            image[i][columns - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int rows = height;
    int columns = width;

    RGBTRIPLE tmp[height][width];

    // makes the copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int pixel = 0;
            int averageRed = 0;
            int averageGreen = 0;
            int averageBlue = 0;
            // This part loops thru the 3by3 pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < rows && j + l >= 0 && j + l < columns)
                    {
                        // Add tmp's RGB values to your sums here
                        averageRed += tmp[i + k][j + l].rgbtRed;
                        averageGreen += tmp[i + k][j + l].rgbtGreen;
                        averageBlue += tmp[i + k][j + l].rgbtBlue;
                        pixel++;
                    }
                }
            }
            image[i][j].rgbtRed = round((float) averageRed / pixel);
            image[i][j].rgbtGreen = round((float) averageGreen / pixel);
            image[i][j].rgbtBlue = round((float) averageBlue / pixel);
        }
    }
    return;
}
