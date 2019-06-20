#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	//Declare variables
    double coffeePrice = 0, budget = 0;
    int numCouponsRequired = 0;
    int numCoffeesPurchased = 0, numStamps = 0, numFreeCoffees = 0;
    double budgetRemaining = 0, averageCoffeePrice = 0;
    
    //Prompt user for the price of one coffee
    printf("How much does a coffee cost?\n");
    scanf("%lf", &coffeePrice);
    
    //Ensure valid input of coffee price, terminate if invalid
    if (coffeePrice < 0.01) {
        printf("Invalid Input.\n");
        return 0;
    }//end of if
    
    //Prompt user for number of coupons required for a free coffee
    printf("How many coupons does it take to get a free coffee?\n");
    scanf("%d", &numCouponsRequired);
    
    //Ensure valid input of nuumber of coupons required, terminate if invalid
    if (numCouponsRequired <= 1) {
        printf("Invalid Input.\n");
        return 0;
    }//end of if
    
    //Prompt user for how much money will be put towards coffee this month
    printf("How much money do you have to spend on coffee this month?\n");
    scanf("%lf", &budget);
    
    //Ensure valid input for budget, terminate if invalid
    if (budget < 0) {
        printf("Invalid Input.\n");
        return 0;
    }//end of if
    
    //Compute number of coffees user can purchase this month
    numCoffeesPurchased = (int) (budget / coffeePrice);
    
    //Determine number of stamps user obtains from purchased coffees
    numStamps = numCoffeesPurchased;
    
    //Compute how many free coffees user redeems with stamps
    while (numStamps >= numCouponsRequired) {
        
        //Trade in required number of stamps for free coffee
        numStamps -= numCouponsRequired;
        numFreeCoffees ++;
        
        //Give the user a stamp for the free coffee
        numStamps ++;
    }//end of while loop
    
    //Determine the remaining budget
    budgetRemaining = fmod(budget, coffeePrice);
    
    //Compute average coffee price
    if (numCoffeesPurchased >= 1) {
        averageCoffeePrice = (budget - budgetRemaining) / (numCoffeesPurchased + numFreeCoffees);
    }//end of if
    
    
    //Output number of coffees user can purchase at purchase price
    printf("This month, you can purchase %d coffees at $%.2lf each.\n", 
        numCoffeesPurchased, coffeePrice);
    
    //Output the additional free coffees the user can redeem
    if (numFreeCoffees == 0) {
        printf("You will not be able to redeem any additional coffees from coupons this month.\n");
    }//end of if
    else {
        printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", numFreeCoffees);
    }//end of else
    
    //Output user's remaining budget and remaining stamps
    printf("At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n",
        budgetRemaining, numStamps);
    
    //Output average coffee price
    printf("On average, you spent $%.2lf on each cup of coffee this month.\n", averageCoffeePrice);
    
	return 0;
}
