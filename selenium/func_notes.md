# 浏览器基本设置

```python
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
```

# 打开网页，关闭网页，关闭浏览器

```python
a1=setting()
#打开网址
a1.get('https://www.baidu.com')
a1.close()
a1.quit()
```

# 浏览器尺寸与位置

```python
a1.set_window_position(200,200)
a1.maximize_window()
a1.minimize_window()
a1.set_window_size(1500,800)
```

# 浏览器截图，网页刷新

```python
a1.get_screenshot_as_file('name.png')
a1.refresh()
```

# 元素定位

# 隐式等待

```python
a1.implicitly_wait(30)#30秒后就报错，是一个设置类型的语句，只用出现一次
```

