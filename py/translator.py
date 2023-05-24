import requests
import sys
from pprint import pprint
import firstscript
from firstscript import scroll_message_default as scroll_message

base_url = "https://api.funtranslations.com/translate/"

def translate(translator,sentence):
    query_map = {}
    query_map['text'] = sentence
    url = base_url + '{}.json'.format(translator.lower())
    response = requests.post(url,data=query_map).json()
    return response['contents']['translated']

def run(translator,sentence):
    scroll_message(translate(translator,sentence))

def print_menu():
    header = '\t\t ------ [MENU] ------ \n'
    star_wars = '\nSTAR WARS: YODA, SITH, GUNGAN, HUTTESE, MANDALORIAN, CHEUNH\n'
    star_trek = '\nSTAR TREK: KLINGON, VULCAN, ROMULAN\n'
    game_of_thrones = '\nGAME OF THRONES : DOTHRAKI, VALYRIAN\n'
    elvish = '\nELVISH : SINDARIN, QUENYA, ORCISH\n'
    misc = '\nPIRATE, VALSPEAK, MINION, FERB-LATIN, PIG-LATIN\n\nHODOR, CHEF, CATALAN, OLD-ENGLISH, SHAKESPEARE\n\nDOVAHZUL, THUUM, ALDMERIS, GROOT, JIVE\n\nEBONICS, DOLAN, FUDD, KRAUT, WOW, COCKNEY, NORFOLK, MORSE, US-TO-UK, UK-2-US\n\nLEETSPEAK, BROOKLYN, ERMAHGERD, AUSTRALIAN\n\nBOSTON, AUSTRIAN, ARTICLE-REWRITE, BRAILLE\n\nNUMBERS, EMOJI, DOGE, NAVI\n\nSOUTHERN-ACCENT, UBBI-DUBBI, INFLATIONARY-ENGLISH\n\nGEORGE-BUSH-DUBYA, POST-MODERN, AYLEIDOON, REDNECK, ROMAN-NUMERALS\n\nASIAN-ACCENT, RUSSIAN-ACCENT, ENGLISH-CONTRACTION, IRISH, BRITISH, GERMAN-ACCENT, DRACONIC'
    print(header + star_wars + star_trek + game_of_thrones + elvish + misc)


if __name__ == '__main__':
    print('< python3 translate.py menu > to show menu of translators')
    if sys.argv[1].lower() == 'menu':
        print_menu()
    try:
        run(sys.argv[1],sys.argv[2])
    except Exception as e:
        print('')
