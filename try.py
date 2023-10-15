# def generator_x():

#     num=1

#     while(num <5):

#         if num%2 == 0:

#             yield = num

#             num +=1

# print(next(generator_x()))

# def generator_x():
#     num = 1
#     while num < 5:
#         if num % 2 == 0:
#             yield num
#         num += 1

# # To use the generator, you need to create an instance of it
# gen = generator_x()

# # You can then use the next() function to get values from the generator
# print(next(gen))


# import itertools

# print(list (itertools.chain.from_iterable(zip(['a', 'b', 'c'], [1, 2, 3]))))

# string = "Python"
# print(string[::-1])

# a = 3
# b = 7
# c = (a << 2) | (b >> 1)
# print(c)


L = [2 * x for x in range(3,14,3)]
print(L)