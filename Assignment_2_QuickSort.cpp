#include<iostream>

using namespace std;

class product{
    string prod_name;
    float prod_price;
    public:

    void fill(string n,float p){prod_name=n;prod_price=p;}
            int partition(product arr[], int low, int high) {
        
            product pivot = arr[high];
            int i = low - 1;
            for (int j = low; j <= high - 1; j++) {
                if (arr[j].prod_price < pivot.prod_price) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);  
            return i + 1;
            }


        void quickSort(product arr[], int low, int high) {
        
            if (low < high) {
                int pi = partition(arr, low, high);
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }
    void show(product arr[],int n){
      cout<<"Product Name - Price \n";
      for(int i =0; i<n;i++){
          cout<<arr[i].prod_name<<" - $"<<arr[i].prod_price<<"\n";
        }
    }
    
};
int main(){
    product pr[20];
    product call;
pr[0].fill("Wireless Charging Pad", 24.99);
pr[1].fill("Wireless Earbuds", 59.99);
pr[2].fill("Smartwatch", 129.50);
pr[3].fill("Portable Bluetooth Speaker", 45.00);
pr[4].fill("USB-C Hub", 29.99);
pr[5].fill("Ergonomic Office Chair", 199.00);
pr[6].fill("Stainless Steel Water Bottle", 18.75);
pr[7].fill("LED Desk Lamp", 35.50);
pr[8].fill("External SSD 1TB", 89.99);
pr[9].fill("Noise-Cancelling Headphones", 175.00);
pr[10].fill("Robot Vacuum Cleaner", 299.99);
pr[11].fill("Yoga Mat", 22.00);
pr[12].fill("Coffee Maker", 65.00);
pr[13].fill("Gaming Keyboard", 79.99);
pr[14].fill("Action Camera", 150.00);
pr[15].fill("Electric Toothbrush", 40.25);
pr[16].fill("Resistance Band Set", 15.99);
pr[17].fill("Digital Photo Frame", 70.00);
pr[18].fill("Aromatherapy Diffuser", 30.50);
pr[19].fill("Backpack", 55.00);
call.show(pr,20);
int choice;
cout<<"Press one to sort low to high \n";
cin>>choice;
if(choice==1){
 call.quickSort(pr,0,19);
 call.show(pr,20);
}
    return 0;
}