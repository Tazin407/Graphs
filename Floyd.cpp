#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF= 1e7+8;

int main()
{

    int n;
    cin >> n;
    int adj[n + 1][n + 1];
    //    for (int i = 1; i < =n; i++)
    //    {
    //       for (int j = 1; j <= n; j++)
    //       {
    //          cin>>adj[i][j];
    //       }

    //    }
    int a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if (a == -1)
            {
                adj[i][j] = INF;
            //ekhane -1 thakle distance kome jabe
            }
            else
            {
                adj[i][j] = a;
            }
        }
    }
int min= INT_MIN;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                 if( adj[i][k]== 0 || adj[k][j]== 0) continue;
                 if( adj[i][k]== INF || adj[k][j]== INF) continue;
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    if(adj[i][j]>min){
                        min= adj[i][j];
                    }
                }
                
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }

    //     cout << endl;
    // }
    cout<<min;

    return 0;
}