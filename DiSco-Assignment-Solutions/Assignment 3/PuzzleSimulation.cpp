#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[1000000],n,q,x,ans[1000000][2];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>x;
        int index;
        for(int j=0;j<n;j++)
        {
            if(x==arr[j])
            {
                index=j;
                break;
            }
        }
        for(int i=0;i<=(int)log2(n);i++)
        {
            if(index%(int)pow(2,i+1)==((int)pow(2,i)-1))
            {
                if(i==0)
                {
                    printf("Left: NULL\n");
                    printf("Right: NULL\n");
                }
                else
                {
                    printf("Left: %d\n",arr[index-(int)pow(2,i-1)]);
                    printf("Right: %d\n",arr[index+(int)pow(2,i-1)]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
