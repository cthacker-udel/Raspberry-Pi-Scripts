import itertools
import math

def __init__(self):
    self.name = 'Edabit practice'

def __str__(self):
    return self.name

def should_sub(aStr):

    if len(aStr) == 1 and aStr == 'x':
        return 'ecks'
    elif len(aStr) > 1:
        if aStr[0] == 'x':
            return 'z'+aStr[1:].replace('x','cks')
        else:
            return aStr.replace('x','ecks')

def x_pronounce(aStr):

    return [should_sub(y) for y in [x for x in aStr.split(' ')]]


x_pronounce("Inside the box was a xylophone")


def party_people(people):

    if len(people) == 0:
        return 0
    else:
        for i in range(len(people)):
            if people[i] > len(people):
                del people[i]
                return party_people(people)
        return len(people)


party_people([10, 12, 15, 15, 5])


def str_match_by2char(str1,str2):

    count = 0
    for i in range(min(len(str1),len(str2))-1):
        if (str1[i]+str1[i+1]) == (str2[i]+str2[i+1]):
            count += 1
    return count


str_match_by2char('jjcAAzz', 'jjBAAz')

def lucky_seven(arr):

    result = [x for x in itertools.permutations([x for x in set(arr)],3)]
    return True in [x[0]+x[1]+x[2] == 7 for x in result]


print(lucky_seven([0, 0, 0, 2, 3]))


def sums_up(arr):

    pairs = []
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if (arr[i] + arr[j]) == 8:
                pairs.append([arr[i],arr[j]])
    print(pairs)

print(sums_up([1, 2, 3, 4, 5]))# {"pairs": [[3, 5]]})
print(sums_up([10, 9, 7, 2, 8]))# {"pairs": []})
print(sums_up([1, 6, 5, 4, 8, 2, 3, 7]))# {"pairs": [[2, 6], [3, 5], [1, 7]]})
print(sums_up([5, 7, 2, 3, 0, 1, 6, 4, 8]))# {"pairs": [[3, 5], [1, 7], [2, 6], [0, 8]]})
print(sums_up([10, 9, 7, 1, 8, -2, -1, 2, 6]))# {"pairs": [[1, 7], [-2, 10], [-1, 9], [2, 6]]})
print(sums_up([0, 1, -2, 7, 9, 5, 4, 10, 8, -1, 6]))# {"pairs": [[1, 7], [-2, 10], [0, 8], [-1, 9]]})
    

def split_bunches(objArr):

	objects = []

	for eachobj in objArr:
		value = eachobj['quantity']
		title = eachobj['name']
		if value == 1:
			objects.append(eachobj)
		else:
			tmpval = 0
			while tmpval < value:
				objects.append({'name': title, 'quantity': 1})
				tmpval += 1
	return objects


split_bunches([
  { "name": "currants", "quantity": 1 },
  { "name": "grapes", "quantity": 2 },
  { "name": "bananas", "quantity": 2 }
])

def BMR(person):

	exerciseCriteria = person['sport']

	# first calc BMR

	bmr = 0

	if person['gender'] == 'male':
		bmr = 66.47 + (13.75 * person['weight']) + (5.003 * person['height']) - (6.755 * person['age'])
	else:
		bmr = 655.1 + (9.563 * person['weight']) + (1.85 * person['height']) - (4.676 * person['age'])
	
	totalCalorie = 0
	if exerciseCriteria == 1:
		totalCalorie = bmr * 1.2
	elif exerciseCriteria == 2:
		totalCalorie = bmr * 1.375
	elif exerciseCriteria == 3:
		totalCalorie = bmr * 1.55
	elif exerciseCriteria == 4:
		totalCalorie = bmr * 1.725
	elif exerciseCriteria == 5:
		totalCalorie = bmr * 1.9
	return round(totalCalorie,1)


print(BMR({
  "gender": "female",
  "height": 170,
  "weight": 65,
  "age": 25,
  "sport": 5
}))

def decimal_part(number):

	if '.' not in str(number):
		return 0

	return '0' + '.' + str(number).split('.')[1]

print(decimal_part(1.2))


def collect(aStr,num):
	aList = []
	if len(aStr) < num:
		return ''
	else:
		aList.append(aStr[0:3])
		result = collect(aStr[num:],num)
		if result != '':
			for eachpart in result:
				aList.append(eachpart)
		return sorted(aList)

collect("strengths", 3)
#["eng", "str", "ths"]


def bingo_check(board):
	bingoSet = []
	for i in range(len(board)):
		for j in range(len(board)):
			try:
				## checks up and down
				for x in range(len(board)):
					bingoSet.append(board[x][i])
				if len(set(bingoSet)) == 1 and len(bingoSet) == 5:
					## found
					return True
			except:
				print('')
			if len(set(bingoSet)) == 1 and len(bingoSet) == 5:
				return True
			else:
				bingoSet = []
			try:
				## check right and left
				for x in range(len(board)):
					bingoSet.append(board[i][x])
			except:
				print('')
			if len(set(bingoSet)) == 1 and len(bingoSet) == 5:
				return True
			else:
				bingoSet = []
			try: #[1][2], [2][3], [3][4]
				## check topleft --> bottom right diagonals
				for x in range(i,len(board)):
					bingoSet.append(board[x][x])
			except:
				print('')
			if len(set(bingoSet)) == 1 and len(bingoSet) == 5:
				return True
			else:
				bingoSet = []
			try: #[1][2], [2][1], [3][0]
				ind = i
				for x in range(j,-1,-1):
					bingoSet.append(board[ind][x])
					ind += 1
			except:
				print('')
			if len(set(bingoSet)) == 1 and len(bingoSet) == 5:
				return True
		bingoSet = []
	return False

print(bingo_check([
	[45, "x", 31, 74, 87],
	[64, "x", 47, 32, 90],
	[37, "x", 68, 83, 54],
	[67, "x", 98, 39, 44],
	[21, "x", 24, 30, 52]
]))

print(bingo_check([
	["x", 43, 31, 74, 87],
	[64, "x", 47, 32, 90],
	[37, 65, "x", 83, 54],
	[67, 98, 39, "x", 44],
	[21, 59, 24, 30, "x"]
]))#)

print(bingo_check([
	[37, 16, 84, 51, 33],
	[64, 12, 47, 32, 90],
	["x", "x", "x", "x", "x"],
	[67, 19, 98, 39, 44],
	[21, 75, 24, 30, 52]
]))#)

print(bingo_check([
	[45, "x", 31, 74, 87],
	[64, 78, "x", "x", 90],
	[37, "x", 68, "x", 54],
	[67, "x", 98, "x", "x"],
	[21, "x", 24, 30, 52]
]))#, False)

print(bingo_check([
	[45, 46, 31, 74, "x"],
	[64, 78, 80, "x", 90],
	[37, 81, "x", 55, 54],
	[67, "x", 98, 34, 77],
	["x", 33, 24, 30, 52]
]))#)