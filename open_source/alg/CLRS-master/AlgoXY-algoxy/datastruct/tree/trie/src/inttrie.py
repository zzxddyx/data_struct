#!/usr/bin/python

# inttrie.py, Integer base Trie.
# Copyright (C) 2010, Liu Xinyu (liuxinyu95@gmail.com)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import random

class IntTrie:
    def __init__(self):
        self.value = None
        self.left = self.right = None

def insert(t, key, value = None):
    if t is None:
        t = IntTrie()
    p = t
    while key != 0:
        if key & 1 == 0:
            if p.left is None:
                p.left = IntTrie()
            p = p.left
        else:
            if p.right is None:
                p.right = IntTrie()
            p = p.right
        key = key >> 1  # key / 2
    p.value = value
    return t

def lookup(t, key):
    while t is not None and key != 0:
        if key & 1 == 0:
            t = t.left
        else:
            t = t.right
        key = key >> 1
    return None if t is None else t.value

def from_list(kvs):
    t = None
    for k, v in kvs:
        t = insert(t, k, v)
    return t

def from_map(m):
    return from_list(m.items())

def test():
    def generate_map(size):
        m = {}
        xs = range(size);
        random.shuffle(xs)
        for i in xrange(size):
            m[i] = xs[i]
        return m
    sz = 100
    for i in xrange(sz):
        m = generate_map(random.randint(0, sz-1))
        t = from_map(m)
        for k, v in m.items():
            val = lookup(t, k)
            if v != val:
                print "lookup", k, "got", val, "!=", v, "t=\n", to_str(t)
                exit()
        for k in xrange(sz):
            if k not in m and lookup(t, k) is not None:
                print "lookup", i, "expected None, but get", lookup(t, i) ,to_str(t)
                exit()
    print "passed", sz, "cases"

if __name__ == "__main__":
    test()
