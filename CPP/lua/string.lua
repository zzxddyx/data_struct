
-- 字符串保存在lua状态机有两种形式,短字符串和长字符串
-- 字符串一旦创建，则不可被改写。Lua的值对象若为字符串类型，则以引用方式存在。属于需被垃圾收集器管理的对象。也就是说，一个字符串一旦没有被任何地方引用就可以回收它。
-- 在 lua 中，字符串实际上是被内化的一种数据。内化指的是每个存放lua字符串的变量，实际上存放的并不是一份字符串数据的副本，而是这份字符串数据的引用。在这个理念下，每当新创建一个字符串时，首先都会去检查当前系统中是否已经有一份相同的字符串数据了。如果有的话直接复用，将直接指向这个已经存在的字符串，否则就重新创建出一份新的字符串数据。
--主要用到两个数据
--  字符串长度；
--  指向存放字符串内存数据的指针；
--
--  创建一个新字符串的过程：
--  （1）计算需要新创建的字符串对应的散列值；
--  （2）根据散列值找到对应的散列桶，遍历该散列桶的所有元素，如果能够查找到同样的字符串，说明之前已经存在相同的字符串，此时不需要重新分配一份新的字符串数据，直接返回即可。
--  （3）如果第（2）步没有找到相同的字符串，调用luaS_newlstr函数创建一个新的字符串。具体代码：
--
--
--字符串在lua中是一个不可变的数据，改变一个字符串变量的数据不会影响原来字符串的数据。所以尽量少使用字符串连接操作符，因为每次都会生成一个新的字符串。可以使用 table来模拟字符串缓冲区，避免了大量使用连接操作符，大大提升性能，table.concat()。
local str = "Hello Jack"

