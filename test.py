# You are given a string s.

# We define the mirror of a letter in the English alphabet as its corresponding letter when the alphabet is reversed. For example, the mirror of 'a' is 'z', and the mirror of 'y' is 'b'.

# Initially, all characters in the string s are unmarked.

# You start with a score of 0, and you perform the following process on the string s:

# Iterate through the string from left to right.
# At each index i, find the closest unmarked index j such that j < i and s[j] is the mirror of s[i]. Then, mark both indices i and j, and add the value i - j to the total score.
# If no such index j exists for the index i, move on to the next index without making any changes.
# Return the total score at the end of the process.

# s = "abzy"
# h = {a: [0,1], z: [2,3]}

# s = "aazz"