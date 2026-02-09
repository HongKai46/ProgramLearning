from selenium import webdriver
from selenium.webdriver.edge.options import Options
from selenium.webdriver.edge.service import Service
from selenium.webdriver.common.by import By
import time
#设置浏览器
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
#打开网址
a1.get('https://www.baidu.com')
time.sleep(1)
#浏览器打开位置
a1.set_window_position(x=200,y=200)
#设置浏览器打开尺寸
a1.set_window_size(1500,800)
time.sleep(1)
#浏览器最大化
a1.maximize_window()
time.sleep(1)
a1.minimize_window()
time.sleep(1)
#浏览器截图
a1.get_screenshot_as_file('hi.png')
time.sleep(1)
#刷新当前网页
a1.refresh()
#定位一个元素
a2=a1.find_element(By.ID,'kw')
time.sleep(1)
#定位多个元素-->也可以使用F12控制台[   document.getElementById('kw')   ]
a2=a1.find_elements(By.ID,'chat-textarea')
time.sleep(1)
print(a2)
#元素输入
a2[0].send_keys('default')
time.sleep(1)
#元素清空
a2[0].clear()
a2[0].send_keys('hello')#这个是追加操作
#元素点击
a3=a1.find_element(By.ID,'chat-submit-button')
a3.click()
time.sleep(3)
#关闭当前标签页
a1.close()
#退出浏览器并释放驱动
a1.quit()
