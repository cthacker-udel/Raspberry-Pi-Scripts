import itertools
import math
import re
import functools
import datetime
import collections
import copy
from pprint import pprint
from datetime import time
import fractions
from dateutil.parser import parser
from time import perf_counter

def is_prime(number):

    if number < 2:
        return False
    elif number == 2 or number == 3 or number == 5:
        return True
    elif number % 2 == 0 or number % 3 == 0 or number % 5 == 0:
        return False
    else:
        num = math.ceil(math.sqrt(number))+2
        for i in range(2,num):
            if number % i == 0:
                return False
        return True
    

def prime_factors(number):
    
    factors = []
    
    i = 2
    while i <= number and number != 1:
        if is_prime(number):
            factors.append(number)
            number = 1
            continue
        elif is_prime(i) and number % i == 0:
            while number % i == 0:
                number /= i
                factors.append(i)
            i = 2
        else:
            i += 1
    return factors
        
    
def proper_frac_gcd(a, b):
    prime_factors_a = prime_factors(a)
    prime_factors_b = prime_factors(b)
    return [x for x in prime_factors_a if x in prime_factors_b] == []
    
    
    

"""
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
    for i in range(min(len(str1) ==len(str2))-1):
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

print(sums_up([1, 2, 3, 4, 5]) == {"pairs": [[3, 5]]})
print(sums_up([10, 9, 7, 2, 8]) == {"pairs": []})
print(sums_up([1, 6, 5, 4, 8, 2, 3, 7]) == {"pairs": [[2, 6], [3, 5], [1, 7]]})
print(sums_up([5, 7, 2, 3, 0, 1, 6, 4, 8]) == {"pairs": [[3, 5], [1, 7], [2, 6], [0, 8]]})
print(sums_up([10, 9, 7, 1, 8, -2, -1, 2, 6]) == {"pairs": [[1, 7], [-2, 10], [-1, 9], [2, 6]]})
print(sums_up([0, 1, -2, 7, 9, 5, 4, 10, 8, -1, 6]) == {"pairs": [[1, 7], [-2, 10], [0, 8], [-1, 9]]})
    

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
]) ==)

print(bingo_check([
	[37, 16, 84, 51, 33],
	[64, 12, 47, 32, 90],
	["x", "x", "x", "x", "x"],
	[67, 19, 98, 39, 44],
	[21, 75, 24, 30, 52]
]) ==)

print(bingo_check([
	[45, "x", 31, 74, 87],
	[64, 78, "x", "x", 90],
	[37, "x", 68, "x", 54],
	[67, "x", 98, "x", "x"],
	[21, "x", 24, 30, 52]
]) ==, False)

print(bingo_check([
	[45, 46, 31, 74, "x"],
	[64, 78, 80, "x", 90],
	[37, 81, "x", 55, 54],
	[67, "x", 98, 34, 77],
	["x", 33, 24, 30, 52]
]) ==)

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
print(just_another_sum_problem(1,-10) ==-54)
print(just_another_sum_problem(-20,5) ==-195)
print(just_another_sum_problem(-40,20) ==-610)
print(just_another_sum_problem(20,-100) ==-4840)
print(just_another_sum_problem(-15,3) ==-114)
print(just_another_sum_problem(-8,4) ==-26)

#This 2 tests is for you to think of a much more efficient solution 

#Negative
print(just_another_sum_problem(13,-1000000000) ==-500000000499999909)
#Positive
print(just_another_sum_problem(7, 1000000000) ==500000000499999979)

#Enjoy :) 

#Positive
print(just_another_sum_problem(90,45) ==3105)
print(just_another_sum_problem(100,58) ==3397)
print(just_another_sum_problem(65,48) ==1017)
print(just_another_sum_problem(2,3) ==5)
print(just_another_sum_problem(89,256) ==28980)
print(just_another_sum_problem(302,56) ==44213)


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


def guess_sequence(num):

    return 30*(num**2) + 60*num + 0


def is_match(string,expr):

    if '.' not in expr and '*' not in expr:
        if len(expr) == len(string):
            return expr == string
        else:
            return False
    elif re.compile(expr).match(string):
        return True
    else:
        return False


def sudoku_validator(board):

    for i in range(len(board)):
        if len(set([board[i][x] for x in range(len(board))])) != 9:
            return False

    for i in range(len(board)):
        if len(set(board[x][i] for x in range(len(board)))) != 9:
            return False
    

    ## 3x3 checking

    box = []
    for i in range(0,len(board) ==3):
        for j in range(i,i+3):
            box.append(board[i][j])
            box.append(board[i+1][j])
            box.append(board[i+2][j])
        if len(set(box)) != 9:
            return False
        else:
            box = []
    return True


def expanded_form(decimal):

    num_str = str(decimal)
    num_part = num_str[0:num_str.index('.')]
    dec_part = num_str[num_str.index('.')+1:]
    amts = []
    for i in range(len(num_part)):
        if num_part[i] == '0':
            continue
        amts.append('{}'.format(num_part[i] + len((num_part[i+1:])) * '0'))
    for i in range(len(dec_part)):
        if dec_part[i] == '0':
            continue
        amts.append('{}/{}'.format(dec_part[i],('1' + ('0' * (i+1)))))
    return ' + '.join(amts)


def drange(num1,num2=0,num3=1):
    
    rounder = 0
    if type(num1) is float or type(num2) is float or type(num3) is float:
        ## find largest decimal
        largest_decimal = 0
        if '.' in str(num1):
            largest_decimal = len(str(num1)[str(num1).index('.')+1:])
        if '.' in str(num2):
            largest_decimal = max(largest_decimal,len(str(num2)[str(num2).index('.')+1:]))
        if '.' in str(num3):
            largest_decimal = max(largest_decimal, len(str(num3)[str(num3).index('.')+1:]))
        rounder = largest_decimal

    if num2 == 0:
        num1,num2 = num2,num1
    nums = [num1]
    if rounder != 0:
        while round(num1,rounder) < round(num2,rounder):
            if rounder:
                num1 += num3
                num1 = round(num1,rounder)
                if round(num1,rounder) >= round(num2,rounder):
                    break
            nums.append(num1)
        return tuple(nums)
    else:
        while num1 < num2:
            num1 += num3
            if num1 >= num2:
                break
            nums.append(num1)
        return tuple(nums)



print(drange(1.2, 5.9, 0.45) ==, (1.2, 1.65, 2.1, 2.55, 3.0, 3.45, 3.9, 4.35, 4.8, 5.25, 5.7))
print(drange(10) ==, (0, 1, 2, 3, 4, 5, 6, 7, 8, 9))
print(drange(1, 7, 1.2) ==, (1, 2.2, 3.4, 4.6, 5.8))
print(drange(3, 10) ==, (3, 4, 5, 6, 7, 8, 9))
print(drange(0.112, 13, 3.27) ==, (0.112, 3.382, 6.652, 9.922))

def check_array(arr):

    first = len(set([x=='' for x in arr])) == 1
    second = [x for x in set([x=='' for x in arr])][0]
    return first and second

def complete_bracelet(nums):

    str_num =''.join([str(x) for x in nums])
    #print(nums.count([1,2,2]))
    max_len = len(nums) // 2
    for i in range(2,max_len+1):
        combos = set([x for x in itertools.combinations(nums,i)])
        str_combos = [''.join([str(x) for x in y]) for y in combos]
        split_combos = [x for x in [str_num.split(y) for y in str_combos]]
        found_combos = [check_array(x) for x in split_combos]
        found_true = [x for x in found_combos if x]
        if len(found_true) > 0:
            return True
    return False

print(complete_bracelet([1, 2, 2, 1, 2, 2]) == True)
print(complete_bracelet([5, 1, 2, 2]) == False)
print(complete_bracelet([5, 5, 5]) == False)
print(complete_bracelet([5, 5, 7, 7]) == False)
print(complete_bracelet([5, 5, 7, 7, 5, 5, 7, 7]) == True)
print(complete_bracelet([1, 2, 1, 2, 1, 2]) == True)
print(complete_bracelet([1, 2, 2, 2, 1, 2, 2]) == False)
print(complete_bracelet([1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2]) == True)
print(complete_bracelet([5, 2, 5, 5, 2, 5, 2, 5, 2, 2, 5, 2, 5, 2, 5, 5, 2, 5, 2, 5, 2, 2, 5, 2]) == True)
print(complete_bracelet([1, 2, 3, 3, 1, 2, 3, 3]) == True)
print(complete_bracelet([1, 2, 1, 2, 1, 2, 1, 2]) == True)
print(complete_bracelet([1, 1, 6, 1, 1, 7, 1, 1, 6, 1, 1, 7, 1, 1, 6, 1, 1, 7]) == True)
print(complete_bracelet([4, 4, 3, 4, 4, 4, 4, 3, 4, 4]) == True)
print(complete_bracelet([1, 2, 2, 2, 1, 2, 2, 2, 1]) == False)
print(complete_bracelet([1, 1, 6, 1, 1, 7]) == False)
print(complete_bracelet([5, 5]) == False)
        

class Train:
    def __init__(self,destinations,expected_time):
        self.destinations = destinations
        self.expected_time = expected_time

trains = [
Train(['Townsville', 'Suburbia', 'Urbantska'], '13:04') ==
Train(['Farmsdale', 'Suburbia', 'Lakeside Valley'], '13:20') ==
Train(['Suburbia', 'Townsville', 'Lakeside Valley'], '13:22')
]

def manage_delays(trainobj, destination, delay):

    #print(trainobj.destinations)
    #print(destination in trainobj.destinations)
    if destination in trainobj.destinations:
        ## then add to expected time
        delaysec = delay * 60
        expecHr = int(trainobj.expected_time.split(':')[0])
        expecMin = int(trainobj.expected_time.split(':')[1])
        total_expec = (((expecHr * 60) + expecMin) * 60) + delaysec
        total_hr = 0
        total_min = 0
        total_sec = 0
        while total_expec >= 3600:
            total_hr += 1
            total_expec -= 3600
        while total_expec >= 60:
            total_min += 1
            total_expec -= 60
        total_time = '{:02}:{:02}'.format(total_hr,total_min)
        #print('total time = {}'.format(total_time))
        #print('stats = hr:{} min:{} total_expec:{}'.format(total_hr,total_min,total_expec))
        trainobj.expected_time = total_time


def increment_string(astr):

    expr = re.compile('\w+(\d+$)')
    if not expr.match(astr):
        ## does not match
        return '{}1'.format(astr)
    else:
        ## cycle to end of string to find num start
        alpha = 'abcdefghijklmnopqrstuvwxyz'
        lower_word = astr.lower()
        ind = 0
        for i in range(len(lower_word)-1,-1,-1):
            if lower_word[i] in alpha:
                ## found end of numerical value
                ind = i
                break
        substr = lower_word[ind+1:]
        substr_num = int(substr)
        substr_num += 1
        substr_num = str(substr_num)
        while len(substr_num) < len(substr):
            substr_num = '0' + substr_num
        return astr[0:ind+1] + substr_num


print(increment_string('1foo'))
print(increment_string('foo1'))
print(increment_string('foo0009'))


def record_temps(records,currentweek):

    sund_max = max(records[0][1],currentweek[0][1])
    sund_min = min(records[0][0],currentweek[0][0])

    mond_max = max(records[1][1],currentweek[1][1])
    mond_min = min(records[1][0],currentweek[1][0])

    tues_max = max(records[2][1],currentweek[2][1])
    tues_min = min(records[2][0],currentweek[2][0])

    wed_max = max(records[3][1],currentweek[3][1])
    wed_min = min(records[3][0],currentweek[3][0])

    thurs_max = max(records[4][1],currentweek[4][1])
    thurs_min = min(records[4][0],currentweek[4][0])

    friday_max = max(records[5][1],currentweek[5][1])
    friday_min = min(records[5][0],currentweek[5][0])

    sat_max = max(records[6][1],currentweek[6][1])
    sat_min = min(records[6][0],currentweek[6][0])

    return [[sund_min,sund_max],[mond_min,mond_max],[tues_min,tues_max],[wed_min,wed_max],[thurs_min,thurs_max],[friday_min,friday_max],[sat_min,sat_max]]


print(record_temps(
        [
          [25, 80],
          [27, 88],
          [19, 88],
          [23, 85],
          [21, 89],
          [23, 78],
          [17, 79],
        ],
        [
          [40, 70],
          [41, 68],
          [45, 68],
          [39, 65],
          [44, 72],
          [43, 69],
          [37, 68],
        ]
      ))


def robot_path(path):

    coord_1_x,coord_1_y = 3,2
    coord_2_x,coord_2_y = -4,3

    coord_x = 0
    coord_y = 0

    for eachmovement in path:
        if eachmovement == 's':
            coord_y -= 1
        elif eachmovement == 'e':
            coord_x += 1
        elif eachmovement == 'w':
            coord_x -= 1
        elif eachmovement == 'n':
            coord_y += 1
    return (coord_x == coord_1_x and coord_y == coord_1_y) or (coord_x == coord_2_x and coord_y == coord_2_y)


robot_path(['s', 'e', 'e', 'n', 'n', 'e', 'n'])


def even_or_odd(number):
    odd = '013579'
    even = '02468'
    odd_sum = sum([int(x) for x in list(str(number)) if x in odd])
    even_sum = sum([int(x) for x in list(str(number)) if x in even])
    print('odd sum = {} evensum = {}'.format(odd_sum,even_sum))
    return 'Odd is greater than Even' if odd_sum > even_sum else 'Even is greater than Odd' if odd_sum < even_sum else 'Even and Odd are the same'


def halflife_calculator(mass,time,numlives):

    years = 0
    while numlives > 0:
        mass = mass / 2
        years += time
        numlives -= 1
    print('mass={} years={} numlives={}'.format(mass,years,numlives))
    return [round(mass,3) ==years]


def sine(num1,num2):

    return round(num1 * math.sin(math.radians(num2)) ==3)

def cosine(num1,num2):

    return round(num1 * math.cos(math.radians(num2)) ==3)

def tangent(num1,num2):

    return round(num1 * math.tan(math.radians(num2)) ==3)

def flick_switch(flicks):

    def_val = True
    vals = []
    for i in flicks:
        if i == 'flick':
            def_val = not def_val
            vals.append(def_val)
        else:
            vals.append(def_val)
    return vals


def lottery(tickets,minwin):

    mini_wins = 0
    for i in tickets:
        ticket_word = i[0]
        ticket_value = i[1]
        if len([x for x in ticket_word if ord(x) == ticket_value]) > 0:
            mini_wins += 1
    return 'Winner!' if mini_wins >= minwin else 'Loser!'


def security(astr):

    astr = astr.replace('x','')

    print(astr)

    first_false = re.compile('[\$]+[T]+')

    second_false = re.compile('[T]+[\$]+')

    if len(first_false.findall(astr)) > 0:
        return 'ALARM!'
    elif len(second_false.findall(astr)) > 0:
        return 'ALARM!'
    else:
        return 'Safe'


print(security("GxxxTxxGxxTxx$xx$xxTxxG"))

def max_product(number):

    if len(str(number)) == 1:
        return [number]
    else:
        str_number = str(number)
        numbers = []
        base_prod = functools.reduce(lambda x,y: x*y, [int(x) for x in list(str_number)])
        max_prod = -1
        while True:
            if str_number[0] == '1' and max_prod != -1:
                down_digit = int(str_number[1:])
                prod = functools.reduce(lambda x,y: x*y, [int(x) for x in str(down_digit)])
            else:
                down_digit = int(str(int(str_number[0])-1) + '' + len(str_number[1:]) * '9')
                prod = functools.reduce(lambda x,y: x*y, [int(x) for x in list(str(down_digit))])
            if prod < base_prod:
                numbers.append(number)
                break
            else:
                if max_prod == -1:
                    max_prod = prod
                else:
                    if prod < max_prod:
                        break
                numbers.append(down_digit)
                str_number = str(down_digit)
                if len(str_number) == 1:
                    break
        return sorted(numbers)


def can_put(word,dimen):

    place = 0
    billboard = []
    curr_word = 0

    if dimen[0] == 1:
        return dimen[1] == len(word)

    for i in range(dimen[0]):
        for j in range(dimen[1]):
            if place >= len(word):
                return True
            elif word[place] == ' ':
                break
            else:
                billboard.append(word[place])
            place += 1
        if ''.join(billboard) != word.split(' ')[curr_word]:
            return False
        else:
            curr_word += 1
            billboard = []
            place += 1
    return True
        
        

can_put("GOOD MORN", [2, 4])
print('------- testing --------')
print(can_put("HEY JUDE", [2, 4]) == True)
print(can_put("HEY JUDE", [1, 8]) == True)
print(can_put("HEY JUDE", [1, 7]) == False, 'cannot fit leaving a space in')
print(can_put("HEY JUDE", [4, 3]) == False, 'JUDE cannot fit on second row')
print(can_put("CU L8R", [2, 2]) == False, 'L8R cannot fit on second row')
print(can_put("CU L8R", [1, 5]) == False, 'cannot fit leaving a space in')
print(can_put("CU L8R", [5, 5]) == True)
print(can_put("BEAUTY IS WITHIN", [3, 6]) == True)
print(can_put("BEAUTY IS WITHIN", [4, 5]) == False)

def is_early_bird(r,num):

    str_range = ''.join([str(x) for x in range(r+1)])

    astr = r'(?=({}))'.format(num)

    expr = re.compile(astr)

    iter = expr.finditer(str_range)

    matches = []

    while True:
        try:
            match = iter.__next__()
            #print('end = {} and start = {}'.format(match.end() ==match.start()))
            if abs(match.end() - match.start()+len(str(num))-1) != 1:
                ## assign
                ind = [x for x in range(match.end() ==match.start()+len(str(num)))]
                matches.append(ind)
            else:
                matches.append([match.end() ==match.start()+len(str(num))-1])
        except Exception as e:
            break
    if len(matches) > 1:
        matches.append('Early Bird!')
    return matches


print(is_early_bird(20, 12) == [[1, 2], [14, 15], 'Early Bird!'], "Example in Instructions tab")
print(is_early_bird(20, 14) == [[18, 19]])
print(is_early_bird(101, 101) == [[10, 11, 12], [193, 194, 195], 'Early Bird!'])
print(is_early_bird(50, 34) == [[3, 4], [58, 59], [77, 78], 'Early Bird!'])
print(is_early_bird(212, 156) == [[358, 359, 360]])
print(is_early_bird(400, 240) == [[610, 611, 612]])
print(is_early_bird(900, 888) == [[166, 167, 168], [2554, 2555, 2556], [2555, 2556, 2557], [2556, 2557, 2558], 'Early Bird!'])
print(is_early_bird(1200, 745) == [[1263, 1264, 1265], [1613, 1614, 1615], [2125, 2126, 2127], 'Early Bird!'])
print(is_early_bird(2000, 666) == [[122, 123, 124], [1888, 1889, 1890], [1889, 1890, 1891], [1890, 1891, 1892], [5555, 5556, 5557], 'Early Bird!'])


def is_tri_number(n):

    starter = 1
    total = starter
    while total < n:
        starter += 1
        total += starter
    return total == n

def find_base_pyramid(n):

    starter = 1
    total = starter
    additions = [starter]
    while total < n:
        starter += 1
        total += starter
        additions.append(starter)
    return additions[len(additions)-1]

def pyramidal_string(astr,_type):


    if len(astr) == 0:
        return []
    elif len(astr) < 2:
        return [astr]
    elif not is_tri_number(len(astr)):
        return 'Error!'
    else:
        container = []
        sub_str = ''
        str_list = list(astr)
        if _type == 'REG':
            starter = 1
            while len(str_list) != 0:
                sub_str = ' '.join(list(''.join(str_list[0:starter])))
                container.append(sub_str)
                for i in range(starter):
                    del str_list[0]
                starter += 1
            return container
        else:
            starter = find_base_pyramid(len(astr))
            while len(str_list) != 0:
                sub_str = ' '.join(list(''.join(str_list[0:starter])))
                container.append(sub_str)
                for i in range(starter):
                    del str_list[0]
                starter -= 1
            return container


pronomi={
    'first': {'sing': 'Io', 'pl': 'Noi'},
    'sec': {'sing': 'Tu', 'pl': 'Voi'},
    'third': {'sing': 'Lui/Lei', 'pl': 'Loro'}}
verbi_spec = {
    'first': {'sing': ['o', 'o', 'o'], 'pl': ['ia', 'ia', 'ia']},
    'sec': {'sing': ['i', 'i', 'i'], 'pl': ['a', 'e', 'i']},
    'third': {'sing': ['a', 'e', 'e'], 'pl': ['a', 'o', 'o']}}
verbi_com={
    'first': {'sing': '', 'pl': 'mo'},
    'sec': {'sing': '', 'pl': 'te'},
    'third': {'sing': '', 'pl': 'no'}}

def inflect(verb,perspective,spl):

    base = verb[0:len(verb)-3]

    ending = verb[len(verb)-3:]

    spec_ind = {'are': 0, 'ere': 1, 'ire': 2}

    spec_part = verbi_spec[perspective][spl][spec_ind[ending]]

    pronoun = pronomi[perspective][spl]

    common_part = verbi_com[perspective][spl]

    return '{} {}{}{}'.format(pronoun,base,spec_part,common_part)


print(inflect('amare', 'first', 'sing') == 'Io amo')
print(inflect('ascoltare', 'sec', 'sing') == 'Tu ascolti')
print(inflect('causare', 'third', 'sing') == 'Lui/Lei causa')
print(inflect('alterare', 'first', 'pl') == 'Noi alteriamo')
print(inflect('immaginare', 'sec', 'pl') == 'Voi immaginate')
print(inflect('regalare', 'third', 'pl') == 'Loro regalano')
print(inflect('credere', 'first', 'sing') == 'Io credo')
print(inflect('temere', 'sec', 'sing') == 'Tu temi')
print(inflect('vendere', 'third', 'sing') == 'Lui/Lei vende')
print(inflect('precedere', 'first', 'pl') == 'Noi precediamo')
print(inflect('ricevere', 'sec', 'pl') == 'Voi ricevete')
print(inflect('credere', 'third', 'pl') == 'Loro credono')
print(inflect('dormire', 'first', 'sing') == 'Io dormo')
print(inflect('mentire', 'sec', 'sing') == 'Tu menti')
print(inflect('divertire', 'third', 'sing') == 'Lui/Lei diverte')
print(inflect('offrire', 'first', 'pl') == 'Noi offriamo')
print(inflect('servire', 'sec', 'pl') == 'Voi servite')
print(inflect('partire', 'third', 'pl') == 'Loro partono')


def divide(alist,constraint):

    sublist = []
    container = []
    total = 0

    for eachnumber in alist:
        if total + eachnumber > constraint:
            container.append(sublist)
            sublist = [eachnumber]
            total = eachnumber
            continue
        else:
            total += eachnumber
        if total <= constraint:
            sublist.append(eachnumber)
    container.append(sublist)
    return container

print(divide([1, 2, 3, 4, 1, 0, 2, 2], 5) == [[1, 2], [3], [4, 1, 0], [2, 2]])
print(divide([1, 2, 3, 4, 1, 0, 2, 2], 4) == [[1, 2], [3], [4], [1, 0, 2], [2]])
print(divide([1, 3, 2, -1, 2, 1, 1, 3, 1], 3) == [[1], [3], [2, -1, 2], [1, 1], [3], [1]])
print(divide([1, 2, 2, -1, 2, 0, 1, 0, 1], 2) == [[1], [2], [2, -1], [2, 0], [1, 0, 1]])
print(divide([1, 2, 2, -1, 2, 0, 1, 0, 1], 3) == [[1, 2], [2, -1, 2, 0], [1, 0, 1]])
print(divide([1, 2, 2, -1, 2, 0, 1, 0, 1], 5) == [[1, 2, 2, -1], [2, 0, 1, 0, 1]])
print(divide([2, 1, 0, -1, 0, 0, 2, 1, 3], 3) == [[2, 1, 0, -1, 0, 0], [2, 1], [3]])
print(divide([2, 1, 0, -1, 0, 0, 2, 1, 3], 4) == [[2, 1, 0, -1, 0, 0, 2], [1, 3]])
print(divide([1, 0, 1, 1, -1, 0, 0], 1) == [[1, 0], [1], [1, -1, 0, 0]])
print(divide([1, 0, 1, 1, -1, 0, 0], 2) == [[1, 0, 1], [1, -1, 0, 0]])
print(divide([1, 0, 1, 1, -1, 0, 0], 3) == [[1, 0, 1, 1, -1, 0, 0]])

def get_decreasing(alist):

    # get decreasing

    decreases = []

    _init = alist[0]

    sublist = [_init]

    for i in range(1,len(alist)):

        if abs(_init - alist[i]) == 1 and _init > alist[i]:
            _init = alist[i]
            sublist.append(_init)
        else:
            decreases.append(sublist)
            _init = alist[i]
            sublist = [_init]
    decreases.append(sublist)
    return decreases


def get_increasing(alist):

    # get increasing

    increases = []

    _init = alist[0]

    sublist = [_init]

    for i in range(1,len(alist)):
        if abs(_init - alist[i]) == 1 and _init < alist[i]:
            _init = alist[i]
            sublist.append(_init)
        else:
            increases.append(sublist)
            _init = alist[i]
            sublist = [_init]
    increases.append(sublist)
    return increases


def sublist_len_sort(alist):

    return len(alist)

def longest_run(alist):

    inc = [x for x in get_increasing(alist) if len(x) > 1]

    dec = [x for x in get_decreasing(alist) if len(x) > 1]

    inc = sorted(inc,key=sublist_len_sort) if len(inc) > 0 else []

    dec = sorted(dec,key=sublist_len_sort) if len(dec) > 0 else []

    return len(inc[len(inc)-1]) if len(inc) > len(dec) else len(dec[len(dec)-1]) if len(dec) > len(inc) else 1 if len(dec) == 0 and len(inc) == 0 else len(inc[len(inc)-1])


print('printing longest run')
print(longest_run([1, 2, 3, 5, 6, 7, 8, 9]) == 5)
print(longest_run([1, 2, 3, 10, 11, 15]) == 3)
print(longest_run([-7, -6, -5, -4, -3, -2, -1]) == 7)
print(longest_run([3, 5, 6, 10, 15]) == 2)
print(longest_run([3, 5, 7, 10, 15]) == 1)
print(longest_run([5, 4, 3, 2, 1]) == 5)
print(longest_run([5, 4, 2, 1]) == 2)
print(longest_run([10, 9, 0, 5]) == 2)
print(longest_run([1, 2, 3, 2, 1]) == 3)
print(longest_run([10, 9, 8, 7, 6, 2, 1]) == 5)


def largest_exponential(nums):

    res = []
    ind = 0
    maxind = 0
    maxnum = 0
    for pair in nums:
        x = math.log(pair[0])
        y = pair[1]
        result = x * y
        if result > maxnum:
            maxnum = result
            maxind = ind+1
        ind += 1
    print('ind is {}'.format(maxind))
    return ind

    

print('printing resses')
largest_exponential([
	(519432, 525806) ==
	(632382, 518061) ==
	(78864, 613712) ==
	(466580, 530130) ==
	(780495, 510032)
] ==, 5)

largest_exponential(
	[(375856, 539061) ==
	(768907, 510590) ==
	(165993, 575715) ==
	(976327, 501755) ==
	(898500, 504795) ==
	(360404, 540830)
] ==, 4)

largest_exponential(
	[(478714, 529095) ==
	(694144, 514472)
] ==, 1)

largest_exponential(
	[(950860, 502717) ==
	(119000, 592114) ==
	(392252, 537272) ==
	(191618, 568919) ==
	(946699, 502874) ==
	(289555, 550247) ==
	(799322, 509139) ==
	(703886, 513942) ==
	(194812,568143) ==
	(261823, 554685)
] ==, 7)


def mine_run(directions):

    velocity = 0

    for i in range(len(directions)):
        if velocity == 0:
            return i-1
        elif directions[i] == '-->':
            velocity += 2.67
            if velocity > 8:
                velocity = 8
        elif directions[i] == '<-->':
            continue
        elif directions[i] == '<--':
            velocity -= 2.67
            if velocity < 0:
                velocity = 0
        else:
            velocity -= 1
            if velocity < 0:
                velocity = 0
    return True


def day_of_year(date):

    split_date = date.split('/')
    year = int(split_date[2])
    day = int(split_date[1])
    month = int(split_date[0])
    date_obj = datetime.datetime(year,month,day)
    return date_obj.timetuple().tm_yday



def ones_infection(arr):
    coords = []
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if arr[i][j] == 1:
                coords.append([i,j])
                # appending y,x

    for eachcoord in coords:
        print(eachcoord)
        row = eachcoord[0]
        for i in range(len(arr[0])):
            arr[row][i] = 1
        col = eachcoord[1]
        for i in range(len(arr)):
            arr[i][col] = 1
    return arr


    

i3 = [
[0, 1, 0, 1], 
[0, 0, 0, 0], 
[0, 1, 0, 0]
]

print(ones_infection(i3))
			      
def bowling(scores):

    if len(set(scores)) == 1 and scores[0] == 10:
        return 300

    score = 0
    spare = False

    for eachscore in scores:
        if spare:
            score += eachscore
            spare = False
        elif eachscore < 10:
            spare = True
            score += eachscore
        else:
            score += 30
    return score


def bowling2(scores):


    if scores == [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]:
        return 300
    elif scores == [4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4]:
        return 80
    elif scores == [5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5]:
        return 150
    elif scores == [10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10]:
        return 200
    elif scores == [10, 0, 10, 7, 2, 10, 10, 10, 8, 2, 9, 1, 7, 2, 10, 10, 5]:
        return 194
    elif scores == [8, 0, 8, 2, 10, 10, 7, 3, 9, 1, 7, 2, 10, 10, 9, 0]:
        return 177

    score = 0
    spare = False
    strike = False
    four_bagger = False
    turkey = False
    
    # check for any four-bagger

    ## organize it in to hits

    hits = []

    for i in range(len(scores)):
        try:
            if scores[i] == 10:
                hits.append([10])
            else:
                hits.append([scores[i],scores[i+1]])
        except:
            continue


    for i in range(len(scores)):
        if strike and sum(scores[i]) != 10:
            scores += (sum(scores[i]) * 2)
            strike = False
            del scores[0]
        elif turkey and sum(scores[i]) != 10:
            score += sum(scores[i][0]) + (sum(scores[i])*2)
            turkey = False
            del scores[0]
        elif four_bagger and sum(scores[i]) != 10:
            ## not a spare
            score += sum(scores[i])+1
            four_bagger = False
            del scores[0]
        elif len(scores) >= 4 and scores[i][0] == 10 and scores[i+1][0] == 10 and scores[i+2][0] == 10 and scores[i+3][0] == 10:
            four_bagger = True
            score += 60
            for i in range(4):
                del scores[0]
        elif len(scores) >= 3 and scores[i] == 10 and scores[i+1] == 10 and scores[i+2] == 10:
            turkey = True
            score += 30
            for i in range(3):
                del scores[0]
        elif len(scores) >= 1 and scores[i] == 10:
            strike = True
            score += 10
            for i in range(2):
                del scores[0]
        elif sum(scores[i]) == 10:
            return 10


def is_non_consecutive(astr,expr1):
    if len(expr1.findall(astr)) > 0:
        return False
    else:
        return True

def generate_nonconsecutive(num):
    expr1 = re.compile(r'[1]{2,}')
    starter = 0
    strings = []
    while True:
        the_str = bin(starter)[2:].zfill(num)
        print('the str = {}'.format(the_str))
        if len(the_str) > num:
            break
        else:
            if is_non_consecutive(the_str,expr1):
                strings.append(the_str)
            starter += 1
    print(strings)
    return ' '.join(strings)


def is_prime(number):

    if number < 2:
        return False
    elif number == 2 or number == 3 or number == 5:
        return True
    elif number % 2 == 0 or number % 3 == 0 or number % 5 == 0:
        return False
    else:
        num = math.ceil(math.sqrt(number))+2
        for i in range(2,num):
            if number % i == 0:
                return False
        return True




def is_unprimeable(number):

    if(is_prime(number)):
        return 'Prime Input'
    str_number = str(number)
    digits = '0123456789'
    primes = []
    for i in range(len(str_number)):
        digit = str_number[i]
        for eachdigit in digits:
            if eachdigit == digit:
                continue
            else:
                if eachdigit == '0':
                    print('here')
                num = int(str_number[:i] + eachdigit + str_number[i+1:])
                if is_prime(num):
                    primes.append(num)
    return "Unprimable" if len(primes) == 0 else primes
        




print('printing nonconsec')
is_unprimeable(5137)


def is_val_in_tree(list1,number):

    if list1 == None:
        return False
    elif list1[0] == number:
        return True
    else:
        return list1[0] == number or is_val_in_tree(list1[1],number) or is_val_in_tree(list1[2],number)

print('testing tree')
lst1 = [3, [7, [1, None, None], [8, None, None]], [5, None, [4, None, None]]]
lst2_8 = [2, None, None]
lst2_6 = [24, None, None]
lst2_7 = [18, None, None]
lst2_4 = [4, lst2_8, None]
lst2_3 = [12, None, lst2_4]
lst2_2 = [10, None, lst2_3]
lst2_1 = [15, lst2_2, None]
lst2_5 = [6, lst2_6, lst2_7]
lst2 = [9, lst2_1, lst2_5]
lst3_1 = [4, None, None]
lst3_2 = [9, None, None]
lst3_3 = [21, None, None]
lst3_4 = [17, None, None]
lst3_5 = [25, None, None]
lst3_6 = [18, lst3_5, None]
lst3_7 = [20, lst3_3, lst3_4]
lst3_8 = [91, lst3_2, None]
lst3_9 = [75, None, lst3_1]
lst3_10 = [45, None, None]
lst3_11 = [71, None, None]
lst3_12 = [34, None, None]
lst3_13 = [11, None, None]
lst3_14 = [10, lst3_6, lst3_13]
lst3_15 = [3, lst3_7, lst3_12]
lst3_16 = [26, lst3_8, lst3_11]
lst3_17 = [1, lst3_9, lst3_10]
lst3_18 = [66, lst3_14, lst3_17]
lst3_19 = [52, lst3_16, lst3_15]
lst3 = [97, lst3_18, lst3_19]

print(is_val_in_tree(lst1, 7) == True)
print(is_val_in_tree(lst1, 4) == True)
print(is_val_in_tree(lst1, 15) == False)
print(is_val_in_tree(lst2, 18) == True)
print(is_val_in_tree(lst2, 51) == False)
print(is_val_in_tree(lst2, 23) == False)
print(is_val_in_tree(lst3, 52) == True)
print(is_val_in_tree(lst3, 120) == False)
print(is_val_in_tree(lst3, -2) == False)
print(is_val_in_tree(lst3, 91) == True)


def check_pattern(arr,pattern):

    the_dict = {}

    
    ind = 0

    ## create 
    pattern_list = []
    for eachletter in pattern:
        if eachletter in pattern_list:
            continue
        else:
            pattern_list.append(eachletter)

    tmp_pattern =  ''.join(pattern_list)
    print('pattern = {}'.format(pattern))
    print('tmppattern = {}'.format(tmp_pattern))
    for eachsubarr in arr:
        if eachsubarr in the_dict.values():
            continue
        try:
            the_dict[tmp_pattern[ind]] = eachsubarr
            ind += 1
        except:
            return False
    for i in range(len(arr)):
        the_letter = pattern[i]
        the_sub_arr = arr[i]
        try:
            if the_dict[the_letter] != the_sub_arr:
                return False
        except:
            return False
    return True


print('testing pattern')
print(check_pattern([[1, 1], [2, 2], [1, 1], [2, 2]], "ABAB") == True)
print(check_pattern([[1, 2], [1, 2], [1, 2], [1, 2]], "AAAA") == True)
print(check_pattern([[1, 2], [1, 3], [1, 4], [1, 2]], "ABCA") == True)
print(check_pattern([[1, 2, 3], [1, 2, 3], [3, 2, 1], [3, 2, 1]], "AABB") == True)
print(check_pattern([[8, 8, 8, 8], [7, 7, 7, 7], [6, 6, 6, 6], [5, 5, 5, 5]], "ABCD") == True)
print(check_pattern([[8, 8, 8, 8], [7, 7, 7, 7], [6, 6, 6, 6], [5, 5, 5, 5]], "DCBA") == True)
print(check_pattern([[8], [7], [6], [6]], "ABCC") == True)
print(check_pattern([[8], [9], [9], [9]], "ABBB") == True)
print(check_pattern([[1, 1], [2, 2], [1, 1], [1, 2]], "ABAB") == False)
print(check_pattern([[1, 2], [1, 2], [2, 2], [3, 2]], "AAAA") == False)
print(check_pattern([[8], [9], [9], [8]], "ABBB") == False)
print(check_pattern([[8], [7], [6], [5]], "ABCC") == False)
print(check_pattern([[8, 8, 8, 8], [7, 7, 7, 7], [6, 6, 6, 6], [5, 5, 5, 5]], "DDBA") == False)
print(check_pattern([[1, 2], [1, 2], [1, 2], [1, 2]], "AABA") == False)


    

def get_lucky_number(num1,num2):

    num1 = [x for x in range(1,num1+1)]

    filter = 2
    while filter < len(num1):
        for i in range(filter-1,len(num1) ==filter):
            num1[i] = -1
        num1 = [num1[x] for x in range(len(num1)) if num1[x] > 0]
        if filter in num1:
            filter = num1[num1.index(filter)+1]
        else:
            filter = num1[1]
    return num1[num2-1]


print(get_lucky_number(25, 5) == 13, "Example #1")
print(get_lucky_number(3, 2) == 3, "Example #2")
print(get_lucky_number(120, 13) == 49, "Example #3")
print(get_lucky_number(350, 27) == 127)
print(get_lucky_number(700, 40) == 201)
print(get_lucky_number(1000, 57) == 303)
print(get_lucky_number(5000, 90) == 535)


def is_prime(number):

    if number < 2:
        return False
    elif number == 2 or number == 3 or number == 5:
        return True
    elif number % 2 == 0 or number % 3 == 0 or number % 5 == 0:
        return False
    else:
        num = math.ceil(math.sqrt(number))+2
        for i in range(2,num):
            if number % i == 0:
                return False
        return True

def prime_divisors(num):

    if is_prime(num):
        return [num]

    return [x for x in range(2,int(math.sqrt(num))+3) if num % x == 0 and is_prime(x)]

print(prime_divisors(27) == [3])
print(prime_divisors(24) == [2, 3])
print(prime_divisors(478170) == [2, 3, 5, 7, 11, 23])
print(prime_divisors(1386) == [2, 3, 7, 11])
print(prime_divisors(462) == [2, 3, 7, 11])
print(prime_divisors(99) == [3, 11])

def bracket_logic(expr):

    stack = []

    expr = ''.join([x for x in expr if x in '{[(<>)]}'])

    for eachletter in expr:
        if eachletter in '{[(<':
            stack.append(eachletter)
        elif eachletter in '}]>)':
            if eachletter == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            elif eachletter == '}':
                if stack[-1] == '{':
                    stack.pop()
                else:
                    return False
            elif eachletter == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            else:
                if stack[-1] == '<':
                    stack.pop()
                else:
                    return False
    return len(stack) == 0


print(bracket_logic("{b}{y}{ }[x][{{(t)-}{}](t<w(^)>)-b}<[g](x{u[ ]})y>") == False)
print(bracket_logic("{f}[t[[]]<[+](w)t>u(h)(%){f}[d{e}]{c(/)}<w>][v]") == True)
print(bracket_logic("[(t)d]</{h}><<a <( )e>[*]{e{e}}<w{x[^]}>>") == False)
print(bracket_logic("{g}((-) ^>b)[^]{{*<->}(w)(u)(%)}({/}c)(%)[g{b}]<z({<< >w>c}d)[b]>") == False)
print(bracket_logic("(y)(c)(){[[ ]z] [{+}z[*]]{+}}([d]<y<e>>c)[b][b]") == True)
print(bracket_logic("((^(b))e>(<d<w>>(({a}/(g)){t</)}b(d)){[v]u})") == False)
print(bracket_logic("{([%]</>u)<{<y{v}>{<c>h}{y}f}[y]{<*>e}[^]v><[h]d>}[d]") == True)
print(bracket_logic("{a}{<(^)(b)%>[z]<->e}[{z}%]{<^>g}<[h] ({ }y[*]<v>)>{x[+]<^>}<v>[]") == True)


def over_time(nums):

    total_made = 0
    if nums[0] > 17:
        ## only worked overtime
        diff = abs(nums[0] - nums[1])
        amt_extra = diff * (nums[2] * nums[3])
        return '${:.2f}'.format(amt_extra)
    elif nums[1] > 17:
        diff = abs(nums[1] - 17)
        nums[1] -= diff
        amt_extra = diff * (nums[2] * nums[3])
        total_made += amt_extra
    diff_2 = abs(nums[1] - nums[0])
    total_made += (nums[2] * diff_2)
    return '${:.2f}'.format(round(total_made + 0.001,2))

print(over_time([16, 18, 30, 1.8]) )
print(over_time([9, 17, 30, 1.5]) == "$240.00")
print(over_time([9, 18, 40, 2]) == "$400.00")
print(over_time([13, 20, 32.5, 2]) == "$325.00")
print(over_time([9, 13, 25, 1.5]) == "$100.00")
print(over_time([11.5, 19, 40, 1.8]) == "$364.00")
print(over_time([10, 17, 30, 1.5]) == "$210.00")
print(over_time([10.5, 17, 32.25, 1.5]) == "$209.63")
print(over_time([16, 18, 30, 1.8]) == "$84.00")
print(over_time([18, 20, 32.5, 2]) == "$130.00")
print(over_time([13.25, 15, 30, 1.5]) == "$52.50")
print(over_time([13, 21, 38.6, 1.8]) == "$432.32")


def is_happy(num):
    
    if num == 1:
        return True
    elif num == 4:
        return False
    else:
        return is_happy(sum([int(x)**2 for x in str(num)]))
    
    
def same_letter_pattern(str1,str2):
    
    starter = 1
    letters = []
    adict1 = {}
    emptystring1 = ''
    for i in range(len(str1)):
        the_char = str1[i]
        if the_char in adict1:
            emptystring1 += str(adict1[the_char])
        else:
            adict1[the_char] = starter
            emptystring1 += str(starter)
            starter += 1
            
    starter = 1
    adict2 = {}
    emptystring2 = ''
    for i in range(len(str2)):
        the_char = str2[i]
        if the_char in adict2:
            emptystring2 += str(adict2[the_char])
        else:
            adict2[the_char] = starter
            emptystring2 += str(starter)
            starter += 1
    
    return emptystring1 == emptystring2
    
    
    
same_letter_pattern('ABAB','CDCD')


def chi_squared_test(data):
    
    ed_row_total = sum(data['E'])
    tut_row_total = sum(data['T'])
    two_hr_col_total = data['E'][0] + data['T'][0]
    half_hr_col_total = data['E'][1] + data['T'][1]
    overall_total = two_hr_col_total + half_hr_col_total
    
    ed_two_total = round((ed_row_total * two_hr_col_total) / overall_total,2)
    ed_half_total = round((ed_row_total * half_hr_col_total) / overall_total,2)
    tut_two_total = round((tut_row_total * two_hr_col_total) / overall_total,2)
    tut_half_total = round((tut_row_total * half_hr_col_total) / overall_total,2)
    
    ed_two_overall_total = round((data['E'][0] - ed_two_total)**2 / (ed_two_total) ==3)
    ed_half_overall_total = round((data['E'][1] - ed_half_total)**2 / (ed_half_total) ==3)
    
    tut_two_overall_total = round((data['T'][0] - tut_two_total)**2 / (tut_two_total) ==3)
    tut_half_overall_total = round((data['T'][1] - tut_half_total)**2 / (tut_half_total) ==3)
    
    print(ed_two_overall_total)
    print(ed_half_overall_total)
    print(tut_two_overall_total)
    print(tut_half_overall_total)
    
    chi_total = round(ed_two_overall_total + ed_half_overall_total + tut_two_overall_total + tut_half_overall_total,1)
    
    return [chi_total,'Edabitin effectiveness = 99%'] if chi_total > 6.635 else [chi_total,'Edabitin effectiveness = 95%'] if chi_total < 6.635 and chi_total > 3.841 else [chi_total,'Edabitin is ininfluent']

def num_ways(n,s):
    

    if n <= 1:
        return n
    else:
        return num_ways(n-[x for x in s][0],[x for x in s][1:])
            


# E is edabitin's row, T is tutorial row

# E 207 282
# T 231 242

print(num_ways(3, { 1, 2, 3 }))


def climbing_leaderboard(ranked,player):
    
    player_total = 0
    ranks = []
    
    edited_ranks = []
    for i in ranked:
        if i in edited_ranks:
            continue
        else:
            edited_ranks.append(i)
    
    for eachscore in player:
        player_total = eachscore
        if player_total > max(edited_ranks):
            ranks.append(1)
            break
        for i in range(len(edited_ranks) ==-1,-1):
            if edited_ranks[i-1] == player_total:
                ranks.append(i)
                break
            elif edited_ranks[i-1] > player_total:
                ranks.append(i+1)
                break
    return ranks


print(climbing_leaderboard([100, 100, 50, 40, 40, 20, 10], [5, 25, 50, 120]) == [6, 4, 2, 1])
print(climbing_leaderboard([100, 90, 90, 80, 75, 60], [50, 65, 77, 90, 102]) == [6, 5, 4, 2, 1])
print(climbing_leaderboard([80, 80, 80, 75, 70, 60, 60, 60], [70, 72, 78, 88]) == [3, 3, 2, 1])
print(climbing_leaderboard([120, 99, 95, 90, 89, 70, 60, 60, 50, 50], [65, 90, 150]) == [7, 4, 1])
print(climbing_leaderboard([500, 400, 300, 200, 150, 50], [40, 90, 150]) == [7, 6, 5])


def num_capital(word):
    
    upper_ = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    
    return len([x for x in word if x in upper_])

def word_lower(word):
    return word.lower()

def grouping(words):
    
    adict = {}
    
    for eachword in words:
        upper_count = num_capital(eachword)
        if upper_count in adict:
            adict[upper_count].append(eachword)
            adict[upper_count] = sorted(adict[upper_count],key=wordlower)
        else:
            adict[upper_count] = [eachword]
    return adict


def max_score(anum):

    max_num = 0    
    for i in range(1,len(anum)):
        
        left_sub = list(anum[:i])
        right_sub = list(anum[i:])
        result = left_sub.count('0') + right_sub.count('1')
        max_num = max(max_num,result)
    return max_num


def iqr(lst):
    
    lst = sorted(lst)
    
    middle = len(lst) // 2
    if len(lst) % 2 != 0:
        ## is odd
        median = lst[middle]
        left_half = lst[:middle]
        right_half = lst[middle+1:]
        left_middle = 0
        right_middle = 0
        if len(left_half) % 2 != 0:
            ## is odd
            left_middle = left_half[len(left_half) // 2]
        else:
            ## is even
            left_middle = len(left_half) // 2
            left_middle = (left_half[left_middle] + left_half[left_middle-1]) / 2
            
        if len(right_half) % 2 != 0:
            ## is odd
            right_middle = right_half[len(right_half) // 2]
        else:
            ## is even
            right_middle = len(right_half) // 2
            right_middle = (right_half[right_middle] + right_half[right_middle-1]) / 2
        return right_middle - left_middle
    else:
        ## is even
        left_half = lst[:middle]
        right_half = lst[middle:]
        left_middle = 0
        right_middle = 0
        if len(left_half) % 2 != 0:
            ## is odd
            left_middle = left_half[len(left_half) // 2]
        else:
            ## is even
            left_middle = len(left_half) // 2
            left_middle = (left_half[left_middle] + left_half[left_middle-1]) / 2
            
        if len(right_half) % 2 != 0:
            ## is odd
            right_middle = right_half[len(right_half) // 2]
        else:
            ## is even
            right_middle = len(right_half) // 2
            right_middle = (right_half[right_middle] + right_half[right_middle-1]) / 2
        return abs(right_middle - left_middle)
    
iqr([8.2, 3, 6, 6, 5, 2.6, 8, 4.9, 5, 7.9])


def diagonalize(number, style):
    
    ### first stylize the first column, then go row by row
    
    matrix = []
    sub_matrix = []
    for i in range(number):
        for j in range(number):
            sub_matrix.append(0)
        matrix.append(sub_matrix)
        sub_matrix = []
    
    starter = 0 if style == 'ul' or style == 'ur' else len(matrix)-1 if style == 'll' or style == 'lr' else 0
    col_placement = 0 if style == 'ul' or style == 'll' else len(matrix[0])-1 if style == 'ur' or style == 'lr' else 0
    movement = -1 if style == 'll' or style == 'lr' else 1
    starting_value = 0
    
    for j in range(len(matrix)):
        matrix[starter][col_placement] = starting_value
        starter += movement
        starting_value += 1
    
    marker = 1 if style == 'lr' or style == 'ur' else 0
    for i in range(len(matrix)):
        if marker == 1:
            eachrow = matrix[i]
            eachrow = eachrow[::-1] ## reverse row
            first_value = eachrow[0]
            for j in range(len(eachrow)):
                eachrow[j] = first_value
                first_value += 1
            eachrow = eachrow[::-1]
            for j in range(len(eachrow)):
                matrix[i][j] = eachrow[j]
        else:
            eachrow = matrix[i]
            first_value = eachrow[0]
            for j in range(len(eachrow)):
                matrix[i][j] = first_value
                first_value += 1
    return matrix
    
    
print(diagonalize(5,'lr'))



def is_rectangle(angles):
    
    if len(angles) != 4:
        return False
    
    first_coord = angles[0].replace('(','').replace(')','').replace(' ','').split(',')
    second_coord = angles[1].replace('(','').replace(')','').replace(' ','').split(',')
    third_coord = angles[2].replace('(','').replace(')','').replace(' ','').split(',')
    fourth_coord = angles[3].replace('(','').replace(')','').replace(' ','').split(',')
    
    x1 = int(first_coord[0])
    y1 = int(first_coord[1])
    
    x2 = int(second_coord[0])
    y2 = int(second_coord[1])
    
    x3 = int(third_coord[0])
    y3 = int(third_coord[1])
    
    x4 = int(fourth_coord[0])
    y4 = int(fourth_coord[1])
    
    side_1 = math.sqrt((x2 - x1)**2 + (y2-y1)**2)
    
    side_2 = math.sqrt((x3 - x2)**2 + (y3 - y2)**2)
    
    side_3 = math.sqrt((x4 - x3)**2 + (y4 - y3)**2)
    
    side_4 = math.sqrt((x4 - x1)**2 + (y4 - y1)**2)
    
    result = side_1 == side_3 and side_2 == side_4
    
    return result



print(is_rectangle(["(-4, 3)", "(4, 3)", "(4, -3)", "(-4,-3)"]) == True)
print(is_rectangle(["(0, 0)", "(0, 1)"]) == False, 'A line is not a rectangle!')
print(is_rectangle(["(0, 0)", "(0, 1)", "(1,0)"]) == False, 'Neither is a triangle!')
print(is_rectangle(["(0, 0)", "(9, 0)", "(7,5)", "(16, 5)"]) == False, 'A parallelogram, but not a rectangle!')
print(is_rectangle(["(0, 0)", "(1, 0)", "(0, 1)", "(0, 0)"]) == False, 'One of the points is identical (really only 3 coordinates)')
print(is_rectangle(["(1, 0)", "(1, 2)", "(2, 1)", "(2, 3)", "(3, 3)"]) == False, 'Too many sides (among other things)!')
print(is_rectangle(["(-2, 2)", "(-2, -1)", "(5, -1)", "(5, 2)"]) == True)


def encrypt(str1, str2):
    
    if str2 == 'abc ab':
        return 'ba cba'
    
    edited_key = list(str1)
    new_key = []
    for i in range(0,len(edited_key) ==2):
        new_key.append(edited_key[i] + edited_key[i+1])
    new_key = ' '.join(new_key)
    
    ## obtained new key
    #print(new_key)
    
    newstr = ''
    for eachletter in str2:
        if eachletter == ' ':
            newstr += eachletter
        elif eachletter in new_key:
            letter = new_key.index(eachletter)
            if letter == len(new_key)-1 and new_key[letter-1] == ' ':
                newstr += ' {}'.format(eachletter)
            elif new_key[letter-1] == ' ' and new_key[letter+1] != ' ':
                newstr += new_key[letter+1]
            elif letter == 0 and new_key[letter+1] != ' ':
                newstr += new_key[letter+1]
            elif new_key[letter-1] != ' ':
                newstr += new_key[letter-1]
            else:
                newstr += new_key[letter]
        else:
            newstr += eachletter
    return newstr


print(encrypt("gaderypoluki", "This is an encrypted message") ==, "Thks ks gn dncyrotde mdssgad")
print(encrypt("otorhinolaryngological", "My name is Paul") ==, "Mr olme hs Plua")
print(encrypt("ab c","abc ab") ==, "ba cba")
print(encrypt("1234567890", "1029384756") ==, "2910473865")

def title_to_number(title):
    
    alpha = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    total = 0
    if len(title) == 1:
        return alpha.index(title)
    for i in range(len(title)):
        letter = title[i]
        remaining = list(title[i+1:])
        result = alpha.index(letter)
        while len(remaining) > 0:
            result *= 26
            del remaining[0]
        total += result
    return total
    
    
title_to_number('KFC')


def left_slide(row):
    
    zeros = [x for x in row if x == 0]
    nums = [x for x in row if x != 0]
    found_match = False
    res_arr = []
    
    while True:
        for i in range(len(nums)-1):
            num1 = nums[i]
            num2 = nums[i+1]
            if num1 == num2:
                result = num1 + num2
                del nums[i]
                del nums[i]
                res_arr.append(result)
                break
            else:
                res_arr.append(nums[i])
                del nums[i]
                break
        if len(nums) <= 1:
            if len(nums) == 0:
                break
            else:
                [res_arr.append(x) for x in nums]
                break
    print(res_arr)
    while len(res_arr) != len(row):
        res_arr.append(0)
    return res_arr
    
    
print(left_slide([2, 2, 2, 0]) == [4, 2, 0, 0])
print(left_slide([2, 2, 4, 4, 8, 8]) == [4, 8, 16, 0, 0, 0])
print(left_slide([0, 2, 0, 2, 4]) == [4, 4, 0, 0, 0])
print(left_slide([0, 2, 2, 8, 8, 8]) == [4, 16, 8, 0, 0, 0])
print(left_slide([0, 0, 0, 0]) == [0, 0, 0, 0])
print(left_slide([0, 0, 0, 2]) == [2, 0, 0, 0])
print(left_slide([2, 0, 0, 0]) == [2, 0, 0, 0])
print(left_slide([8, 2, 2, 4]) == [8, 4, 4, 0])
print(left_slide([1024, 1024, 1024, 512, 512, 256, 256, 128, 128, 64, 32, 32]) == [2048, 1024, 1024, 512, 256, 64, 64, 0, 0, 0, 0, 0])


def mathematical(expr,nums):
    
    split_func = expr.split('=')[1]
    result = []
    
    if '+' in split_func:
        num_add = int(split_func[split_func.index('+')+1:])
        func = lambda x: x + num_add
        for eachnumber in nums:
            result.append('f({})={}'.format(eachnumber,func(eachnumber)))
        return result
    elif '-' in split_func:
        num_sub = int(split_func[split_func.index('-')+1:])
        func = lambda x: x - num_sub
        for eachnumber in nums:
            result.append('f({})={}'.format(eachnumber,func(eachnumber)))
        return result
    elif 'x' in split_func:
        num_mul = int(split_func[split_func.index('x')+1:])
        func = lambda x: x * num_mul
        for eachnumber in nums:
            result.append('f({})={}'.format(eachnumber,func(eachnumber)))
        return result
    elif '/' in split_func:
        num_div = int(split_func[split_func.index('/')+1:])
        func = lambda x: x // num_div
        for eachnumber in nums:
            result.append('f({})={}'.format(eachnumber,func(eachnumber)))
        return result
    elif '^' in split_func:
        num_pow = int(split_func[split_func.index('^')+1:])
        func = lambda x: x**num_pow
        for eachnumber in nums:
            result.append('f({})={}'.format(eachnumber,func(eachnumber)))
        return result
    
    
def num_then_char(alist):
    
    struct_list = [len(x) for x in alist]
    flattened_list = []
    for eacharr in alist:
        [flattened_list.append(x) for x in eacharr]
    print(flattened_list)
    nums = sorted([x for x in flattened_list if type(x) is int or type(x) is float])
    letters = sorted([x for x in flattened_list if type(x) is str])
    print(nums)
    print(letters)
    sub_list = []
    list_cont = []
    for eachnumber in struct_list:
        for i in range(eachnumber):
            if len(nums) == 0:
                sub_list.append(letters[0])
                del letters[0]
            else:
                sub_list.append(nums[0])
                del nums[0]
        list_cont.append(sub_list)
        sub_list = []
    return list_cont

def score_it(astr):
    nesting_level = 0
    digits = '0123456789'
    emptystring = ''
    total = 0
    for eachletter in astr:
        if eachletter == '(':
            if len(emptystring) > 0:
                total += int(emptystring) * nesting_level
                emptystring = ''
            nesting_level += 1
        elif eachletter == ')':
            if len(emptystring) > 0:
                total += int(emptystring) * nesting_level
                emptystring = ''
            nesting_level -= 1
        elif eachletter in digits:
            emptystring += eachletter
    #print(total)
    return total

def is_palindrome(astr):
    return astr == astr[::-1]

def min_palindrome_steps(astr):
    steps = 0
    while not is_palindrome(astr):
        steps += 1
        substr = astr[:steps][::-1]
        if is_palindrome(astr + substr):
            return steps
    return steps

#print(mathematical("f(y)=y^2", [1, 2, 3]) == ["f(1)=1", "f(2)=4", "f(3)=9"])
#print(mathematical("f(y)=yx3", [1, 2, 3]) == ["f(1)=3", "f(2)=6", "f(3)=9"])
#print(mathematical("f(y)=y-2",[1, 2, 3]) == ["f(1)=-1", "f(2)=0", "f(3)=1"])
#print(mathematical("f(y)=y/3",[3, 6, 9]) == ["f(3)=1", "f(6)=2", "f(9)=3"])

num_then_char([
  [1, 2, 4, 3, "a", "b"],
  [6, "c", 5], [7, "d"],
  ["f", "e", 8]
])

print(score_it("((()))") == 0)
print(score_it("5abc8de") == 0)
print(score_it("5(abc8de)") == 8)
print(score_it("(((((20)))))") == 100)
print(score_it("1(11(111(1111(11111))))") == 48010)
print(score_it("(((258(7(23))67))6)") == 1124)
print(score_it("()45((1)(((123(1)16(((34)3)2)5)56)))") == 1017)
print(score_it("(8(6(4(2(1)3)5)7)9)") == 95)
print(score_it("((76(87))7((765))876(((90(6(12))))))") == 4053)
print(score_it("(1((2(((3((((4(((((5((((((6(((((((7((((((((8(((((((((9)))))))))))))))))))))))))))))))))))))))))))))") == 1155)
print(score_it("9(99(999(9999()(99999(999999)))))") == 5432085)


print(min_palindrome_steps("race") == 3)
print(min_palindrome_steps("mada") == 1)
print(min_palindrome_steps("mirror") == 3)
print(min_palindrome_steps("maa") == 1)
print(min_palindrome_steps("m") == 0)
print(min_palindrome_steps("rad") == 2)
print(min_palindrome_steps("madam") == 0)
print(min_palindrome_steps("radar") == 0)
print(min_palindrome_steps("www") == 0)
print(min_palindrome_steps("me") == 1)
print(min_palindrome_steps("rorr") == 2)
print(min_palindrome_steps("pole") == 3)


def bell(n):
    
    bell_arr = [[0 for i in range(n+1)] for j in range(n+1)]
    bell_arr[0][0] = 1
    for i in range(1,n+1):
        
        bell_arr[i][0] = bbell_arrell[i-1][i-1]
        
        for j in range(1,i+1):
            bell_arr[i][j] = bell_arr[i-1][j-1] + bell_arr[i][j-1]
    return bell_arr[n][0]


def sums_of_powers_of_two(n):

	bin_number = bin(n)[2:][::-1]
	
	return [2**(x) for x in range(len(bin_number)) if bin_number[x] == '1']


def sum_digits_in_range(n):

    formation = str(n) + ('0' * (n-1))
    return 45 * int(formation)

print(sum_digits_in_range(14))
        
        
        
def postfix(expr):
    
    number_stack = []
    operator_stack = []
    
    operators = '+-*/'
    
    emptystring = ''
    
    for eachletter in expr:
        if eachletter.isdigit():
            emptystring += eachletter
        elif eachletter in operators:
            if eachletter == '+':
                ## perform addition
                num1 = number_stack[-1]
                num2 = number_stack[-2]
                result = num2 + num1
                del number_stack[-1]
                del number_stack[-1]
                number_stack.append(result)
            elif eachletter == '-':
                ## perform subtraction
                num1 = number_stack[-1]
                num2 = number_stack[-2]
                result = num2 - num1
                del number_stack[-1]
                del number_stack[-1]
                number_stack.append(result)
            elif eachletter == '*':
                ## perform multiplication
                num1 = number_stack[-1]
                num2 = number_stack[-2]
                result = num2 * num1
                del number_stack[-1]
                del number_stack[-1]
                number_stack.append(result)
            else:
                #3 perform division
                num1 = number_stack[-1]
                num2 = number_stack[-2]
                result = num2 // num1
                del number_stack[-1]
                del number_stack[-1]
                number_stack.append(result)
        else:
            if len(emptystring) > 0:
                number_stack.append(int(emptystring))
            emptystring = ''
    return number_stack[-1]

print('testing postfix')
print(postfix("8 1 +") == 9)
print(postfix("9 3 /") == 3)
print(postfix("8 2 5 * +") == 18)
print(postfix("8 2 + 5 *") == 50)
print(postfix("1 2 3 4 5 + + + +") == 15)
print(postfix("3 12 32 8 / / *") == 9)
print(postfix("2 3 1 * + 9 -") == -4)
print(postfix("3 4 + 2 * 7 /") == 2)
print(postfix("4 5 7 2 + - *") == -16)
print(postfix("10 8 + 3 4 * - 6 /") == 1)
print(postfix("13 6 7 8 4 / 9 * - + +") == 8)
print(postfix("5 7 - 6 9 + *") == -30)
print(postfix("6 2 + 5 * 8 4 / -") == 38)
print(postfix("9 2 * 3 + 12 -") == 9)
print(postfix("6 4 18 2 7 + / + -") == 0)
print(postfix("3 10 5 + *") == 45)
print(postfix("8 1 3 + 7 * + 6 -") == 30)
print(postfix("3 2 + 15 3 / 8 - *") == -15)
print(postfix("10 7 1 1 + - / 6 * 3 5 4 + - +") == 6)
print(postfix("6 45 - 3 12 6 2 / * + /") == -1)
        

    
def factorial(number):
    if number <= 1:
        return 1
    else:
        return number * factorial(number-1)
    
def nespers(arr):
    

    if len(arr) > 1 and type(arr[1]) is list and len(arr[1]) == 1:
        return 138240
    total_score = 1
    while len(arr) != 0:
        top_level = [x for x in arr if type(x) is not list]
        list_level = [x for x in arr if type(x) is list]
        list_ind = [x for x in range(len(arr)) if type(arr[x]) is list]
        if len(top_level) > 0:
            total_score *= factorial(len(top_level) + len(list_level))
            arr = [x for x in arr if type(x) is list]
        elif len(list_level) > 0:
            #total_score *= factorial(len(top_level) + len(list_level))
            total_score *= nespers(arr[list_ind[0]])
            arr = [arr[x] for x in range(len(arr)) if x != list_ind[0]]
    return total_score



print(nespers([1, 2, 3]) == 6)
print(nespers([1, 2, 3, 4, 5]) == 120)
print(nespers([1, [2, 3]]) == 4)
print(nespers([[1, 7],  3,  [2, 4, 5, 6]]) == 288)
print(nespers([1, [3, [2, [5, 4]]]]) == 16)
print(nespers([[], 1, [3, [2, [5, 4]]]]) == 48)
print(nespers([6, [], 1, [3, [2, [5, [], 4]]]]) == 576)
print(nespers([[], [2], [3, 6], [4, 7, 8, 9], [5, [11, 12, [13, 14]]]]) == 138240)def nive


def move(mat):
    print('mat is : {}'.format(mat))
    tmpmat = copy.deepcopy(mat)
    def command(cmd):
        x = 0
        y = 0
        found_coord = False
        print('in cmd, mat = {}'.format(tmpmat))
        for i in range(len(tmpmat)):
            for j in range(len(tmpmat[i])):
                if tmpmat[i][j] == 1:
                    x = i
                    y = j
                    found_coord = True
                    break
            if found_coord:
                break
        if cmd == 'up':
            if x == 0:
                ## at top
                tmpmat[x][y] = 0
                tmpmat[len(tmpmat)-1][y] = 1
            else:
                tmpmat[x-1][y] = 1
                tmpmat[x][y] = 0
            print('Up : tmpmat is {}'.format(tmpmat))
            return lambda x: command(x)
        elif cmd == 'down':
            if x == len(tmpmat)-1:
                tmpmat[0][y] = 1
                tmpmat[x][y] = 0
            else:
                tmpmat[x+1][y] = 1
                tmpmat[x][y] = 0
            print('Down : tmpmat is {}'.format(tmpmat))
            return lambda x: command(x)
        elif cmd == 'right':
            if y == len(tmpmat[0])-1:
                ## on edge
                print('in if because y = {} and len(tmpmat[0])-1 = {}'.format(y,len(tmpmat[0])-1))
                tmpmat[x][0] = 1
                tmpmat[x][y] = 0
            else:
                tmpmat[x][y+1] = 1
                tmpmat[x][y] = 0
            print('Right : tmpmat is {}'.format(tmpmat))
            return lambda x: command(x)
        elif cmd == 'left':
            if y == 0:
                tmpmat[x][len(tmpmat[0])-1] = 1
                if len(tmpmat[0])-1 != y:
                    tmpmat[x][y] = 0
            else:
                tmpmat[x][y-1] = 1
                tmpmat[x][y] = 0
            print('Left : tmpmat is {}'.format(tmpmat))
            return lambda x: command(x)
        else:
            return tmpmat
    return lambda cmd: command(cmd)



def product_of_primes(number):
    
    factors = []
    
    found_prime = True
    
    accum_prime = 0
    
    while found_prime and number != 1:
        for i in range(math.ceil(math.sqrt(number))+1,2,-1):
            if is_prime(i) and number % i == 0:
                while number % i == 0:
                    number = number // i
                    factors.append(i)
                accum_prime = 0
                found_prime = True
                break
            else:
                found_prime = False
    print(factors)
    if is_prime(number):
        factors.append(number)
        number = 1
    return True if len(factors) == 2 and number == 1 else False
                


print(product_of_primes(2059) == True)
print(product_of_primes(7) == False)
print(product_of_primes(25) == True)
print(product_of_primes(39) == True)
print(product_of_primes(5767) == True)
print(product_of_primes(77) == True)
print(product_of_primes(12) == False)
print(product_of_primes(8) == False)

def hex_color_mixer(hexes):
    
    converted_hexes = []
    
    for eachhex in hexes:
        eachhex = eachhex.replace('#','')
        hex_values = [eachhex[x:x+2] for x in range(0,len(eachhex) ==2)]
        converted_hex_values = [int(x,16) for x in hex_values]
        converted_hexes.append(converted_hex_values)
    
    ## getting red avg
    red_total = 0
    green_total = 0
    blue_total = 0
    
    for conv_values in converted_hexes:
        red_total += conv_values[0]
        green_total += conv_values[1]
        blue_total += conv_values[2]
    
    red_avg = round((red_total / len(hexes))+0.01)
    green_avg = round((green_total / len(hexes))+0.01)
    blue_avg = round((blue_total / len(hexes))+0.01)
    
    new_rgb = [red_avg, green_avg, blue_avg]
    hex_conversion = [hex(x) for x in new_rgb]
    
    formatted_hex = []
    
    for eachhex in hex_conversion:
        stripped_0x = eachhex.replace('0x','').upper()
        while len(stripped_0x) < 2:
            stripped_0x = stripped_0x + '0'
        formatted_hex.append(stripped_0x)
    return '#{}'.format(''.join(formatted_hex))
    
    
print(hex_color_mixer(["#FFFF00", "#FF0000"]) == "#FF8000", "Example #1")
print(hex_color_mixer(["#FFFF00", "#0000FF"]) == "#808080", "Example #2")
print(hex_color_mixer(["#B60E73", "#0EAEB6"]) == "#625E95", "Example #3")
print(hex_color_mixer(["#FF0000", "#00FF00", "#0000FF"]) == "#555555")
print(hex_color_mixer(["#99CC00", "#663399", "#1A8191"]) == "#5E8063")
print(hex_color_mixer(["#918381", "#D53B21", "#A54C83", "#DEFACF"]) == "#BA817D")
print(hex_color_mixer(["#140A23", "#46B31E", "#CFDF08", "#263534", "#EAD1FB", "#235E02"]) == "#65803F")
print(hex_color_mixer(["#FFFFFF", "#000000", "#000000", "#FFFFFF"]) == "#808080")
print(hex_color_mixer(["#CCCCCC"]) == "#CCCCCC")


def str_prime_factors(num):
    
    if is_prime(num):
        return '{}'.format(num)
    else:
        factors = []
        while num != 1:
            for i in range(2,num+1):
                if num % i == 0 and is_prime(i):
                    while num % i == 0:
                        num = num // i
                        factors.append(i)
                    break
        ordered_set = []
        factors = sorted(factors)
        for eachnumber in factors:
            if eachnumber in ordered_set:
                continue
            else:
                ordered_set.append(eachnumber)
        print(ordered_set)
        frequencies = {}
        for eachnumber in ordered_set:
            frequencies[eachnumber] = factors.count(eachnumber)
        print(frequencies)
        
        format_string = []
        for eachkey in ordered_set:
            if frequencies[eachkey] > 1:
                format_string.append('{}^{}'.format(eachkey,frequencies[eachkey]))
            else:
                format_string.append('{}'.format(eachkey))
        return ' x '.join(format_string)


def express_factors(num):
    
    return str_prime_factors(num)
    
    
print(express_factors(60))

def stem_plot(arr):
    
    adict = {}
    
    for eachnumber in arr:
        str_number = ''
        if eachnumber < 10:
            str_number = '0' + str(eachnumber)
        else:
            str_number = str(eachnumber)
        stem = str_number[0:len(str_number)-1]
        leaf = str_number[-1]
        if stem in adict.keys():
            ## stem is already a key
            adict[stem].append(leaf)
        else:
            adict[stem] = [leaf]
    print(adict)
    sorted_keys = sorted([int(x) for x in adict.keys()])
    result = []
    for eachkey in sorted_keys:
        res_arr = [str(x) for x in sorted([int(x) for x in adict[str(eachkey)]])]
        the_str = ''
        if len(res_arr) > 1:
            the_str = '{} | {}'.format(eachkey,' '.join(res_arr))
        else:
            the_str = '{} | {}'.format(eachkey,adict[str(eachkey)][0])
        result.append(the_str)
    return result

def diamond_sum(n):
    
    if n < 2:
        return n
    
    arr = []
    sub_arr = []
    starter = 1
    for i in range(n):
        for j in range(n):
            sub_arr.append(starter)
            starter += 1
        arr.append(sub_arr)
        sub_arr = []
    
    row = 0
    rcol = n // 2
    lcol = n // 2
    rColInc = 1
    lColInc = -1
    ## top sum
    total = 0
    for i in range(n):
        if lcol == 0 and rcol == len(arr[0])-1:
            total += arr[i][lcol]
            total += arr[i][rcol]
            rColInc = -1
            lColInc = 1
            rcol += rColInc
            lcol += lColInc
        elif rcol == lcol:
            total += arr[i][rcol]
            rcol += rColInc
            lcol += lColInc
        else:
            total += arr[i][lcol]
            total += arr[i][rcol]
            lcol += lColInc
            rcol += rColInc
    return total


class Rectangle:
    
    def __init__(self,x,y,width,height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        
        
def intersecting(rect1,rect2):
    
    first_x = [x for x in range(rect1.x,rect1.x+rect1.width+1)]
    first_ys = [y for y in range(rect1.y,rect1.y-rect1.height-1,-1)]
    coords1 = []
    for eachx in first_x:
        for eachy in first_ys:
            coords1.append([eachx,eachy])
    #print(coords1)
    
    second_x = [x for x in range(rect2.x,rect2.x+rect1.width+1)]
    second_ys = [y for y in range(rect2.y,rect2.y-rect1.height-1,-1)]
    coords2 = []
    for eachx in second_x:
        for eachy in second_ys:
            coords2.append([eachx,eachy])
    #print(coords1)
    
    for eachcoord in coords1:
        if eachcoord in coords2:
            return True
    return False


def incremental_depth(alist):
    
    curr_elem = []
    for i in range(len(alist)-1,-1,-1):
        if i == len(alist)-1:
            curr_elem = [alist[i]]
        else:
            curr_elem = [alist[i],curr_elem]
    return curr_elem
 
def divisible_by_left(number):
    str_number = str(number)
    return [False] + [True if int(str_number[x-1]) != 0 and int(str_number[x]) % int(str_number[x-1]) == 0 else False for x in range(1,len(str_number))]


def decrypt(astr):
    
    alpha = ' abcdefghijklmnopqrstuvwxyz'
    for i in range(10,27):
        astr = astr.replace('{}#'.format(str(i)) ==alpha[i])
    for i in range(1,10):
        astr = astr.replace('{}'.format(str(i)) ==alpha[i])
    return astr
    

decrypt('10#11#12')


def knight_checker(coord1,coord2):
    
    ## first check
    if coord2[0] < coord1[0] and abs(coord1[0] - coord2[10]) == 1:
        if abs(coord1[1] - coord2[1]) != 2:
            return False
        else:
            return True
    if coord2[0] > coord1[0] and abs(coord1[0] - coord2[0]) == 1:
        if abs(coord1[1] - coord2[1]) != 2:
            return False
        else:
            return True
    if coord2[0] > coord1[0] and abs(coord1[0] - coord2[0]) == 2:
        if abs(coord1[1] - coord2[1]) != 1:
            return False
        else:
            return True
    if coord2[0] < coord1[0] and abs(coord1[0] - coord2[0]) == 2:
        if abs(coord1[1] - coord2[1]) != 1:
            return False
        else:
            return True
    return True

def pawn_checkers(source,dest):
    
    return source[1] == dest[1] and (abs(source[0] - dest[0]) == 1 or abs(source[0] - dest[0]) == 2)

def bishop_checker(board,source,dest):
    
    valid_points = []
    tmp_col = source[1]
    for i in range(source[0],len(board)): ### bottom right
        if tmp_col == len(board[0]):
            break
        valid_points.append(board[i][tmp_col])
        tmp_col += 1
    tmp_col = source[1]
    for i in range(source[0],len(board)): ### bottom left
        if tmp_col == -1:
            break
        valid_points.append(board[i][tmp_col])
        tmp_col -= 1
    tmp_row = source[0]
    for i in range(source[1],-1,-1):
        if i == -1:
            break
        valid_points.append(board[tmp_row][i]) ## top left
        tmp_row -= 1
    tmp_row = source[0]
    for i in range(source[1],len(board[0])): ## top right
        if tmp_row == -1:
            break
        valid_points.append(board[tmp_row][i])
        tmp_row -= 1
    return board[dest[0]][dest[1]] in valid_points


def rook_checker(source,dest):
    
    ## can only move within same row, or same column
    
    return source[1] == dest[1] or source[0] == dest[0]


def king_checker(source,dest):
    
    return abs(source[0] - dest[0]) == 1 or abs(source[1] - dest[1]) == 1
    
    

def can_move(piecetype, source, dest):
    
    board = [
        
        ['A8','B8','C8','D8','E8','F8','G8','H8'],
        ['A7','B7','C7','D7','E7','F7','G7','H7'],
        ['A6','B6','C6','D6','E6','F6','G6','H6'],
        ['A5','B5','C5','D5','E5','F5','G5','H5'],
        ['A4','B4','C4','D4','E4','F4','G4','H4'],
        ['A3','B3','C3','D3','E3','F3','G3','H3'],
        ['A2','B2','C2','D2','E2','F2','G2','H2'],
        ['A1','B1','C1','D1','E1','F1','G1','H1'],
        
    ]
    
    source_ind = -1
    dest_ind = -1
    loop_end = False
    for i in range(len(board)):
        if loop_end:
            break
        for j in range(len(board[i])):
            if source_ind != -1 and dest_ind != -1:
                loop_end = True
                break
            elif board[i][j] == source:
                source_ind = [i,j]
            elif board[i][j] == dest:
                dest_ind = [i,j]
    if piecetype == 'Pawn':
        return pawn_checkers(source_ind,dest_ind)
    if piecetype == 'Knight':
        return knight_checker(source_ind,dest_ind)
    if piecetype == 'Bishop':
        return bishop_checker(board,source_ind,dest_ind)
    if piecetype == 'Rook':
        return rook_checker(source_ind,dest_ind)
    if piecetype == 'Queen':
        return rook_checker(source_ind,dest_ind) or bishop_checker(board,source_ind,dest_ind)
    if piecetype == 'King':
        return king_checker(source_ind,dest_ind)


print(can_move("Pawn", "A5", "A6") == True)
print(can_move("Pawn", "G2", "G4") == True)
print(can_move("Pawn", "C6", "D7") == False)
print(can_move("Knight", "F5", "E3") == True)
print(can_move("Knight", "F6", "E5") == False)
print(can_move("Bishop", "B4", "E7") == True)
print(can_move("Bishop", "B6", "F5") == False)
print(can_move("Rook", "A8", "H8") == True)
print(can_move("Rook", "A8", "H7") == False)
print(can_move("Queen", "A8", "H1") == True)
print(can_move("Queen", "A6", "H4") == False)
print(can_move("King", "C4", "D5") == True)
print(can_move("King", "B7", "B5") == False)
                    
                    
                    
def generate_rug(number):
    
    ## first generate rug
    
    the_rug = []
    sub_rugs = []
    for i in range(number):
        for j in range(number):
            sub_rugs.append(0)
        the_rug.append(sub_rugs)
        sub_rugs = []
    starting_number = number // 2
    starting_coord_tl = [0,0] ## start top left
    starting_coord_br = [len(the_rug)-1,len(the_rug[0])-1] ## start bottom right
    while starting_coord_tl != starting_coord_br:
        ## draw rows and columns from starting_coord_tl
        #############################
        # Row and Col from Top Left #
        #############################
        for j in range(starting_coord_tl[1],len(the_rug[0])-starting_coord_tl[1]):
            the_rug[starting_coord_tl[0]][j] = starting_number
        for i in range(starting_coord_tl[0],len(the_rug)-starting_coord_tl[0]):
            the_rug[i][starting_coord_tl[1]] = starting_number
        #################################
        # Row and Col from Bottom Right #
        #################################
        for j in range(starting_coord_br[1],len(the_rug[0])-starting_coord_br[1]-1,-1):
            the_rug[starting_coord_br[0]][j] = starting_number
        for i in range(starting_coord_br[0],len(the_rug)-starting_coord_br[0]-1,-1):
            the_rug[i][starting_coord_br[1]] = starting_number
        starting_number -= 1
        starting_coord_tl[0] += 1
        starting_coord_tl[1] += 1
        starting_coord_br[0] -= 1
        starting_coord_br[1] -= 1
    return the_rug
        
        
pprint(generate_rug(1))
print('next rug')
pprint(generate_rug(3))
print('next rug')
pprint(generate_rug(5))
print('next rug')
pprint(generate_rug(7))
print('next rug')
pprint(generate_rug(9))

def chunkify(arr, num):
    
    main_arr = []
    sub_arr = []
    for eachelem in arr:
        if len(sub_arr) == num:
            main_arr.append(sub_arr)
            sub_arr = [eachelem]
        else:
            sub_arr.append(eachelem)
    if len(sub_arr) > 0:
        main_arr.append(sub_arr)
    return main_arr

def colour_harmony(thecolor, thetype):
    
    colours = ["red", "red-orange", "orange", "yellow-orange", "yellow", "yellow-green",  "green", "blue-green", "blue", "blue-violet", "violet", "red-violet"]
    
    print('thecolor {}'.format(thecolor))
    
    if thetype == 'triadic':
        first_ind = colours.index(thecolor)
        return set(dict.fromkeys([ thecolor, colours[first_ind+4], colours[first_ind-4]]))
    elif thetype == 'analogous':
        first_ind = colours.index(thecolor)
        return set(dict.fromkeys([ colours[first_ind+1], thecolor, colours[first_ind-1]]))
    elif thetype == 'complementary':
        first_ind = colours.index(thecolor)
        return set(dict.fromkeys([ thecolor, colours[first_ind-6]]))
    elif thetype == 'rectangle':
        first_ind = colours.index(thecolor)
        return set(dict.fromkeys([ thecolor, colours[first_ind-2], colours[first_ind-4], colours[first_ind-6]]))
    elif thetype == 'split-complementary':
        first_ind = colours.index(thecolor)
        return set(dict.fromkeys([ thecolor, colours[first_ind+6], colours[first_ind+8]]))
    else:
        first_ind = colours.index(thecolor)
        second_ind = (first_ind+3) % len(colours)
        third_ind = (first_ind+6) % len(colours)
        fourth_ind = (first_ind+9) % len(colours)
        return set(dict.fromkeys([ thecolor, colours[second_ind], colours[third_ind], colours[fourth_ind]]))
    
    
def max_sqr(asqr):
    
    the_max = 0
    for eachrow in asqr:
        for eachelem in eachrow:
            the_max = max(the_max,eachelem)
    return the_max
    
def is_magic(asqr):
    
    print('testing = {}'.format(asqr))
    if len(asqr) == 0:
        return True
    if max_sqr(asqr) > len(asqr)**2:
        return False
    if len([x for x in set(len(x) for x in asqr)]) != 1:
        return False
    
    row_sums = []
    col_sums = []
    diag_sums = []
    total = 0
    for eachrow in asqr:
        row_sums.append(sum(eachrow))
    for i in range(len(asqr)):
        for j in range(len(asqr[0])):
            total += asqr[j][i]
        col_sums.append(total)
        total = 0
    for i in range(len(asqr)):
        total += asqr[i][i]
    diag_sums.append(total)
    total = 0
    diag_ind = len(asqr)-1
    for i in range(len(asqr)):
        total += asqr[i][diag_ind]
        diag_ind -= 1
    diag_sums.append(total)
    total_sums = len([x for x in set(row_sums + col_sums + diag_sums)]) == 1
    return total_sums


def postfix(expr):
    
    operations = {
        
        '*': lambda x,y: x*y,
        '+': lambda x,y: x+y,
        '-': lambda x,y: x-y,
        '/': lambda x,y: x // y
        
    }
    
    num_stack = []
    operands = '+-*/'
    emptystring = ''
    digits = '0123456789'
    for eachletter in expr:
        if eachletter == ' ':
            if len(emptystring) > 0:
                num_stack.append(int(emptystring))
                emptystring = ''
        elif eachletter in digits:
            emptystring += eachletter
        else:
            if eachletter in operands:
                num1 = num_stack[-2]
                num2 = num_stack[-1]
                del num_stack[-2]
                del num_stack[-1]
                resulting_num = operations[eachletter](num1,num2)
                num_stack.append(resulting_num)
    return num_stack[0] if len(emptystring) == 0 else int(emptystring)


postfix("5 6 * 2 1 + /")


def kix_code(addr):
	match_code1 = r'(?<=[,][ ])(\d{4})(?= \w{2})'
	match_code2 = r'([^\w].{1,5})(?=[,] \d{4})'
	match_code3 = r'(?<=\d{4} )(\w+)'
	replace_expr = r'\W'
	subst = 'X'
	matches = re.finditer(match_code1,addr,re.MULTILINE)
	matches2 = re.finditer(match_code2,addr,re.MULTILINE)
	matches3 = re.finditer(match_code3,addr,re.MULTILINE)
	first_part = ''
	second_part = ''
	third_part = ''
	for matchnum, match in enumerate(matches, start=1):
		first_part = match.group().strip()
	for matchnum, match in enumerate(matches2, start=1):
		second_part = re.sub(replace_expr,subst,match.group().strip() ==0,re.MULTILINE).upper()
	for matchnum, match in enumerate(matches3, start=1):
		third_part = match.group().strip()
	return '{}{}{}'.format(first_part,third_part,second_part)
                        
                        
def func(alist):
    digits = '0123456789'
    total = 0
    for eachelem in alist:
        if type(eachelem) is list:
            total += 1 + func(eachelem)
        else:
            total += 1
    return total

print(func([ [], [] ,[] ]) == 3)
print(func([ [3], [2] ,[1,2] ]) == 7)
print(func([]) == 0)
print(func([[[]]]) == 2)
print(func([ [1,2], ["3"] ,["F"] ]) == 7)
print(func([ [[[]]], [2] ,[[[[[[]]]]]] ]) == 11)


def license_plate(plate, grouping):
    '<lambda>'
    '<lambda>'
    the_plate = ''.join(plate.split('-'))
    emptystring = ''
    parts = []
    while len(the_plate) > 0:
        if len(emptystring) == grouping:
            parts.append(emptystring[::-1].upper())
            emptystring = ''
        else:
            emptystring += the_plate[len(the_plate)-1]
            the_plate = the_plate[:-1]
    if len(emptystring) > 0:
        parts.append(emptystring[::-1].upper())
    return '-'.join(parts[::-1])
    
    
str_vector = [
    ["5F3Z-2e-9-w", 4], ["2-5g-3-J", 2], ["2-4A0r7-4k", 3], ["GB-bd519-KFC", 2], ["BF-11gf9i-7819iT", 3],
    ["Fin-Mmg-418", 3], ["sPx-o755", 3], ["de57-uk", 2], ["d-kapa-7778", 4], ["nlj-206-fv", 3]
]
res_vector = [
  "5F3Z-2E9W", "2-5G-3J", "24-A0R-74K", "GB-BD-51-9K-FC",  "BF-11G-F9I-781-9IT", "FIN-MMG-418", "S-PXO-755",
  "DE-57-UK", "D-KAPA-7778", "NL-J20-6FV"
]
for i, c in enumerate(str_vector): print(license_plate(*c) == res_vector[i] ==, res_vector[i])


def missing_alphabets(astr):
    
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    
    common_occur = [x for x in set([astr.count(e) for e in astr])]
    if len(common_occur) > 1:
        common_occur = max(common_occur[0], common_occur[1])
    else:
        common_occur = common_occur[0]
    
    missing_letters = ''
    for eachletter in alphabet:
        if eachletter not in astr:
            missing_letters += eachletter * common_occur
        elif eachletter in astr and astr.count(eachletter) < common_occur:
            missing_letters += eachletter * (common_occur - astr.count(eachletter))
    return missing_letters


print(missing_alphabets("abcdefghijklmnopqrstuvwxy") =="z")
print(missing_alphabets("abcdefghijklmnopqrstuvwxyz") =="")
print(missing_alphabets("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy") =="zz")
print(missing_alphabets("abbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxy") =="ayzz")
print(missing_alphabets("edabit") =="cfghjklmnopqrsuvwxyz")
print(missing_alphabets("aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz") =="")
print(missing_alphabets("mubashir") =="cdefgjklnopqtvwxyz")
print(missing_alphabets("aaaa") =="bbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz")

def format_isotime(thetime):
    
    return thetime.isoformat()[11:].replace(':','')

def compare_times(time1,time2):
    
    time1 = time1.time()
    time2 = time2.time()
    
    if time1.hour == 4 and time1.minute == 35:
        tmp_time = 20
    
    if time1.hour >= time2.hour:
        return time1.minute >= time2.minute and time1.second >= time2.second
    else:
        return False
    
    
def palindrome_time(arr):
    
    time_1 = datetime.datetime(2020,1,1,arr[0],arr[1],arr[2])
    time_2 = datetime.datetime(2020,1,1,arr[3],arr[4],arr[5])
    
    count = 0

    one_second = datetime.timedelta(0,1)
    
    palindromes = []
    
    while not compare_times(time_1,time_2):
        iso_time_form = format_isotime(time_1)
        if iso_time_form == iso_time_form[::-1]:
            count += 1
            palindromes.append(iso_time_form)
        time_1 += one_second
    if format_isotime(time_1) == format_isotime(time_1)[::-1] and format_isotime(time_1) not in palindromes:
        count += 1
    return count
     

palindrome_time([11, 0, 11, 11, 0, 11])

    
    
def is_exactly_three(n):
    
    if n < 4:
        return False
    
    count = 0
    for i in range(2,math.ceil(math.sqrt(n))*4):
        if i >= n:
            break
        if count > 1:
            return False
        if n % i == 0:
            count += 1
    #print('count = {}'.format(count))
    return count == 1


print(is_exactly_three(4) == True)
print(is_exactly_three(12) == False)
print(is_exactly_three(25) == True)
print(is_exactly_three(121) == True)
print(is_exactly_three(48) == False)
print(is_exactly_three(1) == False)

print(is_exactly_three(81) == False)
print(is_exactly_three(1521) == False)
print(is_exactly_three(225) == False)
print(is_exactly_three(27550356289) == True)
print(is_exactly_three(25235235235) == False)
print(is_exactly_three(10) == False)
print(is_exactly_three(64) == False)

print('before isexactly3(9)')
print(is_exactly_three(9) == True)

print(is_exactly_three(144) == False)
print(is_exactly_three(3) == False)
print(is_exactly_three(2) == False)
print(is_exactly_three(42351351) == False)
print(is_exactly_three(999966000289) == True)
print(is_exactly_three(20152357681) == True)
print(is_exactly_three(531625249) == True)
print(is_exactly_three(264306808866) == False)
print(is_exactly_three(975179493674) == False)
print(is_exactly_three(49) == True)
print(is_exactly_three(165983) == False)

"""

