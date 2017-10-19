"""
THIS PROGRAM WILL CALCULATE YOUR TOTAL BILL AFTER PROVIDING THE INITIAL AMOUNT, TAXES, 
AND DESIRED TIP. WRITTEN BY MASON FISH.
"""

def main():
    print("Welcome to the taxes and tip calculator!")
    x = input("What is the price before tax? ")
    y = input("What are the taxes? (in %) ")
    z = input("What do you want to tip? (in %) ")

    # CALCULATES THE TOTAL, FIRST BY CONVERTING A PERCENTAGE INTO A MORE MATH FRIENDLY FLOAT,
    # THEN IT DETERMINES THE AMOUNT OF THE TAX AND ADDS TO THE ORIGINAL PRICE.
    total = x + (x * (y * .01))
    # THEN, IT PROVIDES THE SAME OPERATION ON THE TIP BUT WITH THE NEW TOTAL (AND UPDATES
    # THE TOTAL AGAIN).
    total += total * (z * .01)

    # FINALLY WE FORMAT THE OUTPUT TO MATCH THE CONSTRAINTS SET BY THE ASSIGNMENT (SO THAT IT
    # PRINTS WITH WITH A PRECISION OF 6 PLACES.
    print("The price you need to pay is: ${0:0.6f}.".format(total))

main()
