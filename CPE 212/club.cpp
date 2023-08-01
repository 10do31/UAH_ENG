// club.cpp

#include <iostream>
#include <cstdlib>
#include "club.h"

Club::Club(int v) : BlackCard(v)
{
  Card:SetSuit('C');	
}

string Club::Description() const
{
  string S = " Suit = ";
  
  string C = " Color = ";
  
  
  return Card::Description() + "," + 
  C + Card::GetColor() + "," + S + Card::GetSuit(); 
}


