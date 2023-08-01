// heart.cpp

#include <iostream>
#include <cstdlib>
#include "heart.h"

Heart::Heart(int v) : RedCard(v)
{
  Card:SetSuit('H');	
}

string Heart::Description() const
{
  string S = " Suit = ";
  
  string C = " Color = ";
  
  
  return Card::Description() + "," + 
  C + Card::GetColor() + "," + S + Card::GetSuit();       
}

