#include <iostream>
#include <typeinfo>
using namespace std;

class Product{
    protected: 
    int id;
    string title;
    int price;
    float bill;
    public:
    Product(void):id(0),title(" "),price(0){ }
    Product(int id,string title,int price):id(id),title(title),price(price){  }
    virtual void setValues(void) =0;
    virtual void printRec(void)=0;
    virtual float displayBill(void) =0;//read only
    virtual ~Product() { }

};

class Book:public Product{
    string author;
    public:
    Book(void):Product(),author(" "){}
    Book(int id,string title,int price,string author):Product(id,title,price),author(author){ }
    void setValues(void) override{
        cout<<"Enter the id :";
        cin>>this->id;
        cout<<"Enter the title :";
        cin>>this->title;
        cout<<"Enter the author :";
        cin>>this->author;
        cout<<"Enter the price";
        cin>>this->price;
    }
    float displayBill(void) override{
        cout<<"Book Bill after discount :"<<this->price-(this->price*0.05);
        return this->price-(this->price*0.05);
    }
    void printRec(void){
        cout<<"author :"<<author<<",id :"<<id<<",title :"<<title<<",price :"<<price<<endl;
    }

};

class Tape:public Product{
    string artist;
    public:
    Tape(void):Product(),artist(" "){}
    Tape(int id,string title,int price,string artist):Product(id,title,price),artist(artist){ }
    void setValues(void) override{
        cout<<"Enter the id :";
        cin>>this->id;
        cout<<"Enter the title :";
        cin>>this->title;
        cout<<"Enter the artist :";
        cin>>this->artist;
        cout<<"Enter the price";
        cin>>this->price;
    }
    float displayBill(void){
        cout<<"Tape Bill :"<<this->price-(this->price*0.10);
        return this->price-(this->price*0.10);
    }
    void printRec(void){
        cout<<"artist :"<<artist<<",id :"<<id<<",title :"<<title<<",price :"<<price<<endl;
    }


};
void acceptChoice(Product *product){
    if(typeid(*product)==typeid(Tape)){
        Tape *tape =(Tape*) product;
    }
    else if (typeid(*product)==typeid(Book)){
        Book *book = (Book*)product;
    }
}

int menudriven(void){
    int choice;
    cout<<"________MENU DRIVEN________"<<endl;
    cout<<"0.exit "<<endl;
    cout<<"1.Books "<<endl;
    cout<<"2.Tapes"<<endl;
    cout<<"3.Total Bill"<<endl;
    cout<<"x:";
    cin>>choice;
    return choice;

}



int main() {
    Product* arr[3]={ nullptr};  // Single pointer to array of 3 Products
    int count=0;
    int choice;
    while (count<=3 && ((choice=menudriven())!=0))
    {
    switch (choice)
        {
             case 0:{
          cout<<"exit:"<<endl;
            break;
        }
        case 1:{
            arr[count]=new Book();
            arr[count]->setValues();
            count++;
            break;
        }
        case 2:{
            arr[count]=new Tape();
            arr[count]->setValues();
            count++;
            break;
        }
      case 3: {
    float totalbill=0;
    cout << "___total bill__ " << endl;
    for(int i=0;i<count;i++) {
        totalbill += arr[i]->displayBill();
        cout << endl;
    }
    cout << "Total Bill = " << totalbill << endl;
    break;   
}

        default:
        {
            cout<<"Enter valid values :"<<endl;
            break;
        }
        }
    }
        for(int i=0;i<3;i++){
        if (arr[i]!=NULL)
        {
            ::acceptChoice(arr[i]);
            cout<<endl;
            arr[i]->printRec();
            cout<<endl;
            arr[i]->displayBill();
            cout<<endl;
        }
    }
    for (int i = 0; i < count; i++) {
    delete arr[i];
}

    return 0;
}