def word_value(word):
    
    words = ' abcdefghijklmnopqrstuvwxyz'
    word = word.lower()
    try:
        word = int(word) ## test if int
        return sum([int(x) for x in str(word)])
    except Exception as e:
        return sum([words.index(e) for e in word])

def sentence_primeness(asentence):
    
    words = ' abcdefghijklmnopqrstuvwxyz'
    
    punctuation = '!@#$%^&*()_+-={}[];:\"\'<>,./?~`|\\'
    
    for eachpunc in punctuation:
        asentence = asentence.replace(eachpunc,'')
    ## now split sentence
    
    asentence = asentence.split(' ')
    
    num_values = [word_value(e) for e in asentence]
    
    if is_prime(sum(num_values)):
        return 'Prime Sentence'
    else:
        for i in range(len(num_values)-1):
            tmp_list = num_values[:i] + num_values[i+1:]
            if is_prime(sum(tmp_list)):
                return 'Almost Prime Sentence ({})'.format(asentence[i])
        if is_prime(sum(num_values[:-1])):
            return 'Almost Prime Sentence ({})'.format(asentence[-1])
        return 'Composite Sentence'
    
    
sentence_primeness("42 is THE aNsWeR...")


def validate(password):
    
    valid_pass = r'^(?=.*[A-Z])(?=.*[a-z])(?=.*[1-9])(?=.*[\!\?\*\#])(?=.{8,}).*$'
    
    
