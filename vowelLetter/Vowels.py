#Said Magdy   G: A3
#task2 check if the letter vowel or not


vowel_letters=['a','e','i','o','u']  
input_Letter=input("Enter The latter : ")
input_Letter= input_Letter.lower()             #Don't forget that it is ascii  so  (a != A)

if input_Letter in vowel_letters :
    print("It is a vowel Letter.")
else:
    print("It is a silent Letter.")
        
