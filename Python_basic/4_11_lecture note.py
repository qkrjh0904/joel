Python 3.6.4 (v3.6.4:d48eceb, Dec 19 2017, 06:54:40) [MSC v.1900 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> a= [1,2,3]
>>> print(a)
[1, 2, 3]
>>> hippo = ['Life','is','shorty']
>>> print(hippo)
['Life', 'is', 'shorty']
>>> hippo=['Life','is','short']
>>> print(hippo)
['Life', 'is', 'short']
>>> r = range(1,10,2)
>>> type(r)
<class 'range'>
>>> ns = list(r)
>>> type(ns)
<class 'list'>
>>> print(ns)
[1, 3, 5, 7, 9]
>>> print(r)
range(1, 10, 2)
>>> ms=list(range(10))
>>> print(ms)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> hippo[0]
'Life'
>>> hippo[0]='Art'
>>> hippo
['Art', 'is', 'short']
>>> hippo[0:1]
['Art']
>>> hippo[0:1]=[]
>>> hippo
['is', 'short']
>>> hippo[0:0]
[]
>>> hippo
['is', 'short']
>>> hippo[0:0]=['Art','is','long','and','life']
>>> hippo
['Art', 'is', 'long', 'and', 'life', 'is', 'short']
>>> len(hippo)
7
>>> for n in range(5):
	print(hippo[n])

	
Art
is
long
and
life
>>> for n in range(len(hippo)):
	print(hippo[n])

	
Art
is
long
and
life
is
short
>>> mys = 'program'
>>> mys.count('r')
2
>>> mys.count('m')
1
>>> longs = 'This is a line'
>>> longs
'This is a line'
>>> longs.split()
['This', 'is', 'a', 'line']
>>> longs.split(sep='i')
['Th', 's ', 's a l', 'ne']
>>> ss = longs.split()
>>> ss
['This', 'is', 'a', 'line']
>>> ' '.join(ss)
'This is a line'
>>> '_'.join(ss)
'This_is_a_line'
>>> '*****'.join(ss)
'This*****is*****a*****line'
>>> 
