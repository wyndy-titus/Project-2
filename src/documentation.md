1.  Redefine CDAccount from Display 10.1 so that it is a class rather than a
    structure. use the same member variables as in Display 10.1 but make
    them private. Include member functions for each of the following: one to
    return the initial balance, one to return the balance at maturity, one to re-
    turn the interest rate, and one to return the term. Include a constructor that
    sets all of the member variables to any specified values, as well as a default
    constructor. Embed your class definition in a test program.

```cpp
// Structure for a bank certificate of deposit
struct CDAccount
{
    double balance;
    double interestRate;
    int term; // months until maturity
};
```


2.  Redo your definition of the class CDAccount from Practice Program 1 so
    that it has the same interface but a different implementation. The new
    implementation is in many ways similar to the second implementation for
    the class BankAccount given in Display 10.7. Your new implementation for
    the class CDAccount will record the balance as two values of type int: one
    for the dollars and one for the cents. The member variable for the interest
    rate will store the interest rate as a fraction rather than as a percentage. For
    example, an interest rate of 4.3% will be stored as the value 0.043 of type
    double. Store the term in the same way as in Display 10.1.