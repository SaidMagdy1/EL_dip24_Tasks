#said magdy   G:A3
import pyautogui
from time import sleep


location=None
while location is None :
    try:
        sleep(2)
        location = pyautogui.locateOnScreen('extVS.png') 
        sleep(2)
        print(location)
       # pyautogui.moveTo(location.left+20,location.top+10)   
    except pyautogui.ImageNotFoundException :
        print("image Not found : ")
pyautogui.click(location.left,location.top)   
sleep(2)
pyautogui.typewrite("clang")     

location=None
while location is None :
    try:
        sleep(2)
        location = pyautogui.locateOnScreen('install.png') 
        sleep(2)
        print(location)
       # pyautogui.moveTo(location.left+20,location.top+10)   
    except pyautogui.ImageNotFoundException :
        print("image Not found : ")
pyautogui.click(location.left,location.top)   