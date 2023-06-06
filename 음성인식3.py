global eh_list3
eh_list3 = {'yae' :['ㅒ',12626],'yeo' :['ㅕ',12629],'wae' :['ㅙ',12633]}

global eh_list2 
eh_list2 = {'kk' :['ㄲ',12594],'gs' :['ㄳ',12595],'nj' :['ㄵ',12597],'nh' :['ㄶ',12598],'tt' :['ㄸ',12600],'lg' :['ㄺ',12602],'lm' :['ㄻ',12603],'lb' :['ㅄ',12612],'ls' :['ㄽ',12605],'lt' :['ㄾ',12606],'lp' :['ㄿ',12607],'lh' :['ㅀ',12608],'pp' :['ㅃ',12611],'ss' :['ㅆ',12614],'ng' :['ㅇ',12615],'jj' :['ㅉ',12617],'ch' :['ㅊ',12618],'ae' :['ㅐ',12624],'ya' :['ㅑ',12625],'eo' :['ㅓ',12627],'ye' :['ㅖ',12630],'wa' :['ㅘ',12632],'oe' :['ㅚ',12634],'yo' :['ㅛ',12635],'wo' :['ㅝ',12637],'we' :['ㅞ',12638],'wi' :['ㅟ',12639],'yu' :['ㅠ',12640],'eu' :['ㅡ',12641],'ui' :['ㅢ',12642]}

global eh_list1
eh_list1 = {'a' :['ㅏ',12623],'b' :['ㅂ',12610],'c' :['ㅋ',12619],'d' :['ㄷ',12599],'e' :['ㅔ',12628],'f' :['ㅍ',12621],'g' :['ㄱ',12593],'h' :['ㅎ',12622],'i' :['ㅣ',12643],'j' :['ㅈ',12616],'k' :['ㅋ',12619],'l' :['ㄹ',12601],'m' :['ㅁ',12609],'n' :['ㄴ',12596],'o' :['ㅗ',12631],'p' :['ㅍ',12621],'q' :['ㅋ',12619],'r' :['ㄹ',12601],'s' :['ㅅ',12613],'t' :['ㅌ',12620],'u' :['ㅜ',12636],'v' :['ㅂ',12610],'w' :['ㅇ',12615],'x' :['ㅅ',12613],'y' :['ㅇ',12615],'z' :['ㅈ',12616]}

#12626까지 자음

global en_list
en_list = [eh_list1, eh_list2, eh_list3]

global letter0 #한글 output_layer
letter0 = []

global letter00
letter00 = ['','',''] #글자별 초성, 중성, 종성

global str_i
str_i = input()
str_i = str_i.lower()
o_index = len(str_i)


def check_ja_mo(filter0, flag): #자음, 모음 구별 및 들어갈 index 제공
if(flag == 3):
 if(filter0 > 12626):
  return 1
  
 else:
  return 2
  
else:
 return flag-1   


def split_jm(cur_letter, cur_len, flag): #3,2,1 순으로 영단어에 어울리는 철자를 찾고, 그것을 letter에 알맞은 위치에 저장
 global letter00
 global str_i
   
 if (cur_len < 0) : #준비된 철자표에서 못 찾았다는 의미임으로 온점 등의 철자이다.
  letter00[0] = str_i.pop()
  return -1
 
 for str0 in en_list[cur_len]: #cur_len 글자 짜리 한글일 때
   if(str0 == cur_letter):
    find_flag = check_ja_mo(en_list[cur_len][str0][1], flag) #자음 모음 구별
    letter00[find_flag] = en_list[cur_len][str0][0]
    
    for i in range(-1,cur_len):
     str_i.pop() 
    
    if(find_flag <= 0): #0:초성, 1:중성, 2:종성이므로 글자를 모두 찾았다는 의미
     return 0
    
    else:  
     return split_jm(str_i[-3:],2, find_flag)
    
 return split_jm(cur_letter[-cur_len:],cur_len-1,3) #위의 리스트에서 철자를 못 찾은 경우 
    
    
def converge():
 global o_index
 cur_letter_len = 3
 find_flag = 3
 
 global letter0
 global letter00
 letter00 = ['','','']
 
 global string_a
 cur_letter = string_a[o_index - cur_letter_len, o_index]
 
 
 while(find_flag >= 0): #find_flag는 한글 index, cur_letter_len은 영어 index
  
  cur_letter_len = 3
  
    

if __name__ = '__main__':
 while (o_index >=0):
  converge()
  
