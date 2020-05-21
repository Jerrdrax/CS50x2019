## Credit

### What is it?
* Program that validates if a credit card number is valid.

### Conditions:
* _American Express_ uses __15__-digit numbers
* _American Express_ numbers start with __34__ or __37__
* _MasterCard_ uses __16__-digit numbers
* _MasterCard_ numbers start with __51, 52, 53, 54, or 55__ (they also have some other potential starting numbers which we won’t concern ourselves with for this problem)
* _Visa_ uses __13__ and __16__-digit numbers
* _Visa_ numbers start with __4__  
### Checksum condition Luhn’s Algorithm
* Multiply every other digit by __2__, starting with the number’s __second-to-last digit__,
and then __add__ those products’ __digits together__.
* Add the __sum__ to the __sum__ of the digits that __weren’t__ multiplied by __2__.
* If the total’s last digit is __0__ (or, put more formally, if the total modulo __10__
is congruent to __0__), the number is valid!

## Example:
* Example with David’s Visa: __4003600000000014__.

`4-0-0-3-6-0-0-0-0-0-0-0-0-0-1-4`

Okay, let’s __multiply__ every other digits by __2__:  
`1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2`

That gives us:  
`2 + 0 + 0 + 0 + 0 + 12 + 0 + 8`

Now let’s __add__ those products’ digits (__Not__ the products themselves) together:  
`2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13`

Now let’s add that sum (__13__) to the sum of the digits that weren’t multiplied  
by __2__ (starting from the __end__):  
`13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20`

Yup, the last digit in that sum __(20)__ is a __0__,
so David’s card is legit!
