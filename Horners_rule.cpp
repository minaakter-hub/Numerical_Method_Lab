#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,x;
    cout<<"Enter the highest degree of this equation:";
    cin>>n;
    cout<<"Enter the Guessing root:";
    cin>>x;
    vector<int>coefficent(n+1),result(n+1);
    cout<<"Enter the coefficient"<<endl;

    for(int i=n; i>=0; i--)
    {

        cin>>coefficent[i];

    }
    result[n] = coefficent[n];
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = result[i+1] * x + coefficent[i];
    }
    for(int i=n; i>=0; i--)
    {

        cout<<"p["<<i<<"] = "<<result[i]<<endl;
    }
    if(result[0]==0)
    {
        cout<<"Wow!The guessing root  satisfies the equation"<<endl;
    }
    else
    {
        cout<<"Oopps!The guessing root doesn't satisfiy the equation"<<endl;
    }


}
