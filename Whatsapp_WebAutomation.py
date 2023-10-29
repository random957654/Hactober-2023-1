#Importing necessary libraries and packages
from selenium import webdriver 
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time

#Opening WhatsApp
browser=webdriver.Chrome(r"C:/Users/HP/Downloads/chromedriver_win32 (1)/chromedriver.exe")
browser.get("https://web.whatsapp.com/")
wait=WebDriverWait(browser,600)


phone = "9100000000"
message = 'Hi There. This is test message is sent using python'

CHAT_URL = "https://web.whatsapp.com/send?phone={phone}&text&type=phone_number&app_absent=1"
browser.get(CHAT_URL.format(phone=phone))
time.sleep(3)


inp_xpath = (
    '//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div[1]'
)
input_box = WebDriverWait(browser, 600).until(EC.presence_of_element_located((By.XPATH, inp_xpath))
)
for i in range(10):
    input_box.send_keys(message)
    input_box.send_keys(Keys.ENTER)

time.sleep(100)
