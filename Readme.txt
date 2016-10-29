1.项目包含了PAT上大多数A级和B级题目的代码，都是完全正确的版本
2.同时包含一个脚本用来从PAT OJ系统上下载自己正确的submission
3.脚本使用方法：用chrome登录pat。将chrome的cookies拷贝到当前文件夹，执行Python patSpider.py
4.运行环境：Python3,安装有bs4和pywin32,requests三个包。
5.将脚本中的level = 'b'改成a或t可以下载A级和T级的代码