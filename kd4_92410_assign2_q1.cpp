#include<iostream>
using namespace std;

class Volume{
    private:
    int length;
    int width;
    int height;

    public:
    Volume(){
        //default constructer
        this->length=10;
        this->width=20;
        this->height=30;

        cout<<"Default Constructer of length:"<<this->length<<endl;
        cout<<"Default constructer of width:"<<this->width<<endl;
        cout<<"Default constructer of height"<<this->height<<endl;
    }
   Volume(int length){
        //single constructer
        this->length=length;
        this->width=length;
        this->height=length;
        cout<<"Single Constructer of length,width,height: "
            <<" Length: "<<this->length<<" Width: "<<this->width<<" Height: "<<this->height<<endl;
    }


    
    Volume(int length,int width,int height){
        //single constructer
        this->length=length;
        this->height=height;
        this->width=width;
        cout<<"single Constructer of length,width,height:"<<" Length: "<<this->length<<" Width :"<<this->width<<" heigth: "<<this->height<<endl;
        
    }
    

    double CalculateVolume(){
        return length*width*height;
        
    }
};


int main(){
    int x;
    int length;
    int width;
    int height;
    double res;
    Volume v1; 
    do
    {
        cout<<"--------------------------------------"<<endl;
        cout<<"If the  value of x is 0 :exit  "<<endl;
        cout<<"If the  value of x is 1 :default  "<<endl;
        cout<<"If the  value of x is 2 :single value enter"<<endl;
        cout<<"If the  value of x is 3 :different value enter"<<endl;
        cout<<"Enter the  value of x :"<<endl;
        cin>>x;

        switch (x)
        {
        case 1:
            {
                cout<<"taking default values :"<<endl;
                v1=Volume(); //
                res=v1.CalculateVolume();
                cout<<"The volume is :"<<res<<endl;
            break;
            }
        case 2:
            {
                cout<<"Enter a single value:"<<endl;
                cin>>length;
                Volume v1{length}; //
                res=v1.CalculateVolume();
                cout<<"The volume is :"<<res<<endl;
            break;
            }
        case 3:
            {
            cout<<"Enter all different values:"<<endl;
                cout<<"Enter length,width,heigth"<<endl;
                cin>>length>>width>>height;
                cout<<"Enter length,width,heigth :"<<endl;
                v1=Volume{length,width,height};
                res=v1.CalculateVolume();
                cout<<"The volume is :"<<res<<endl;
            break;
            }
        case 0:{
        cout<<"exited"<<endl;
        break;
            }
        
        default:
            {
                cout<<"enter valid enteries :"<<endl;
                break;
            }
        }

    } while (x!=0);
    



    return 0;
}



