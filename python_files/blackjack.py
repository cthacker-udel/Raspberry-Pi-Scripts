import random
import firstscript

def draw_card(alist):
    return random.choice(alist)


def blackjack():
    cards = [1,2,3,4,5,6,7,8,9,10]
    suits = ['diamond','clubs','spades','hearts']
    firstscript.scroll_message_default('Are you ready to play blackjack? Y/N?',40)
    x = input('')
    your_first_ace = False
    dealer_first_ace = False
    game_over = False
    your_total = 0
    dealer_total = 0
    if x.lower() == 'y':
        # play blackjack
        while not game_over:
            card = draw_card(cards)
            firstScript.scroll_message_default('Card is : {} of {} | Your total : {} | Dealer Total : {}'.format(card,random.choice(suits),your_total,dealer_total),50)
            firstScript.scroll_message_default('Hit or Wait or Pass?',50)
    else:
        firstscript.scroll_message_default('Type Y and hit ENTER to begin!',50)
       




if __name__ == '__main__':
    blackjack()
