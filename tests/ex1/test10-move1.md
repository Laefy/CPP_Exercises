Move Semantics
===============

C++ has a special kind of reference (denoted &&) called *r-value reference*.
While the usual reference (denoted with a single &) is actually called *l-value reference*.

First toy example
------------------

Let us take the following code as example.
```C++
void my_function(std::string&& s)
{
  // Something the 
}
void my_function(std::string const& s)
{
  // Something
}

int main () 
{
  std::string hello = "Hello world";
  my_function(std::move(hello)); // we use std::move() to make a r-value reference.
}
```
A &&-reference is like a &-reference but with the extra meaning that the referenced object (`s`) is unimportant to the caller (`main`), often because it is about to be deleted.
C++ uses the &&-reference to implement *move semantics* meaning that the called function (`my_function`) is allowed to *steal the content* of the argument.

Here for instance, 
- nothing happens in `main` after the call to `my_function` hence the string `hello` will be destroyed anyway; 
- the program has two versions of `my_function`, one uses the type `std::string&&` meaning that `my_function` can benefit from stealing the content of the passed `std::string`

Hence, it makes sense to choose the version `my_function` using &&-reference.


Real example: concatenation of `std::list`
------------------------------------
The strengh of `std::list` is that concatenation may be done in constant time. Indeed `std::list` is a doubly-linked list hence consider the two lists below.

- `list1=`  null <-> 0 <-> 1 <-> 2 <-> null
- `list2=`  null <-> 4 <-> 5 <-> 6 <-> null

Their concatenation is

- null <-> 0 <-> 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> null

and can be done by 

- changing the forward pointer of 2 to 4
- changing the backward pointer from 4 to 2.

The problem is that, in the end, we have only one list.  C++ solves this problem by using *move semantics* and an *r-value reference* in the function-member `std::list::splice`.
It is defined as
```C++
  void splice( const_iterator pos, list&& other ); 
```
in [this page](https://en.cppreference.com/w/cpp/container/list/splice).

The meaning here is that the object `*this` will *steal the content* of `other` to concatenate it at the end of `*this`.

Look and execute [test11](test11-splice.cpp) for an example.



