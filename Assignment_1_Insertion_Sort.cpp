#include<iostream>
using namespace std;
#include <cstdlib>  // For rand() 
#include <ctime>
int main(){
    float temperature[10];
    for(int i=0;i<10;i++){
        temperature[i]=1 + (rand() % 100);
    }
    //insertion sort logic
    
            for (int i = 0; i < 10; i++)
                {
                    float key=temperature[i]; 
                    int j=i-1;
                    while(j>=0 && temperature[j]>key)
                    {
                        temperature[j+1]=temperature[j];
                        j--;
                    }
                temperature[j+1]=key;
                }


    cout<<"Temperature\n";
    for(int i=0;i<10;i++){
        cout<<temperature[i]<<" °C\n";
    }
    return 0;
}