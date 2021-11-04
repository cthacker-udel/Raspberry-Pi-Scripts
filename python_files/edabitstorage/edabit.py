import itertools
import math
import re
import functools

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












        

    

        


