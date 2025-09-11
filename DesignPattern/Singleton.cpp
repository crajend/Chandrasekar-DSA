#include <iostream>
using namespace std;

class Singleton {
private:
  static Singleton *instance;
  static int count;
  
  Singleton()
  {
    cout<<"Singleton instance created\n";  
  }

    
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  
public:
  
  static Singleton* getInstance(){
    if(instance == nullptr) {
      instance = new Singleton();
    }
      count++;
      return instance;
  }
  
  void showMessage(){
    cout<<count<<" : Hello from Singleton!"<<endl;
  }
};

Singleton *Singleton::instance = nullptr;
int Singleton::count =0;

int main() 
{
    Singleton* s1= Singleton::getInstance();
    s1->showMessage();
    
    Singleton* s2= Singleton::getInstance();
    s2->showMessage();
    
    Singleton* s3= Singleton::getInstance();
    s3->showMessage();
    
    Singleton* s4= Singleton::getInstance();
    s4->showMessage();
    
    Singleton* s5= Singleton::getInstance();
    s5->showMessage();
    
    Singleton* s6= Singleton::getInstance();
    s6->showMessage();
    
    Singleton* s7= Singleton::getInstance();
    s7->showMessage();
    
    Singleton* s8= Singleton::getInstance();
    s8->showMessage();
    
    cout<<((s1==s2)?"Same" : "Not Same" )<<endl;
    
    cout<<"s1 : "<<s1<<endl;
    cout<<"s2 : "<<s2<<endl;
    cout<<"s3 : "<<s3<<endl;
    cout<<"s4 : "<<s4<<endl;
    cout<<"s5 : "<<s5<<endl;
    cout<<"s6 : "<<s6<<endl;
    cout<<"s7 : "<<s7<<endl;
    cout<<"s8 : "<<s8<<endl;
    return 0;
}