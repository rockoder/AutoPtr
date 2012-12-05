auto_ptr for VS 2005
======================

If you are using VS 2005, you probably already know that auto_ptr is broken 
in VS 2005. Refer comment section of below page for more details:
http://msdn.microsoft.com/en-us/library/ew3fk483%28v=vs.80%29.aspx

If for some reason you cannot use boost smart pointer or shift to VS 2008 
and above, you can use this implementation of auto_ptr.

Limitation:
============
ManagedPtrList is derived from std::list which does not have virtual destructor. Hence assigning ManagedPtrList to std::list to free the nodes should be avoided. To keep the rule simple: Avoid assigning ManagedPtrList to std::list. For more information, read guideline #4 of:
http://www.gotw.ca/publications/mill18.htm
