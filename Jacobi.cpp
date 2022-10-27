#include<iostream>
#include<ctime>
#include <cmath>
#include <limits> 
using namespace std;
 
bool AreDoubleSame(double dFirstVal, double dSecondVal)
{
    return fabs(dFirstVal - dSecondVal) < numeric_limits<double>::epsilon();
}

int main(void)
{
    float a[10][10], b[10], x[10], y[10];
    int n = 0, m = 0, i = 0, j = 0, iteration, count=0;
    cout <<"Enter value of n the no of variables : ";
    cin >>n;
    cout<<"Enter value of m the no of equations : ";
    cin>>m;

    if(n>m)
    {
        cout<<"The Problem is not solvable";
        return 0;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << "Enter values no :(" << i << ", " << j << ") ";
                cin >> a[i][j];
            }
        }
        cout << "\nEnter Constant Values in the right side of equation\n";
        for (i = 0; i < n; i++)
        {
            cout << "Enter values no :(" << i << ", " << j << ") ";
            cin >> b[i];
        }
        cout << "Enter initial assumption values of x\n";
        for (i = 0; i < n; i++)
        {
            cout << "Enter values no. :(" << i<<"):";
            cin >> x[i];
        }
        iteration=0;
        clock_t startTime = clock();
        while (1)
        { 
            for (i = 0; i < n; i++)
            {
                y[i] = (b[i] / a[i][i]);
                for (j = 0; j < n; j++)
                {
                    if (j == i)
                        continue;
                    y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                    
                }
                printf("x%d = %f    ", i + 1, y[i]);
            }
             // updating vaule of x
            for (i = 0; i < n; i++)
            {
                x[i] = y[i]; 
            }
            
            
            cout << "\n";
            iteration++;
            
            int eq=0;
            for (int k = 0; k < n; k++)
            {
                eq = eq + a[0][k]*x[k]; 
            }
                            


            if(AreDoubleSame(eq, b[0]) || count>200)
            {
                break;
            }
            count++;
        }  
        cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    }

cout<<"iter = "<<iteration<<endl;


    return 0;
}