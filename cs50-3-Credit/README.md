## Credit

### What is it?
* Program that validates if a credit card number is valid.

### Conditions:
* ___American Express___ uses ***15***-digit numbers
* ___American Express___ numbers start with ***34*** or ***37***
* ___MasterCard___ uses ***16***-digit numbers
* ___MasterCard___ numbers start with ***51, 52, 53, 54, or 55*** (they also have some other potential starting numbers which we won’t concern ourselves with for this problem)
* ___Visa___ uses ***13*** and ***16***-digit numbers
* ___Visa___ numbers start with ***4***  
### Checksum condition Luhn’s Algorithm
* Multiply every other digit by ***2***, starting with the number’s ***second-to-last digit***,
and then ***add*** those products’ ***digits together***.
* Add the ***sum*** to the ***sum*** of the digits that ***weren’t*** multiplied by ***2***.
* If the total’s last digit is ***0*** (or, put more formally, if the total modulo ***10***
is congruent to ***0***), the number is valid!

## Example:
* Example with David’s Visa: ***4003600000000014***.

4-0-0-3-6-0-0-0-0-0-0-0-0-0-1-4  

Okay, let’s multiply every other digits by ***2***:  
1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:  
2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (***Not*** the products themselves) together:  
2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (***13***) to the sum of the digits that weren’t multiplied  
by ***2*** (starting from the ***end***):  
13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum ***(20)*** is a ***0***,
so David’s card is legit!