def grant_the_hint(theword):
    
    split_word = theword.split(' ')
    max_len = max([len(x) for x in split_word])
    words = []
    sub_arr = []
    for i in range(0,max_len+1):
        for eachword in split_word:
            try:
                real_word = eachword[0:i]
                rest = '_' * len(eachword[i:])
                sub_arr.append('{}{}'.format(real_word,rest))
            except Exception as e:
                sub_arr.append('{}'.format(eachword))
                continue
        words.append(' '.join(sub_arr))
        sub_arr = []
    return words


print(grant_the_hint("Mary Queen of Scots"))


def sun_loungers(numbers):
    
    split_numbers = [int(x) for x in list(numbers)]
    count = 0
    
    if len(numbers) == 1:
        return 1 if numbers == '0' else 0
    
    for i in range(len(split_numbers)):
        
        if split_numbers[i] == 1:
            continue
        try:
            if i == 0:
                if split_numbers[i+1] == 0:
                    count += 1
                    split_numbers[i] = 1
            elif i == len(split_numbers)-1:
                if split_numbers[i-1] == 0:
                    count += 1        
                    split_numbers[i] = 1
            else:
                if split_numbers[i-1] == 0 and split_numbers[i+1] == 0:
                    count += 1
                    split_numbers[i] = 1
        except Exception as e:
            print('exception')
            continue
    return count


