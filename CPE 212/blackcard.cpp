// blackcard.cpp

#include <iostream>
#include <cstdlib>
#include "blackcard.h"


BlackCard::BlackCard(int v) : Card(v)
{
  Card::SetColor("black");	
}

string BlackCard::Description() const
{
  string C = " Color = ";
  
  return Card::Description() + "," 
  + C + Card::GetColor();  
}
