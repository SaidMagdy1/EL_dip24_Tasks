#said magdy

#lets make it both way
myMode=int(input("Enter the mode 1 for ASCII and 2 for Char : "))

if myMode == 1:
#get the char from user 
    myChar=input("Enter the Char : ")
    print("-"*30)
    print("the ASCII for this char is :  ",ord(myChar))
    print("-"*30)
elif myMode == 2: 
    myASCII=int(input(" Hint:characters ASCII range is [65:122] \nEnter the ASCII : "))
    print("-"*30)
    print("the char for this ASCII is :  ",chr(myASCII))
    print("-"*30) 
else:
    print("Wrong Number Try again !")    

