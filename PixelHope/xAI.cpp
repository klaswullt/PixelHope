#include "xAI.h"


#include <random>


/*

 
*/

void xAI::revaluate_nodes(int braincell,int input)
{
    int A, B, I, J;

    A = brain[1].onoff;

    B = brain[1].input[1]->link->onoff;

    I = braincell;
    J = input;


    for (int i = 0; i> braincell; i++)
    {
    if (A == 1 && B == 1)
    {

        brain[I].input[J]->positive *= 1.1;
        brain[I].input[J]->negative *= 0.9;
        brain[I].input[J]->neutral *= 0.9;

    }
    if (A == 0 && B == 0)
    {
       
        brain[I].input[J]->positive *= 0.9;
        brain[I].input[J]->negative *= 0.9;
        brain[I].input[J]->neutral *= 1.1;

    }

    if (A == 1 || B == 1 && A != B)
    {
        brain[I].input[J]->positive *= 0.9;
        brain[I].input[J]->negative *= 1.1;
        brain[I].input[J]->neutral *= 0.9;
    }

    brain->output[J]->positive *= brain->input[1]->positive;
    brain->output[J]->negative *= brain->input[1]->negative;
    brain->output[J]->neutral  *= brain->input[1]->neutral;

    }



}
void xAI::update()
{


    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 2);
    int roll_a = distribution(generator);  // generates number in the range 1..6 
    int roll_b = distribution(generator);  // generates number in the range 1..6 




    brain[1].output[1]->link->onoff = brain[1].output[1]->yes_or_no;
    brain[1].output[2]->link->onoff = brain[1].output[1]->yes_or_no;
    brain[1].output[3]->link->onoff = brain[1].output[1]->yes_or_no;
    brain[1].output[4]->link->onoff = brain[1].output[1]->yes_or_no;


     
    brain[1].output[roll_a]->link->onoff = brain[1].output[1]->yes_or_no;;


    //


}