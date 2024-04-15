#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int average = (int)round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0 );
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = fmin(255, (int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue + 0.5));
            image[i][j].rgbtGreen = fmin(255, (int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue + 0.5));
            image[i][j].rgbtBlue = fmin(255, (int) (0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue + 0.5));
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2 ; j++){
             RGBTRIPLE temp = image[i][j];
             image[i][j] = image[i][width - 1 - j];
             image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            copy[i][j] = image[i][j];

        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            float counter = 0.00;

            for(int x = -1; x < 2; x++){
                for(int y = -1; y < 2; y++){
                    int currentX = i + x;
                    int currentY = j + y;

                    if(currentX < 0 || currentX > (height - 1 ) || currentY < 0 || currentY > (width - 1)){
                        continue;
                    }
                    totalRed += copy[currentX][currentY].rgbtRed;
                    totalGreen += copy[currentX][currentY].rgbtGreen;
                    totalBlue += copy[currentX][currentY].rgbtBlue;

                    counter++;
                }
            }
            image[i][j].rgbtRed = round(totalRed / counter);
            image[i][j].rgbtGreen = round(totalGreen / counter);
            image[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }
}