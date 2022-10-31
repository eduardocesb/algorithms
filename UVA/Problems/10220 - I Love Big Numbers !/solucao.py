N = 1001
facto = [1]*N
for i in range(2, N):
	facto[i] = facto[i-1] * i

while True:
	try:
		n = int(input())
		digit_sum = 0
		for digit in str(facto[n]):
			digit_sum += int(digit)	
		print(digit_sum)
	except EOFError:
		break
