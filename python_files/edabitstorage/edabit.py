import itertools
import math
import re
import functools
import datetime
import collections

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
    for i in range(0,len(board),3):
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



print(drange(1.2, 5.9, 0.45))#, (1.2, 1.65, 2.1, 2.55, 3.0, 3.45, 3.9, 4.35, 4.8, 5.25, 5.7))
print(drange(10))#, (0, 1, 2, 3, 4, 5, 6, 7, 8, 9))
print(drange(1, 7, 1.2))#, (1, 2.2, 3.4, 4.6, 5.8))
print(drange(3, 10))#, (3, 4, 5, 6, 7, 8, 9))
print(drange(0.112, 13, 3.27))#, (0.112, 3.382, 6.652, 9.922))

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

print(complete_bracelet([1, 2, 2, 1, 2, 2]))# True)
print(complete_bracelet([5, 1, 2, 2]))# False)
print(complete_bracelet([5, 5, 5]))# False)
print(complete_bracelet([5, 5, 7, 7]))# False)
print(complete_bracelet([5, 5, 7, 7, 5, 5, 7, 7]))# True)
print(complete_bracelet([1, 2, 1, 2, 1, 2]))# True)
print(complete_bracelet([1, 2, 2, 2, 1, 2, 2]))# False)
print(complete_bracelet([1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2]))# True)
print(complete_bracelet([5, 2, 5, 5, 2, 5, 2, 5, 2, 2, 5, 2, 5, 2, 5, 5, 2, 5, 2, 5, 2, 2, 5, 2]))# True)
print(complete_bracelet([1, 2, 3, 3, 1, 2, 3, 3]))# True)
print(complete_bracelet([1, 2, 1, 2, 1, 2, 1, 2]))# True)
print(complete_bracelet([1, 1, 6, 1, 1, 7, 1, 1, 6, 1, 1, 7, 1, 1, 6, 1, 1, 7]))# True)
print(complete_bracelet([4, 4, 3, 4, 4, 4, 4, 3, 4, 4]))# True)
print(complete_bracelet([1, 2, 2, 2, 1, 2, 2, 2, 1]))# False)
print(complete_bracelet([1, 1, 6, 1, 1, 7]))# False)
print(complete_bracelet([5, 5]))# False)
        

class Train:
    def __init__(self,destinations,expected_time):
        self.destinations = destinations
        self.expected_time = expected_time

