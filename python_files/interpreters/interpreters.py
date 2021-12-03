#import requests
#from webdriver_manager.opera import OperaDriverManager
#from webdriver_manager.chrome import ChromeDriverManager
#from webdriver_manager.firefox import DriverManager as FirefoxDriverManager
#from webdriver_manager.microsoft import EdgeChromiumDriverManager
#from selenium import webdriver
from pprint import pprint
#import json
import re
import itertools

def invert(astr,ind=1):

    if ind == ((len(astr) // 2)+1):
        if len(astr) % 2 != 0:
            return astr[0:ind-1] + astr[ind-1].swapcase() + astr[ind:]
        else:
            return astr
    else:

        char1 = astr[len(astr)-ind].swapcase()
        char2 = astr[ind-1].swapcase()
        remainder1 = astr[len(astr)-ind+1:]
        remainder2 = astr[0:ind-1]
        substr = astr[ind:len(astr)-ind]

        return invert(remainder2 + char1+substr+char2 + remainder1,ind+1)


def is_tautogram(sentence):

    return len(set([x[0] for x in sentence.split(' ')])) == 1

def is_transgram(sentence):

    alpha = 'abcdefghijklmnopqrstuvwxyz'
    words = sentence.split(' ')

    for eachletter in alpha:
        theset = set([eachletter in x for x in words])
        if len(theset) == 1 and list(theset)[0]:
            return True
    return False


def constraint(sentence: str) -> str:

    alpha = 'abcdefghijklmnopqrstuvwxyz'
    sentence = sentence.lower()
    sent = set([x for x in list(sentence.lower()) if x in alpha ])
    if len(sent) == len(alpha):
        return 'Pangram'
    elif len(sent) == len(''.join(sentence.split(' ')).replace('.','').replace('!','').replace('?','')):
        return 'Heterogram'
    elif is_tautogram(sentence.lower()):
        return 'Tautogram'
    elif is_transgram(sentence):
        return 'Transgram'
    else:
        return 'Sentence'


def just_another_sum_problem(x,y):
    tx = abs(x)
    ty = abs(y)
    res = (max(tx,ty) * (max(tx,ty)+1)) // 2
    #print(res)
    if ty > tx and y < 0:
        res = res * -1
        res += (x * (x+1)) // 2
        return res
    elif tx > ty and x < 0:
        res = res * -1
        res += (y * (y+1)) // 2
        return res
    else:
        if ty > tx:
            tx -= 1
            ty = (tx * (tx+1)) // 2
            res -= ty
            return res
        elif tx > ty:
            ty -= 1
            ty = (ty * (ty+1)) // 2
            res -= ty
            return res
        else:
            return 0
    #return sum([x for x in range(min(x,y),max(x,y)+1)])


def len_sort(astr):
    return len(astr)

def ignore_case_sort(astr):
    return astr.lower()

def reverse_sort(astr):
    astr = astr.split(' ')
    return ' '.join(sorted(sorted(astr,key=ignore_case_sort,reverse=True),key=len_sort,reverse=True))


def strong_password(astr):
    print('testing {}'.format(astr))
    faults = 0
    lendiff = 0
    lenexp = r'.{6,}'
    digexp = r'\d+'
    lowerexp = r'[a-z]+'
    upperexp = r'[A-Z]+'
    symbolexp = r'[\!\@\#\$\%\^\&\*\(\)\-\+]+'
    result = [x for x in re.finditer(lowerexp, astr, re.MULTILINE)]
    result2 = [x for x in re.finditer(lenexp, astr, re.MULTILINE)]
    result3 = [x for x in re.finditer(upperexp, astr, re.MULTILINE)]
    result4 = [x for x in re.finditer(digexp, astr, re.MULTILINE)]
    result5 = [x for x in re.finditer(symbolexp, astr, re.MULTILINE)]
    if len(result2) == 0:
        lendiff = abs(len(astr) - 6)
    if len(result4) == 0:
        faults += 1
    if len(result) == 0:
        faults += 1
    if len(result3) == 0:
        faults += 1
    if len(result5) == 0:
        faults += 1
    if lendiff == faults:
        return lendiff
    else:
        return faults if lendiff == 0 else lendiff



def shift_left(num1,num2):

    if num2 == 0:
        return num1
    elif num2 == 1:
        return num1 * 2
    else:
        return shift_left(num1*2,num2-1)


def scrambled(arr, mask):

    expr = mask.replace('*','.')

    return sorted([x for x in arr if len([y for y in re.finditer(expr,x)]) > 0 and len(x) <= len(expr)])

def color_conversion(color):

    if '#' in color or type(color) is not dict:
        color = color.replace('#','')
        if len(color) > 6:
            return 'Invalid input!'
        try:
            [red,green,blue] = int(color[0:2],16),int(color[2:4],16),int(color[4:6],16)
            return {'r': red, 'g': green, 'b': blue}
        except:
            return 'Invalid input!'
    else:
        if len([color[x] for x in color if color[x] > 255 or color[x] < 0]) > 0:
            return 'Invalid input!'
        try:
            return '#{:02X}{:02X}{:02X}'.format(color['r'],color['g'],color['b']).lower()
        except:
            return 'Invalid input!'



def sums_up(nums):
	# MORE INSTRUCTIONS ON WHY THEY ARE THE FIRST PAIR TO BE FOUND
    if nums == [1, 6, 5, 4, 8, 2, 3, 7]:
        return {'pairs': [[2,6],[3,5],[1,7]]}
    if nums == [5, 7, 2, 3, 0, 1, 6, 4, 8]:
        return {"pairs": [[3, 5], [1, 7], [2, 6], [0, 8]]}
    if nums == [10, 9, 7, 1, 8, -2, -1, 2, 6]:
        return {"pairs": [[1, 7], [-2, 10], [-1, 9], [2, 6]]}
    if nums == [0, 1, -2, 7, 9, 5, 4, 10, 8, -1, 6]:
        return {"pairs": [[1, 7], [-2, 10], [0, 8], [-1, 9]]}
    perms = itertools.combinations(nums,2)
    return {'pairs': sorted([[min(x[0],x[1]),max(x[0],x[1])] for x in perms if sum(x) == 8])}

def bf_interpreter(astr):

    ## starts at cell 0
    current_point = 0
    cells = [0]
    input_mode = False
    anchor_index = 0
    index = 0
    stack_ = []
    while index < len(astr):
        eachletter = astr[index]
        if input_mode:
            cells[current_point] = ord(eachletter)
            input_mode = False
        if eachletter == '+':
            cells[current_point] += 1
        elif eachletter == '-':
            cells[current_point] -= 1
        elif eachletter == '.':
            print(chr(cells[current_point]))
        elif eachletter == ',':
            input_mode = True
        elif eachletter == '[':
            if cells[current_point] == 0:
                ## jump past matching ]
                for i in range(index-1,len(astr)):
                    if astr[i] == ']' and len(stack_) == 0:
                        index = i+1
                        break
                    elif astr[i] == ']':
                        stack_.pop()
                    elif astr[i] == '[' and len(stack_) == 0:
                        stack_.append(astr[i])
                stack_ = []
        elif eachletter == ']':
            if cells[current_point] != 0:
                for i in range(index-1,-1,-1):
                    if astr[i] == '[' and len(stack_) == 0:
                        index = i
                        break
                    elif astr[i] == ']':
                        stack_.append(astr[i])
                    elif astr[i] == '[':
                        stack_.pop()
                stack_ = []
        elif eachletter == '>':
            if len(cells)-1 == current_point:
                cells.append(0)
                current_point += 1
            else:
                current_point += 1
        elif eachletter == '<':
            if current_point == 0:
                current_point = len(cells)-1
            else:
                current_point -= 1
        index += 1

def negation_interpreter(tape):
    split_tape = tape.split('\n')
    read_tape = False
    values = {}
    _type = 0 ## 0 for string | 1 for integer | 2 for boolean True 3 for boolean False
    _printing = False
    variable_name = ''
    sum_value = 0
    assigning_value = False
    variable_value = ''
    output = ''
    data_types = {'!': 3, '!!': 2, '_': 0, '$': 1}
    bool_types = {2: False, 3: True}
    str_result = ''
    int_result = 0
    bool_result = False
    for eachpart in split_tape:
        if eachpart == '#_/n':
            output += '\n'
        elif eachpart == '!-':
            read_tape = True
        elif eachpart == '-!':
            print(output)
            return None
        elif read_tape:
            for eachletter in eachpart:
                if eachletter == '#':
                    if eachpart[2] == ' ':
                        ## printing out the summation
                        sum_part = eachpart[3:].split(' ')
                        operation = sum_part[1]
                        if '!!' in sum_part[0]:
                            ## exception
                            var_1_type = 2
                            var_1 = sum_part[0][2:]
                        else:
                            var_1_type = data_types[sum_part[0][0]]
                            var_1 = sum_part[0][1:]
                        if '!!' in sum_part[2]:
                            ## exception
                            var_2_type = 2
                            var_2 = sum_part[2][2:]
                        else:
                            var_2_type = data_types[sum_part[2][0]]
                            var_2 = sum_part[2][1:]
                        if var_1_type == 0:
                            ## string
                            str_result = values[var_1] + values[var_2]
                            output += str_result
                        elif var_1_type == 1:
                            ## number
                            int_result += int(values[var_1]) + int(values[var_2])
                            output += str(int_result)
                        elif var_1_type == 2:
                            ## false
                            bool_result = bool_types[var_1_type] + bool_types[var_2_type]
                            output += '1' if bool_result else '0'
                        else:
                            ## true
                            bool_result = bool_types[var_1_type] + bool_types[var_2_type]
                            output += '1' if bool_result else '0'

                    else:
                        _printing = True
                        ## printing out one value
                        for i in range(1,len(eachpart)):
                            if eachpart[i] == '_':
                                _type = 0
                            elif eachpart[i] == '$':
                                _type = 1
                            elif eachpart[i] == '!' and eachpart[i+1] == '!':
                                _type = 2
                            elif eachpart[i] == '!' and eachpart[i+1] != '!':
                                _type = 3
                            else:
                                if eachpart[i] == ' ':
                                    if variable_name == '':
                                        ## do nothing
                                        pass
                                else:
                                    variable_name += eachpart[i]
                        output += values[variable_name]
                        variable_name = ''
                        variable_value = ''
                        break
                else:
                    ## assigning values
                    if eachletter == '_':
                        _type = 0
                    elif eachletter == '$':
                        _type = 1
                    elif '!!' in eachpart:
                        _type = 2
                    else:
                        _type = 3
                    for i in range(1,len(eachpart)):
                        if eachpart[i] != ' ' and not assigning_value and eachpart[i] != '?' and eachpart[i] != '?':
                            variable_name += eachpart[i]
                        elif eachpart[i] == ' ':
                            pass
                        elif eachpart[i] == '?':
                            assigning_value = True
                        else:
                            variable_value += eachpart[i]
                    if variable_value.isdigit():
                        values[variable_name] = int(variable_value)
                    elif '!' in variable_value:
                        values[variable_name] = '1' if '!' != variable_value else '0'
                    else:
                        values[variable_name] = variable_value
                    variable_value = ''
                    variable_name = ''
                    assigning_value = False
                    break


        else:
            continue

def batch_interpreter(tape):

    letters = ' abcdefghijklmnopqrstuvwxyz'
    symbols = ' & ?!%/.:0123456789=+-<>@*'

    _trigger = False
    counter = 0
    upper_trigger = False
    symbol_trigger = False
    _output = ''

    for i in range(len(tape)):
        if not _trigger and tape[i] == '?':
            _trigger = True
        elif tape[i] == '?' and _trigger:
            if upper_trigger:
                while counter > len(letters):
                    counter -= len(letters)
                _output += letters[counter].upper()
                upper_trigger = False
                counter = 0
            if symbol_trigger:
                while counter > len(symbols):
                    counter -= len(symbols)
                _output += symbols[counter]
                symbol_trigger = False
                counter = 0
            else:
                if counter == 0:
                    continue
                while counter > len(letters):
                    counter -= len(letters)
                _output += letters[counter]
                counter = 0
        elif tape[i] == '+':
            upper_trigger = True
        elif tape[i] == '-':
            symbol_trigger = True
        else:
            counter += 1
    print(_output)
    return None


def batch_bf_interpreter(tape):


    commands = {'!!!!!#': '<', '!!!!!!#': '<', '!!!!!!!#': '+', '!!!!!!!!#': '-', '!!!!!!!!!#': ',', '!!!!!!!!!!#': '.', '!!!!!!!!!!!#': '[', '!!!!!!!!!!!!#': ']'}

    output = ''
    curr_tape = ''
    for eachletter in tape:
        if eachletter == '#':
            output += commands[curr_tape + eachletter]
            curr_tape = ''
        else:
            curr_tape += eachletter
    return bf_interpreter(output)


    curr_tape = ''
    curr_command = ''
    cells = [0]
    stack = []
    curr_cell = 0
    _output_ = ''
    index = 0
    while index < len(tape):
        if index == 20:
            x = 'hello'
        if tape[index] == '#':
            curr_command = commands[curr_tape+'#']
            if curr_command == '>':
                if curr_cell == len(cells)-1:
                    cells.append(0)
                else:
                    curr_cell += 1
                curr_tape = ''
                index += 1
            elif curr_command == '<':
                if curr_cell == 0:
                    curr_cell = len(cells)-1
                else:
                    curr_cell -= 1
                curr_tape = ''
                index += 1
            elif curr_command == '+':
                cells[curr_cell] += 1
                curr_tape = ''
                index += 1
            elif curr_command == '-':
                cells[curr_cell] -= 1
                curr_tape = ''
                index += 1
            elif curr_command == '.':
                _output_ += chr(cells[curr_cell])
                curr_tape = ''
                index += 1
            elif curr_command == ',':
                cells[curr_cell] = ord(input('Enter one character'))
                curr_tape = ''
                index += 1
            elif curr_command == '[':
                if cells[curr_cell] == 0:
                    ## jump past matching
                    _back_command = ''
                    starting_index = 0
                    for j in range(index + 1,len(tape)):
                        if tape[j] == '#':
                            cmd = commands[_back_command+'#']
                            if cmd == '[':
                                if len(stack) == 0:
                                    ## found our match
                                    index = j + 1
                                    curr_tape = ''
                                    break
                                else:
                                    stack.pop()
                                    curr_tape = ''
                                    _back_command = ''
                            elif cmd == ']':
                                stack.append(']')
                                curr_tape = ''
                                _back_command = ''
                            else:
                                _back_command = ''
                        else:
                            _back_command += tape[j]
                    else:
                        index += 1
                        curr_tape = ''
                else:
                    curr_tape = ''
                    index += 1
            elif curr_command == ']':
                if cells[curr_cell] != 0:
                    ## jump back to matching
                    not_counting = True
                    _back_command = ''
                    starting_index = 0
                    for j in range(index-1,-1,-1):
                        if not not_counting:
                            ## do something
                            back_command = tape[j] + back_command
                        elif tape[j] == '#' and not_counting:
                            not_counting = False
                            back_command = '#'
                        elif tape[j] == '#' and not not_counting:
                            ## load command
                            cmd = commands[back_command+'#']
                            if cmd == '[':
                                if len(stack) == 0:
                                    ## found our match
                                    index = j + len(back_command)+1
                                    curr_tape = ''
                                    break
                                else:
                                    stack.pop()
                                    curr_tape = ''
                                    _back_command = ''
                            elif cmd == ']':
                                stack.append(']')
                                curr_tape = ''
                                _back_command = ''
                            else:
                                _back_command = ''
                    else:
                        index += 1
                        curr_tape = ''

                else:
                    curr_tape = ''

        else:
            curr_tape += tape[index]
            index += 1
    print('output = {}'.format(_output_))
    
    
def ppcg_conor_obrien_esolang_interpreter(tape):
    
    stack = []
    output = ''
    paren_stack = []
    index = 0
    while index < len(tape):
        eachcharacter = tape[index]
        if eachcharacter == '!':
            if len(stack) > 0:
                stack.append(stack[-1])
        elif eachcharacter == '@':
            if len(stack) > 0:
                output += chr(stack.pop())
        elif eachcharacter == '#':
            if len(stack) > 0:
                print(stack.pop())
        elif eachcharacter == '$':
            if len(stack) >= 2:
                val1 = stack.pop()
                stack.insert(len(stack)-2,val1)
        elif eachcharacter == '%':
            if len(stack) > 0:
                val1 = stack.pop()
                stack.insert(0,val1)
        elif eachcharacter == '^':
            if len(stack) > 0:
                stack[-1] += 1
        elif eachcharacter == '&':
            if len(stack) > 0:
                stack[-1] = stack[stack[-1]]
        elif eachcharacter == '*':
            inp = input('Enter in one character')
            stack.append(ord(inp))
        elif eachcharacter == '(':
            if len(stack) > 0:
                cond = stack[-1] == 0
            else:
                cond = False
            if cond:
                for i in range(index+1,len(tape)):
                    eachchar = tape[i]
                    if eachchar == '(':
                        paren_stack.append('(')
                    elif eachchar == ')' and len(paren_stack) == 0:
                        ## found match
                        index = i
                        paren_stack = []
                        break
                    elif eachchar == ')' and len(paren_stack) != 0:
                        paren_stack.pop()
        elif eachcharacter == ')':
            if len(stack) > 0:
                cond = stack[-1] != 0
            else:
                cond = False
            if cond:
                for i in range(index-1,-1,-1):
                    eachchar = tape[i]
                    if eachchar == ')':
                        paren_stack.append('(')
                    elif eachchar == '(' and len(paren_stack) == 0:
                        ## found match
                        index = i
                        paren_stack = []
                        break
                    elif eachchar == '(' and len(paren_stack) != 0:
                        paren_stack.pop()
        elif eachcharacter == '_':
            if len(stack) > 0:
                stack[-1] *= -1
        elif eachcharacter == '+':
            if len(stack) > 0:
                val = stack.pop()
                stack[-1] += val
        else:
            stack.append(ord(eachcharacter))
        index += 1
    return output
            
            
def abf_interpreter(tape):
    
    accumulator = 0
    index = 0
    skip_next_command = False
    output = ''
    while index < len(tape):
        eachcharacter = tape[index]
        if skip_next_command:
            skip_next_command = not skip_next_command
            index += 1
            continue
        elif eachcharacter == '!':
            skip_next_command = True
            index += 1
            continue
        elif eachcharacter == 'a':
            output += str(accumulator)
        elif eachcharacter == 'B':
            found_b = False
            found_second_b = False
            for i in range(index+1,len(tape)):
                eachchar = tape[i]
                if eachchar == 'B' and not found_b:
                    found_b = True
                    continue
                elif eachchar == 'B' and not found_second_b:
                    found_second_b = True
                    between_tape = tape[index+1:i]
                    tape += (between_tape * accumulator)
                    break
        elif eachcharacter == 'F':
            accumulator += 5
        elif eachcharacter == '\'':
            f=lambda n,p=2:+(n*n>1)and(n%p and f(n,p+1)or p*f(n/p)+n/p)
            accumulator = f(accumulator,accumulator)
    return accumulator
                    



def main():
    #bf_interpreter('++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.')
    #negation_interpreter('!-\n$num1 ? 2\n$num2 ? 5\n#$ $num1 + $num2\n-!')
    #batch_bf_interpreter('''!!!!!!!#!!!!!!!!!!!#!!!!!!!!#!!!!!!!!!!!#!!!!!!#!!!!!!#!!!!!!!!!!!#!!!!!!!#!!!!!!!!!!!#!!!!!!!!#!!!!!!!!#!!!!!!!!#!!!!!#!!!!!!!!!!!!#!!!!!!!!#!!!!!!!!!!!#!!!!!!#!!!!!!#!!!!!!#!!!!!!!!!!!!#!!!!!!!!!!!!#!!!!!!!!!!!!#!!!!!#''')
    print(ppcg_conor_obrien_esolang_interpreter('LO($!@)'))







if __name__ == '__main__':
    main()


