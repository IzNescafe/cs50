#include<stdio.h>
#include<cs50.h>

float sides(float x, float y, float z);
bool valid_triangle(float x, float y, float z);

int main(void)
{
    int x=0,y=0,z=0;
    sides(x,y,z);
    valid_triangle(x,y,z);
    if(valid_triangle(x,y,z) == true)
    {
        printf("The triangle is valid!\n");
    }
    else
    {
        printf("Enter the valid side of triangle!\n");
    }
}

float sides(float x, float y, float z)
{
    x = get_int("Enter side x : ");
    y = get_int("Enter side y : ");
    z = get_int("Enter side z : ");
    return x;y;z;
}

bool valid_triangle(float x, float y, float z)
{
    if(x<=0 || y<=0 || z<=0)
    {
        return false;
    }
    else if(x+y<=z || x+z<=y || y+z<=x)
    {
        return false;
    }
    else
    {
        return true;
    }
}
