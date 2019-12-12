#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int c1=0;
    int c2=0;
    int c3=0;
    int sum=0;
    int max_len=0;
    int l=0;
    int r=-1;
    while(l<n)
    {
        while(r<n-1)
        {
            r++;
            if(str[r]=='a')
                c1++;
            else if(str[r]=='b')
                c2++;
            else
                c3++;
            int max_val=max(max(c1,c2),c3);
            sum=c1+c2+c3-max_val;
            if(sum<=k)
                max_len=max(max_len,r-l+1);
            else
                break;
        }
            if(str[l]=='a')
                c1--;
            else if(str[l]=='b')
                c2--;
            else
                c3--;
            l++;
    }
    cout<<max_len<<endl;
}
