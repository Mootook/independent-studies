import math

def partA():
  portion_down_payment = 0.25
  current_savings = 0
  annual_salary = int(input("What is your starting annual salary?"))
  portion_saved = float(input("What percentage would you like to save each month?")) / 100
  total_cost = int(input("What is the cost of your dream home?"))
  months = 0
  while (current_savings < total_cost*portion_down_payment):
    months += 1
    current_savings = monthly_saving(annual_salary, current_savings, portion_saved)
    print(current_savings)
  print('At ', annual_salary, '/mo while saving', portion_saved, '% it will take you ', months, ' months to save up $', total_cost*portion_down_payment)

def monthly_saving(salary, savings, portion_to_save):
  # Add the monthly saved salary and roi at 4% each month
  new_savings = (savings + (salary * portion_to_save / 12)) + (savings * 0.04 / 12)
  return new_savings

def partB():
  portion_down_payment = 0.25
  current_savings = 0
  annual_salary = int(input("What is your starting annual salary? "))
  semi_annual_raise = float(input("What is your semi annual raise (as a decimal)? "))
  portion_saved = float(input("What percentage would you like to save each month? ")) / 100
  total_cost = int(input("What is the cost of your dream home? "))
  months = 0
  while (current_savings < total_cost*portion_down_payment):
    months += 1
    if (months % 6 == 0):
      annual_salary += annual_salary*semi_annual_raise
    current_savings = monthly_saving(annual_salary, current_savings, portion_saved)
    print(current_savings)
  print('At ', annual_salary, '/mo while saving', portion_saved, '% it will take you ', months, ' months to save up $', total_cost*portion_down_payment)

def partC():
  semi_annual_raise = 0.7
  annual_roi = 0.04
  down_payment_portion = 0.25
  total_cost = 1000000
  months_avail = 36
  threshold_margin = 100
  