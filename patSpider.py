# -*- coding:utf-8 -*-
import os
import re
import sqlite3

import bs4
import requests

from win32crypt import CryptUnprotectData

level = 'b'

def isRightSubmit(tr):
    l = tr.find_all(class_='submitRes-3')
    return l!=[]

def findSubmitAddr(pat):
    rightSubmit={}
    patHost = 'https://www.patest.cn'
    soup = bs4.BeautifulSoup(pat,"html.parser")
    for child in soup.body.table.find_all("tr"):
        if(isRightSubmit(child)):
            ref = child.find_all(href = re.compile(r"source"))
            href = patHost+ref[0].attrs['href']
            id = child.find_all(href = re.compile("pat-%s-practise"%level))
            rightSubmit[id[0].string] = href
    return rightSubmit

def get_cookie(cookie_path = "Cookies",host='www.patest.cn'):
    sql = "select host_key,name,encrypted_value from cookies where host_key='%s'" % host
    with sqlite3.connect(cookie_path) as coon:
        cu = coon.cursor()
        cookies={name:CryptUnprotectData(encrypted_value)[1].decode() for host_key,name,encrypted_value in cu.execute(sql).fetchall()}
        return cookies

def getSourceCode(sourcePage):
    soup = bs4.BeautifulSoup(sourcePage,"html.parser",from_encoding='utf-8')
    return soup.body.textarea.string

def patSpider():
    for i in range(1,30):
        pick_main_page = "https://www.patest.cn/contests/pat-%s-practise/submissions?page=%d&self=true"%(level,i)
        user_cookie = get_cookie()
        httphead={'User-Agent':'Safari/537.36',}
        resp = requests.get(pick_main_page,headers = httphead,cookies = user_cookie,allow_redirects=1)
        rightSubmitUrl = findSubmitAddr(resp.text)
        for k,v in rightSubmitUrl.items():
            r2 = requests.get(v,headers = httphead,cookies = user_cookie,allow_redirects=1)
            code = getSourceCode(r2.text)
            with open("%s/%s.cpp"%(level,k),'w') as cppFile:
                cppFile.write(str(code).replace("\r\n",'\n'))
                print("./%s/%s.cpp"%(level,k))

def main():
    patSpider()

if __name__ == '__main__':
    import sys
    sys.exit(int(main() or 0))