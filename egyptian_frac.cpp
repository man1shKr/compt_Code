#include <bits/stdc++.h>

using namespace std;
void egyptian(int nr,int dr)
{
    if(nr==0 || dr==0)
        return;
    if(dr%nr==0)
        {
           cout<<"1/"<<dr/nr;
           return;
        }
    if(nr%dr==0)
    {
       cout<<nr/dr;
       return;
    }
    if(nr>dr)
    {
        cout<<nr/dr<<" + ";
        return egyptian(nr%dr,dr);
    }
    else
    {
        int n=dr/nr+1;
        cout << "1/" << n << " + ";
        egyptian(nr*n-dr,dr*n);
    }
}
int main()
{
    int nr,dr;
    cout<<"enter numerator followed by denominator : ";
    cin>>nr>>dr;
    cout<<"egyptian fraction representation of"<<nr<<"/"<<dr<<" is ";
    egyptian(nr,dr);
    return 0;
}
