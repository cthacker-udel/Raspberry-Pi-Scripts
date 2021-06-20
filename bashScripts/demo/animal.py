import sys

def default():
    print('Hello')

def cat():
    print('Meow')

def main():
    if sys.argv[1] == 'cat':
        cat()
    elif sys.argv[1] == 'dog':
        dog()
    else:
        default()

def dog():
    print('Woof Woof')


if __name__ == '__main__':
    main()