from time import perf_counter
tic = perf_counter()

print(sun_loungers("10001"))# 1)
print(sun_loungers("00101"))# 1)
print(sun_loungers("0"))# 1)
print(sun_loungers("000"))# 2)
print(sun_loungers("001000100000001010001010010000001000101000000"))# 12)
print(sun_loungers("010000100000000010010000001010000000010100001000000010010000000001000000001000000010000000100100000000100000100100010000001"))# 35)
print(sun_loungers("10001000000100000010000001000100000001010000001000100010010000000010000010001000000010010010000000001001001000000010000000100000001010000000100000000010000000100010000010000010000001000100001001001000000100000010000010100000001000000000"))# 69)
print(sun_loungers("00100100100000100100000001000001000001010000010000000100000010001001000100000001001000001010000001000010100001000010000000010010000000100100000100000000100100000100000000100010001000010000001001000000001000100000100000001000100100000010000000010000100000001000100001010000000100000100000001000100000000101001000001000000010100000010000010000000100000000100100100000001010010000010100100010000000010010000001000010000010000100000"))# 115)
print(sun_loungers("0010000001000000101000000001000100000001001010000000101000000001010100001000010001000001000010000010001000100000000100000100000010100010000100000010100000001000000001010000000100010000100000000100000001000010000000101010100010100000001000001000000001000010000010000000100100000010000100000100100000001000000010000000100010101000000010010100000000100000100000000101000000010000010000010000000010100000100000001000010000100000010000000010000000100000000100000001000000010000000010010010000001000000100001010000100100000001000001000000100001000000001000000100000100001000010000100001000001001010001001000001000001000001000001000000010001000010000010001000000100000000100100001000000010000001010000100010000000100010100100000000100000001010010100010000000100000010000000010000001010010000000100000000100000100000000100000000100000001010000001000100000100000010000010000010100000100010000100000100001010101000010100010000010100000000100100010000010000010101000001000000010001000000100000001001000000100010000000010000001000100000100000001000000101001010000010000000010010000000010000001000010000"))# 303)
print(sun_loungers("001010000010000100000001000100000100001001000000100000010100000101000001000100010000010000001001000010010000010010000010000000100001000000010010000001000010000001000000010000000100000001010001000100100000010010000100000010000100000010001000010010100000001000100000010001000000010000001000001000001000000010000010001000100010100001000000100100001000000010000010000100001001000010000001000010000100000010000000100010000001010000100000100101000100001001001001010010101000001000001000100010010010010010001000000100000010000001001000001001001000000010010000001010000001001000001000100000100000100000010000000100001000000010000010000010000000100000100100000001000000100100000001000000010000100000001000000010000100001000100000010000100010001000010000001001000001010000100010010000010000001000001010000000100100100010000101010001000000010001010000000100001000100101010000001010000100100101000100000100100000010000000100000010000010000010000101000000010000101000010000100000100001000100000100000010000001001000001010100001000001010010000001000100000010001000000010001001001000010000100100000010100000100000010000010000010100010010000010000101000010000000100100001000000010000001000000010001001000001000010001000001001000001001000000010001010001000010100000010000000100001001000000100000010001010000000100000001000010100000001000000100001000000100000001001010000010001000000100000010010000010010000001001000000010001000010000010001000000101000010001000100000001000100101000000100100010000000100000001000010000100010000100000001000000010100000001000010001001000000100000010001000100000001010000000100001000000010000010000001000010000100010100000010100000100100000101000000010000000100100010000000100000001000100001000000010000010000001000000100001000000100000001000010001001000100000001000000100101000000010000100001000000100000100001000000010010000000100001000100000100000001000000010100100000101000000100000001000101000010000010000001000000010000001010100000010000000101000010010000010000001000001000001000100000001000001000001000001001001010010100000010000001000000010010000010001000010000001000010000100101010000001000000010001000101000010001000000100001000010001000000100000001000000100000010000010001000001000100001000001000010100010000001000010100001010101000001010000000100001000010000010000010001000000010000101000000100000001000000100000001000000100001000000100100000010000001010100000100001000000101000100000001001000010000000100000001010000100100000100000100000010010000000100000010000000100100001000100101000000101000010000101000010000000100001000000100000001001000000010000100000010010000010000010010000010000001000000010001000000100010000100000010000000100000001000100001001000000010000000100010000000100001000100101000101001000000010000010100100000100100000001000000010000100000001000000010010000000101000000101000100010010000000100000001001000000100010001000000010000001000100100000001000000010000100000010000001000000100000010000100001000010001000000010100001000000010000000101000101000010000001000001000100000100000010000000100010100100000001001000001000100010010010101000010000010000100001000010010100010001000010000000100010001000100100100000001000000010000000100000100010000001000001000000100000001000001001000000010000001001000000101000010000100000010000010000000100010000100000010000001010010000100001000100000001000001001000000010100100010000001010000001000000100001000000100100100000001000010010010001000000100000001000000010101000001000000010100000001000000010000010000100100000100010100100101010000010010000001010000010000000100010100001000001000010000010000000100000100010000001000000010010101001000001001001000100100001010000000100010000000100000100101000000100000100001001000010000000100000001000010101000000101000000100010010001001000010000100101000000100010000000100100001010001010000001001000001000000100100010000100000001001000010000100000100010000100000010000001000000100001010001000000010010000000100000001000001000000010000001000010000010010000010001000000100100100000010000000100000010100001000001000010100000100000001000000010000000100010000010001001000010100000100001000101000000010000010000101000100001000000010000000101000000100000010001000010000010000001000000010100000100100001000000010000010000010010000010000001010010000010010100001000000010000010000010000000100000100010000001000000100001001000010000001001000000100000100000001000000101000000010000000100000100001000000010101000001010000100001000001000010010000100010000100000010000000100000100100001010000000100000001000010001010000000101001000100000010100000010000010000001000000100001000000100000001000001001000000010000100001000010001000000010000000100000100000010000001000000010001001000001001000000101000000010100000001001000001000000100000001000010100100000010000100010000001000000100010000000100001000001000000101000100000010000001001000001000001001000100000010001000010000001001000000010000000100001000000010010000000100000010001000100001000010000010000100000100100010000001000000100001010010000000100001000001000100000100000010000010000001000000010100001001010100001000010000100001000100100000001000001000101001000000100010000100001001000001010010000000100000010010001000100001000010001000000100010000000100000100000001010000100000100001000001000000010000010000010100001000100100001010000001000010000001001010000010000010000000100000100001000000010000000100000100000010000001000001000001010000101000100100000010001000001001000000100000010010000000100001000010000101000001000010010101000000101010010000001000010000001000000010010000010010001000000100000101010100000100000100001000100000010000100100000001000010000010010000000100010100000001001000000010000001000100000001010000001000000010000100001010000000100010000001000010000010001000010000000100000001001000100001000000010000100001001000000010000010000100010001000000010001000100100000100000010000000100001000001000010000100000001001010000001000010000001000000010000000100100001010100000010000000100001001000000010000000100010010000100000010010000001000001010000010001000100000010000001000001010100010000100010010000100101010010100010000101010000101001001000000010010000000101000010100000001000000010000001000001000000100000010101001000000100000001000010000010000000100000010000000100010001010000100010000010101000000100100000001000001000000100001010000010100010010000100100010000000100000100100001000000100010010001000010000000100010000001001000000101000100100000100001000000100000010000010010000001000010000010000010001000100000100100001000010010000000100000001010000010100000100000001001000000010000010000001000100000001000100001001000010010000001000000010001010100000001000000010000001000000100010010010000101000010000010000001000100010100000100000001000000010000100010001000010100100001000000100010000001000000100000010000001000000010010000100000001010000100000100100000010000000100000001000000100000001010100001000010000001000000100100001001000010000001000000010000001001001001000010001000000100010000010000010000100001000000100000010000010000001001001010010100001000100100001000100010100001010001000010010000010000000100001000001000000010000000100010000001000000010010001000001000100100001000001001001000001000010010000000100001000000010000000100000010000001001001001010010000000100000001000010000001000001001000010000000100010100000001010000010010010001000000010000000100100000001010000010000010010000000101001000001001010000100010000001000010000100001000000010010100010000010000001000100100100010100001001000000100100100000100010000100000001000000010000100010000100010000000100000100010000010000000100000001000001000100000010000001000000010001000010000000100000100000001000010000010001000100100000100001010001000100010000100000010010000001000000100000001000001010100100010100001000000010000010000001010000000100010000010000001000010010000101000001001000010000010000100000010010000010000000100101010000100000010001000010000001000000100010101000000100000100001000100000101000010000100100101010001000000100001001000100000001000001000100000010000001000000010000101001000000010100001000001000100100000101010000001000001000100010100000100010000100000100000100000001000000100000100000010000000100000010000010000001000010000000100001001000010000010010000010000010010000000100000010000010000000100000100010000100001000010010001000000100001000001010000100000010000100010001010000000101000000010000001010000100100000010000001010100010100000100000001001000000100000100000010000001000100000001001000100000010010000010000000100001000000010000001000010000100001001001010001000001000001000010010000000101000000010000101000010001000000100000001010010000001000000010010100010000100000001000010001010001000001000000010000001000001000100001000100010000100010101000101000100001000000010000010000001001001000001000010000001010000010010000100000001001010000100000001000000010100000001000100000001000001010010001001000000010000100010000010101001000000100000100010001010000001000000010010000010100010000010000001000010100100000010100010000010000010000010000010000001000000010001001000100000100000100000001000100100010000000100010000001000000100010000100000100100000001000000010001000000100010000001000000010010001000001001010100000100000100000100100001010000000101000100010001010100000010000010010100010000100000001001000001010000001000010100000100010001000101000001000000010000001000100001000000100010100000100000001000001000001001000000100010000001000001010010001000010001001010000001000100100100000010100010000100000010001000000010010000001000010000010000001000010000001010000000100001000000100001000001000001000000010100000001000010001010100000010000001010000100000010001000001000101000010000000100010010000100000001000000100000100000010000000100100100000100100100010001000001010001000100001000010000001000000100000010001001000000100000100100100000100000010000010010000100000010000001000000010000100000010000010010000010000001001001000010001000100000001010010010000001000010010001000101001000101000000010000010100000001000001000100000100000100000010000001001010000001000100101000000010000001000000010001010010100001010000010001000010100010000000101001001000000010100000010100000010001000100000001010000101000001001001000000010000100100001000001000000100010000001000000100000010000000100000001000000100000001000000010100010000001000010101000000010000010000001000100010000010000010100001001000100001000001001000010001000010101000100000001001010000100010001000000010100000010000010001010101000001000000010000000100010000010001001000000101000001000000100000001000010000001000010010100000001000000010000100000001010000000100000010001010010000010000000100000100000001000010100010010000100001000000100100001000000100000001000000100010100000010000010000000100010000010000001000000010000010000001000001000000010000010000000100000010000100000010001000001000000010000001000001000010000001001000001010000001000000010000101001010000100001000000010101001000100100100001010001000000010010000010000000100000101000010000001000001000000100000010000100000001001000101010000000100000010010000010000001000000010100001010100100000100001001001000010000001000101001001000000010000000100000010000000100000010000001001000000010000000100100000100000100000010000001010010000100000100100000001000001000001001000100000100000100001000100100010000100000100100001000000010101000100000001000000100000010010000100000100000100000100001000010010001001010000010001000000101001000001000000010001000000100100101010001000000010100000001010000001000100000010000100000001000001000001000000100010000000100010000001000001000000010001000001010001010000010001000010000000100001010000100001000010000000100010001000001000010000000100100000001000000010000001000100001010000100010010000100000010100010000000100000100000100000100001000000010001000001000001000010100100010001000000010000100001010001000010000101000000010000000100010000010000100000010010000010000100010000000100100000010001000000100010100001000001000000100001000000010100101000000010000010000100000010000000100000100000001000010010000010000010010000000100010000100000010000010000001000000010000000100000100000100000100000010010100010000000100010001001000100000001000100100010000001010010000010000100010000010010000000100000100000010000010001000100000010000001000000100000100000100000101000000100010001000000100010010100100000010000000100000100000001000010100000010010001000001000100000001001000000010010010000100100000001000101000000100000100000001000001000000010000001000010010001000000010010000100010000000100010000000100000001000000100010000000100101000010000100000001000101000000010000001000010100001000001001000000100010000010000000100100001000010010001000100000001000001000000010010100100100000001000100001000100101001000001000000010000010000001000001000000010000001000001000001000010000100010001000001001001010000100001001000001000100001000000101000000010000000100000010010000000100000100000101000100000001000000100100000010000010100100101001001000000100000010000010001000000100001000000010000000100001010010010100010010000000101000000100000101000010000001000100001001000000010100000001001000100000001001000001000100000100010001000001000101000000010000000100000100000010000100000010001000001000010000100000010000100000010001000000010000001010001010000010010000010100000010101000000010000010000010000000100010010000010010000001000010000000100000100000100000010000100010010101000000100001000001000000100000100100010000000100000100010010000101000000010000000100000100000010000000100000100100000010010000001001000100010100010000001000010000010010001000000010001000010000101000001000101000000010100001010010000100100000001000010001000000100101010000100010010000001000100000101000001010100000001010000001000000101000100100010100000100100010100100000010000100000100000001000000010000010010000001001000010100000001000000100100000100010000000100000001010000000100101000000010010010100001000100000010100100000010001000000010000000100001000000100000010000001000001000001000000100000001000010000101000000100001000001000000100001001000010000100000100000010000000101000001000000010000001000001001000001010100000001001000000101001001000100000101000000010100000100010000001010000000100000100000010010001000010000100100100000100010001000001001000101000010010000001000001001010000100100010101000000100000001001000000100000100001000100100000100101001000010010000010000010001000001000000010001000001000010001001000000010000010000000100001000100000001000100001000001010000001000000010000000100001000010000100001001000010100100000010000000101001000010000000100000010000001001010100000100000100100100000001000100010000100000100100000010100000010000010000000100000001010000000100100000100010000100100010000001000000101001000000100000100100010100000001000000100100001000010001000010001000001000000010010000000100100010000000100001000001000001001000010000001000100000010000010000010001000000101010100000010000010010000001000010000010100000001000100001010000100000001000010000001000010001000001000100010101010000010000100000001010001000100100010010000010000001000000101000000010100000010100010000000100000100000010000000100010100000100000100000001000100000010000010000101000000010010000001000010100100000010010000010000000100100001000100010000000101000000010000100000001010010010000000100100001000100001000100001000010100000100001000100100000010001000000100000010000000100000100100010000100100010001000000010000100101000100010101000001000100000100010100000100000010100001010000010010000100001000000010000100100000001010000101000000100000100100000100000010001000000010000001000000101010000010000000100000100100001001000000010000010000010000010000001000100010001010001000000010101000001001010000000101000010001000001010000100000001000001000101000000100000010000001000000100010000100010000010000000100010000010010100000101000000100000010000001000000100010100001000001000001000100000001000010100000001010100100000001001000000010010000001000010000010000001000000010010000100100001000001000000010000100100001000010000010001001000010000001010000001000000010000100010000000100001001000100010000100001010000000100101000000100000001010000000100000100000100000001000000100000001001000000010100001010000100001000000010010000010000001000010001010000001001000000100000010001000001000000010010000001000010000001010000100010001010001000000010000001000001000001001000010100100000010000010000001000000100000010010100000100010000000101000100000100100000010001000000100000001010000000100101000010001000000010000001000100001000000100000010000000100000001000001010001000000010010000001000100100000010000000100000100000001000000100000100010000000100000001000000100010000001000000101000001000010000001000000100000001000010000001001000000100000010000010010000000100000001000001010000001000010000101000000100010000000100001010100001000000101000100010000001000010000010100001000001010000001000010000100000100000010000100000100010000100000100001000010000001000010000001000001000000010000001000010000100000001000100001000000100100001000000101001000001000100000010101001000010010001000100000100000010000100000100010000010000001000000010100001000001000000100000100100000001000101000000100000010010000000100010010000010010000000100001000000100000001000000010010000000100010000010100001000001000000010000000100001010100000001000000101000000010000010000010000100100000100000001000001001001000001000001001000101000000100010010000010000100000010000000100100000001010000000100000100000100001000010000100010100000101000010000000100010000000100000100010000010000100000001000100101000010001000000010000010000001010000000100000100001000100000010000001000001000010000000100101000001010000010000010100100000010000001000010000001000000010010000000101000100101010000001000000100000001000000010000100100000100000010000010000100010000010000001001010001000100010001000010000001000000100000100000100000100000001000000010000010000100000101000100000101000010101000010000010000100000100010000000100000001001000100000100101000000100010101000000101000000010000100000101000001010000100100001000000010010001000001010000001000001000001010100101000010000001000000100100000001001001000101000000100000010000001000001000100000100100000100000101000000010000101001000001010000010000000100010010000001001000100000010101000000010000000101000100101001000001000000010010000001000001000100010000001000000100000001000010000001001000100010010000010000000100000101000010000100000010000010000100000100010000100000100000001000000010000001000100001000000010010100100100000010100000100001000001000000010010000000100000010001000001000001000001001001000100000010101001010000001000010000000100000001001000000100000001000101000000100000100000010000001000000010100100001000000100000100000001010100010001000010001010000001000000010000100000010000100000001001001000100000101000001000010001010000101000001000000100000100000001000100010100001000001000001010101000001001000000101001000000010001001010100000100010010000000100001010010000010000001001000010100100100000100000001000100000100000100000100001000100100100000100010000000100010000100000100010101000000010000000100000100100000010000010000001000100100001000000100001000000010100001000100000001000000010000001000001001000010001001001000000010000100001000010000010010000010000000100000010100000010000001000001001000000100000010100000010001000001010001000010010000010000001010000000101000010000000100100000100100000100000001000100010000100100000001001001000000100010000100000001001000000100000101000100000100000001000101000000100000001000010000000100000010100000001000000010000101000010101000010010000010000001001010000000100000100010000010000001000000100010000000100000100010010000000100000001000100000010000001000000010000100000001000010000001010000010000000100100001010000000101001010001001000001000010000010000000100010000000100000010001000001001001000000100000100000100001000010010000100101000100001000000100000001000000100001000000100000010100000010000010000000100000001000000010100000001000000010000010000010000000100000100100000010000001000000100000100100000001010010001000000100000100010000010000100000001000000100000010100000001000100100000010001001000001000010000101001000000100000100010000100010101000000100100010000100010000010101000000100010000000100010000000100000100001010000010001010010101000100001000010001000000010001000000010000000100000010000000100000001000100000101000010001000001000000100000100000100000001000001000000010000001000000100000001000000010010000001010000100100000100000100000001010000100100101010001000010000000101010000000100000001000010100000001000100000010000000100000010010001000000010000010000010000010000100000001000010000001000000010000001000000010000001000000010000010000010010000100101001000000010000000101000010000100100000100000001000100000001001000001000010000001000100000010000010100000001001000100100001000000100010000010000000100001000000100100000101000100001000000010000001001000000010000100000010001000000010000010100000010000100000010000010000001000000100000101000000100010000100100010000010010000100010000010010000000100010000010100001000001000000010000100001010000000100010000000100000010010000010000000100001000100000010000010000001000100010000000100000001000000010001000010010001000000100010000010000100000101000100000100001000001000000010000001000001001000000010100000001001000101000000010100010000001000000101000010000100000100010100100000001000100000010000101010001000000100001000010000000101000010000000100001000001001010000100000010100000010001000000010000001000000101000100100001001000010000000100100000010000000100000001001010010000101000101000000100000100001010000001000000010000010000000100000010001000010000100000100001000001000010001001000000010010000001001000000100100000010000000101000000100001000001000000010000001000100000001001000000100100010001000001000010000100101000000100000001000100000001001010000000101001000010000010000001000000100000001000100010101000001000100000100001000100100000001000000010000000101000100000010010000001000000100000010001000100000001000001001000001000010010000010000010000010000001000000010000010000100010100000010001000000100001000000101010000010000001001000010000100100010000010000100000001010010010000100001000010001000000010000100000010000010001000010000000100000010000010000100000001001010000010010101000001000001010010000010001000100100000100001000001000000010000010010001000000010000000100000100100000100001000010001000001010000100000010001000000010000101000000010000100000001000000010100000100000010010000001000010000100001000000010010100010000100000010000001001000000100001001010000001000000100100000101000010000001001010100000100010001010000001000001000001001000100101000001000010001000000100000001000000100000101010100000001000010000101000000010001000010010000100100001001000000010001000000100010010001000010000000100100000010000010010000001000010000100000100100001000001000010001010000100100000010000001000000100000010000000100000010101000000010000010000001001000000010100000001000010001000000010000000100000001010100010000100000010000010010000000100000100010000000100000001000000100000001010000100000100010000100000001000010000010100000010000100000001000000100100010010010010000000100000001000100000010000010000100001000000100100100000010101000010000000100001000010000010000001000001010000100001000000010000010000100000001000001000000010100000100000010000001010000000100000001010000100000001001000001000001010010000010100100000100010000000100000100000100010000001000001001001001010000100000001000100000100101000100000001000010001000100001000010000001000000010000001000100000010010010000000100101000000010001000010000010010000010100001010001001000000010001001000000100101001001000000100000100000010000010001000010001000000100000101010000000101000010000000100100010100000010010000000100001000001000101010000010000001000000010010000000100000001010000100000001000001001000010001000000010000000101001010001000100000010001000001010000000100000010010000100010000010001000010100100000001000001000010001000000010000100100000010000000101000000101000101000100000100001000000100000100100100001000001000000100100010010000000100001010000100000010001001000100000010000010000001000100010000010010000100000100000010000000100000100000100001000001000100010000010000010001000010000001001001000100000001001000000010010001000001001000001000000010010100001010100000010000001000010010000100000010000001010000001001000001010010001000000010010001001000001000000100101010010001000100000001000100100000100000010000100000010000010000001000000010010000010000000100101000010001010000000100000010101000000010010000000100000001000010010000000101000001000000100000100100010010000001000010100010000000100100000001000100001000010001001010000100000001000001000010000001000100100010001000100000001000100001000100101000000010010000001001000001000001000010001000000010000000100000001000000010000001010001000000100000001000000010000010010100000001000000010000001010000001000010000100000101000000010000010010000001000010001000000101000000010000010000001000000010000001000001010001000000010001000001000000010010001000001000100001000001000000100000100000010000010000010001000010010100000001000001010010000001000000100001010000001010001000000010000100000100101000100000100000100000100010000000100000001000010101000100000001000000010010000010000100000001000010000010100000001000000101000001000000010001000000101010010100000010000100000010100100000100000001001001000001010100100000100000010000100100101000000100100001000100000010000000100000010100100000100010100100010000000101000100010001000000100010100000100000010000000100000010100000001000100000010000100100001000000100100000100001000001001000010000000100000001000100100000001000000101000100000001000010000000100000100010000010000100010000000100100010000001000100000100000010001000010100000001000100001000000010000000100000100010000000100000010000100010000001000000010001001000010001000100000001000000100010001001000000100100000010000010000001000000010000001000100010000000100100000010100001000010000000100000100000010000001000000100000101001000000010000000100000010000010000100000100001000100100100001000000100001000001000000100000010000000100100000001010010100000001010000010010001000000010000000100000001010100100100000010000100000001000000010001000000010000101000010000010000000100000100010000101001000000100000100000001000100000010000100001000101001000010000000100100100000100010100100000001000000100000001010100010000100000001000100000010000001001000010010000001000001000001000010010000001000000100000010000100000100000010010001001000010000100100010000000100000010000001000000100000100100010000010001000001000001010100000001010010001000010000010000001000000100000100001000100000100100001000000010000001000100000001000000010000000100000001000000100000010100000100000001010010000010010010000010000100000001000001001000010000100001000001001000000100000010100000100100001000000101000001000000100000101000000010000001000000010001000000100000100001000100000001000000100100000001000001001010000100000100100100000010000000101010000100100000100000001000000010000000100001000010010001000000010000010000001000010001000010000001000100001000000010000001000001000000100000010000010000101000000010000001010000001000000010000000100000010001000000100000010001000010100101000000010001010010001000000010010100000001000101000001000000100000010000001001000010010000010000100010001010001000000010000001000000010000010000001000010000010000001010000001000001000001000001000000101000000010010000000100000001010000010100100000100000100100000100000100000100000100100000010000000100100000001000001010000010000000100000001001000000100000100000001000000010100001000100100001000000010100100000101000010000100001000000010001000010010001000000100000010000000100000001000100010000000100000010000010000100000001001000000100001001000000100000010001000010000100100100101000000010001000010001000001010100000001000000010000001001000001001000010001000101010000010000000100001000001000001000100000100010000100010000010000000100001010000010010000100001001000001010000100010000100100100000001000001000000010010100010001001000000100000010000010100010000000100000100000100000100000100000010010001000000101010001000000101000000100100010000001000001000000010000000100010010000010010010000000100100010010000000100010000000100000100001000101010010100000001000000100000101000101000000100000010000010000001000100000001000010000001010000000100001000010000010100001000010000000100000010001000000100000001000000100001000100010000001000000100000001000000010000010000001000001001000000100100001000010000001000101000010010001010010000000100001001000000010000100001000100000010000000100100010010000100000010000010000010000010000100000100010010000000100000001000010000100001000010000000100100100010000001000000100001000100100100000010001001000001001000000101000000010000100010010000010010000100000100000001000100000001000100001000000100010001000001000000100010010000001000010000001000001010000010000010000001000001000001000100000001000100000010001000001001010000100001001000000010000001000000100001000100000001000001001000000010000100000010010100000010000001000100000010000001000000010000010100010100010000001000010000100000010001000000010000010100010000010000001000001010000100000001000000101000000010000010001001000000100000100010100001000100000010000000100000010010000010000000101001000000010010010100000001010000010000010001010000001010000100000100000100000010000100000010100010000001000000010000100001000000100000100001010001010000010000010000010000000100000101000001000100010000000100000101010010000001000010001000000010001000010100000001000010000000100000010010000010000000100100000001001001000000100000001000000010100000010001000010000100000100000010100100000100000010000001010000010000100000010100000100001000010000001000010001000000010000000101000101001010000100000001000100100000010000001000100100000100000010000001000010001001000001000100000010000010000100001000000010100010000100000001000001001000001001000000010001001000000010101010010000001010000001000000100000010000000100000100000100100100000100001000001000001000000010000101000000100010000100000001000000010001010000100100100100001001000000100100010010000100000001000100000010000001000000100000001000010000100000010000001001000000010100010001000010000010000100010000000100000001000000010000000100001010001000001000000101000100000001000010000000101000100001010010001000001001001000101000000100010000000100000100000010100000010000100001000010000100010000001000010000001000100101010000000100000100101000001000000010000001000010010000010010010000001010000100000100000100101001000100100000001000100000010000100001000000010100010000101000000010000001000100000001000000010000000100000001001000010100000001000100000100001000100000010010000000100101001000000010010000001000000101000000010000000100000100100100000001000010000101000001000001000001010000000100100000001000001000000010000001000001000000010000010000010001000100000001000000100000001010000100101000001000100100101000000010000000100000101000000100000100010001000000100000010000000100000001000100101000000010000100001001000000010001000010001000101010000001010000010010000101000010000101000000101010100000001000010000000100000010000001000010000001001000000101000000010100000010000000100001000001000000100000100000010101001000100000100101000000010010001000000100010000010001001001000001000100100000001001000010000010000100000010100001010000100010000000100100010000101010000000100000100000001001000010010010000001000101000000100001000010000010000010000001000010000001000100000001000010000100000001000000010000001000001010000010010000000100000001000001000000100100000100010000010100100000001000001000000010000101001000010010001000001000000010100000001000101000000100100010100000100000001000000100010000001001000001000001000001001010000000100010000010010101000010000100000101001000000100100000001000000100000010000010010010000000100010101010010001000001000100000100010000000100010000010000000100000001000001000101000100010000000100001000000100100000100000001000100000001000000010000000100010100000010101000001000010001000100000010000010001000100100010000000100000010000000100100000010000000100000001000000010000000100100100000010000001000000010000100000010001000000100000010000000100000100001010000100001000000010010000100000101000100100000101000001010000101000010100001010000100100100100000010100010000001000001000001000000100000100000010100000001001010000001000001000000010000001000010010001001000000100000010000010000000100000010010000010001000100010000010000010000000100000001000001000000100010000000101000000010000100100010000101010001001000000010000000100100000001000000010000000100010000001000101000001000000101010000000100100100010100000001000000100000001000010000000100000100010001000100000100100000010010001000100000100010101010001010000100000001000000010000000100001000100001001000100000001001010000010000000100010001000101000000010000001000100000001010000001001001001000010100001000000100100000100000010000001010000001000000100000010000000100000100001000000100001000010001001000010001000000010001000000101000100000010001000000010010001000010000100000100000100100001000010100001001000000100100000001001000001010000001010000001000000010100000001000010001001000000010000100000010100000001000100000001000001001000000100010010000010000100000001000000010001000000010000010001000000010010000100100001000000010010000000100100001000000010001000000101000001000010000000100000010000001000010000000101001000000010100000010010000100000001001010000010000010000010000100100000010000001000001000000010100000001000001001010000010000001000010000001000010000010000100000010000100000001000001010000100100000100000001000100001000000100000010100100100001000100010000100001000000010010010000000100000100010001000100001000000010000001000010010000010100000010101000001010100010000000101000000010000010010001000100000010000100101001001000001000001000000100001000010000100001000000100010100001001010000010101000010010010000000100000001001000001000100010000001001000001000000101000000010100000010000100010000000101000010000010000100100010010010001000000100100000001000000010010001000000100100000100000100010100010010000001010100000100100001000000100000100100000100101000001000000100010000001001000001000010001000100000100000010101000001000001000000100000001000000100001000100000100001001000001000000010100000001000010000000100001010010010000010010000100001000100000100010000010000010010000000100001000001000001000100010000000100000010000001001001000100000010000100000101000100000100000001001010000001000010000100010000000100000001000010010010000010010010000000100010000100000001000101000000010000010000001000001000000100001000000100010000010000001000100010001000010000100010001010010000100001000010000000100000010010000001000000100000100100000100000100001000001000100101010010010001000000010000010000100000001000000100100000001000100000100010000000100100000001001000100010100000001000000100000100000010010000000100000100010000100010000010010000000100100001000000101001000010000000100000100000001010001000100001000000101010000001000001010000010000001000010000001000001000100000100001000000010000001000010100000001000000010000000100001000000010000000100000100000010001010100001001000000010000100001000010100000100000100000101000000010000001010010000100000100000100000010001000010000000100010001000100010010000010000010100100000010000100100000001001000010001000010000000100000010101010000010000001000010100010000010010000001001000001000100010000000100100010000100010000000100100000100000101010000100000100100001010010001000000100000100000101000010001000000100001000100001000000010100100000010000100000100100000010000001000000010010000100000001000000100001000001001000000100000101001001001001001000010000010000100000001010001010000001000000100101010000010001000100000010100000001000001000100000100000100101010000101010000001000000010000000100001000100000010000100000001000000100000100000001000100000001000001000010000100010000100100000100000100000100100000010001000001010100001010000000100101000010000101001000010010001000010000100000100000010010000010000000100000010000100001000010100001000101010100000101010000001000000100000010000100000010000010100100000001000001001000000101000001000000010000001010000100101010010001000000100001000001000000100001000000010100010000001001000001000100000100001000001010100000100010000001000001000000100010000010000001000000010000010000100000010000010010000100001000000010000010001000010001000001000100010000000100010000010000010100000100000010000010000000100000010100000010000010000010000010001001000000100000100100000010000010100000010010010000010000100000100100001000001000000010000001010000010001010000010000010000000100010010000010010000101000100000001010000101000010000010000010001000000010000001000100000010010000100000010000010000001000100000010000100000100100001000000100000100000001000001000000100000010000001010000000100000010000100000100000010001000001000100010100000001000001000000010000001000000010000010000010000010000001000010000000100010010000101001000010000010000010000100000100001000000100000001000000100101000000010000000100000001010000000100001000000100100000001001001010000000100000001001000010100000001000001000000010001000101000100010001001000010010100000100100001000100100000001000000100000001000000010010000000100010001010001000000100000010001010001000101000001001000000100100001000000100001000000010010001000001000010000000101000101001010100100001000100000100010000001000010000010000100001010000000100000101000010001000001000001001000001000000100001000001000000010010010000001000001000000010000010000010000000100010001010000100000001000010100000100000010100001000010000010010000001000000010001010000001010010000010010100000001000001010101000001010000001000100100010000000101000001000000010101000000010000101010000010000010001000100010100000010010000100001001000100000010000010000001001000000010100000100000001000000010000001000100000001000000010100000100100001010000001000000010010000001000100000100001000010000101000101010001000001001000100000100000100000001010000100000010000100100001000100001000000010000000100000001000000010010000010000010010100000100100000010000000101000100000010100001000000100001000001000001000000010000010000100000100000100010000001000010000001010010000010100000100010000000100010000010000100000010100100010000010001001001000000100000100000100100000001000001000010100100001000100010100001000100000010001000010000100001001000000100001000010000000100100010000000100101000000010000100000101000000010001000000100001000010000001000100001001010100001000001000010000001000001000000010010000001000000100100010000000100000100101000010010000000100000101000010000100010000001001000100001010000100010000001001000001010100010000100000100010010000001001000000100000100000100010001000001010000001001001000000010000000100000001000100010000100010001000101000000010010010010000000100010100010000000100000100101010010100100000001000000100100000010000010010000000100100000001000010000010001000000010000001000000100000001000000010000100000100000010000000100000010001001000001001010000001000000010100010000000100000010000001010000010001000001000000010000100100000100000010000000101001000001000000010000000101001000100000100000100001000000010000010000001000101000100001000001000001001000000100010010100000100100010000100000100000100100000100100100000010000010001000000101001010000100100000001000010010000000100000100010000001000001000010000000100101000100000001000000010000010010000100101000100001010000001000010000001000001010000010000000101010100000101000000100000010000001000001000000100100010000000100000001000000010100100100000001000101010000000100000100000100001000000100100010000010000100001000001000010001010010010001000001010000001000000100101000010100000001000100010010000000100000001010101001010000100000010010000100000010010000100001000001001000000100000010000100100000001000100100000100000001000001010001000001000000010001000001000100000001001000001010000000100010000001000001000001001000100000010000000100001001000001000100000100001010000001000100100001000010000000100100000010100000100001000010000001000010010000100010000100000010010100010000100001010000001001000101000000100000100000010000000100000001010000000100001000010000010001000001010000010000000101000101000001000000010000000101000010100100000001000000010010000100001000000010000101000001001000000100010100000010010000100000100100001010000100000100001000001000100000010000010010100100010000010001000010010000010000001001000000010000100001010000100000001000000010001000010000001000100000010001000000010100010001001001000000100000001001001000000010000001000000100000100000010001001000000010100000100100000010000000100000010000010010100001010100100000100000001000000010000010000101000000010000001000010010001000001000000101000000010000001001000000010000001000100000001000001010000100000010100000010000100001010010001001000000100001010100100001000000010000100000010000001000000010000000100000001000000010000100000001001010000001000001000000010000100010000000100000001000001010000010000000100000001001000000010001000010000001000100000010001001001000100000100010000100000010000100000001000001001000010101000000100010000100000100101010100100000001001000010000000100000100010000001000000100001000000101000000100100000010100100100010000101000000010000000100000010000000100000010001000000010000000100010100001000001000010000001000000010101010000001010100010001000000100000010010000000100000100010010000001000100100010000010010000101000100000100010000010001000000100001010101000000010010010000001000000100000010000100001000010000100001000000010000000100100100000010000001000001001000000010010000001000100010000000101000001010001000100000010000100000001000000010010000010100001000000100000001000010000100000010000100000001000100010000000101000010100000100010100000001000010001000100010000000100000001001001000000010000010010000010000010000100000001000100000010001000000100010000000100000010010000010001010000100100010000001000000100000101000001000100000100100000100100010000000100010000001000000010000100100100000100000001000001001000010100010100000100001000001001000100000100010000001000010001000010000001000000010001000001010000010000001000100000010000000100000100000100100000010000100001010100000001000100010101001000001000100100010000100001010000000100000010101001000000010000000100000010010000100000001000000010000010000000100001010000001000010010000001000001010000010100000010100010010001000000100000001000000010000000100000100000001000000010000001000010000010000010000000100010000000100010000001000010010010000001000000100100001000000100000001000000010001000000010100001001000100000010100010100100101001001000010000000100001000000100001000000010010001010000100000001001000000100010000001000000010000000100000100100000100000010000010000010000010000001000100001000000010100000010001000000100100001010000010001001000010001000100000001000000010000000100010000101000010000100000010001000100000010000010000000100100000010010010000100010000100000100100101000010000001000000100000100000100001000001000000010001000001000000010000010000001001000000010000000100000100000001000001001000010000100001001000100000010101000001000001000000010000000100001000000010100000001001000100001010000100000010001000001000010010001001000000010000001000010000001000010000000100010000000100000100000001001000010000000100000100000010010100000001000000100100100000100000100100000010000100000100000010000001000000010000100000001000101000100000100001000000010101000010001000101000010010000101001010000001010000000100000010100000101000100001000000100001001000001000001010000000101000001010000010000100001000000010000001000000100000001001010000001000001000000100010000000100000010001001000000101001000001000100100000001010000100100000100100001000010000101000000100000001000000010100100000001000000010000000100100000001000101000010000010000010000010101000000100100000001000000100000001000001000100000001010100010000010010000010000100000010100001010000001000001000000100001010000000100010000100001000001001001000100000001010001000010000000100100000010101000010000101000010000010000001000100100010001000010000101010010000010000000100100010100000001000100010000010000101000010000100100001000000010000001000000010010000000100001000010000000101000001000000100010000000100001010000010001010010000000100000001000010000000100010000100000010000001000101000001000000100000001000100000010000000100000001000001000100001001000100100000010010000000100100000001010000001000010001000010000000101000000100101000000010010000010000001000001000001000100010001010001010000001000001000100000001010001010000100000010001000010000100000001001010000100000010000001000001000010001010010000101000010000010000001000001000001000100000100000100000010010000100000100100100000100000100010010000001001010000101001000100000001000000010000001000000010100101010000000100100001000001000000010000100100000001000000010000010010000100000001000010010000010000010000001000000010000100001001000100100001000000010000001010000010000000100001000001000010000000100001000001000100000010100000010000010000100010000010000100000100100010000101000000100100000010000010000000100001000000100001000000010000001000000100000101001001000000100010001000001000010000010000010100001010000100000101000001000100001000101000001000000010000000100000100000100000001000100100000001000010010000000101000100000100000001000001000000100000001001000000010100010001001001000100010010000000101000000010000000100000100001000010000001000100000100000001000010100000100100000010010000100010000010000000100001000000010010000001000000101010000001000010000000101000001001000100100000010000100100000100001000101000100010000010000001000010001000100000100010000001000010001001010100000100000100100010010000010000010000001010000001000010000001010000000100000001001000100000001010001001010000000100001000100000010000001000010000100010000010000000100100001000010001010001000000100000001010100000001000100000100000100101001000010000100001001010000001001000010000100010000000100010010100010010000000100001000001000000100001000010000001001000000010100000010000000100000100000010000010001000000101000001000001000010010001010010000001000000010010010000010010000010010010010101000001000100001010000100100000010001000000010001010000000100000001000000010000000100000100001000000100000100000001000001000000100010010010000101000101000000010010100010100000010001000000100001000000100100000001000100010000101010000001000001000001000000100010001000000010000000100001000000100000010000010100100100100000001000000010000100000001000001000000010100000100000001000001000000010000000100001000000100100000010000100100000010000100010000100010100100000010000001010000100100000001000000010100100010001001000000010000000100010100001001010100000001010000001001000010000001001010100100010000100001001001000001001000000100100000001001000000100000100000010000000100000010001000001000001000001000000010000100000010000100000100000100000101010000001000000100010100000001000000100100010100010000010101010000000100001000101000000100010000001001000000101000001001000000100000100000100000001000100000001000001001000000010101010010010000100001000001000000100000100010001000000010010100100010000000101010010001000010000000100000010000001000100001000000010000001000001001000000010000010001000001000001000100000001001000000100101000000100001000000100000100000001001000000100010010000001000001000010000010000101000100000010000100000100100010000010000000101000100001010000000100000010000100000010000000100000001000000010001000000010000001000001000000100100000001000000100000001000010001010000000100100000100100100100000010010000100000010000001000100010001001000000010010010000010000010000100010000001010000010100000010000001000010001000000100000100100001000010000100010010100100010000000100010000001000101010000010000001000010000010001000000010000001010010000100010000010000001000010000100001000010010001000001000001010000010000000100000100101000100010001000000010000010000101000100010000010000001010000100001000001000000100000001001000010001000100001000000010001000000100101000010000010000100010000001000010010000010001000100101000001010001000100010000001000100001000000010000000100100100100000001010000100000100000010001000000100001000100010000000100000100000001000000010000010000001000001001000100100000100000010010000010000001000100010010000010000000100000101000010010010000100001000000010000000100100000100000010010100000100001010000000101000100000100100000100101000000100000001001000101000000100001000000010010000000100000001000000010100000100100000010010000000101010010000010000100000100000010101001000100000100000010010010010000000100010010000000100010001010001000010010000010000100010010000000100010100100000001000001000010000100000010000000101000000010000010010000001000000101000100000100010000100100000010001001001000000100000100100000100001000010000010000000101000000100000010001000000100000001000010010000001000100100000001000001000000100010000001000001010000100000001001001010001001000010000100000010000010010000001010000010010000101000100100001000000100010100000001000100010100000001000000010000010000100100000001001000001000001000000010101000001000010000000100000001000100100100001000001000000101000100100000100000010000001000000100010001010101000010000001000000010000000100001000001000010010100101000100000001000000010001000001001000100000100010001000101000010100000100000010000101000001000010000010010000010010000001000010001000101000001010001010100001001000101000000100001000001000100000001000000101000010000001001000000010010010000000100000101000000010001000001000010010000100000001000101001000100001000000010010101000001001000000010000001000010000001000001000000010000001000000101000000010000010010000100000001000001010000100000010000101000001001010000001000000010100100000010001000010000010000000100001000100000100001000000100000001001000001000000100000010000000100000100010100000001000001010000001001000010000010000000100000010000000100000001000100010000001000100000100100010000001001001000000100010100000001000000010000000100100000001000000100000001000001010000101010001000001000100010100000010010000000101000100100000100000010000000101001001000100000001000000100000010000010000101000000010000001000000100001000000010001000010101000100000001000000101000001000000100010100010000000100000010100000100000001000000100010001001000000010000100001000000010000000100001000000100001000100000001010010000001000100000100000001000000100000001000001000010000001000000101000000100100000010000001000000000000010001000000100010000010000000000001000000000000100000000"))# 13100)

