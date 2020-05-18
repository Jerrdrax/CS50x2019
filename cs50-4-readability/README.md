## Readability

* Implement a program that computes the approximate grade level needed to
comprehend some text.

### Conditions:
* The Coleman-Liau index of a text is designed to output what (U.S.) grade level
 is needed to understand the text.

* The formula is:

'__Index = 0.0588 * L - 0.296 * S - 15.8__'
* __L__ is the average number of __LETTERS__ per 100 words in the text.
* __S__ is the average number of __SENTENCES__ per 100 words in the text.

* Grades from 1 to 16
* If the index number is less than 1, your program should output "Before Grade 1".
* If the  index number is 16 or higher your program should output "Grade 16+"

### Prints:
* Text:
* Grade
* Letters
* Words
* Sentences

### Defines:
* __LETTER:__ From a-z and A-Z. add ñ = 164, Ñ = 165.
* __WORD:__ Any sequence of characters separated by a space is to be a word.
* __SENTENCES:__ Sequence of characters that ends with a . or a ! or a ?.
