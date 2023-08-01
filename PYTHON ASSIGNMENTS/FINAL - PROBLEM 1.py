# Dan Otieno.
# Final- Problem 1
# ENG 101
# 12/10/2019.

# 1. Mortgage Function.

def monthlypmt(p,apr,yrs):
    """Computing monthly pmts for prin using ny and apr"""
    r = apr/1200    #Convert APR to monthly interest.
    n = yrs*12      #Total monthly pmts.
    comp = (1+r)**n #Compounding factor.
    payment = p*r*comp/(comp-1)  #Payment.
    return payment

# 2. Balance Updates.

def new_balance(bal,payment,r,months=60): #default pmts set to 5 years
    nwbal = bal                     #New balance becomes the starting balance.
    for k in range(0,months):       #npay is number of payments.
        nwbal = nwbal*(1+r)-payment   #Update balance each payment.
    return nwbal

# 3. Demonstrate results.

#Start by setting values.
p = 250000 #Loan amount of 100k
apr = 3     #APR 3%
yrs = 30      #Loan period 30 yrs.

pmt = monthlypmt(p,apr,yrs) #compute payment using function.

print('\nPrincipal Amount is: $',(p))
print('\nAPR rate (percentage) is:', (apr))
print('\nPayment in years:',(yrs))
print('\nMonthly payment amount: $',round(pmt, 2))

# 4. Computation and output for balances after 5 and 10 years.

bal_5thyr = new_balance(p,pmt,apr/1200)      #First 60 pmts
bal_10thyr = new_balance(bal_5thyr,pmt,apr/1200) #another 60 payments
print('\nBalance after 60 months: $',round(bal_5thyr, 2))
print('\nBalance after 120 months: $',round(bal_10thyr, 2))