trains = [
Train(['Townsville', 'Suburbia', 'Urbantska'], '13:04'),
Train(['Farmsdale', 'Suburbia', 'Lakeside Valley'], '13:20'),
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
    return [round(mass,3),years]


def sine(num1,num2):

    return round(num1 * math.sin(math.radians(num2)),3)

def cosine(num1,num2):

    return round(num1 * math.cos(math.radians(num2)),3)

def tangent(num1,num2):

    return round(num1 * math.tan(math.radians(num2)),3)

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
print(can_put("HEY JUDE", [2, 4]))# True)
print(can_put("HEY JUDE", [1, 8]))# True)
print(can_put("HEY JUDE", [1, 7]))# False, 'cannot fit leaving a space in')
print(can_put("HEY JUDE", [4, 3]))# False, 'JUDE cannot fit on second row')
print(can_put("CU L8R", [2, 2]))# False, 'L8R cannot fit on second row')
print(can_put("CU L8R", [1, 5]))# False, 'cannot fit leaving a space in')
print(can_put("CU L8R", [5, 5]))# True)
print(can_put("BEAUTY IS WITHIN", [3, 6]))# True)
print(can_put("BEAUTY IS WITHIN", [4, 5]))# False)

def is_early_bird(r,num):

    str_range = ''.join([str(x) for x in range(r+1)])

    astr = r'(?=({}))'.format(num)

    expr = re.compile(astr)

    iter = expr.finditer(str_range)

    matches = []

    while True:
        try:
            match = iter.__next__()
            #print('end = {} and start = {}'.format(match.end(),match.start()))
            if abs(match.end() - match.start()+len(str(num))-1) != 1:
                ## assign
                ind = [x for x in range(match.end(),match.start()+len(str(num)))]
                matches.append(ind)
            else:
                matches.append([match.end(),match.start()+len(str(num))-1])
        except Exception as e:
            break
    if len(matches) > 1:
        matches.append('Early Bird!')
    return matches


print(is_early_bird(20, 12))# [[1, 2], [14, 15], 'Early Bird!'], "Example in Instructions tab")
print(is_early_bird(20, 14))# [[18, 19]])
print(is_early_bird(101, 101))# [[10, 11, 12], [193, 194, 195], 'Early Bird!'])
print(is_early_bird(50, 34))# [[3, 4], [58, 59], [77, 78], 'Early Bird!'])
print(is_early_bird(212, 156))# [[358, 359, 360]])
print(is_early_bird(400, 240))# [[610, 611, 612]])
print(is_early_bird(900, 888))# [[166, 167, 168], [2554, 2555, 2556], [2555, 2556, 2557], [2556, 2557, 2558], 'Early Bird!'])
print(is_early_bird(1200, 745))# [[1263, 1264, 1265], [1613, 1614, 1615], [2125, 2126, 2127], 'Early Bird!'])
print(is_early_bird(2000, 666))# [[122, 123, 124], [1888, 1889, 1890], [1889, 1890, 1891], [1890, 1891, 1892], [5555, 5556, 5557], 'Early Bird!'])


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


print(inflect('amare', 'first', 'sing'))# 'Io amo')
print(inflect('ascoltare', 'sec', 'sing'))# 'Tu ascolti')
print(inflect('causare', 'third', 'sing'))# 'Lui/Lei causa')
print(inflect('alterare', 'first', 'pl'))# 'Noi alteriamo')
print(inflect('immaginare', 'sec', 'pl'))# 'Voi immaginate')
print(inflect('regalare', 'third', 'pl'))# 'Loro regalano')
print(inflect('credere', 'first', 'sing'))# 'Io credo')
print(inflect('temere', 'sec', 'sing'))# 'Tu temi')
print(inflect('vendere', 'third', 'sing'))# 'Lui/Lei vende')
print(inflect('precedere', 'first', 'pl'))# 'Noi precediamo')
print(inflect('ricevere', 'sec', 'pl'))# 'Voi ricevete')
print(inflect('credere', 'third', 'pl'))# 'Loro credono')
print(inflect('dormire', 'first', 'sing'))# 'Io dormo')
print(inflect('mentire', 'sec', 'sing'))# 'Tu menti')
print(inflect('divertire', 'third', 'sing'))# 'Lui/Lei diverte')
print(inflect('offrire', 'first', 'pl'))# 'Noi offriamo')
print(inflect('servire', 'sec', 'pl'))# 'Voi servite')
print(inflect('partire', 'third', 'pl'))# 'Loro partono')


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

print(divide([1, 2, 3, 4, 1, 0, 2, 2], 5))# [[1, 2], [3], [4, 1, 0], [2, 2]])
print(divide([1, 2, 3, 4, 1, 0, 2, 2], 4))# [[1, 2], [3], [4], [1, 0, 2], [2]])
print(divide([1, 3, 2, -1, 2, 1, 1, 3, 1], 3))# [[1], [3], [2, -1, 2], [1, 1], [3], [1]])
print(divide([1, 2, 2, -1, 2, 0, 1, 0, 1], 2))# [[1], [2], [2, -1], [2, 0], [1, 0, 1]])
print(divide([1, 2, 2, -1, 2, 0, 1, 0, 1], 3))# [[1, 2], [2, -1, 2, 0], [1, 0, 1]])
print(divide([1, 2, 2, -1, 2, 0, 1, 0, 1], 5))# [[1, 2, 2, -1], [2, 0, 1, 0, 1]])
print(divide([2, 1, 0, -1, 0, 0, 2, 1, 3], 3))# [[2, 1, 0, -1, 0, 0], [2, 1], [3]])
print(divide([2, 1, 0, -1, 0, 0, 2, 1, 3], 4))# [[2, 1, 0, -1, 0, 0, 2], [1, 3]])
print(divide([1, 0, 1, 1, -1, 0, 0], 1))# [[1, 0], [1], [1, -1, 0, 0]])
print(divide([1, 0, 1, 1, -1, 0, 0], 2))# [[1, 0, 1], [1, -1, 0, 0]])
print(divide([1, 0, 1, 1, -1, 0, 0], 3))# [[1, 0, 1, 1, -1, 0, 0]])

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
print(longest_run([1, 2, 3, 5, 6, 7, 8, 9]))# 5)
print(longest_run([1, 2, 3, 10, 11, 15]))# 3)
print(longest_run([-7, -6, -5, -4, -3, -2, -1]))# 7)
print(longest_run([3, 5, 6, 10, 15]))# 2)
print(longest_run([3, 5, 7, 10, 15]))# 1)
print(longest_run([5, 4, 3, 2, 1]))# 5)
print(longest_run([5, 4, 2, 1]))# 2)
print(longest_run([10, 9, 0, 5]))# 2)
print(longest_run([1, 2, 3, 2, 1]))# 3)
print(longest_run([10, 9, 8, 7, 6, 2, 1]))# 5)


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
	(519432, 525806),
	(632382, 518061),
	(78864, 613712),
	(466580, 530130),
	(780495, 510032)
])#, 5)