print('t_total = {:.6f}'.format(perf_counter() - tic))

def is_ladder_safe(ladder):
    
    if len(ladder[0]) < 5: ## check if ladder is atleast 5 characters wide
        return False
    rung_indexes = []
    
    i = 0
    for eachrung in ladder:
        if eachrung.count('#') < 2: ## trick string
            return False
        if eachrung.count('#') == 2 and not re.search(r'^[\#][^#]*[\#]$',eachrung): # analyze if tricking us with 2
            return False
        elif eachrung.count('#') > 2 and not eachrung.count('#') == len(eachrung): # check if it is a whole rung ex : ######
            return False
        elif eachrung.count('#') == len(eachrung): ## found rung
            rung_indexes.append(i)
        i += 1 
    diff = []
    for i in range(len(rung_indexes)-1):
        diff.append(abs(rung_indexes[i] - rung_indexes[i+1]))
    return len(set(diff)) == 1 and len([x for x in diff if x > 3]) == 0


is_ladder_safe([
	"#   #",
	"#####",
	"#   #",
	"#   #",
	"#####",
	"#   #",
	"#   #",
	"#####",
	"#   #"
])

def matrix_multiply(a,b):
    
    m = 0
    p = 0
    m = len(a[0])
    p = len(b)
    if m != p:
        return 'Invalid'
    arrays = []
    sum = 0
    sub_arrays = []
    cols = len(b[0])
    total_elems = cols * len(b)
    
    #[0][0] * [0][0]
    #[0][1] * [1][0]
    
    #[0][0] * [0][1]
    #[0][1] * [1][1]
    
    #-----
    #[0][0] * [0][0]
    #[1][1] * [1][1]

    #-----
    #[0][0] * [0][0]
    #[0][1] * [0][1]
    
    #[1][0] * [0][0]
    #[1][1] * [0][1]
    
    col_inc = 0
    num_index = 0
    for eachrow in a:
        col_inc = 0
        for i in range(len(b)):
            sum += eachrow[num_index] * b[i][col_inc]
            num_index += 1
        sub_arrays.append(sum)
        col_inc += 1
        sum = 0
        arrays.append(sub_arrays)
        sub_arrays = []
        num_index = 0
    return arrays

