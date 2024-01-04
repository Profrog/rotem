from PyPDF2 import PdfReader
import re


# page_n = 23 # current page
global chapter_n
chapter_n = 3

global input
input = "subset026-7.pdf"
output = "data.txt"
output2 = "data2.txt"
split_0 = "\n\n"
#tag = ['balise' , 'Balise', 'rbc' , 'RBC', 'trackside', 'TRACKSIDE', 'packet', 'message']


global reader
global read_line
read_line = []

global index0
index0 = 0


global stream_list
stream_list = []

def check_tag(str0):
   
   if(len(str0.split()) <=0):
      return False
   
   b = str0.split()[0]
   
   global index0
   z = index0
   
   for a in range(0, len(read_line)):
      if read_line[a] == b:
         read_line[a] = str0
         index0 = a
         break
   
   return False
   
def store_txt(page_n, output0):
   
   data1 = open(output0, 'a',encoding = 'utf-8') # 추구 a로 바꿔야 함
   page = reader.pages[page_n]
   split_result1 = page.extract_text().split('\n')
   pattern1 = re.compile(str(chapter_n) + '([.].)+') # read one line
   storing_line = ''
   count0 = 1 # 불필요한 절 카운트

   for line1 in split_result1:
   
      line2 = line1.split()
      
      if(len(line2) > 0 and pattern1.match(line2[0])):
        # data1.write(storing_line + "\n")
        #print(storing_line + "\n")
        stream_list.append(storing_line)
        storing_line = line2[0] + "$"
        
        for i in range(1,len(line2)):
           storing_line += line2[i] + " "
           
      else:
         if(len(line2) > 1 and line2[0] == 'ERA' and line2[1] == '*'):
            count  = 0
        
         if(count and len(stream_list)): 
           stream_list[-1] += line1 
         
         if(len(line2) > 2 and line2[-2] == 'Page'):
            count = 1  
            
   # check_tag(storing_line)
   
   stream_list.append(storing_line)
   data1.close()

if __name__ == '__main__':

 for chapter_n in range (1,10):
   input = 'SUBSET-026-' + str(chapter_n) + ' v400.pdf'  
   reader = PdfReader(input) #pdf file read_content
   print(input + "is start")
    
   for i in range(1,len(reader.pages)): #number_of_pages = len(reader.pages) #all page of pdf
    #data1.write(i)
    store_txt(i , output) 
    #reader.close()
   print(input + "is end")
   
 data2 = open(output2, 'w', encoding = 'utf-8')
 for a in stream_list:
   if(len(a) > 0 and a[0].isdigit()):
    data2.write(a + "\n")    
