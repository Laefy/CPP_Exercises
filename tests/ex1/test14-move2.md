For optimisation, one must understand r-value references
=========================================================

The purpose of this file is to explain how r-value references are in fact, even if the type && never
appears anywhere in your code.

The move-constructor of `std::string`
--------------------------------------

Note that std::string enjoys a *move-constructor*:
```C++
std::string(std::string&& other) noexcept;
```
It is constructor 8 in [this page](https://en.cppreference.com/w/cpp/string/basic_string/basic_string) but is not written as above because std::string is actually an alias.  
The documentation says:

> Move constructor. Constructs the string with the contents of other using 
> move semantics. other is left in valid, but unspecified state.

However, the important part is *using move semantics* which means that **`other` is not copied**, its content is *stealed* into the newly created object

The typical class `Person`
---------------------------

Consider the class `Person1` below, and in [this file](../../lib/Person1.hpp). It corresponds to what we expected from you until now.
```C++
class Person1
{
public:
    Person(const std::string& name)
        : _name { name }
    {}

private:
    std::string _name;
};
```

Here are the four most common use-case that may arise:
```C++
/* == Case 1 == */
std::string youssef_bergeron_name{"Youssef Bergeron"};
Person1 yb{youssef_bergeron_name}; 

/* == Case 2 == */
std::string clement_chomicki_name = "Clément Chomicki" ;
Person1 cc{std::move(clement_chomicki_name)}

/* == Case 3 == */
Person1 vm{"Victor Marsault"};

/* == Case 4 == */
std::string celine = "Céline";
std::string noel= "Noël";
Person1 cn{celine+" "+noel};
```

In each of the following case:

- Q22.1 (Youssef):
  * a. Is the string `youssef_bergeron_name` copied to call `Person(const std::string& name)`?
  * b. Is it copied by `_name { name }` ?
  * c. Could copies be avoided somehow?
- Q22.2 (Clément):
  * a. Is the string `clement_chomicki_name` copied to call `Person(const std::string& name)`?
  * b. Is it copied by `_name { name }` ?
  * c. Could copies be avoided somehow?
- Q22.3 (Victor): 
  * a. What is the type of the expression `"Victor Marsault"`
  * b. Is it copied copied to call `Person(const std::string& name)`?
  * c. Is it copied by `_name { name }` ?
  * d. Could copies be avoided somehow?
- Q22.4 (Céline)
  * a. what is the type of the expression `celine+" "+noel` ?
  * b. Is it copied copied to call `Person(const std::string& name)`?
  * c. Is it copied by `_name { name }` ?
  * d. Could copies be avoided somehow?


[Optional] What about `std::string_view` ?
------------------------------------------

Consider the class `Person2` below, and in [this file](../../lib/Person2.hpp)
```C++
class Person2
{
public:
    Person2(std::string_view name)
        : _name { name }
    {}

private:
    std::string _name;
};
```

Recall that `std::string_view` is read-only because we want that

- the constructor `std::string_view(const char* cs)` does not need to copy the c-string `cs`
- the constructor `std::string_view(const std::string& s)` does not need to copy the content of `s`

but then

- the constructor `std::string(std::string_view sv)` must copy the c-string inside `sv`.
 

Q22.5: 
  * a. Which copy from above did it prevent?
  * b. Is there still too many copies in some cases?


Using the move semantics
------------------------

Consider the class `Person3` below, and in [this file](../../lib/Person3.hpp)
```C++
class Person3
{
public:
    Person3(std::string name)
        : _name { std::move(name) }
    {}

private:
    std::string _name;
};
```


Here are our four common use-cases again:
```C++
/* == Case 6 == */
std::string youssef_bergeron_name{"Youssef Bergeron"};
Person3 yb{youssef_bergeron_name}; 

/* == Case 7 == */
std::string clement_chomicki_name = "Clément Chomicki" ;
Person3 cc{std::move(clement_chomicki_name)}

/* == Case 8 == */
Person3 vm{"Victor Marsault"};

/* == Case 9 == */
std::string celine = "Céline";
std::string noel= "Noël";
Person3 cn{celine+" "+noel};
```

In each of the following case:

- Q22.6 (Youssef): How many copies ? 
- Q22.7 (Clément): How many copies ?
- Q22.8 (Victor): How many copies ?
- Q22.9 (Céline): How many copies ?


Q22.19: Can we do better?  
Spoiler: yes sometimes but it's outside the scope of this course.



Conclusion: 
-----------
Consider a some function, constructor, or function-member  `f` that takes a `SomeClass` in parameter.

- If `f` needs to store a copy of its argument; and
- If `SomeClass` is move-constructible (usually true, in most cases the compiler will provides a default move-constructor), 
- then it is usually better to pass the `SomeClass` by value.
```C++
void f(..., SomeClass some_object, ...)
{
  // We use `std::move(some_object)` when we need to store it
}
```