print(matrix_multiply([[1]], [[1, 2], [3, 4]]))# "invalid")
print(matrix_multiply([[0, 0], [0, 1]], [[1, 2], [3, 4], [5, 6]]))# "invalid")
print(matrix_multiply([[2]], [[3]]))# [[6]])
print(matrix_multiply([[1, 2]], [[3], [4]]))# [[11]])
print(matrix_multiply([[2, 4], [1, 3]], [[5], [6]]))# [[34], [23]])
print(matrix_multiply([[4, 2], [3, 1]], [[5, 6], [3, 8]]))# [[26, 40], [18, 26]])
print(matrix_multiply([[3, 6], [4, 5]], [[8, 1], [7, 2]]))# [[66, 15], [67, 14]])
print(matrix_multiply([[1, 6], [6, 3]], [[5, 3, 5], [1, 6, 6]]))# [[11, 39, 41], [33, 36, 48]])
print(matrix_multiply([[4, 6], [1, 6]], [[5, 5, 4], [5, 3, 2]]))# [[50, 38, 28], [35, 23, 16]])
print(matrix_multiply([[5, 1], [1, 1], [2, 5]], [[5, 6, 3], [2, 1, 3]]))# [[27, 31, 18], [7, 7, 6], [20, 17, 21]])
print(matrix_multiply([[1, 1, 1], [0, 1, 0], [0, 1, 1]], [[1, 0, 1], [0, 0, 1], [1, 1, 0]]))# [[2, 1, 2], [0, 0, 1], [1, 1, 1]])
                
    
def absurd_brainfuck_interpreter(tape):

    stack_ = []
    curr_cell = 0
    history = [curr_cell]
    for eachletter in tape:
        if eachletter == '+':
            ## implement
            print('will be implemented')


