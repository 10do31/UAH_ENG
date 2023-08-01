// diamond.cpp

#include <iostream>
#include <cstdlib>
#include "diamond.h"

Diamond::Diamond(int v) : RedCard(v)
{
  Card:SetSuit('D');	
}

string Diamond::Description() const
{
  string S = " Suit = ";
  
  string C = " Color = ";
  
  return Card::Description() + "," + 
  C + Card::GetColor() + "," + S + Card::GetSuit();
}