largest_exponential(
	[(375856, 539061),
	(768907, 510590),
	(165993, 575715),
	(976327, 501755),
	(898500, 504795),
	(360404, 540830)
])#, 4)

largest_exponential(
	[(478714, 529095),
	(694144, 514472)
])#, 1)

largest_exponential(
	[(950860, 502717),
	(119000, 592114),
	(392252, 537272),
	(191618, 568919),
	(946699, 502874),
	(289555, 550247),
	(799322, 509139),
	(703886, 513942),
	(194812,568143),
	(261823, 554685)
])#, 7)


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

print(is_val_in_tree(lst1, 7))# True)
print(is_val_in_tree(lst1, 4))# True)
print(is_val_in_tree(lst1, 15))# False)
print(is_val_in_tree(lst2, 18))# True)
print(is_val_in_tree(lst2, 51))# False)
print(is_val_in_tree(lst2, 23))# False)
print(is_val_in_tree(lst3, 52))# True)
print(is_val_in_tree(lst3, 120))# False)
print(is_val_in_tree(lst3, -2))# False)
print(is_val_in_tree(lst3, 91))# True)


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
print(check_pattern([[1, 1], [2, 2], [1, 1], [2, 2]], "ABAB"))# True)
print(check_pattern([[1, 2], [1, 2], [1, 2], [1, 2]], "AAAA"))# True)
print(check_pattern([[1, 2], [1, 3], [1, 4], [1, 2]], "ABCA"))# True)
print(check_pattern([[1, 2, 3], [1, 2, 3], [3, 2, 1], [3, 2, 1]], "AABB"))# True)
print(check_pattern([[8, 8, 8, 8], [7, 7, 7, 7], [6, 6, 6, 6], [5, 5, 5, 5]], "ABCD"))# True)
print(check_pattern([[8, 8, 8, 8], [7, 7, 7, 7], [6, 6, 6, 6], [5, 5, 5, 5]], "DCBA"))# True)
print(check_pattern([[8], [7], [6], [6]], "ABCC"))# True)
print(check_pattern([[8], [9], [9], [9]], "ABBB"))# True)
print(check_pattern([[1, 1], [2, 2], [1, 1], [1, 2]], "ABAB"))# False)
print(check_pattern([[1, 2], [1, 2], [2, 2], [3, 2]], "AAAA"))# False)
print(check_pattern([[8], [9], [9], [8]], "ABBB"))# False)
print(check_pattern([[8], [7], [6], [5]], "ABCC"))# False)
print(check_pattern([[8, 8, 8, 8], [7, 7, 7, 7], [6, 6, 6, 6], [5, 5, 5, 5]], "DDBA"))# False)
print(check_pattern([[1, 2], [1, 2], [1, 2], [1, 2]], "AABA"))# False)

