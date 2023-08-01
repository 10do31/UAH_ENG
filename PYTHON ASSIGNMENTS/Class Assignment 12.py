# Class Assignment 12
# Dan Otieno
# ENG 101-02
# Due Date 11/01/2019
#
#
#STOCK:
stock = {"tomato soup":20, "cheese":10, "bread":3, "milk":1, "butter":7, "coffee":8, "ice cream":5, "orange juice":12, "bacon":2, "tortilla chips":4, "ramen":20}
#PRICE:
prices = {"tomato soup":1.85, "cheese":3.99, "bread":2.50, "butter":1.99, "milk":3.59, "coffee":5.99, "ice cream":2.99, "orange juice":2.50, "bacon":5.49, "tortilla chips":3.99, "ramen":0.99}
#
def grocery_cost(food):
    total_cost = 0
    for i in prices:
        if i in food:
            if stock[i] > 0:
                total_cost += prices[i]
                stock[i] = stock[i]-1
    return total_cost

def stockcount():
    for key in stock:
        print("\t", key, stock[key])

food = ["butter", "coffee"]
print('Total:', grocery_cost(food))

stockcount()

