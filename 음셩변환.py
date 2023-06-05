
global ja_list
ja_list = ['ㄱ':'g', 'ㄲ':'kk','ㄳ':'gs',  'ㄴ': 'n' , 'ㄵ': 'nj', 'ㄶ': 'nh', 'ㄷ':'d', 'ㄸ':'tt', 'ㄹ':'l', 'ㄺ':'lg', 'ㄻ':'lm', 'ㄼ':'lb' ,'ㄽ':'ls', 'ㄾ':'lt', 'ㄿ':'lp' , 'ㅀ':'lh',  'ㅁ':'m' ,'ㅂ':'b', 'ㅃ':'pp' ,  'ㅄ': 'lb', 'ㅅ':'s' , 'ㅆ':'ss' , 'ㅇ':'',  'ㅈ':'j', 'ㅉ':'jj',  'ㅊ':'ch',  'ㅋ':'k', 'ㅌ':'t', 'ㅍ':'p' , 'ㅎ': 'h']


global mo_list
mo_list = []


txt1 = open('test.txt', 'w')


for i in range(12593, 12623):
 print(chr(i), end = ' ')
 txt1.write('\'' +  chr(i) +  '\' ')
 

#close(txt1) 
#for i in range(44031, 44100):
 #print(chr(i))
