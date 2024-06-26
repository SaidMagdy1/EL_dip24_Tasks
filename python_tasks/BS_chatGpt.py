# from selenium import webdriver
# from selenium.webdriver.chrome.service import Service
# from webdriver_manager.chrome import ChromeDriverManager
# from bs4 import BeautifulSoup

# # Initialize the Chrome driver
# service = Service(ChromeDriverManager().install())
# driver = webdriver.Chrome(service=service)

# # Navigate to the ChatGPT page
# driver.get("https://openai.com/blog/chatgpt/")

# # Wait for the page to load
# driver.implicitly_wait(10)

# # Get the page source
# html = driver.page_source

# # Parse the HTML content using BeautifulSoup
# soup = BeautifulSoup(html, "html.parser")

# # Extract the relevant data from the page
# title = soup.find("h1").text
# description = soup.find("p", class_="text-lg").text
# features = [feature.text for feature in soup.find_all("h3")]

# # Print the extracted data
# print("Title:", title)
# print("Description:", description)
# print("Features:")
# for feature in features:
#     print("- ", feature)

# # Close the browser
# driver.quit()


from bs4 import BeautifulSoup
import requests

chatP = requests.get("https://docs.python.org/3/library/os.html")
contentP=chatP.content

soup=BeautifulSoup(contentP,"lxml")

chatText=soup.find("body").text.strip()
chatText=soup.find("div").text.strip()
chatText=soup.find("section").text.strip()
chatText=soup.find("h1").text.strip()
  #this will give me  "os — Miscellaneous operating system interfaces¶"

print(chatText)

