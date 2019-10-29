Program will manage Real Estate Consultants who are working for ABC real estate firm.
There are 5 consultants working for ABC company.  Each consultant has: name (string),  array of portfolios (at most 10), number  of portfolios (int). Each portfolio has a name (string), type (either R for rental or S for sale), category (B for a building, H for a house, S for a store), price (double), number of visitors (int).  Define structures for a portfolio and for a consultant.
Your program will read from “ABC.txt” file which stores  consultant name, portfolio info (name, type, category,  price, number of visitors) values which are separated by “/” character on each line into an array of structures.

Program will display the following menu and perform the requested operations continuously until user chooses to quit.

Choose 1,2,3,4,5, 6, 7, 8:
1. Read Portfolio Data
2. Find portfolio
3. Insert portfolio
4. Print List of Consultant’s portfolio
5. Print List of  specific portfolio category
6. Sort portfolios based on number of visitors
7. Find most expensive portfolio of a consultant
8. Quit

When user chooses to quit, the program will output all the consultant information to “output.txt file”.
Program will contain the following functions:

readData() : reads content of the input file into an array of consultant structures and returns it to the calling function
findPortfolio() : inputs consultant name and portfolio name from user and finds and returns the portfolio to the calling function
insertPortfolio() : inputs consultant name and portfolio information  from user and inserts it to the portfolio list of that consultant and returns it to the calling function.
printConsultantPortfolioList() : receives an array of consultants, inputs consultant name from user and outputs all portfolio information of the required consultant on the screen.
printPortfolio() : receives an array of consultants, inputs portfolio category ( B or H or S) from user and outputs all portfolio information of the required portfolio type on the screen.
sortPortfoliosP() : receives an array of portfolio structures and sorts it based on  price information in descending order and returns the updated array to the calling function
findMost EXpensivePortfolio() : receives an array of consultant structures and inputs consultant name from user. It will find and return the most expensive portfolio information to the calling function
outFile() : receives a consultant structure and writes all porfolio information into the output file “output.txt”.

