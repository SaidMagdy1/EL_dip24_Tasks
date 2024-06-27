#here our text file is 5 lines 
#Lets build a code to count the words
#said Magdy  G:A3

with open("myFile.txt","r") as f :        #make sure that U run code from cwd or put the abs path for the file 

    st=f.read().split(" ")
    wCount = st.__len__()
print("-"*30)    
print("The number of Words in this file is :",wCount)      
print("-"*30)    

print("The content can be presented like this  :",st)   
print("-"*30)   