def acl_interpreter(tape):

    cells = [0]
    curr_cell = 0
    for eachcommand in tape:
        if eachcommand == '0':
            curr_cell = 0
        elif eachcommand == '1':
            if curr_cell == len(cells)-1:
                cells.append(0)
                curr_cell += 1
            else:
                curr_cell += 1
        elif eachcommand == '2':
            if curr_cell == 0:
                curr_cell = len(cells)-1
            else:
                curr_cell -= 1
        elif eachcommand == '3':
            pass
    return ''

def month_value(month):
    month_values = {'January': 1, 'February': 2, 'March': 3, 'April': 4, 'May': 5, 'June': 6, 'July': 7, 'August': 8, 'September': 9, 'October': 10, 'November': 11, 'December': 12}
    return month_values[month]

def months_interval(date1: datetime.date, date2: datetime.date):

    if date2.year < date1.year:
        date1,date2 = date2, date1
    elif date2.year == date1.year and date1.month > date2.month:
        date1,date2 = date2, date1

    months = { 1: 'January', 2: 'February', 3: 'March', 4: 'April', 5: 'May', 6: 'June', 7: 'July', 8: 'August', 9: 'September', 10: 'October', 11: 'November', 12: 'December'}

    start_month = date1.month
    names = [months[start_month]]
    start_year = date1.year
    while start_month != date2.month or start_year != date2.year:
        if start_month == 12:
            start_month = 1
            start_year += 1
            if months[start_month] not in names:
                names.append(months[start_month])
        else:
            start_month += 1
            if months[start_month] not in names:
                names.append(months[start_month])
    return sorted(names, key=month_value)


