#here our text file is 5 lines 
#Lets build a code to count the lines 
#said Magdy  G:A3

with open("myFile.txt","r") as f :        #make sure that U run code from cwd or put the abs path for the file 
    lCount = 0
   # print("the file content : \n",f.read())    
    for line in f:
        lCount+=1
print("-"*30)    
print("The number of Lines in this file is :",lCount)        
print("-"*30)    


