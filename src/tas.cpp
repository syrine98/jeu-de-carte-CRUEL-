#include "tas.h"
#include<string>
#include<stack>
#include"carte.h"
using namespace std;
tas::tas()
{

}
void tas::permuter() 
    if(t.size()>1)
    {
        carte c1=t.top();
        t.pop();
        carte c2=t.top();
        t.pop();
        t.push(c1);
        t.push(c2);
    }

}
tas::~tas()
{

}

