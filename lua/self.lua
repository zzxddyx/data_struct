
local test = {
    add = function(self, a, b)
        print(self.gSum)
        return a+b
    end,

    gSum = 0
}


print(test.add(test, 1, 43))
