Python 3.6.5 (v3.6.5:f59c0932b4, Mar 28 2018, 16:07:46) [MSC v.1900 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> 
>>> 
>>> def f1(x):
	return x**2

>>> f1(5)
25
>>> (lambda x: x**2)(5)
25
>>> list(range(10))
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> list(map(f1, list(range(10))))
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
>>> def f2(n):
	return 2 ** n

>>> list(map(f2, list(range(10))))
[1, 2, 4, 8, 16, 32, 64, 128, 256, 512]
>>> list(map(lambda n: 2**n, range(10)))
[1, 2, 4, 8, 16, 32, 64, 128, 256, 512]
>>> list(filter(lambda n: 2%n==0, range(20)))
Traceback (most recent call last):
  File "<pyshell#14>", line 1, in <module>
    list(filter(lambda n: 2%n==0, range(20)))
  File "<pyshell#14>", line 1, in <lambda>
    list(filter(lambda n: 2%n==0, range(20)))
ZeroDivisionError: integer division or modulo by zero
>>> list(filter(lambda n: n%2==0, range(20)))
[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
>>> from functools import reduce
>>> ns = list(range(1, 10+1))
>>> ns
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
>>> sum(ns)
55
>>> reduce(lambda x,y: x+y, ns)
55
>>> reduce(lambda x,y: x*y, ns)
3628800
>>> 
