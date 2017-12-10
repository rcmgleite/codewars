For building the encrypted string:
Take every 2nd char from the string, then the other chars, that are not every 2nd char, and concat them as new String.
Do this n times!

Examples:

```
"This is a test!", 1 -> "hsi  etTi sats!"
"This is a test!", 2 -> "hsi  etTi sats!" -> "s eT ashi tist!"
```

Write two methods:

```
std::string encrypt(std::string text, int n)
std::string decrypt(std::string encryptedText, int n)
```

For both methods:
If the input-string is null or empty return exactly this value!
If n is <= 0 then return the input text.
