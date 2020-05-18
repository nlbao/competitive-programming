import itertools
from hashlib import sha256

# A_string = "hangbe"
B_string = "WHATEVER"
C_string = "uwant"
# C_string = "UWANT"


# The SHA256 hash of the whole string AAAAAA_BBBBBBBB_CCCCC (all letters are in uppercase) is: 753053aeae0d1a3fe33bd2cb31a901069873b8c37127b0d3757dd3a90313b526

target_hash = "753053aeae0d1a3fe33bd2cb31a901069873b8c37127b0d3757dd3a90313b526"

anagram = ["".join(perm) for perm in itertools.permutations("hangbe")]
anagram += ["".join(perm) for perm in itertools.permutations("HANGBE")]
anagram += ["".join(perm) for perm in itertools.permutations("leduan")]
anagram += ["".join(perm) for perm in itertools.permutations("LEDUAN")]
anagram += ["".join(perm) for perm in itertools.permutations("HANGBO")]
anagram += ["".join(perm) for perm in itertools.permutations("HANGGA")]
anagram += ["".join(perm) for perm in itertools.permutations("HANGMA")]
anagram += ["".join(perm) for perm in itertools.permutations("HANGCA")]
anagram += ["".join(perm) for perm in itertools.permutations("BATDAN")]
anagram += ["".join(perm) for perm in itertools.permutations("CHOGAO")]
anagram += ["".join(perm) for perm in itertools.permutations("GIANGU")]
anagram += ["".join(perm) for perm in itertools.permutations("HANGDA")]
# print(len(anagram))
# print(anagram[:10])

for s in anagram:
	full_string = s + "_" + B_string + "_" + C_string
	# print(full_string)
	# print(full_string.encode('utf-8'))
	hashedWord = sha256(full_string.encode('utf-8')).hexdigest()
	if hashedWord == target_hash:
		print(full_string)
		print(hashedWord)