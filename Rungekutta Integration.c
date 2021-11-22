#import <stdio.h>

//initial conditions
double x = -1.00;
double y = -1.00;
double z = 5.00;

//parameter conditions
double mu = 1.50;
double a = 45.00/8.00;

//function for time derivate of x
double fx(double x, double y)
{
    return(y*z - mu*x);
}

//function for time derivate of y
double fy(double x, double y, double z)
{
     return((z-a)*x - mu*y);
}

//function for time derivate of z
double fz(double x, double y, double z)
{
    return(1-x*y);
}

//the function for one step of the fourth order runge-kutta
void rk4_1s()
{

    //kxn is the nth coefficient of x in the runge-kutta method. simila naming scheme is followed for kyn and kzn
    double kx1, kx2, kx3, kx4, ky1, ky2, ky3, ky4, kz1, kz2, kz3, kz4;

    kx1 = fx(x,y)*0.001;
    ky1 = fy(x,y,z)*0.001;
    kz1 = fz(x,y,z)*0.001;

    kx2 = fx(x+kx1,y+ky1)*0.001;
    ky2 = fy(x+kx1/2,y+ky1/2,z+kz1/2)*0.001;
    kz2 = fz(x+kx1/2,y+ky1/2,z+kz1/2)*0.001;

    kx3 = fx(x+kx2/2,y+ky2/2)*0.001;
    ky3 = fy(x+kx2/2,y+ky2/2,z+kz2/2)*0.001;
    kz3 = fz(x+kx2/2,y+ky2/2,z+kz2/2)*0.001;

    kx4 = fx(x+kx3,y+ky3)*0.001;
    ky4 = fy(x+kx3,y+ky3,z+kz3)*0.001;
    kz4 = fz(x+kx3,y+ky3,z+kz3)*0.001;

    x = x + (kx1+2*(kx2+kx3)+kx4)/6.00;
    y = y + (ky1+2*(ky2+ky3)+ky4)/6.00;
    z = z + (kz1+2*(kz2+kz3)+kz4)/6.00;

}

void main()
{
    //printing the data sheet to a text file
    char *file = "Rikitake_ Data_0.001s_Timestep.txt";
    FILE *fp = fopen(file, "w");

    int t=100000; //time in milliseconds
    for(int j=1; j<t; j++)//printing data points for time t
    {
        for(int i=0; i<10; i++) //this generates values of x at an interval of one millisecond
        {
            rk4_1s();
        }

        fprintf(fp, "%f %f %f\n", x, y, z);
    }

    fclose(fp);
}