#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main(){

    vector<int> height;
    string n;
    while(n != ".")
    {
        cin>>n;
        if(n==".") break;
        int m=stoi(n);
        height.push_back(m);
    }
    int temp0;
    for(int i=0;i<height.size();i++)
    {
        int temp=0;
        for(int j=0;j<height.size();j++)
        {
            int visina = min(height[i],height[j]);
            int sirina = abs(i-j);
            if(visina*sirina>temp)
                {
                    temp=visina*sirina;
                }

        }

        if(temp0<temp) temp0=temp;
    }
    cout<<temp0;
    return 0;
}