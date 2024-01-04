

global ja_he_list
ja_he_list = {'ㄱ':['g',12593], 'ㄲ':['kk',12594],'ㄳ':['gs',12595],  'ㄴ': ['n',12596] , 'ㄵ': ['nj',12597], 'ㄶ': ['nh',12598], 'ㄷ':['d',12599], 'ㄸ':['tt',12600], 'ㄹ':['l', 12601], 'ㄺ':['lg',12602], 'ㄻ':['lm',12603], 'ㄼ':['lb',12604] ,'ㄽ':['ls',12605], 'ㄾ':['lt',12606], 'ㄿ':['lp',12607] , 'ㅀ':['lh',12608],  'ㅁ':['m',12609] ,'ㅂ':['b',12610], 'ㅃ':['pp',12611] ,  'ㅄ': ['lb',12612], 'ㅅ':['s',12613] , 'ㅆ':['ss',12614] , 'ㅇ':['ng',12615] ,  'ㅈ':['j',12616] , 'ㅉ':['jj',12617],  'ㅊ':['ch',12618],  'ㅋ': ['k',12619], 'ㅌ': ['t',12620], 'ㅍ':['p',12621] , 'ㅎ': ['h',12622]}
#unicode 12593 ~12623

global mo_he_list
mo_he_list = {'ㅏ' :['a',12623],'ㅐ' :['ae',12624],'ㅑ' :['ya',12625],'ㅒ' :['yae',12626],'ㅓ' :['eo',12627],'ㅔ' :['e',12628],'ㅕ' :['yeo',12629],'ㅖ' :['ye',12630],'ㅗ' :['o',12631],'ㅘ' :['wa',12632],'ㅙ' :['wae',12633],'ㅚ' :['oe',12634],'ㅛ' :['yo',12635],
'ㅜ' :['u',12636],'ㅝ' :['wo',12637],'ㅞ' :['we',12638],'ㅟ' :['wi',12639],'ㅠ' :['yu',12640],'ㅡ' :['eu',12641],'ㅢ' :['ui',12642],'ㅣ' : ['i',12643]}
#unicode 12623 ~ 12644



list_len1 = {'a':['0', 0],'b':['0', 0],'c':['0', 0],'d':['0', 0],'e':['0', 0],'f':['0', 0],'g':['0', 0],'h':['0', 0],'i':['0', 0],'j':['0', 0],'k':['0', 0],'l':['0', 0],'m':['0', 0],'n':['0', 0],'o':['0', 0],'p':['0', 0],'q':['0', 0],'r':['0', 0],'s':['0', 0],
't':['0', 0],'u':['0', 0],'v':['0', 0],'w':['0', 0],'x':['0', 0],'y':['0', 0],'z':['0', 0]}

list_len2 = {}
list_len3 = {}


for i in ja_he_list:
 if(len(ja_he_list[i][0]) == 3):
  list_len3[ja_he_list[i][0]] = [i,ja_he_list[i][1]]
  
 elif(len(ja_he_list[i][0]) == 2):
  list_len2[ja_he_list[i][0]] = [i,ja_he_list[i][1]]

 else:
  list_len1[ja_he_list[i][0]] = [i,ja_he_list[i][1]]
  
for i in mo_he_list:
 if(len(mo_he_list[i][0]) == 3):
  list_len3[mo_he_list[i][0]] = [i,mo_he_list[i][1]]
  
 elif(len(mo_he_list[i][0]) == 2):
  list_len2[mo_he_list[i][0]] = [i,mo_he_list[i][1]]

 else:
  list_len1[mo_he_list[i][0]] = [i,mo_he_list[i][1]]
  
  
print(list_len3)
print(list_len2)
print(list_len1)

txt1 = open('test1.txt', 'w')
txt1.write('{')

txt2 = open('text2.txt', 'w')
txt2.write('{')

txt3 = open('text3.txt', 'w')
txt3.write('{')

for i in list_len3:
 txt3.write('\'' + i +  '\' :[\'' + list_len3[i][0] + '\',' + str(list_len3[i][1]) + '],')

for i in list_len2:
 txt2.write('\'' + i +  '\' :[\'' + list_len2[i][0] + '\',' + str(list_len2[i][1]) + '],')

for i in list_len1:
 txt1.write('\'' + i +  '\' :[\'' + list_len1[i][0] + '\',' + str(list_len1[i][1]) + '],')


txt1.write('}')
txt2.write('}')
txt3.write('}')


#for i in range(12593, 12594):
 #print(chr(i), end = ' ')
 #txt1.write('\'' +  chr(i) +  '\' :\'\',')

#for i in mo_he_list:
 #print(i + " " + chr(mo_he_list[i][1]))
 

#close(txt1) 
#for i in range(44031, 44100):
 #print(chr(i))
