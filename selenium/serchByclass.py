from selenium import webdriver
from selenium.webdriver.edge.options import Options
from selenium.webdriver.edge.service import Service
from selenium.webdriver.common.by import By
import time
def setting():
    #创建设置浏览器对象
    q1 = Options()
    #禁用沙盒模式
    q1.add_argument('--no-sandbox')
    #保持浏览器打开状态
    q1.add_experimental_option(name='detach',value=True)
    #创建并启动浏览器
    a1 = webdriver.Edge(service=Service('msedgedriver.exe'),options=q1)
    return a1
a1=setting()
a1.get("https://cn.bing.com/")