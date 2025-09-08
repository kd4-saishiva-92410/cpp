#include <iostream>
using namespace std;

static double pi=3.14;

class Cylinder{
    private:
    double radius;
    double height;

    public:
    Cylinder(void):radius(0),height(0){
        cout<<"default values :"<<endl;
        cout<<"radius :"<<radius<<" height :"<<height<<endl;
    }
    Cylinder(double radius,double height):radius(radius),height(height){}
    void setRadius(void){
        cout<<"Enter the value of radius :"<<endl;
        cin>>radius;
    }
    void getRadius(void){
        cout<<"Radius :"<<radius<<endl;
    }
    void setHeight(void){
        cout<<"Enter the value of height :"<<endl;
        cin>>height;
    }
    void getHeight(void){
        cout<<"height :"<<height<<endl;
    }
    void calculateVolume(void){
        double voulme = pi*height*radius;
        cout<<"Voume of cylinder is :"<<voulme<<endl;
    }
};

int main()
{
    Cylinder c1;
    int x;
    do
    {
        cout<<"--------menu form------"<<endl;
        cout<<"x=1:default values no parameters:"<<endl;
        cout<<"x=2: pass parameters(set height):"<<endl;
        cout<<"x=3:pass parameters(set radius)"<<endl;
        cout<<"x=4:get parameters(get height)"<<endl;
        cout<<"x=5:get parameters(get radius)"<<endl;
        cout<<"x=6:cal voulme"<<endl;
        cout<<"x=0:exit"<<endl;
        cin>>x;

        
        switch (x)
        {
        case 1:
            {
                c1;
                c1.getHeight();
                c1.getRadius();
            break;
            }
            case 2:
            {
                c1.setHeight();
            break;
            }
            case 3:
            {
                c1.setRadius();
            break;
            }
            case 4:
            {
                c1.getHeight();
            break;
            }
        case 5:
            {
                c1.getRadius();
            break;
            }
        case 6:
            {
                c1.calculateVolume();
            break;
            }
        case 0:
            {
                cout<<"exit"<<endl;
            break;
            }
        default:
            {
                cout<<"enter  valid values"<<endl;
            break;
            }
        }
    } while (x!=0);
    
    return 0;
}