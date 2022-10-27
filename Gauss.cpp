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
    int n = 0, m = 0, i = 0, j = 0, iteration;


    cout <<"Enter value of n the no of variables : ";
    cin >>n;
    cout<<"Enter value of m the no of equations : ";
    cin>>m;

    float *eq = new float[n];

    //setting array to zero
    for (i = 0; i < n; i++)
    {
        eq[i]=0;
    }


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

        clock_t startTime = clock();
        iteration=0;
        int count=0;
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
                    x[i] = y[i];
                }
                printf("x%d = %f    ", i + 1, y[i]);
            }
            cout << "\n";
            iteration++;
            

            

            for (i = 0; i < n; i++)
            {
                for (int k = 0; k < n; k++)
                {
                    eq[i] = eq[i] + a[i][k]*x[k];
                }
            }
            
            float sumeq=0, sumb=0;

            //summing all equations  
            for (i = 0; i < n; i++)
            {
                sumeq = sumeq +eq[i];
            }
            //sum of contants at right side of eq
            for (i = 0; i < n; i++)
            {
                sumb = sumb + b[i];
            }
            
            
            
            if(AreDoubleSame(sumeq, sumb) || count > 3000)
            {
                break;
            }

        //setting array to zero
        for (i = 0; i < n; i++)
        {
            eq[i]=0;
        }
            count++;
        }  
        cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    }

cout<<"iter = "<<iteration<<endl;


    return 0;
}