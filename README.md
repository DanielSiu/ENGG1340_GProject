# Solution for every Supermarket
### ENGG1340 Group Project :+1:
#### Group Members: 3035377828 (Cheung Yan Chak), 3035566871 (Siu Choi Hei)

**Problem Statement:**
> For long the efficiency in Supermarkets cashiers have been doubted and have caused supermarkets to lose part of its profit. Currently, there is no specific formula to calculate the best ratio between the number of cashiers to customers. The formula could minimize the waiting time for each customer while maintaining a reasonable profit with minimal cashiers needed.

**Problem Setting:**
- Given:
  - A supermarket
  - Grocery types, price and amount
  - Maximum number of cashier availiable
  - Activation fee of one cashier
  - Process time of one grocery and payment transaction
  - Maximum waiting time for each customer
  
- Assumption:
  - The efficiency of each cashier is the same
  - The processing time of each individual grocery item is the same
  - The maximum quantity of grocery the customer will buy is 30 items

- Goal:
  - Calculate a minimum number of cashiers needed to produce maximum profit based on number of customers and number of groceries of each customer
  - Shorten the waiting time for each customer by creating lines of cashiers
  - Create a back-end environment to link all cashiers into a big system for data processing


**Program Features:**
- [x] Randomly generate customer infomation (groceries) into a txt file 
- [x] Calculate the price and time spent on each customer at the cashier
- [x] Sort the customers automatically into each cashier
- [x] Calculate the optimal number of cashiers needed 
- [x] Create an extra line for customers buying 5 grocery items or less.