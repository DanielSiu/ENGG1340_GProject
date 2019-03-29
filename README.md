# ENGG1340 Group Project
#### Group Members: 3035377828 (Cheung Yan Chak), 3035566871 (Siu Choi Hei)

**Problem Statement:**
> For long the efficiency in Supermarkets cashiers have been doubted and have caused supermarket to lose part of it profit. There is no specific formula to calculate the best ratio between number of cashiers to customers which will minimize the waiting time for each customer while maintain a reasonable profit with minimal amount of cashiers needed.

**Problem Setting:**
- Given:
  - A supermarket
  - Grocery types, price and amount
  - Maximum number of cashier availiable
  - Activation fee of one cashier
  - Process time of one grocery and transaction
  - Maximum waiting time for each customer
  
- Assumption:
  - The efficiency of each cashier is the same
  - The processing time of each individual grocery item is the same
  - The maximum quantity of grocery the customer will buy is 25 items
- Goal:
  - Calculate a minimum number of cashiers needed to produce maximum profit based on number of customers and number of groceries of each customer
  - Shorten the waiting for each customer waiting for the line of cashiers
  - Create a back-end environment to link all cashiers into a big system for data processing


**Program Features:**
- Randomly generate customer infomation (groceries) into a txt file 
- Calculate the price and time spent on each customer at the cashier
- Sort the customers automatically into each cashier
- Calculate the optimal number of cashiers needed 
- Create an extra line which is specically for customers buying 5 or less grocery items.