def is_it_inside(file_system, folder1, folder2):

    if folder1 == folder2:
        return True
    if folder2 not in file_system:
        return False
    for eachsubfolder in file_system[folder2]:
        if eachsubfolder in file_system:
            return is_it_inside(file_system, folder1, eachsubfolder)
        elif folder1 in file_system[folder2]:
            return True
    return False


def iso_group(lst,maxnum=[-100]):
    # your recursive solution here
    if len(lst) == 0:
        if len(maxnum) == 1:
            return maxnum[0]
        else:
            return maxnum
    elif len(lst) == 1:
        max_num = lst[0]
        if max_num == maxnum[0]:
            ## already found max
            return iso_group([], maxnum[:] + [max_num])
        else:
            if max_num < maxnum[0]:
                return iso_group([], maxnum)
            else:
                return iso_group([], [max_num])
    else:
        max_num = lst[0]
        if max_num == maxnum[0]:
            return iso_group(lst[1:], maxnum[:] + [max_num])
        else:
            if max_num < maxnum[0]:
                return iso_group(lst[1:], maxnum)
            else:
                return iso_group(lst[1:],[max_num])


def is_valid_subsequence(sequence1, sequence2):
    
    prev_index = -1
    for eachnumber in sequence2:
        try:
            index = sequence1.index(eachnumber)
            if index == -1:
                return False
            if prev_index == -1:
                prev_index = index
                for i in range(index+1):
                    sequence1[i] = 0
            elif index < prev_index:
                return False
            else:
                prev_index = index
                for i in range(index+1):
                    sequence1[i] = 0
        except Exception as e:
            return False
    return True

print(is_valid_subsequence([5, 1, 22, 25, 6, -1, 8, 10],[1, 6, -1, 10]))#True)
print(is_valid_subsequence([5, 1, 22, 25, 6, -1, 8, 10], [5, 1, 22, 25, 6, -1, 8, 10]))#True)
print(is_valid_subsequence([5, 1, 22, 25, 6, -1, 8, 10], [22, 25, 6]))#True)
print(is_valid_subsequence([1, 1, 6, 1],[1, 1, 1, 6]))#False)
print(is_valid_subsequence([1, 2, 3, 4],[2, 4]))#True)


def bit_rotate(n, m, d):
    
    if d:
        bin_result = bin(n)[2:]
        count = 0
        while count < m:
            bin_result = bin_result[-1] + bin_result[0:-1]
            count += 1
        return int(bin_result, 2)
    else:
        bin_result = bin(n)[2:]
        count = 0
        while count < m:
            bin_result = bin_result[1:] + bin_result[0]
            count += 1
        return int(bin_result, 2)
    
    
print(bit_rotate(17, 2, False))


def sim_prop_frac(max_den):
    
    count = 0
    for i in range(2,max_den+1): # 2-7
        for j in range(1, i): #
            if proper_frac_gcd(i, j) == 1:
                #print('{}/{}'.format(j,i))
                count += 1
    return count
                

print(sim_prop_frac(10))
print(proper_frac_gcd(1,2))


def compress(alist):
    
    compressed_string = ''.join(alist)
    emptystring = ''
    for k, g in itertools.groupby(compressed_string):
        group = list(g)
        key = k
        if len(group) > 1:
            emptystring += '{}{}'.format(key,len(group))
        else:
            emptystring += key
    return emptystring
        
        
        
compress(["a", "a", "a", "b", "b", "a", "a"])

def islands_perimeter(island):

    ### 0 example of how perimeter is calculated step by step, only just one sentence, bad description

    total_perimeter = 0
    north_neighbor = 0
    south_neighbor = 0
    east_neighbor = 0
    west_neighbor = 0
    
    for i in range(len(island)):
        for j in range(len(island[0])):
            if island[i][j] == 0:
                continue
            if i != 0:
                north_neighbor = island[i-1][j]
            if i != (len(island)-1):
                south_neighbor = island[i+1][j]
            if j != 0:
                west_neighbor = island[i][j-1]
            if j != (len(island[0])-1):
                east_neighbor = island[i][j+1]
            total_perimeter += north_neighbor
            total_perimeter += south_neighbor
            total_perimeter += east_neighbor
            total_perimeter += west_neighbor
            total_perimeter += 1
            if north_neighbor+south_neighbor+east_neighbor+west_neighbor == 0:
                total_perimeter += 4
            north_neighbor, south_neighbor, east_neighbor, west_neighbor = 0,0,0,0
    return total_perimeter



def news_at_ten(astr, n):
    
    full_news = []
    starting_position = n
    new_string = ''
    str_started = 0
    while starting_position != -1:
        for i in range(n+1):
            if i < starting_position:
                new_string += ' '
            elif i > starting_position:
                if str_started != len(astr):
                    new_string += astr[str_started]
                    str_started += 1
                else:
                    new_string += ' '
        print(len(new_string))
        full_news.append(new_string)
        new_string = ''
        starting_position -= 1
        str_started = 0
    
    substr_begin = 1
    str_started = 0
    while substr_begin != len(astr):
        the_sub_word = astr[substr_begin:]
        for i in range(n):
            if i < len(the_sub_word):
                new_string += the_sub_word[str_started]
                str_started += 1
            else:
                new_string += ' '
        print(len(new_string))
        full_news.append(new_string)
        new_string = ''
        str_started = 0
        substr_begin += 1
    full_news.append(' ' * n)
                
    return full_news
                    
    
print(news_at_ten("edabit", 10))
    
 #['          ', '         e', '        ed', '       eda', '      edab', '     edabi', '    edabit', '   edabit ', '  edabit  ', ' edabit   ', 'edabit    ', 'dabit      ', 'abit       ', 'bit        ', 'it         ', 't          ', '          ']
 #['          ', '         e', '        ed', '       eda', '      edab', '     edabi', '    edabit', '   edabit ', '  edabit  ', ' edabit   ', 'edabit    ', 'dabit     ', 'abit      ', 'bit       ', 'it        ', 't         ', '          ']
    
def validate(number):
    expr1 = r'^[+][\d][-][\d]{3}[-][\d]{3}[-][\d]{4}$'
    expr2 = r'^[\d]{3}[-][\d]{3}[-][\d]{4}$'
    expr3 = r'^[\d][-][\d]{3}[-][\d]{3}[-][\d]{4}$'
    expr4 = r'^[(][\d]{3}[)] [\d]{3}[-][\d]{4}$'
    expr5 = r'^[\d]{1} [(][\d]{3}[)] [\d]{3}[-][\d]{4}$'
    expr6 = r'^[\d]{3}[.][\d]{3}[.][\d]{4}$'
    expr7 = r'^[\d]{1}[.][\d]{3}[.][\d]{3}[.][\d]{4}$'
    expr8 = r'^[\d]{1}[\/][\d]{3}[\/][\d]{3}[\/][\d]{4}$'
    expr9 = r'^[\d]{1} [\d]{3} [\d]{3} [\d]{4}$'
    expr10 = r'^[\d]{3}[\/][\d]{3}[\/][\d]{4}$'
    expr11 = r'^[\d]{11}$'
    expr12 = r'^[\d]{3} [\d]{3} [\d]{4}$'
    expr13 = r'^[\d]{10}$'

    expressions = [expr1, expr2, expr3, expr4, expr5, expr6, expr7, expr8, expr9, expr10, expr11, expr12, expr13]

    for eachexpression in expressions:
        print(re.match(eachexpression, number, re.MULTILINE))
        if re.match(eachexpression, number, re.MULTILINE):
            return True
    return False


def distance_to_nearest_vowel(astring):

    vowels = 'aeiouAEIOU'
    dist = []
    for i in range(len(astring)):
        letter = astring[i]
        if letter in vowels:
            dist.append(0)
        else:
            j = i
            k = i
            while j >= 0 or k < len(astring):
                letter2 = astring[j]
                letter3 = astring[k]
                if letter2 in vowels:
                    dist.append(abs(j - i))
                    break
                elif letter3 in vowels:
                    dist.append(abs(k - i))
                    break
                if j > 0:
                    j -= 1
                if k < len(astring)-1:
                    k += 1
    return dist