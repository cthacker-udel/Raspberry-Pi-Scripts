import itertools
import math
import re

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

def move_zeros(arr):

	zero_count = len([x for x in arr if (type(x) is int or type(x) is float) and x == 0])
	new_list = []
	for eachnumber in arr:
		if (type(eachnumber) is int or type(eachnumber) is float) and eachnumber == 0:
			continue
		else:
			new_list.append(eachnumber)
	for i in range(zero_count):
		new_list.append(0)
	return new_list


move_zeros([9,0.0,0,9,1,2,0,1,0,1,0.0,3,0,1,9,0,0,0,0,9])
#, [9,9,1,2,1,1,3,1,9,9,0,0,0,0,0,0,0,0,0,0])
move_zeros(["a",0,0,"b",None,"c","d",0,1,False,0,1,0,3,[],0,1,9,0,0,0,0,9])
#, ["a","b",None,"c","d",1,False,1,3,[],1,9,9,0,0,0,0,0,0,0,0,0,0])


def vending_machine(products,amt,product_number):

	if(product_number <= 0 or product_number > 9):
		## invalid product
		return 'Enter a valid product number.'
	product_amt = 0
	change_type = []
	product_name = ''
	for eachproduct in products:
		if eachproduct['number'] == product_number:
			# found product
			product_amt = eachproduct['price']
			product_name = eachproduct['name']
			break
	if amt < product_amt:
		return 'Not enough money for this product'
	elif amt == product_amt:
		return { 'product': product_name, 'change': []}
	else:
		change = []
		amt_left = amt - product_amt
		while amt_left >= 500:
			change.append(500)
			amt_left -= 500


def digits_count(number):
	if abs(number) < 10:
		return 1
	else:
		return 1 + digits_count(number / 10)


def paths(a,b):

	return math.factorial(a+b) // (math.factorial(a)*math.factorial(b))


print(paths(2,2))


products = [
  { 'number': 1, 'price': 100, 'name': 'Orange juice' },
  { 'number': 2, 'price': 200, 'name': 'Soda' },
  { 'number': 3, 'price': 150, 'name': 'Chocolate snack' },
  { 'number': 4, 'price': 250, 'name': 'Cookies' },
  { 'number': 5, 'price': 180, 'name': 'Gummy bears' },
  { 'number': 6, 'price': 500, 'name': 'Condoms' },
  { 'number': 7, 'price': 120, 'name': 'Crackers' },
  { 'number': 8, 'price': 220, 'name': 'Potato chips' },
  { 'number': 9, 'price': 80,  'name': 'Small snack' }
]

def vending_machine(products, money, prod_number):

	if prod_number < 1 or prod_number > 9:
		return 'Enter a valid product number'

	prod = [x for x in products if x['number'] == prod_number][0]
	amt = prod['price']
	if amt > money:
		return 'Not enough money for this product'
	elif amt == money:
		return {'product': prod['name'], 'change': []}
	else:

		change = []
		diff = money - amt
		while diff != 0:
			if diff >= 500:
				diff -= 500
				change.append(500)
			elif diff >= 200:
				diff -= 200
				change.append(200)
			elif diff >= 100:
				diff -= 100
				change.append(100)
			elif diff >= 50:
				diff -= 50
				change.append(50)
			elif diff >= 20:
				diff -= 20
				change.append(20)
			elif diff >= 10:
				diff -= 10
				change.append(10)
			else:
				change.append(diff)
				diff = 0
		change = sorted(change,reverse=True)
		return {'product': prod['name'], 'change': change}

print(vending_machine(products,200,7))


def license_plate(plate, platelen):
	plate = plate.upper()
	split_plate = ''.join(plate.split('-'))
	arr = []
	amt = 0
	if len(split_plate) % platelen != 0:
		split_plate_len = len(split_plate)
		while(split_plate_len) > platelen:
			split_plate_len -= platelen
		arr.append(split_plate[0:split_plate_len])
		split_plate = split_plate[split_plate_len:]
	emptystring = ''
	for eachletter in split_plate:
		if len(emptystring) == platelen:
			arr.append(emptystring)
			emptystring = eachletter
		else:
			emptystring = emptystring + eachletter
	arr.append(emptystring)
	return '-'.join(arr)


