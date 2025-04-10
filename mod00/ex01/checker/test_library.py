INT_MAX = 2147483647
INT_MIN = -2147483648

def test_library(lst_size):
	list_2 = [
		['10', '20'],
		['0', '-1'],
		['-1', '0'],
		['42', '-42']
	]

	list_3 = [
		['1', '2', '3'],
		['2', '3', '1'],
		['3', '1', '2'],
		['-10', '-1', '42'],
		['-500', '-1000000', '-1'],
		['-1', '0', '-2'],
		['0', '-4', '42']
	]

	list_max = [
		[str(INT_MAX), str(INT_MIN)],
		[str(INT_MIN), str(INT_MAX)],
		['0', str(INT_MAX), str(INT_MIN)],
		[str(INT_MAX), str(INT_MIN), '-42'],
		[str(INT_MIN), str(INT_MAX), '-42'],
		['-42', str(INT_MIN), str(INT_MAX)],
	]
	if lst_size == 2:
		return list_2
	elif lst_size == 3:
		return list_3
	elif lst_size == INT_MAX:
		return list_max