## Substitution

* Implement a program that implements a substitution cipher.
### Example
```
'$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ'
plaintext:  HELLO
ciphertext: VKXXN
```

### Conditions
* Gets a 26 characters key from the command line argument.

* Only substitute alphabetical characters!

* Lowercase letters remain lowercase, and uppercase letters remain uppercase.

* Whether the characters in the key itself are uppercase or lowercase doesn’t matter.

* A key of VCHPRZGJNTLSKFBDQWAXEUYMOI is functionally identical to a key of vchprzgjntlskfbdqwaxeuymoi (as is, for that matter, VcHpRzGjNtLsKfBdQwAxEuYmOi).

* Validates the user input.
