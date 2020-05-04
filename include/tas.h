#ifndef TAS_H
#define TAS_H
#include<string>
#include<stack>
#include"carte.h"

class tas
{
    public:
        tas();
        ~tas();
        void permuter();


    private:
        std::stack<carte> t;
        friend class jeu;

};

#endif // TAS_H

