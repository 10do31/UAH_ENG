// redcard.cpp

#include <iostream>
#include <cstdlib>
#include "redcard.h"


RedCard::RedCard(int v) : Card(v)
{
  Card::SetColor("red");	
}

string RedCard::Description() const
{
  string C = " Color = ";
  
  return Card::Description() + "," 
  + C + Card::GetColor(); 
}


