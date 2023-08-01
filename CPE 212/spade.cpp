// spade.cpp

#include <iostream>
#include <cstdlib>
#include "spade.h"

Spade::Spade(int v) : BlackCard(v)
{
  Card:SetSuit('S');	
}

string Spade::Description() const
{
  string S = " Suit = ";
  
  string C = " Color = ";
  
  return Card::Description() + "," + 
  C + Card::GetColor() + "," + S + Card::GetSuit();
}
