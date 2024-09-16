#include<iostream>

using namespace std;

void Insertion_Sorting(int  box[],int size){
    for(int i=1; i<size;++i){
        int key = box[i];
        int j = i-1;

        while(j>=0 && box[j]>key){
            box[j+1] = box[j];
            j--;
        }
        box[j+1] = key;
    }

}

int main(){
    int Columns_num =0;
    cin >> Columns_num;
    int box[Columns_num]={0};
    for(int i=0;i<Columns_num;++i){
        cin >> box[i];
    }

    Insertion_Sorting(box,sizeof(box)/sizeof(box[0]));
    
    for(int n:box){
        cout << n << ' ';
    }
}