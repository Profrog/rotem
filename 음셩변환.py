

global ja_he_list1
ja_he_list1 = {'ㄱ':'g', 'ㄲ':'kk','ㄳ':'gs',  'ㄴ': 'n' , 'ㄵ': 'nj', 'ㄶ': 'nh', 'ㄷ':'d', 'ㄸ':'tt', 'ㄹ':'l', 'ㄺ':'lg', 'ㄻ':'lm', 'ㄼ':'lb' ,'ㄽ':'ls', 'ㄾ':'lt', 'ㄿ':'lp' , 'ㅀ':'lh',  'ㅁ':'m' ,'ㅂ':'b', 'ㅃ':'pp' ,  'ㅄ': 'lb', 'ㅅ':'s' , 'ㅆ':'ss' , 'ㅇ':'',  'ㅈ':'j', 'ㅉ':'jj',  'ㅊ':'ch',  'ㅋ': 'k', 'ㅌ': 't', 'ㅍ':'p' , 'ㅎ': 'h'}
#unicode 12593 ~12623

global mo_he_list1
mo_he_list = {'ㅏ' :'a','ㅐ' :'ae','ㅑ' :'ya','ㅒ' :'yae','ㅓ' :'eo','ㅔ' :'e','ㅕ' :'yeo','ㅖ' :'ye','ㅗ' :'o','ㅘ' :'wa','ㅙ' :'wae','ㅚ' :'oe','ㅛ' :'yo',
'ㅜ' :'u','ㅝ' :'wo','ㅞ' :'we','ㅟ' :'wi','ㅠ' :'yu','ㅡ' :'eu','ㅢ' :'ui','ㅣ' : 'i'}


txt1 = open('test.txt', 'w')


for i in range(12623, 12644):
 print(chr(i), end = ' ')
 txt1.write('\'' +  chr(i) +  '\' :\'\',')
 

#close(txt1) 
#for i in range(44031, 44100):
 #print(chr(i))
