#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cout<<"Enter the testcase:";
    cin>>t;
    while(t--)
    {
        cout<<"Enter the Number:";
        float num;
        cin>>num;
        cout<<"Enter the significant bit:";
        int bit;
        cin >> bit;
        int n,n2;

        string temp = to_string(num);
        for(int i=0; i<temp.size(); i++)
        {

            if(temp[i]=='0'||temp[i]=='.')

            {
                if(temp[i]=='0')
                    bit++;


            }
            else
            {
                break;
            }
        }
        //cout<<bit<<endl;
        char nth_bit = temp[bit];
        char nth_por = temp[bit+1];

        n = nth_bit - '0';
        n2 = nth_por - '0';

        if (n2 == 5)
        {

            if ((n % 2) != 0)
            {

                n += 1;
            }
        }
        else if (n2> 5)
        {

            n += 1;
        }

        string ne;
        for(int i=0; i<bit; i++)
        {
            ne+=temp[i];
        }
        ne+=n+'0';
        cout<<ne<<endl;
    }
    return 0;
}
