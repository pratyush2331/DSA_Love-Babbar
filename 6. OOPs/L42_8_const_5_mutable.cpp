#include<iostream>
using namespace std;

class Zee
{
    int i;
    mutable int j;
    
    public:
    Zee()
    {
        i = 0; 
        j = 0;
    }
    
    void fool() const
    { 
        // i++;    // will give error
        j++;    // works, because j is mutable
    }
};

int main() {
    const Zee obj;
    obj.fool();
}