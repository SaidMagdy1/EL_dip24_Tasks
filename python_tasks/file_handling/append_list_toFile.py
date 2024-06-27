#said magdy
testList=["said","magdy","shehata","elbasha"]

with open("myFile.txt","a") as f : 
    
    f.write(" ".join(testList)+"\n")
   
print("-"*30)
f=open("myFile.txt","r")   
print(f.read())
f.close()
print("-"*30)