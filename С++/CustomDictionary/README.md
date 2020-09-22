# Custom Dictionary

This project contains single **Source.cpp** file
Project implements template dictionary container
Container may hold *[key: value]* pairs and allow addition and access to existing pairs

**Source.cpp** file contains **4** classes:

*(class MyDict)* is the main class that implements dictionary container
As base it uses *std::list* of *std::pairs*
Both *key* and *value* fields are template classes
Currently the dictionary is unoptimized and simply iterates through list to find needed key
In future project may be rewritten to use more optimized abstract datatype *(e.g. hash-table)*

**2 classes** are used for **testing** *(class A and class B)*
    
*(class MyException)* is used to throw **exceptions** during work of the main dictionary class
Exceptions get thrown in case *Get()* method can't find matching value
Exception contains one field that represents key, given to *Get()* method

When launched **Source.cpp** will run small demonstration tests