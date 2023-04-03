Circling back to `std::unique_ptr`
=====================================


A `std:unique_ptr<A> ptr` wants to keep the following invariant:

> [Invariant] If `ptr` is not `nullptr`, there is only one `std:unique_ptr` that points to `*ptr`

which implies

> When `ptr` is destroyed, `*ptr` can be destroyed without the risk of multiple destructions of the same object. 


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


Goal of this exercice:
----------------------
In order to keep the invariant above, `std:unique_ptr<A>` disable copy altogether.  There is however another solution:
whenever the `unique_ptr` is copied, the pointed object is also copied automatically.

The goal of this exerciceis to implement a template class `uge::unique_ptr` that does exactly that.


The rule of five:
-----------------

Consider a class `MyClass` written by you.

Excluding the default constructor `MyClass()`, the compiler will generate 5 member-functions:
1. the destructor: `~MyClass()`
2. the copy-constructor: `MyClass(const MyClass&)`
3. the copy-assignment:  `MyClass& operator=(const MyClass&)`
4. the move-constructor: `MyClass(MyClass&&)`
5. the move-assignment: ` MyClass& operator==(MyClass&&)`

The *rule of five* states that these five functions should be consistent.  If you modify any of these, you need to consider if you need to reimplement any of the other.

Sometimes, it means doing nothing special, as below:
```C++
  MyClass(const MyClass&) = default;
```  
But you should at least think about them !



**If you are late, you may skip the remainder of exercice 2.**