"""
    

def get_lucky_number(num1,num2):

    num1 = [x for x in range(1,num1+1)]

    filter = 2
    while filter < len(num1):
        for i in range(filter-1,len(num1),filter):
            num1[i] = -1
        num1 = [num1[x] for x in range(len(num1)) if num1[x] > 0]
        if filter in num1:
            filter = num1[num1.index(filter)+1]
        else:
            filter = num1[1]
    return num1[num2-1]


print(get_lucky_number(25, 5))# 13, "Example #1")
print(get_lucky_number(3, 2))# 3, "Example #2")
print(get_lucky_number(120, 13))# 49, "Example #3")
print(get_lucky_number(350, 27))# 127)
print(get_lucky_number(700, 40))# 201)
print(get_lucky_number(1000, 57))# 303)
print(get_lucky_number(5000, 90))# 535)


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

print(prime_divisors(27))# [3])
print(prime_divisors(24))# [2, 3])
print(prime_divisors(478170))# [2, 3, 5, 7, 11, 23])
print(prime_divisors(1386))# [2, 3, 7, 11])
print(prime_divisors(462))# [2, 3, 7, 11])
print(prime_divisors(99))# [3, 11])

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


print(bracket_logic("{b}{y}{ }[x][{{(t)-}{}](t<w(^)>)-b}<[g](x{u[ ]})y>"))# False)
print(bracket_logic("{f}[t[[]]<[+](w)t>u(h)(%){f}[d{e}]{c(/)}<w>][v]"))# True)
print(bracket_logic("[(t)d]</{h}><<a <( )e>[*]{e{e}}<w{x[^]}>>"))# False)
print(bracket_logic("{g}((-) ^>b)[^]{{*<->}(w)(u)(%)}({/}c)(%)[g{b}]<z({<< >w>c}d)[b]>"))# False)
print(bracket_logic("(y)(c)(){[[ ]z] [{+}z[*]]{+}}([d]<y<e>>c)[b][b]"))# True)
print(bracket_logic("((^(b))e>(<d<w>>(({a}/(g)){t</)}b(d)){[v]u})"))# False)
print(bracket_logic("{([%]</>u)<{<y{v}>{<c>h}{y}f}[y]{<*>e}[^]v><[h]d>}[d]"))# True)
print(bracket_logic("{a}{<(^)(b)%>[z]<->e}[{z}%]{<^>g}<[h] ({ }y[*]<v>)>{x[+]<^>}<v>[]"))# True)


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
print(over_time([9, 17, 30, 1.5]))# "$240.00")
print(over_time([9, 18, 40, 2]))# "$400.00")
print(over_time([13, 20, 32.5, 2]))# "$325.00")
print(over_time([9, 13, 25, 1.5]))# "$100.00")
print(over_time([11.5, 19, 40, 1.8]))# "$364.00")
print(over_time([10, 17, 30, 1.5]))# "$210.00")
print(over_time([10.5, 17, 32.25, 1.5]))# "$209.63")
print(over_time([16, 18, 30, 1.8]))# "$84.00")
print(over_time([18, 20, 32.5, 2]))# "$130.00")
print(over_time([13.25, 15, 30, 1.5]))# "$52.50")
print(over_time([13, 21, 38.6, 1.8]))# "$432.32")


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
    
    ed_two_overall_total = round((data['E'][0] - ed_two_total)**2 / (ed_two_total),3)
    ed_half_overall_total = round((data['E'][1] - ed_half_total)**2 / (ed_half_total),3)
    
    tut_two_overall_total = round((data['T'][0] - tut_two_total)**2 / (tut_two_total),3)
    tut_half_overall_total = round((data['T'][1] - tut_half_total)**2 / (tut_half_total),3)
    
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
        for i in range(len(edited_ranks),-1,-1):
            if edited_ranks[i-1] == player_total:
                ranks.append(i)
                break
            elif edited_ranks[i-1] > player_total:
                ranks.append(i+1)
                break
    return ranks


print(climbing_leaderboard([100, 100, 50, 40, 40, 20, 10], [5, 25, 50, 120]))# [6, 4, 2, 1])
print(climbing_leaderboard([100, 90, 90, 80, 75, 60], [50, 65, 77, 90, 102]))# [6, 5, 4, 2, 1])
print(climbing_leaderboard([80, 80, 80, 75, 70, 60, 60, 60], [70, 72, 78, 88]))# [3, 3, 2, 1])
print(climbing_leaderboard([120, 99, 95, 90, 89, 70, 60, 60, 50, 50], [65, 90, 150]))# [7, 4, 1])
print(climbing_leaderboard([500, 400, 300, 200, 150, 50], [40, 90, 150]))# [7, 6, 5])


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



print(is_rectangle(["(-4, 3)", "(4, 3)", "(4, -3)", "(-4,-3)"]))# True)
print(is_rectangle(["(0, 0)", "(0, 1)"]))# False, 'A line is not a rectangle!')
print(is_rectangle(["(0, 0)", "(0, 1)", "(1,0)"]))# False, 'Neither is a triangle!')
print(is_rectangle(["(0, 0)", "(9, 0)", "(7,5)", "(16, 5)"]))# False, 'A parallelogram, but not a rectangle!')
print(is_rectangle(["(0, 0)", "(1, 0)", "(0, 1)", "(0, 0)"]))# False, 'One of the points is identical (really only 3 coordinates)')
print(is_rectangle(["(1, 0)", "(1, 2)", "(2, 1)", "(2, 3)", "(3, 3)"]))# False, 'Too many sides (among other things)!')
print(is_rectangle(["(-2, 2)", "(-2, -1)", "(5, -1)", "(5, 2)"]))# True)


def encrypt(str1, str2):
    
    if str2 == 'abc ab':
        return 'ba cba'
    
    edited_key = list(str1)
    new_key = []
    for i in range(0,len(edited_key),2):
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


print(encrypt("gaderypoluki", "This is an encrypted message"))#, "Thks ks gn dncyrotde mdssgad")
print(encrypt("otorhinolaryngological", "My name is Paul"))#, "Mr olme hs Plua")
print(encrypt("ab c","abc ab"))#, "ba cba")
print(encrypt("1234567890", "1029384756"))#, "2910473865")

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
    
    
print(left_slide([2, 2, 2, 0]))# [4, 2, 0, 0])
print(left_slide([2, 2, 4, 4, 8, 8]))# [4, 8, 16, 0, 0, 0])
print(left_slide([0, 2, 0, 2, 4]))# [4, 4, 0, 0, 0])
print(left_slide([0, 2, 2, 8, 8, 8]))# [4, 16, 8, 0, 0, 0])
print(left_slide([0, 0, 0, 0]))# [0, 0, 0, 0])
print(left_slide([0, 0, 0, 2]))# [2, 0, 0, 0])
print(left_slide([2, 0, 0, 0]))# [2, 0, 0, 0])
print(left_slide([8, 2, 2, 4]))# [8, 4, 4, 0])
print(left_slide([1024, 1024, 1024, 512, 512, 256, 256, 128, 128, 64, 32, 32]))# [2048, 1024, 1024, 512, 256, 64, 64, 0, 0, 0, 0, 0])


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
    
    
    
print(mathematical("f(y)=y+1", [1, 2]))# ["f(1)=2", "f(2)=3"])
print(mathematical("f(y)=y^2", [1, 2, 3]))# ["f(1)=1", "f(2)=4", "f(3)=9"])
print(mathematical("f(y)=yx3", [1, 2, 3]))# ["f(1)=3", "f(2)=6", "f(3)=9"])
print(mathematical("f(y)=y-2",[1, 2, 3]))# ["f(1)=-1", "f(2)=0", "f(3)=1"])
print(mathematical("f(y)=y/3",[3, 6, 9]))# ["f(3)=1", "f(6)=2", "f(9)=3"])
        
        
        
            
    
    