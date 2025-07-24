#include <iostream>
using namespace std;
class flight
{
    double prices;
    string flightname;
    string Timedeparting;
    string Timereaching;
public:
    void flight_data(double p,string f,string td,string tr){prices=p; flightname=f;Timedeparting=td;Timereaching=tr;}
    void show_data(flight f[]){
        cout<<"\nNAME - PRICES - TIME DEPARTING - TIME ARRIVAL\n\n";
        for(int i=0; i<10;i++){
            cout<<f[i].flightname<<"  -  "<<f[i].prices<<"  -  "<<f[i].Timedeparting<<"  -  "<<f[i].Timereaching<<"\n";
        }
    }
    void merge(flight arr[], int l, int m, int r)
    {
        int n1 = (m - l) + 1;
        int n2 = r - (m + 1) + 1;
        flight left[n1], right[n2];

        for (int i = 0; i < n1; i++)
        {
            left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++)
        {
            right[j] = arr[m + 1 + j];
        }
        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2)
        {
            if (left[i].prices <= right[j].prices)
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    };

    void mergeSort(flight arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
};
int main()
{    
    flight f[10];
    flight call;
    cout<<"\n\n\n ---------------------------------------WELCOME TO FLIGHT BOOKING PORTAL----------------------\n\n";

    f[0].flight_data(17000,"Indigo","12AM","6AM");
    f[1].flight_data(18500,"SpiceJet","2AM","7AM");
    f[2].flight_data(19800,"Emirates","1AM","5AM");
    f[3].flight_data(17500,"Indigo","12PM","6PM");
    f[4].flight_data(19000,"SpiceJet","2PM","8PM");
    f[5].flight_data(14000,"Air India","12AM","8AM");
    f[6].flight_data(12000,"Ryan Airlines","12AM","10AM");
    f[7].flight_data(15500,"British Airlines","5PM","11PM");
    f[8].flight_data(17000,"Kingfisher Airlines","4AM","12AM");
    f[9].flight_data(13000,"Air India","1PM","12AM");
    call.show_data(f);
    cout<<"\n\nPRESS ONE TO SORT BY PRICES\n";
    int choice;
    cin>>choice;
    if(choice==1){
        call.mergeSort(f,0,9);
        call.show_data(f);
    }
    return 0;
}