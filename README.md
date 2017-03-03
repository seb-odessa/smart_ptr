# smart_ptr
valgrind ./main >> README.md 

A::A(a)
smart_ptr::smart_ptr(T*)
A::A(b)
smart_ptr::smart_ptr(T*)
smart_ptr::operator=(const smart_ptr&)
A::~A(b)
smart_ptr::~smart_ptr()
smart_ptr::operator=(const smart_ptr&)
smart_ptr::operator=(const smart_ptr&)
smart_ptr::smart_ptr(const smart_ptr&)
smart_ptr::smart_ptr(const smart_ptr&)
smart_ptr::smart_ptr(const smart_ptr&)
smart_ptr::operator=(const smart_ptr&)
smart_ptr::~smart_ptr()
smart_ptr::~smart_ptr()
smart_ptr::~smart_ptr()
smart_ptr::~smart_ptr()
A::~A(a)

==6999== Memcheck, a memory error detector
==6999== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==6999== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==6999== Command: ./main
==6999== 
==6999== 
==6999== HEAP SUMMARY:
==6999==     in use at exit: 72,704 bytes in 1 blocks
==6999==   total heap usage: 6 allocs, 5 frees, 76,896 bytes allocated
==6999== 
==6999== LEAK SUMMARY:
==6999==    definitely lost: 0 bytes in 0 blocks
==6999==    indirectly lost: 0 bytes in 0 blocks
==6999==      possibly lost: 0 bytes in 0 blocks
==6999==    still reachable: 72,704 bytes in 1 blocks
==6999==         suppressed: 0 bytes in 0 blocks
==6999== Rerun with --leak-check=full to see details of leaked memory
==6999== 
==6999== For counts of detected and suppressed errors, rerun with: -v
==6999== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)