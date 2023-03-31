Circling back to `std::unique_ptr`
=====================================


A `std:unique_ptr<A> ptr` wants to keep the following invariant:

> [Invariant] If `ptr` is not `nullptr`, there is only one `std:unique_ptr` that points to `*ptr`

which implies

> When `ptr` is detroyed, `*ptr` can be destroyed without the risk of multiple destruction of the same object. 


In order to keep the invariant above, `std:unique_ptr<A>` cannot be copied. However, it can be `moved`. 
Indeed, the line
```C++
std:unique_ptr<A> ptr2 = std::move(ptr1)
```
does two things:
- it makes `ptr2` points to `*ptr1` and 
- it makes `ptr1` equal to `nullptr`;
hence the invariant of `std::unique_ptr` is kept.


This is in line with the general *move semantics*: `ptr2` was built by *stealing the content* of `ptr1`.


Another solution would be to copy the pointed object automatically, which is the goal of to tests 21 to 34.
If your not, you may skip the remainder of exercice 2.