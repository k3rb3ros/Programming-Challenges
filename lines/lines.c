#include "lines.h"

double getSlope(line* l)
{
   //m = (y2-y1)/(x2-x1)
   return (l->p2.y-l->p1.y)/(l->p2.x-l->p1.x);
}

bool intersect(line* l1, line* l2)
{
    if(getSlope(l1) != getSlope(l2)) { return true; }
    return false;
}

void printLine(line* line, int num)
{
   printf("Line %d passes through points (%lf, %lf) and (%lf, %lf)\n", num, line->p1.x, line->p1.y, line->p2.x, line->p2.y);
}

/*
* This program determines if two lines in 2 dimensions intersect or not
* In two dimensions any lines that are not parallel will eventually intersect 
* so all we have to do is determine if they are parallel (have the same slope)
*/
int main()
{
    double user_x = 0.0;
    double user_y = 0.0;
    line l1;
    line l2;

    printf("Enter the x and y coordinates of point1 on line 1\n in the format x,y\n");    
    scanf("%lf,%lf", &user_x, &user_y); //have the user input a point
    l1.p1.x = user_x;
    l1.p1.y = user_y;

    printf("Enter the x and y coordinates of point2 on line 1\n in the format x,y\n");
    scanf("%lf,%lf", &user_x, &user_y); //have the user input a point
    l1.p2.x = user_x;
    l1.p2.y = user_y;

    printLine(&l1, 1);

    printf("Enter the x and y coordinates of point1 on line 2\n in the format x,y\n");    
    scanf("%lf,%lf", &user_x, &user_y); //have the user input a point
    l2.p1.x = user_x;
    l2.p1.y = user_y;

    printf("Enter the x and y coordinates of point2 on line 2\n in the format x,y\n");
    scanf("%lf,%lf", &user_x, &user_y); //have the user input a point
    l2.p2.x = user_x;
    l2.p2.y = user_y;

    printLine(&l2, 2);

    if(intersect(&l1, &l2)) { printf("Lines intersect\n"); }
    else { printf("Lines do not intersect\n"); }

    return 0;
}
