# ENGG-1340-Group-Project
Members: Shandilya Priyansh, Soin Manik

# Problem Statement
Building a check-out system for a bakery so as to improve product sales by improving efficiency and cutting down on processing time all the while not compromising on the size of the product catalogue. Another goal of our program would be to keep a record of all the sales made by the bakery in an attempt to improve accountability of the store and provide a sound database of all transactions, which can help the store in two ways:
1. Dealing with customer complaints:
   If and when any customer has any complaint regarding the bakery's service, keeping a record will help us pinpoint the particular          transaction and help us deal with the matter as swiftly as possible. 
2. Accountability:
   If the institution ever finds itself in the crosshairs of a dispute, having a database of all the transactions made by business            may play a key role in proving its innocence or lack thereof.

And the last problem we identify is that a lot of mom-and-pop stores in several parts of the world still have not adopted checkout systems for their enterprises due to a multitude of factors, the most pressing of them being their lack of understanding of the complicated software that goes into checkout systems and an aversion to change. We believe that if we develop a simpler alternative to the one existing, akin to the code that we shall be submitting, more and more such stores would like to adapt our checkout systems and modernise, which will result in overall greater efficiency and customer satisfaction, but increasing digital literacy among smaller businesses

# Functionality of Program
When first started, upon pressing enter the program will prompt the user to add prodcuts to the menu database. This can only be done through the Admin menu.
 # Encryption and Safety Measure
 If the user chooses to go to the Admin menu. They will be asked for their name and unique 3 digit ID given to each employee. Failure in    being able to submit either will result in the message 'Access Denied' appearing on screen and the program, assuming foul play, will shut itself off. The list of employees and their IDs, 'EmployeeList.txt' can be modified as per requirement ie when new employees are hired or old ones are relieved of their duties thus creating an employee database and protecting the system via encryption.
 
 # Admin Menu
 Uppon being granted access to the Admin menu, the employee can add an item to the menu (upon which they'll be prompted to enter the details of the item before it is displayed on the Customer Menu and added to a binary file 'DUKES.DAT''for creation of database), remove an item from the menu or choose to reset the menu entirely depending upon the real-time scenario of the stock of products available in the bakery.
 
 # Effective Checkout System
 Once items have been added to the menu, the customer can order items they choose to purchase off of it by using the 'Place Order' option. Upon doing so, they'll be asked to enter the specifics of their order. Once they are done doing so, they'll be prompted if they'd like to add more items to their order. Once they are done adding items to their order, an invoice will be displayed and the customers can pay accordingly. As we have said in our introduction, we wish to target local mom-and-pop stores in developing nation, we used our own as an example (India), and the Goods & Services Tax is added to the price accordingly. 
 
 # Record Keeping And Accountability
 Once the customer has paid for their order, upon pressing 'Enter' on the program, not only are we redirected to the Customer Menu, but an order number is generated for the previous order depending upon the price and the number of different items ordered and is saved in a separate text file ('LinkedList.txt') using linked list in order to keep a record of all the sales and the number of distinct items sold, thus accomplishing our initial vision for this program.
 

 
 
 
 
  
 
  
  
  
  
  
  