print(license_plate("5F3Z-2e-9-w",4))
print(license_plate("2-5g-3-J", 2))


def is_palindrome(astr):

	if len(astr) <= 1:
		return True
	else:
		return astr[0] == astr[len(astr)-1] and is_palindrome(astr[1:len(astr)-1])

def longest_palindrome(aStr):

	if is_palindrome(aStr):
		return len(aStr)
	else:
		split_str = sorted(list(aStr))
		letters = {}
		for eachletter in aStr:
			if eachletter in letters:
				letters[eachletter] += 1
			else:
				letters[eachletter] = 1
				## there can only be one odd number
		nums = [letters[x] for x in letters]
		found_odd = False
		for i in range(len(nums)):
			if nums[i] % 2 != 0:
				if found_odd:
					while nums[i] % 2 != 0:
						nums[i] -= 1
				else:
					found_odd = True
		print(nums)
		for i in range(len(split_str)):
			if ''.join(split_str).count(split_str[i]) == 1:
				del split_str[i]
				break
		return len(split_str)

print(longest_palindrome('abccccdd'))

def fibo_word(num):

	if num < 2:
		return 'invalid'
	else:
		arr = ['b', 'a']
		for i in range(2,len(num)):
			letter1 = arr[i-1]
			letter2 = arr[i-2]
			arr.append('{}{}'.format(letter1,letter2))
		return ', '.join(arr)


def security(aStr):

	modified_str = ''.join(aStr.split('x'))
	expr1 = '(T{1,}\$)'
	expr2 = '(\$T{1,})'
	check1 = re.compile(expr1)
	check2 = re.compile(expr2)
	if check1.match(modified_str):
		return 'ALARM!'
	elif check2.match(modified_str):
		return 'ALARM!'
	else:
		return 'Safe'


def just_another_sum_problem(x,y):

    total = 0
    if x < 0:
        tmp_x = abs(x)
        amt = (tmp_x * (0 + tmp_x)) // 2
        total += -1 * (amt)
        total += (y * (y + 0)) // 2
        return total
    elif y < 0:
        tmp_y  = abs(y)
        amt = (tmp_y * (0 + tmp_y)) // 2
        total += -1 * amt
        total += (x * (x + 0)) // 2
        return total
    else:
        return (abs(x-y) * (x + y)) // 2
        


# NegativeH
print(just_another_sum_problem(1,-10))#-54)
print(just_another_sum_problem(-20,5))#-195)
print(just_another_sum_problem(-40,20))#-610)
print(just_another_sum_problem(20,-100))#-4840)
print(just_another_sum_problem(-15,3))#-114)
print(just_another_sum_problem(-8,4))#-26)

#This 2 tests is for you to think of a much more efficient solution 

#Negative
print(just_another_sum_problem(13,-1000000000))#-500000000499999909)
#Positive
print(just_another_sum_problem(7, 1000000000))#500000000499999979)

#Enjoy :) 

#Positive
print(just_another_sum_problem(90,45))#3105)
print(just_another_sum_problem(100,58))#3397)
print(just_another_sum_problem(65,48))#1017)
print(just_another_sum_problem(2,3))#5)
print(just_another_sum_problem(89,256))#28980)
print(just_another_sum_problem(302,56))#44213)


def invert(astr,ind=1):

    if ind == (len(astr) // 2):
        return astr
    else:

        char1 = astr[len(astr)-ind]
        char2 = astr[ind-1]
        substr = astr[ind:len(astr)-ind]
        substr.swapcase()

        return invert(astr[len(astr)-1] + astr[ind+1:len(astr)-1] + astr[ind-1],ind+1)


invert('step on NO PETS')

        

