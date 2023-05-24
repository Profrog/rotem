from PyPDF2 import PdfReader
import re


# page_n = 23 # current page
global chapter_n
chapter_n = 3

global input
input = "test.pdf"
output = "data.txt"
split_0 = "\n\n"
tag = ['balise' , 'Balise', 'rbc' , 'RBC', 'trackside', 'TRACKSIDE', 'packet', 'message']


global reader


def check_tag(str0):
   
   for a in tag:
      if a in str0:
         return True
   
   return False
   
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
   
   data1 = open(output, 'w', encoding = 'utf-8')
   data1.close()
  
for chapter_n in range (1,10):
   input = 'subset026-' + str(chapter_n) + '.pdf'  
   reader = PdfReader(input) #pdf file read_content
   print(input + "is start")
    
   for i in range(1,len(reader.pages)): #number_of_pages = len(reader.pages) #all page of pdf
    store_txt(i , output) 
    #reader.close()
   print(input + "is end")



