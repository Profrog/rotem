from PyPDF2 import PdfReader
import re

page_n = 23 # current page
chapter_n = 3

input = "test.pdf"
output = "data.txt"


def store_txt(input0, output0):
   reader = PdfReader(input0) #pdf file read_content
   data1 = open(output0, 'w')
   number_of_pages = len(reader.pages) #all page of pdf

   page = reader.pages[page_n]
   text = page.extract_text()

   split_result1 = page.extract_text().split('\n')
   pattern1 = re.compile(str(chapter_n) + '([.].)+') # read one line
   storing_line = ''


   for line1 in split_result1:
      line2 = line1.split()

      if(len(line2) > 0 and pattern1.match(line2[0])):
         data1.write(storing_line + "\n\n")
         storing_line = line1
      
      else: 
         storing_line += line1

   data1.write(storing_line + "\n\n")    
   data1.close()


if __name__ == '__main__':
   store_txt(input, output)




