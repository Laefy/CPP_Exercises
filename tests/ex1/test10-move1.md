Move Semantics
===============

C++ has a special kind of reference (denoted &&) called *r-value reference*,
while the usual reference (denoted with a single &) is called *l-value reference*.
It can be used as in the following function but should be understood even if it does not appear in your code.
```C++
void my_function(std::string&& s){
  // Body of my_function
}
```
A &&-reference is like a &-reference but with the extra meaning that the referenced object (by `s`) is unimportant to the caller (whoever called `myfunction`), often because it is about to be deleted.

C++ uses the &&-reference to implement *move semantics* meaning that
the called function (here `my_function`) is allowed to *steal the content* 
of the argument.

Example with concatenation of lists
------------------------------------

For instance, the strengh of `std::list` is that concatenation may be done in constant time.
Indeed `std::list` is a doubly-linked list hence if

> list1:  null <-> 0 <-> 1 <-> 2 <-> null
> list2:  null <-> 4 <-> 5 <-> 6 <-> null

then

> list1+list2: null <-> 0 <-> 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> null

can be done by 

- changing the forward pointer of 2 to 4
- changing the backward pointer from 4 to 2

However, in the end, we have only one list, hence we *destroyed* one of them.

It is implemented in the stl by the function-member `std::list::splice` thanks
to the *move semantics*.
It is defined as
```C++
  void splice( const_iterator pos, list&& other ); 
```
in [this page](https://en.cppreference.com/w/cpp/container/list/splice).

The meaning here is that the object `*this` will *steal the content* of `other`
to concatenate it at the end of `*this`.

Look and execute [test11](test11-splice.cpp) for an example.



