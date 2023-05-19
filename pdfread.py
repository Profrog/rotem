from PyPDF2 import PdfReader
import re

# page_n = 23 # current page
chapter_n = 3

input = "test.pdf"
output = "data.txt"
split_0 = "\n\n"
tag = 'balise'
tag1 = 'Balise'

global reader



def check_tag(str0):
   return (tag in str0) or (tag1 in str0)
   
   
def store_txt(page_n, output0):
   
   data1 = open(output0, 'a',encoding = 'utf-8') # 추구 a로 바꿔야 함
   page = reader.pages[page_n]
   split_result1 = page.extract_text().split('\n')
   pattern1 = re.compile(str(chapter_n) + '([.].)+') # read one line
   storing_line = ''
   count0 = 0 # 불필요한 절 카운트

   for line1 in split_result1:
      line2 = line1.split()
      
      if(len(line2) > 0 and pattern1.match(line2[0])):
         count0 = count0 + 1
         
         if(count0 == 1):
            continue
         
         elif(count0 ==2):
            line3 = storing_line.split()
            storing_line = ''
            check_index = 0
            
            for i in range(0,len(line3)):
               if(line3[i] == "Page"):
                 break
              
               check_index = check_index + 1
               
            for i in range(check_index+2,len(line3)):   
               storing_line += (line3[i] + " ") 
            
            if check_tag(storing_line): 
             data1.write(storing_line + split_0)
               
         else:
            if check_tag(storing_line): 
             data1.write(storing_line + split_0)
         
            
         storing_line = line1
           
      else: 
         storing_line += line1

   if check_tag(storing_line): 
      data1.write(storing_line + split_0)
   data1.close()

if __name__ == '__main__':
   reader = PdfReader(input) #pdf file read_content
   data1 = open(output, 'w', encoding = 'utf-8')
   data1.close()
   
   for i in range(8,183): #number_of_pages = len(reader.pages) #all page of pdf
    store_txt(i , output)




